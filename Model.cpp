/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationModel.cpp
 * Author: cancian
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
//#include "ParserMyImpl1.h" // avoid link error
#include "StatisticsCollector.h"

bool EventCompare(const Event* a, const Event * b) {
	return a->getTime() < b->getTime();
}

double getReplicationLengthNotMemberFunction() { // REMOVE IT. JUST AN EXAMPLE FOR PAN TEAM DS3 THEME (1)
	return 10;
}

void setReplicationLengthNotMemberFunction(double value) { // REMOVE IT. JUST AN EXAMPLE FOR PAN TEAM DS3 THEME (1)

}

Model::Model(Simulator* simulator) {
	_simulator = simulator; // a simulator is the "parent" of a model 
	// 1:1 associations (no Traits)
	_infos = new ModelInfo();
	_eventHandler = new OnEventManager(); // should be on .h (all that does not depends on THIS)
	_infrastructureManager = new InfrastructureManager(this); 
	_trace = new TraceManager(this);
	// 1:1 associations (Traits)
	_parser = new Traits<Parser_if>::Implementation(this);
	_modelChecker = new Traits<ModelChecker_if>::Implementation(this);
	_modelPersistence = new Traits<ModelPersistence_if>::Implementation(this);
	// 1:n associations
	_components = new List<ModelComponent*>();
	_components->setSortFunc([](const ModelComponent* a, const ModelComponent * b) {
		return a->getId() < b->getId(); /// Components are sorted by ID
	});
	_events = new List<Event*>(); /// The future events list must be chronologicaly sorted
	//_events->setSortFunc(&EventCompare); // It works too
	_events->setSortFunc([](const Event* a, const Event * b) {
		return a->getTime() < b->getTime(); /// Events are sorted chronologically
	});

	
	// PAN
	_responses = new List<SimulationResponse*>();
	_controls = new List<SimulationControl*>();
	// DS1 Theme (1)
	// Model includes its own simulation controls
	// SimulationControl* control = new SimulationResponse(Util::TypeOf<Model>(), "Number of Replications", &getNumberOfReplicationsNotMemberFunction, &setNumberOfReplicationsNotMemberFunction);
	//_controls->insert(control);

}

Model::Model(const Model& orig) {
}


Model::~Model() {
}

void Model::sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay) {
	//_currentEntity = entity;
	//_currentComponent = component;
	/* TODO -: event onEntityMove */
	if (timeDelay > 0) {
		// schedule to send it
		Event* newEvent = new Event(this->getSimulation()->getSimulatedTime() + timeDelay, entity, component);
		this->getEvents()->insert(newEvent);
	} else {
		// send it now
		/* TODO -: supposed not to be a queue associated to a component */
		component->Execute(entity, component);
	}
}

bool Model::saveModel(std::string filename) {
	return this->_modelPersistence->save(filename);
}

bool Model::loadModel(std::string filename) {
	return this->_modelPersistence->load(filename);
}

double Model::parseExpression(const std::string expression) {
	/* TODO +++: not implemented. A whole parser is necessary */
	return _parser->parse(expression);
}

double Model::parseExpression(const std::string expression, bool* success, std::string* errorMessage) {
	return _parser->parse(expression, success, errorMessage);
}



void Model::_showComponents() {
	getTracer()->trace(Util::TraceLevel::mostDetailed, "Simulation Model:");
	std::list<ModelComponent*>* list = getComponents()->getList();
	for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
		getTracer()->trace(Util::TraceLevel::mostDetailed, "   " + (*it)->show()); ////
	}
}



bool Model::checkModel() {
	getTracer()->trace(Util::TraceLevel::blockInternal, "Checking model consistency");
	bool res = this->_modelChecker->checkAll();
	if (res) {
		getTracer()->trace(Util::TraceLevel::blockInternal, "Model check passed");
	} else {
		//std::exception e = new std::exception();
		//getTrace()->traceError() ;
		getTracer()->trace(Util::TraceLevel::errors, "Model check has failed");
	}
	return res;
}

bool Model::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
	return this->_modelChecker->verifySymbol(componentName, expressionName, expression, expressionResult, mandatory);
}

void Model::removeEntity(Entity* entity, bool collectStatistics) {
	/* TODO: Collect statistics */
	/* TODO -: event onEntityRemove */
	// destroy 
	this->getEntities()->remove(entity);
	getTracer()->trace(Util::TraceLevel::blockInternal, "Entity " + std::to_string(entity->getId()) + " was removed from the system");
	//_entities->remove(entity);
	entity->~Entity();
}




List<Event*>* Model::getEvents() const {
	return _events;
}


List<SimulationControl*>* Model::getControls() const {
	return _controls;
}

List<SimulationResponse*>* Model::getResponses() const {
	return _responses;
}

TraceManager* Model::getTracer() const {
	return _trace;
}

OnEventManager* Model::getOnEventManager() const {
	return _eventHandler;
}

InfrastructureManager* Model::getInfraManager() const {
	return _infrastructureManager;
}

ModelInfo* Model::getInfos() const {
	return _infos;
}

Simulator* Model::getParent() const {
	return _simulator;
}

ModelSimulation* Model::getSimulation() const {
	return _simulation;
}



List<Entity*>* Model::getEntities() const {
	List<Entity*>* ents = (List<Entity*>*)(getInfraManager()->getInfrastructures(Util::TypeOf<Entity>())); // static_cast ??
	return ents;
}


Util::identitifcation Model::getId() const {
	return _id;
}

List<ModelComponent*>* Model::getComponents() const {
	return _components;
}


