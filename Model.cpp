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

Model::Model(Simulator* simulator) {
	_simulator = simulator;
	_name = "Model " + std::to_string(Util::GenerateNewIdOfType<Model>()); // (reinterpret_cast<unsigned long> (this));
	// 1:1
	_parser = new Traits<Parser_if>::Implementation(this);
	_modelChecker = new Traits<ModelChecker_if>::Implementation(this);
	_modelPersistence = new Traits<ModelPersistence_if>::Implementation(this);
	// 1:n attributes
	_components = new List<ModelComponent*>();
	_components->setSortFunc([](const ModelComponent* a, const ModelComponent * b) {
		return a->getId() < b->getId(); /// Components are sorted by ID
	});
	_events = new List<Event*>(); /// The future events list must be chronologicaly sorted
	//_events->setSortFunc(&EventCompare); // It works too
	_events->setSortFunc([](const Event* a, const Event * b) {
		return a->getTime() < b->getTime(); /// Events are sorted chronologically
	});

	_infrastructures = new std::map<std::string, List<ModelInfrastructure*>*>(); /// Infrastructures are organized as a map from a string (key), the type of an infrastructure, and a list of infrastructures of that type 
	/* TODO: -- Sort methods for infrastructures should be a decorator */
	/*
	_infrastructures = new List<ModelInfrastructure*>();
	_infrastructures->setSortFunc([](const ModelInfrastructure* a, const ModelInfrastructure * b) {
		return a->getId() < b->getId();
	});
	_entities = new List<Entity*>();
	_entities->setSortFunc([](const Entity* a, const Entity * b) {
		return a->getId() < b->getId();
	});
	 */
}

Model::Model(const Model& orig) {
}

void Model::sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay) {
	//_currentEntity = entity;
	//_currentComponent = component;
	/* TODO -: event onEntityMove */
	if (timeDelay > 0) {
		// schedule to send it
		Event* newEvent = new Event(_simulatedTime + timeDelay, entity, component);
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

bool Model::_finishReplicationCondition() {
	return this->_events->size() == 0
			|| _simulatedTime > _replicationLength
			|| this->parseExpression(this->_terminatingCondition);
}

/*!
 * Checks the model and if ok then initialize the simulation, execute repeatedly each replication and then show simulation statistics
 */
void Model::startSimulation() {
	if (!this->checkModel()) {
		trace(Util::TraceLevel::TL_errors, "Model check failed. Cannot start simulation.");
		return;
	}
	_initSimulation();
	/* TODO -: event onBeginSimulation */

	for (_currentReplicationNumber = 1; _currentReplicationNumber <= _numberOfReplications; _currentReplicationNumber++) {
		_initReplication();
		/* TODO -: event onBeginReplication */

		while (!_finishReplicationCondition()) {
			_stepSimulation();
			if (_pauseOnEvent) {
				std::cout << "[paused] ...press any key to continue...";
				std::cin.get();
				std::cout << std::endl;
			}
		}

		/* TODO -: event onEndReplication */

		std::string causeTerminated;
		if (_events->empty()) {
			causeTerminated = "event queue is empty";
		} else if (_stopRequested) {
			causeTerminated = "user requested to stop";
		} else if (!(this->_simulatedTime < this->getReplicationLength())) {
			causeTerminated = "replication length " + std::to_string(_replicationLength) + " was achieved";
		} else if (_parser->parse(this->getTerminatingCondition())) {
			causeTerminated = "termination condition was achieved";
		} else causeTerminated = "unknown";
		std::cout << "Replication " << _currentReplicationNumber << " of " << _numberOfReplications << " has finished at time " << _simulatedTime << " because " << causeTerminated << ".\n";
		_showReplicationStatistics();
	}
	_showSimulationStatistics();

	std::cout << "Simulation has finished.\n";
	/* TODO -: event onEndSimulation */

}

void Model::showReports() {
	/*TODO +-: not implemented. NEEDED? Probably not. It is included in showReplicationStatistics() and _showSimulationStatistics(). */
}

/*!
 * Initialize once for all replications
 */
void Model::_initSimulation() {
	trace(Util::TL_simulation, "\nSimulation of model \"" + _name + "\" is starting.\n");
	/*TODO +-: not implemented*/
}

/*!
 Clear the event list, restarts simulated time, initialize event list and statistics
 */
void Model::_initReplication() {
	traceReport(Util::TL_simulation, "-----------------------------------------------------");
	traceReport(Util::TL_simulation, _simulator->getName());
	traceReport(Util::TL_simulation, _simulator->getLicense());
	traceReport(Util::TL_simulation, "Projet Title: " + this->_projectTitle);
	traceReport(Util::TL_simulation, "Analysit Name: " + this->_analystName);
	traceReport(Util::TL_simulation, "");
	traceReport(Util::TL_simulation, "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_numberOfReplications) + " is starting.\n");

	_events->clear();
	_simulatedTime = 0.0;
	_pauseRequested = false;

	// insert first creation events
	SourceModelComponent *source;
	Entity *newEntity;
	Event *newEvent;
	double creationTime;
	//for(ModelComponent* comp=_components->first(); comp!=_components->last(); _components->next()) {
	std::list<ModelComponent*>* list = _components->getList();
	for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
		source = dynamic_cast<SourceModelComponent*> (*it);
		if (source != nullptr) {
			creationTime = source->getFirstCreation();
			/* TODO +-: amount of entities to create, max number of creations */
			newEntity = new Entity();
			newEvent = new Event(creationTime, newEntity, (*it));
			_events->insert(newEvent);
		}
	}

	if (this->_initializeStatisticsBetweenReplications) {
		StatisticsCollector* cstat;
		List<ModelInfrastructure*>* list = getInfrastructures(Util::TypeOf<StatisticsCollector>());
		for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
			cstat = (StatisticsCollector*)(*it);
			cstat->getCollector()->clear();
		}
	}
}

void Model::_stepSimulation() {
	// process one single event
	trace(Util::TraceLevel::TL_simulation, ""); // just a new line?
	//trace(Util::TraceLevel::TL_mostDetailed, "\ntime=" + std::to_string(this->_simulatedTime) + ",events=" + _events->show()); // + ",entities=" + _entities->show());
	/* TODO -: event onSimulationStep */

	Event* nextEvent;
	nextEvent = _events->first();
	_events->pop_front();
	if (nextEvent->getTime() <= this->_replicationLength) {
		_processEvent(nextEvent);
	} else {
		this->_simulatedTime = nextEvent->getTime();
	}
}

void Model::_processEvent(Event* event) {
	this->trace(Util::TraceLevel::TL_simulation, "Processing event=(" + event->show() + ")");
	this->_currentEntity = event->getEntity();
	this->_currentComponent = event->getComponent();
	_simulatedTime = event->getTime();
	try {
		event->getComponent()->Execute(event->getEntity(), event->getComponent()); // Execute is static
	} catch (std::exception *e) {
		_excepcionHandled = e;
		this->traceError(*e, "Error on processing event (" + event->show() + ")");
	}
}

void Model::_showModel() {
	trace(Util::TraceLevel::TL_mostDetailed, "Simulation Model:");
	std::list<ModelComponent*>* list = getComponents()->getList();
	for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
		trace(Util::TraceLevel::TL_mostDetailed, "   " + (*it)->show()); ////
	}
}

