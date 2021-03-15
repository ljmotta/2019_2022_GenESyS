/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationModel.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 15:01
 */

#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <string>

#include "Model.h"
#include "SourceModelComponent.h"
#include "Simulator.h"
#include "StatisticsCollector.h"
#include "Traits.h"
//#include "Access.h"

//using namespace GenesysKernel;

bool EventCompare(const Event* a, const Event * b) {
	return a->time() < b->time();
}

Model::Model(Simulator* simulator) {
	_parentSimulator = simulator; // a simulator is the "parent" of a model
	// 1:1 associations (no Traits)
	_traceManager = simulator->tracer(); // every model starts with the same tracer, unless a specific one is set
	_modelInfo = new ModelInfo();
	_eventManager = new OnEventManager(); // should be on .h (all that does not depends on THIS)
	_elementManager = new ElementManager(this);
	_componentManager = new ComponentManager(this);
	_simulation = new ModelSimulation(this);
	// 1:1 associations (Traits)
	//Sampler_if* sampler = new Traits<Sampler_if>::Implementation();
	_parser = new Traits<Parser_if>::Implementation(this, new Traits<Sampler_if>::Implementation());
	_modelChecker = new Traits<ModelChecker_if>::Implementation(this);
	_modelPersistence = new Traits<ModelPersistence_if>::Implementation(this);
	// 1:n associations
	_futureEvents = new List<Event*>(); /// The future events list must be chronologicaly sorted
	//_events->setSortFunc(&EventCompare); // It works too
	_futureEvents->setSortFunc([](const Event* a, const Event * b) {
		return a->time() < b->time(); /// Events are sorted chronologically
	});
	// for process analyser
	_responses = new List<SimulationResponse*>();
	_controls = new List<SimulationControl*>();
	// insert controls
	_controls->insert(new SimulationControl("Model Info", "Number of Replications",
			DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::numberOfReplications),
			DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setNumberOfReplications))
			);
	_controls->insert(new SimulationControl("Model Info", "Replication Length",
			DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::replicationLength),
			DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setReplicationLength))
			);
	_controls->insert(new SimulationControl("Model Info", "Warmup Period",
			DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::warmUpPeriod),
			DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setWarmUpPeriod))
			);
}

void Model::sendEntityToComponent(Entity* entity, Connection* connection, double timeDelay) {
	this->sendEntityToComponent(entity, connection->first, timeDelay, connection->second);
}

void Model::sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay, unsigned int componentInputNumber) {
	this->onEvents()->NotifyEntityMoveHandlers(new SimulationEvent(_simulation->currentReplicationNumber(), new Event(_simulation->simulatedTime(), entity, component, componentInputNumber))); //\todo: Event should include information about "from component" and timeDelay, but it doesn't
	if (timeDelay > 0) {
		// schedule to send it
		Event* newEvent = new Event(this->simulation()->simulatedTime() + timeDelay, entity, component, componentInputNumber);
		this->futureEvents()->insert(newEvent);
	} else {
		// send it now
		/*  \todo: -: supposed not to be a queue associated to a component */
		Util::DecIndent();
		ModelComponent::Execute(entity, component, componentInputNumber);
		Util::IncIndent();
	}
}

bool Model::save(std::string filename) {
	bool res = this->_modelPersistence->save(filename);
	if (res) {
		this->_traceManager->trace(Util::TraceLevel::modelResult, "Model successfully saved");
	} else {
		this->_traceManager->trace(Util::TraceLevel::modelResult, "Model could not be saved");

	}
	return res;
}

bool Model::load(std::string filename) {
	this->clear();
	bool res = this->_modelPersistence->load(filename);
	if (res)
		this->_traceManager->trace(Util::TraceLevel::modelResult, "Model successfully loaded");
	else
		this->_traceManager->trace(Util::TraceLevel::modelResult, "Model could not be loaded");
	return res;
}

double Model::parseExpression(const std::string expression) {
	try {
		return _parser->parse(expression);
	} catch (...) {
		return 0.0; // \todo: HOW SAY THERE WAS AN ERROR?
	}
}

