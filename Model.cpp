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

bool EventCompare(const Event* a, const Event * b) {
    return a->getTime() < b->getTime();
}

double getReplicationLengthNotMemberFunction() { // REMOVE IT. JUST AN EXAMPLE FOR PAN TEAM DS3 THEME (1)
    return 10;
}

void setReplicationLengthNotMemberFunction(double value) { // REMOVE IT. JUST AN EXAMPLE FOR PAN TEAM DS3 THEME (1)

}

Model::Model(Simulator* simulator) {
    _parentSimulator = simulator; // a simulator is the "parent" of a model 
    // 1:1 associations (no Traits)
    _modelInfo = new ModelInfo();
    _eventHandler = new OnEventManager(); // should be on .h (all that does not depends on THIS)
    _elementManager = new ElementManager(this);
    _componentManager = new ComponentManager(this);
    _tracer = new TraceManager(this);
    // 1:1 associations (Traits)
    _parser = new Traits<Parser_if>::Implementation(this);
    _modelChecker = new Traits<ModelChecker_if>::Implementation(this);
    _modelPersistence = new Traits<ModelPersistence_if>::Implementation(this);
    _simulation = new ModelSimulation(this);
    // 1:n associations

    _events = new List<Event*>(); /// The future events list must be chronologicaly sorted
    //_events->setSortFunc(&EventCompare); // It works too
    _events->setSortFunc([](const Event* a, const Event * b) {
	return a->getTime() < b->getTime(); /// Events are sorted chronologically
    });

    // for process analyser
    _responses = new List<SimulationResponse*>();
    _controls = new List<SimulationControl*>();
    // insert controls
    _controls->insert(new SimulationControl("Model Info", "Number of Replications",
	    DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::getNumberOfReplications),
	    DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setNumberOfReplications))
	    );
    _controls->insert(new SimulationControl("Model Info", "Replication Length",
	    DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::getReplicationLength),
	    DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setReplicationLength))
	    );
    _controls->insert(new SimulationControl("Model Info", "Warmup Period",
	    DefineGetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::getWarmUpPeriod),
	    DefineSetterMember<ModelInfo>(this->_modelInfo, &ModelInfo::setWarmUpPeriod))
	    );
}

Model::Model(const Model& orig) {
}

Model::~Model() {
}

void Model::sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay) {
    /* TODO -: event onEntityMove */
    if (timeDelay > 0) {
	// schedule to send it
	Event* newEvent = new Event(this->getSimulation()->getSimulatedTime() + timeDelay, entity, component);
	this->getEvents()->insert(newEvent);
    } else {
	// send it now
	/* TODO -: supposed not to be a queue associated to a component */
	Util::DecIndent();
	component->Execute(entity, component);
	Util::IncIndent();
    }
}

bool Model::saveModel(std::string filename) {
    return this->_modelPersistence->save(filename);
}

bool Model::loadModel(std::string filename) {
    return this->_modelPersistence->load(filename);
}

double Model::parseExpression(const std::string expression) {
    return _parser->parse(expression);
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
    return _parser->parse(expression, success, errorMessage);
}

void Model::_showComponents() {
    getTracer()->trace(Util::TraceLevel::mostDetailed, "Simulation Model:");
    //std::list<ModelComponent*>* list = getComponents()->getList();
    Util::IncIndent();
    for (std::list<ModelComponent*>::iterator it = getComponentManager()->begin(); it != getComponentManager()->end(); it++) {
	getTracer()->trace(Util::TraceLevel::mostDetailed, (*it)->show()); ////
    }
    Util::DecIndent();
}

bool Model::checkModel() {
    getTracer()->trace(Util::TraceLevel::blockInternal, "Checking model consistency");
    Util::IncIndent();
    bool res = this->_modelChecker->checkAll();
    Util::DecIndent();
    if (res) {
	getTracer()->trace(Util::TraceLevel::blockInternal, "Model check passed");
    } else {
	//std::exception e = new std::exception();
	//getTrace()->traceError() ;
	getTracer()->trace(Util::TraceLevel::errors, "Model check has failed");
    }
    return res;
}

//bool Model::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
//    return this->_modelChecker->verifySymbol(componentName, expressionName, expression, expressionResult, mandatory);
//}

void Model::removeEntity(Entity* entity, bool collectStatistics) {
    if (collectStatistics) {
	double timeInSystem = this->getSimulation()->getSimulatedTime() - entity->getAttributeValue("Entity.ArrivalTime");
	entity->getEntityType()->getCstatTotalTime()->getStatistics()->getCollector()->addValue(timeInSystem);
    }
    /* TODO -: event onEntityRemove */
    std::string entId = std::to_string(entity->getId());
    this->getElementManager()->remove(Util::TypeOf<Entity>(), entity);
    getTracer()->trace(Util::TraceLevel::blockInternal, "Entity " + entId + " was removed from the system");
}

List<Event*>* Model::getEvents() const {
    return _events;
}

ComponentManager* Model::getComponentManager() const {
    return _componentManager;
}

List<SimulationControl*>* Model::getControls() const {
    return _controls;
}

List<SimulationResponse*>* Model::getResponses() const {
    return _responses;
}

TraceManager* Model::getTracer() const {
    return _tracer;
}

OnEventManager* Model::getOnEventManager() const {
    return _eventHandler;
}

ElementManager* Model::getElementManager() const {
    return _elementManager;
}

ModelInfo* Model::getInfos() const {
    return _modelInfo;
}

Simulator* Model::getParent() const {
    return _parentSimulator;
}

ModelSimulation* Model::getSimulation() const {
    return _simulation;
}



//List<Entity*>* Model::getEntities() const {
//	List<Entity*>* ents = (List<Entity*>*)(getElementManager()->getElements(Util::TypeOf<Entity>())); // static_cast ??
//	return ents;
//}

Util::identitifcation Model::getId() const {
    return _id;
}

//List<ModelComponent*>* Model::getComponents() const {
//    return _components;
//}


