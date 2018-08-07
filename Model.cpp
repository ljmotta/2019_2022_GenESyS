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
#include "Model.h"
#include "List.cpp"
#include "SourceModelComponent.h" // avoid link error
#include <iostream>
#include <algorithm>

Model::Model(Simulator* simulator) {
	_simulator = simulator;
	_components = new List<ModelComponent*>();
	_infrastructures = new List<ModelInfrastructure*>();
	_events = new List<Event*>();
	_events->sort([](const Event* a, const Event * b) {
		return a->getTime() < b->getTime();
	});
	_name = "Model " + std::to_string(reinterpret_cast<unsigned long> (this));
}

Model::Model(const Model& orig) {
}

double Model::_parseExpression(std::string expression) {
	/* TODO +++: not implemented. A whole parser is necessary */
	double value = std::atof(expression.c_str());
	return value;
}

bool Model::_finishReplicationCondition() {
	/* TODO +-: Should consider TimUnits */
	return this->_events->size() == 0
			|| _simulationTime > _replicationLenght
			|| this->_parseExpression(this->_terminatingCondition);

}

void Model::startSimulation() {
	_initSimulation();
	for (unsigned int replicationNum = 1; replicationNum <= _numberOfReplications; replicationNum++) {
		_initReplication(replicationNum);
		while (!_finishReplicationCondition()) {
			_stepSimulation();
			if (_pauseOnEvent) {
				std::cout << "[paused] ...press any key to continue...";
				std::cin.get();
				std::cout << std::endl;
			}
		}

		std::string causeTerminated;
		//		if (_events->empty()) {
		//			causeTerminated = "event queue is empty";
		//		} else if (_stopRequested) {
		//			causeTerminated = "user requested to stop";
		//		} else if (!(_tnow < _actualModel->getReplicationLength())) {
		//			causeTerminated = "replication length was achieved";
		//		} else if (_parser->parse(_actualModel->getTerminatingCondition())) {
		//			causeTerminated = "termination condition was achieved";
		//		} else causeTerminated = "unknown";
		std::cout << "Replication " << replicationNum << " of " << _numberOfReplications << " has finished at time " << _simulationTime << " because " << causeTerminated << ".\n";
		_showReplicationStatistics();
	}
	std::cout << "Simulation has finished.\n";
	_showSimulationStatistics();

}

void Model::_initSimulation() {
	trace(Util::TL_simulation, "Simulation of model\"" + _name + "\" is starting.\n");
	/*TODO +-: not implemented*/
}

void Model::_initReplication(unsigned int currentReplicationNumber) {
	trace(Util::TL_simulation, "Replication " + std::to_string(currentReplicationNumber) + " of " + std::to_string(_numberOfReplications) + " is starting.\n");

	_events->clear();
	_simulationTime = 0.0;
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
			this->trace(Util::TraceLevel::TL_mostDetailed, "Future events list: "+_events->show());
		}
	}

	if (this->_initializeStatisticsBetweenReplications) {
		/* TODO +: not implemented */
	}

}

void Model::_stepSimulation() {
	// process one single event
	Event* nextEvent;
	nextEvent = _events->first();
	_events->pop_front();
	if (nextEvent->getTime() <= this->_replicationLenght) { /* TODO +-: should consider time Units */
		_processEvent(nextEvent);
	} else {
		this->_simulationTime = nextEvent->getTime();
	}
}

void Model::_processEvent(Event* event) {
	this->trace(Util::TraceLevel::TL_simulation, "Processing event "+event->show());
	_entities->setCurrent(event->getEntity());
	_components->setCurrent(event->getComponent());
	_simulationTime=event->getTime();
	try {
	event->getComponent()->execute(event->getEntity(), event->getComponent()); // Execute is static
	} catch (std::exception *e) {
		_excepcionHandled = e;
		this->traceError(*e, "Error on processing event "+event->show());
	}
}

void Model::_showReplicationStatistics() {
}

void Model::_showSimulationStatistics() {
}

void Model::pauseSimulation() {
}

void Model::stepSimulation() {
	if (!_simulationIsInitiated) {
		this->_initSimulation();
	}
	if (!_replicationIsInitiaded) {
		this->_initReplication(1); /* TODO +: Ops! if user only press step button, model should have to know wich is the current replication. A "for" loop on the startsimulation is not a good idea. It should be an attribute incremented every time a replications ends */
	}
	if (!_finishReplicationCondition()) {
		try {
			this->_stepSimulation();
		} catch (std::exception *e) {
			_excepcionHandled = e;
			this->traceError((*e), "Error on simulation step");
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

void Model::setReplicationLenght(double _replicationLenght) {
	this->_replicationLenght = _replicationLenght;
}

double Model::getReplicationLenght() const {
	return _replicationLenght;
}

void Model::setReplicationLenghtTimeUnit(Util::TimeUnit _replicationLenghtTimeUnit) {
	this->_replicationLenghtTimeUnit = _replicationLenghtTimeUnit;
}

Util::TimeUnit Model::getReplicationLenghtTimeUnit() const {
	return _replicationLenghtTimeUnit;
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

void Model::traceSimulation(Util::TraceLevel tracelevel, std::string text) {
	if (this->_traceLevel >= tracelevel) {

	}
}

void Model::addTraceListener(traceListener traceListener) {
	this->_traceListeners->insert(_traceListeners->end(), traceListener);
}

void Model::addTraceSimulationListener(traceListener traceListener) {
	this->_traceSimulationListeners->insert(_traceSimulationListeners->end(), traceListener);
}

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

double Model::getSimulationTime() const {
	return _simulationTime;
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

List<ModelInfrastructure*>* Model::getInfrastructures() const {
	return _infrastructures;
}