bool Model::checkExpression(const std::string expression, const std::string expressionName, std::string* errorMessage) {
	bool result;
	parseExpression(expression, &result, errorMessage);
	if (!result) {
		std::string msg = "Expression \"" + expression + "\" for '" + expressionName + "' is incorrect. ";
		errorMessage->append(msg);
	}
	return result;
}

double Model::parseExpression(const std::string expression, bool* success, std::string* errorMessage) {
	double value = _parser->parse(expression, success, errorMessage);
	return value;
}

void Model::show() {
	tracer()->trace(Util::TraceLevel::report, "Simulation Model:");
	Util::IncIndent();
	{
		tracer()->trace(Util::TraceLevel::report, "Information:");
		Util::IncIndent();
		tracer()->trace(Util::TraceLevel::report, this->infos()->show());
		Util::DecIndent();
		_showComponents();
		_showElements();
		_showSimulationControls();
		_showSimulationResponses();
	}
	Util::DecIndent();
	tracer()->trace(Util::TraceLevel::report, "End of Simulation Model");
}

bool Model::insert(ModelElement* elemOrComp) {
	ModelComponent* comp = dynamic_cast<ModelComponent*> (elemOrComp);
	if (comp == nullptr) // it's a ModelElement
		return this->elements()->insert(elemOrComp);
	else // it's a ModelComponent
		return this->components()->insert(comp);
}

void Model::remove(ModelElement* elemOrComp) {
	ModelComponent* comp = dynamic_cast<ModelComponent*> (elemOrComp);
	if (comp == nullptr) // it's a ModelElement
		this->elements()->remove(elemOrComp);
	else // it's a ModelComponent
		this->components()->remove(comp);
}

void Model::_showElements() const {
	tracer()->trace(Util::TraceLevel::report, "Elements:");
	Util::IncIndent();
	{
		std::string elementType;
		ModelElement* element;
		std::list<std::string>* elementTypes = elements()->elementClassnames();
		for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
			elementType = (*typeIt);
			List<ModelElement*>* em = elements()->elementList(elementType);
			tracer()->trace(Util::TraceLevel::report, elementType + ":");
			Util::IncIndent();
			{
				for (std::list<ModelElement*>::iterator it = em->list()->begin(); it != em->list()->end(); it++) {
					element = (*it);
					tracer()->trace(Util::TraceLevel::report, element->show());
				}
			}
			Util::DecIndent();
		}
	}
	Util::DecIndent();
}

void Model::_showComponents() const {
	tracer()->trace(Util::TraceLevel::report, "Components:");
	Util::IncIndent();
	for (std::list<ModelComponent*>::iterator it = components()->begin(); it != components()->end(); it++) {
		tracer()->trace(Util::TraceLevel::report, (*it)->show()); ////
	}
	Util::DecIndent();
}

void Model::_showSimulationControls() const {
	tracer()->trace(Util::TraceLevel::report, "Simulation Controls:");
	Util::IncIndent();
	for (std::list<SimulationControl*>::iterator it = _controls->list()->begin(); it != _controls->list()->end(); it++) {
		tracer()->trace(Util::TraceLevel::report, (*it)->show()); ////
	}
	Util::DecIndent();
}

void Model::_showSimulationResponses() const {
	tracer()->trace(Util::TraceLevel::report, "Simulation Responses:");
	Util::IncIndent();
	for (std::list<SimulationResponse*>::iterator it = _responses->list()->begin(); it != _responses->list()->end(); it++) {
		tracer()->trace(Util::TraceLevel::report, (*it)->show()); ////
	}
	Util::DecIndent();
}

void Model::clear() {
	this->_componentManager->clear();
	this->_elementManager->clear();
	//Util::ResetAllIds(); // \todo: To implement
}