void Model::_showInfrastructures() {
	trace(Util::TraceLevel::TL_mostDetailed, "Model Infrastructures:");
	//std::map<std::string, List<ModelInfrastructure*>*>* _infrastructures;
	std::string key;
	List<ModelInfrastructure*>* list;
	for (std::map<std::string, List<ModelInfrastructure*>*>::iterator infraIt = _infrastructures->begin(); infraIt != _infrastructures->end(); infraIt++) {
		key = (*infraIt).first;
		trace(Util::TraceLevel::TL_mostDetailed, "   " + key + ":");
		list = (*infraIt).second;
		for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
			trace(Util::TraceLevel::TL_mostDetailed, "      " + (*it)->show());
		}
	}
}

void Model::_showReplicationStatistics() {
	traceReport(Util::TraceLevel::TL_report, "\nReport for replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_numberOfReplications));

	/*TODO: + To implement */

	// show statistics
	traceReport(Util::TraceLevel::TL_report, "Statistics:");
	StatisticsCollector* cstat;
	List<ModelInfrastructure*>* list = getInfrastructures(Util::TypeOf<StatisticsCollector>());
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		cstat = (StatisticsCollector*)(*it);
		std::string message = cstat->getName()+"\t N="+ std::to_string(cstat->numElements())+", avg="+ std::to_string(cstat->average())+", stddev="+ std::to_string(cstat->stddeviation())+", varCoef="+ std::to_string(cstat->variationCoef())+", min="+ std::to_string(cstat->min())+", max="+ std::to_string(cstat->max())+", e0_95%="+ std::to_string(cstat->halfWidthConfidenceInterval(0.95));
		traceReport(Util::TraceLevel::TL_report, "     "+message);
	}

}

void Model::_showSimulationStatistics() {
	traceReport(Util::TraceLevel::TL_report, "\nReport for simulation\n");
	/* TODO */
}