void Model::_createModelInternalElements() {
	tracer()->trace(Util::TraceLevel::modelInternal, "Creating internal elements");
	Util::IncIndent();

	for (std::list<ModelComponent*>::iterator it = _componentManager->begin(); it != _componentManager->end(); it++) {
		tracer()->trace(Util::TraceLevel::modelInternal, "Internals for " + (*it)->classname() + " \"" + (*it)->name() + "\"");
		ModelComponent::CreateInternalElements((*it));
	}

	std::list<ModelElement*>* modelElements;
	unsigned int originalSize = elements()->elementClassnames()->size(), pos = 1;
	//for (std::list<std::string>::iterator itty = elements()->elementClassnames()->begin(); itty != elements()->elementClassnames()->end(); itty++) {
	std::list<std::string>::iterator itty = elements()->elementClassnames()->begin();
	while (itty != elements()->elementClassnames()->end() && pos <= originalSize) {
		//try {
		modelElements = elements()->elementList((*itty))->list();
		//} catch (const std::exception& e) {
		// \todo Is there a better solution to iterate over a changing sorted list??
		// ops. Sorted list has changed and iteration fails. Starts iterating again
		//	itty = elements()->elementClassnames()->begin();
		//	modelElements = elements()->elementList((*itty))->list();
		//	tracer()->trace(Util::TraceLevel::modelInternal, "Creating internal elements");
		//}
		for (std::list<ModelElement*>::iterator itel = modelElements->begin(); itel != modelElements->end(); itel++) {
			tracer()->trace(Util::TraceLevel::modelInternal, "Internals for " + (*itel)->classname() + " \"" + (*itel)->name() + "\""); // (" + std::to_string(pos) + "/" + std::to_string(originalSize) + ")");
			ModelElement::CreateInternalElements((*itel));
		}
		if (originalSize == elements()->elementClassnames()->size()) {
			itty++;
			pos++;
		} else {
			originalSize = elements()->elementClassnames()->size();
			itty = elements()->elementClassnames()->begin();
			pos = 1;
			tracer()->trace(Util::TraceLevel::modelInternal, "Restarting to create internal elements (due to previous creations)");
		}
	}
	Util::DecIndent();
}

bool Model::check() {
	tracer()->trace(Util::TraceLevel::modelInternal, "Checking model consistency");
	Util::IncIndent();
	// before checking the model, creates all necessary internal ModelElements
	_createModelInternalElements();
	bool res = this->_modelChecker->checkAll();
	Util::DecIndent();
	if (res) {
		tracer()->trace(Util::TraceLevel::modelResult, "End of Model checking: Success");
	} else {
		//std::exception e = new std::exception();
		//getTrace()->traceError() ;
		tracer()->trace(Util::TraceLevel::modelResult, "End of Model checking: Failed");
	}
	return res;
}

//bool Model::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
//    return this->_modelChecker->verifySymbol(componentName, expressionName, expression, expressionResult, mandatory);
//}

void Model::removeEntity(Entity* entity, bool collectStatistics) {
	/*  \todo: -: event onEntityRemove */
	/*  \todo: -: collectStatistics */
	std::string entId = std::to_string(entity->entityNumber());
	this->elements()->remove(Util::TypeOf<Entity>(), entity);
	tracer()->trace("Entity " + entId + " was removed from the system");
}

List<Event*>* Model::futureEvents() const {
	return _futureEvents;
}

void Model::setTracer(TraceManager * _traceManager) {
	this->_traceManager = _traceManager;
}

TraceManager * Model::tracer() const {
	return _traceManager;
}

bool Model::hasChanged() const {
	bool changed = _hasChanged;
	changed &= this->_componentManager->hasChanged();
	changed &= this->_elementManager->hasChanged();
	changed &= this->_modelInfo->hasChanged();
	changed &= this->_modelPersistence->hasChanged();
	return changed;
}

ComponentManager * Model::components() const {
	return _componentManager;
}

List<SimulationControl*>* Model::controls() const {
	return _controls;
}

List<SimulationResponse*>* Model::responses() const {
	return _responses;
}

OnEventManager * Model::onEvents() const {
	return _eventManager;
}

ElementManager * Model::elements() const {
	return _elementManager;
}

ModelInfo * Model::infos() const {
	return _modelInfo;
}

Simulator * Model::parentSimulator() const {
	return _parentSimulator;
}

ModelSimulation * Model::simulation() const {
	return _simulation;
}

Util::identification Model::id() const {
	return _id;
}