bool Model::checkModel() {
	trace(Util::TraceLevel::TL_blockInternal, "Checking model consistency");
	bool res = this->_modelChecker->checkAll();
	/* todo: remove show model and infra from here*/
	this->_showModel();
	this->_showInfrastructures();
	//
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
	trace(Util::TraceLevel::TL_blockInternal, "Entity " + std::to_string(entity->getId()) + " was removed from the system");
	//_entities->remove(entity);
	entity->~Entity();
}

void Model::pauseSimulation() {
}

void Model::stepSimulation() {
	if (_simulationIsInitiated && _replicationIsInitiaded) {
		if (!_finishReplicationCondition()) {
			try {
				this->_stepSimulation();
			} catch (std::exception *e) {
				_excepcionHandled = e;
				this->traceError((*e), "Error on simulation step");
			}

		}
	}

}

void Model::stopSimulation() {
}

void Model::restartSimulation() {
}

void Model::setPauseOnEvent(bool _pauseOnEvent) {
	this->_pauseOnEvent = _pauseOnEvent;
}

bool Model::isPauseOnEvent() const {
	return _pauseOnEvent;
}

void Model::setInitializeStatistics(bool _initializeStatistics) {
	this->_initializeStatisticsBetweenReplications = _initializeStatistics;
}

bool Model::isInitializeStatistics() const {
	return _initializeStatisticsBetweenReplications;
}

void Model::setInitializeSystem(bool _initializeSystem) {
	this->_initializeSystem = _initializeSystem;
}

bool Model::isInitializeSystem() const {
	return _initializeSystem;
}

Model::~Model() {
}

void Model::setName(std::string _name) {
	this->_name = _name;
}

std::string Model::getName() const {
	return _name;
}

void Model::setAnalystName(std::string _analystName) {
	this->_analystName = _analystName;
}

std::string Model::getAnalystName() const {
	return _analystName;
}

void Model::setDescription(std::string _description) {
	this->_description = _description;
}

std::string Model::getDescription() const {
	return _description;
}

void Model::setProjectTitle(std::string _projectTitle) {
	this->_projectTitle = _projectTitle;
}

std::string Model::getProjectTitle() const {
	return _projectTitle;
}

void Model::setVersion(std::string _version) {
	this->_version = _version;
}

std::string Model::getVersion() const {
	return _version;
}

void Model::setNumberOfReplications(unsigned int _numberOfReplications) {
	this->_numberOfReplications = _numberOfReplications;
}

unsigned int Model::getNumberOfReplications() const {
	return _numberOfReplications;
}

void Model::setReplicationLength(double _replicationLength) {
	this->_replicationLength = _replicationLength;
}

double Model::getReplicationLength() const {
	return _replicationLength;
}

void Model::setReplicationLengthTimeUnit(Util::TimeUnit _replicationLengthTimeUnit) {
	this->_replicationLengthTimeUnit = _replicationLengthTimeUnit;
}

Util::TimeUnit Model::getReplicationLengthTimeUnit() const {
	return _replicationLengthTimeUnit;
}

void Model::setWarmUpPeriod(double _warmUpPeriod) {
	this->_warmUpPeriod = _warmUpPeriod;
}

double Model::getWarmUpPeriod() const {
	return _warmUpPeriod;
}

void Model::setWarmUpPeriodTimeUnit(Util::TimeUnit _warmUpPeriodTimeUnit) {
	this->_warmUpPeriodTimeUnit = _warmUpPeriodTimeUnit;
}

Util::TimeUnit Model::getWarmUpPeriodTimeUnit() const {
	return _warmUpPeriodTimeUnit;
}

void Model::setTerminatingCondition(std::string _terminatingCondition) {
	this->_terminatingCondition = _terminatingCondition;
}

std::string Model::getTerminatingCondition() const {
	return _terminatingCondition;
}

void Model::setTraceLevel(Util::TraceLevel _traceLevel) {
	this->_traceLevel = _traceLevel;
}

Util::TraceLevel Model::getTraceLevel() const {
	return _traceLevel;
}

/*
 void Model::traceSimulation(Util::TraceLevel tracelevel, std::string text) {
	if (this->_traceLevel >= tracelevel) {
		TraceSimulationEvent e = TraceEvent(tracelevel, text);
		for (std::list<traceSimulationListener>::iterator it = this->_traceSimulationListeners->begin(); it != _traceSimulationListeners->end(); it++) {
			(*it)(e);
		}
	}
}
 */

void Model::addTraceListener(traceListener traceListener) {
	this->_traceListeners->insert(_traceListeners->end(), traceListener);
}

//void Model::addTraceSimulationListener(traceListener traceListener) {
//	this->_traceSimulationListeners->insert(_traceSimulationListeners->end(), traceListener);
//}

void Model::addTraceSimulationListener(traceSimulationListener traceSimulationListener) {
	this->_traceSimulationListeners->insert(_traceSimulationListeners->end(), traceSimulationListener);
}

void Model::addTraceErrorListener(traceErrorListener traceErrorListener) {
	this->_traceErrorListeners->insert(_traceErrorListeners->end(), traceErrorListener);
}

void Model::addTraceReportListener(traceListener traceReportListener) {
	this->_traceReportListeners->insert(_traceReportListeners->end(), traceReportListener);
}

void Model::trace(Util::TraceLevel tracelevel, std::string text) {
	if (this->_traceLevel >= tracelevel) {
		TraceEvent e = TraceEvent(tracelevel, text);
		/* TODO--: somewhere in future it should be interesting to use "auto" and c++17 at least */
		for (std::list<traceListener>::iterator it = this->_traceListeners->begin(); it != _traceListeners->end(); it++) {
			(*it)(e);
		}
	}
}

void Model::traceError(std::exception e, std::string text) {
	TraceErrorEvent exceptEvent = TraceErrorEvent(text, e);
	/* TODO--: somewhere in future it should be interesting to use "auto" and c++17 at least */
	for (std::list<traceErrorListener>::iterator it = this->_traceErrorListeners->begin(); it != _traceErrorListeners->end(); it++) {
		(*it)(exceptEvent);
	}
}

void Model::traceSimulation(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text) {
	if (this->_traceLevel >= tracelevel) {
		TraceSimulationEvent e = TraceSimulationEvent(tracelevel, time, entity, component, text);
		for (std::list<traceSimulationListener>::iterator it = this->_traceSimulationListeners->begin(); it != _traceSimulationListeners->end(); it++) {
			(*it)(e);
		}
	}
}

void Model::traceReport(Util::TraceLevel tracelevel, std::string text) {
	if (this->_traceLevel >= tracelevel) {
		TraceEvent e = TraceEvent(tracelevel, text);
		for (std::list<traceListener>::iterator it = this->_traceReportListeners->begin(); it != _traceReportListeners->end(); it++) {
			(*it)(e);
		}
	}
}

List<std::string>* Model::getErrorMessages() const {
	return _errorMessages;
}

List<Event*>* Model::getEvents() const {
	return _events;
}

List<ModelInfrastructure*>* Model::getInfrastructures(std::string infraTypename) const {
	std::map<std::string, List<ModelInfrastructure*>*>::iterator it = this->_infrastructures->find(infraTypename);
	if (it == this->_infrastructures->end()) {
		// list does not exists yet. Create it and set a valid iterator
		List<ModelInfrastructure*>* newList = new List<ModelInfrastructure*>();
		newList->setSortFunc([](const ModelInfrastructure* a, const ModelInfrastructure * b) {
			return a->getId() < b->getId();
		});
		_infrastructures->insert(std::pair<std::string, List<ModelInfrastructure*>*>(infraTypename, newList));
		it = this->_infrastructures->find(infraTypename);
	}
	List<ModelInfrastructure*>* infras = it->second;
	return infras;
}

ModelInfrastructure* Model::getInfrastructure(std::string infraTypename, Util::identitifcation id) {
	List<ModelInfrastructure*>* list = getInfrastructures(infraTypename);
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		if ((*it)->getId() == id) { // found
			return (*it);
		}
	}
	return nullptr;
}

std::list<std::string>* Model::getInfrastructureTypenames() const {
	std::list<std::string>* keys = new std::list<std::string>();
	for (std::map<std::string, List<ModelInfrastructure*>*>::iterator it = _infrastructures->begin(); it != _infrastructures->end(); it++) {
		keys->insert(keys->end(), (*it).first);
	}
	return keys;
}

ModelInfrastructure* Model::getInfrastructure(std::string infraTypename, std::string name) {
	List<ModelInfrastructure*>* list = getInfrastructures(infraTypename);
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		if ((*it)->getName() == name) { // found
			return (*it);
		}
	}
	return nullptr;
}

List<Entity*>* Model::getEntities() const {
	List<Entity*>* ents = (List<Entity*>*)(getInfrastructures(Util::TypeOf<Entity>())); // static_cast ??
	return ents;
}

void Model::setStepByStep(bool _stepByStep) {
	this->_stepByStep = _stepByStep;
}

bool Model::isStepByStep() const {
	return _stepByStep;
}

void Model::setPauseOnReplication(bool _pauseOnReplication) {
	this->_pauseOnReplication = _pauseOnReplication;
}

bool Model::isPauseOnReplication() const {
	return _pauseOnReplication;
}

double Model::getSimulatedTime() const {
	return _simulatedTime;
}

bool Model::isRunning() const {
	return _running;
}

bool Model::isSaved() const {
	return _saved;
}

Util::identitifcation Model::getId() const {
	return _id;
}

List<ModelComponent*>* Model::getComponents() const {
	return _components;
}


