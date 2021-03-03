/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelSimulation.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 18:04
 */

#include "ModelSimulation.h"
#include <iostream>
#include "Model.h"
#include "Simulator.h"
#include "SourceModelComponent.h"
#include "StatisticsCollector.h"
#include "Counter.h"
#include "Traits.h"
#include "SimulationControl.h"
#include "ComponentManager.h"

//using namespace GenesysKernel;

ModelSimulation::ModelSimulation(Model* model) {
	_model = model;
	_info = model->infos(); // why??
	_statsCountersSimulation->setSortFunc([](const ModelElement* a, const ModelElement * b) {
		return a->id() < b->id();
	});
	_simulationReporter = new Traits<SimulationReporter_if>::Implementation(this, model, this->_statsCountersSimulation);
}

bool ModelSimulation::_isReplicationEndCondition() {
	bool finish = _model->futureEvents()->size() == 0;
	finish |= _model->parseExpression(_info->terminatingCondition()) != 0.0;
	if (_model->futureEvents()->size() > 0 && !finish) {
		// replication length has not been achieve (sor far), but next event will happen after that, so it's just fine to set tnow as the replicationLength
		finish |= _model->futureEvents()->front()->time() > _info->replicationLength();
	}
	return finish;
}

void ModelSimulation::_traceReplicationEnded() {
	std::string causeTerminated = "";
	if (_model->futureEvents()->empty()) {
		causeTerminated = "event queue is empty";
	} else if (_stopRequested) {
		causeTerminated = "user requested to stop";
	} else if (_model->futureEvents()->front()->time() > _info->replicationLength()) {
		causeTerminated = "replication length " + std::to_string(_info->replicationLength()) + " was achieved";
	} else if (_model->parseExpression(_info->terminatingCondition())) {
		causeTerminated = "termination condition was achieved";
	} else causeTerminated = "unknown";
	std::string message = "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->numberOfReplications()) + " has finished with last event at time " + std::to_string(_simulatedTime) + " because " + causeTerminated;
	_model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, message);
}

/*!
 * Checks the model and if ok then initialize the simulation, execute repeatedly each replication and then show simulation statistics
 */
void ModelSimulation::start() {
	if (!_model->check()) {
		_model->tracer()->trace(Util::TraceLevel::errorFatal, "Model check failed. Cannot start simulation.");
		return;
	}
	Util::SetIndent(0); //force indentation
	if (!_isPaused) {
		_initSimulation();
		_model->onEvents()->NotifySimulationStartHandlers(new SimulationEvent(0, nullptr));
		_currentReplicationNumber = 1;
		Util::IncIndent();
		_initReplication();
	} else {
		_model->onEvents()->NotifySimulationPausedStartHandlers(new SimulationEvent(0, nullptr));
	}
	_running = true;
	_isPaused = false;
	do {
		Util::SetIndent(1);
		_model->onEvents()->NotifyReplicationStartHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
		// main simulation loop
		Util::IncIndent();
		while (!_isReplicationEndCondition() && !_pauseRequested) {
			_stepSimulation();
		}
		Util::SetIndent(1); // force
		if (!_pauseRequested) {
			_replicationEnded();
			_currentReplicationNumber++;
			if (_currentReplicationNumber <= _info->numberOfReplications()) {
				_initReplication();
			}
		}
	} while (_currentReplicationNumber <= _info->numberOfReplications() && !_pauseRequested);
	if (!_pauseRequested) {
		_simulationReporter->showSimulationStatistics(); //_cStatsSimulation);
		Util::DecIndent();

		_model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, "Simulation of model \"" + _info->name() + "\" has finished.\n");
		_model->onEvents()->NotifySimulationEndHandlers(new SimulationEvent(0, nullptr));
	} else {
		_pauseRequested = false;
		_isPaused = true;
	}
	_running = false;
}

void ModelSimulation::_replicationEnded() {
	_traceReplicationEnded();
	_model->onEvents()->NotifyReplicationEndHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
	_simulationReporter->showReplicationStatistics();
	_actualizeSimulationStatistics();
}

void ModelSimulation::_actualizeSimulationStatistics() {
	//\todo: should not be only CSTAT and COUNTER, but any element that generateReportInformation
	const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
	const std::string UtilTypeOfCounter = Util::TypeOf<Counter>();

	StatisticsCollector *sc, *scSim;
	//ModelElement* me;
	List<ModelElement*>* cstats = _model->elements()->elementList(Util::TypeOf<StatisticsCollector>());
	for (std::list<ModelElement*>::iterator itMod = cstats->list()->begin(); itMod != cstats->list()->end(); itMod++) {
		sc = dynamic_cast<StatisticsCollector*> ((*itMod));
		scSim = nullptr;
		for (std::list<ModelElement*>::iterator itSim = _statsCountersSimulation->list()->begin(); itSim != _statsCountersSimulation->list()->end(); itSim++) {
			if ((*itSim)->classname() == UtilTypeOfStatisticsCollector) {
				if ((*itSim)->name() == _cte_stCountSimulNamePrefix + sc->name() && dynamic_cast<StatisticsCollector*> (*itSim)->getParent() == sc->getParent()) {
					// found
					scSim = dynamic_cast<StatisticsCollector*> (*itSim);
					break;
				}
			}
		}
		//scSim = dynamic_cast<StatisticsCollector*> (*(this->_statsCountersSimulation->find((*it))));
		if (scSim == nullptr) {
			// this is a cstat created during the last replication
			//	    scSim = new StatisticsCollector(_model->elements(), sc->name(), sc->getParent());
			_statsCountersSimulation->insert(scSim);
		}
		assert(scSim != nullptr);
		scSim->getStatistics()->getCollector()->addValue(sc->getStatistics()->average());
	}
	Counter *cnt; //, *cntSim;
	List<ModelElement*>* counters = _model->elements()->elementList(Util::TypeOf<Counter>());
	for (std::list<ModelElement*>::iterator itMod = counters->list()->begin(); itMod != counters->list()->end(); itMod++) {
		cnt = dynamic_cast<Counter*> ((*itMod));
		//cntSim = nullptr;
		scSim = nullptr;
		for (std::list<ModelElement*>::iterator itSim = _statsCountersSimulation->list()->begin(); itSim != _statsCountersSimulation->list()->end(); itSim++) {
			if ((*itSim)->classname() == UtilTypeOfStatisticsCollector) {
				//_model->getTraceManager()->trace(Util::TraceLevel::simulation, (*itSim)->getName() + " == "+_cte_stCountSimulNamePrefix + cnt->getName());
				if ((*itSim)->name() == _cte_stCountSimulNamePrefix + cnt->name() && dynamic_cast<StatisticsCollector*> (*itSim)->getParent() == cnt->getParent()) {
					// found
					scSim = dynamic_cast<StatisticsCollector*> (*itSim);
					break;
				}
			}
			/*
			if ((*itSim)->getTypename() == UtilTypeOfCounter) {
			if ((*itSim)->getName() == _cte_stCountSimulNamePrefix + cnt->getName() && dynamic_cast<Counter*> (*itSim)->getParent() == cnt->getParent()) {
				// found
				cntSim = dynamic_cast<Counter*> (*itSim);
				break;
			}
			}
			 */
		}
		/*
		assert(cntSim != nullptr);
		cntSim->incCountValue(cnt->getCountValue());
		 */
		assert(scSim != nullptr);
		scSim->getStatistics()->getCollector()->addValue(cnt->getCountValue());
	}
}

void ModelSimulation::_showSimulationHeader() {
	TraceManager* tm = _model->tracer();
	tm->traceReport("\n-----------------------------------------------------");
	// simulator infos
	tm->traceReport(_model->parentSimulator()->name());
	tm->traceReport(_model->parentSimulator()->licenceManager()->showLicence());
	tm->traceReport(_model->parentSimulator()->licenceManager()->showLimits());
	// model infos
	tm->traceReport("Analyst Name: " + _info->analystName());
	tm->traceReport("Project Title: " + _info->projectTitle());
	tm->traceReport("Number of Replications: " + std::to_string(_info->numberOfReplications()));
	tm->traceReport("Replication Length: " + std::to_string(_info->replicationLength()) + " " + Util::StrTimeUnit(_info->replicationLengthTimeUnit()));
	//tm->traceReport(Util::TraceLevel::simulation, "");
	// model controls and responses
	std::string controls;
	for (std::list<SimulationControl*>::iterator it = _model->controls()->list()->begin(); it != _model->controls()->list()->end(); it++) {
		controls += (*it)->name() + "(" + (*it)->type() + "), ";
	}
	tm->traceReport("Simulation controls: " + controls);
	std::string responses;
	for (std::list<SimulationResponse*>::iterator it = _model->responses()->list()->begin(); it != _model->responses()->list()->end(); it++) {
		responses += (*it)->name() + "(" + (*it)->type() + "), ";
	}
	tm->traceReport("Simulation responses: " + responses);
}

/*!
 * Initialize once for all replications
 */
void ModelSimulation::_initSimulation() {
	_showSimulationHeader();
	//model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, "------------------------------");
	_model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, "");
	_model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, "Simulation of model \"" + _info->name() + "\" is starting.");
	// copy all CStats and Counters (used in a replication) to CStats and counters for the whole simulation
	// \todo: Should not be CStats and Counters, but any element that generates report importation
	this->_statsCountersSimulation->clear();
	StatisticsCollector* cstat;
	List<ModelElement*>* cstats = _model->elements()->elementList(Util::TypeOf<StatisticsCollector>());
	for (std::list<ModelElement*>::iterator it = cstats->list()->begin(); it != cstats->list()->end(); it++) {
		cstat = dynamic_cast<StatisticsCollector*> ((*it));
		// this new CSat should NOT be inserted into the model
		StatisticsCollector* newCStatSimul = new StatisticsCollector(_model, _cte_stCountSimulNamePrefix + cstat->name(), cstat->getParent(), false);
		//_model->elements()->remove(Util::TypeOf<StatisticsCollector>(), newCStatSimul); // remove from model, since it is automatically inserted by the constructor
		this->_statsCountersSimulation->insert(newCStatSimul);
	}
	// copy all Counters (used in a replication) to Counters for the whole simulation
	// \todo: Counters in replication should be converted into CStats in simulation. Each value counted in a replication should be added in a CStat for Stats.
	Counter* counter;
	List<ModelElement*>* counters = _model->elements()->elementList(Util::TypeOf<Counter>());
	for (std::list<ModelElement*>::iterator it = counters->list()->begin(); it != counters->list()->end(); it++) {
		counter = dynamic_cast<Counter*> ((*it));
		// adding a counter
		/*
		Counter* newCountSimul = new Counter(_cte_stCountSimulNamePrefix + counter->getName(), counter->getParent());
		this->_statsCountersSimulation->insert(newCountSimul);
		 */
		// addin a cstat (to stat the counts)
		StatisticsCollector* newCStatSimul = new StatisticsCollector(_model, _cte_stCountSimulNamePrefix + counter->name(), counter->getParent(), false);
		this->_statsCountersSimulation->insert(newCStatSimul);
	}
}

void ModelSimulation::_initReplication() {
	TraceManager* tm = _model->tracer();
	tm->trace(Util::TraceLevel::modelSimulationEvent, "");
	tm->trace(Util::TraceLevel::modelSimulationEvent, "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->numberOfReplications()) + " is starting.");

	_model->futureEvents()->clear();
	_simulatedTime = 0.0;
	_pauseRequested = false;

	//if (_currentReplicationNumber > 1) {
	// init all components between replications
	for (std::list<ModelComponent*>::iterator it = _model->components()->begin(); it != _model->components()->end(); it++) {
		ModelElement::InitBetweenReplications((*it));
	}
	// init all elements between replications
	ModelElement* element;
	std::string elementType;
	//std::string* errorMessage = new std::string();
	std::list<std::string>* elementTypes = _model->elements()->elementClassnames();
	for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
		elementType = (*typeIt);
		List<ModelElement*>* elements = _model->elements()->elementList(elementType);
		for (std::list<ModelElement*>::iterator it = elements->list()->begin(); it != elements->list()->end(); it++) {
			element = (*it);
			ModelElement::InitBetweenReplications(element);
		}
	}
	//}
	Util::ResetIdOfType(Util::TypeOf<Entity>());
	Util::ResetIdOfType(Util::TypeOf<Event>());

	// insert first creation events
	SourceModelComponent *source;
	Entity *newEntity;
	Event *newEvent;
	double creationTime;
	unsigned int numToCreate;
	//std::list<ModelComponent*>* list = _model->getComponents()->list();
	for (std::list<ModelComponent*>::iterator it = _model->components()->begin(); it != _model->components()->end(); it++) {
		source = dynamic_cast<SourceModelComponent*> (*it);
		if (source != nullptr) {
			creationTime = source->firstCreation();
			numToCreate = source->entitiesPerCreation();
			for (unsigned int i = 1; i <= numToCreate; i++) {
				newEntity = new Entity(_model);
				newEntity->setEntityType(source->entityType());
				newEvent = new Event(creationTime, newEntity, (*it));
				_model->futureEvents()->insert(newEvent);
			}
			source->setEntitiesCreated(numToCreate);
		}
	}

	if (this->_initializeStatisticsBetweenReplications) {
		_initStatistics();
	}
}

void ModelSimulation::_initStatistics() {
	StatisticsCollector* cstat;
	List<ModelElement*>* list = _model->elements()->elementList(Util::TypeOf<StatisticsCollector>());
	for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		cstat = (StatisticsCollector*) (*it);
		cstat->getStatistics()->getCollector()->clear();
	}
	Counter* counter;
	list = _model->elements()->elementList(Util::TypeOf<Counter>());
	for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		counter = (Counter*) (*it);
		counter->clear();
	}

}

void ModelSimulation::_checkWarmUpTime(Event* nextEvent) {
	double warmupTime = Util::TimeUnitConvert(_model->infos()->warmUpPeriodTimeUnit(), _model->infos()->replicationLengthTimeUnit());
	warmupTime *= _model->infos()->warmUpPeriod();
	if (warmupTime > 0.0 && _model->simulation()->simulatedTime() <= warmupTime && nextEvent->time() > warmupTime) {// warmuTime. Time to initStats
		_model->tracer()->trace(Util::TraceLevel::modelInternal, "Warmup time reached. Statistics are being reseted.");
		_initStatistics();
	}
}

void ModelSimulation::_stepSimulation() {
	// process one single event
	Event* nextEvent;
	nextEvent = _model->futureEvents()->front();
	if (_model->infos()->warmUpPeriod() > 0.0)
		_checkWarmUpTime(nextEvent);
	if (nextEvent->time() <= _info->replicationLength()) {
		_model->futureEvents()->pop_front();
		_model->onEvents()->NotifyReplicationStepHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
		_processEvent(nextEvent);
	} else {
		this->_simulatedTime = _model->infos()->replicationLength(); ////nextEvent->getTime(); // just to advance time to beyond simulatedTime
	}
}

void ModelSimulation::_processEvent(Event* event) {
	//	_model->tracer()->traceSimulation(Util::TraceLevel::modelSimulationEvent, event->time(), event->entity(), event->component(), "");
	_model->tracer()->trace(Util::TraceLevel::modelSimulationEvent, "Processing event=(" + event->show() + ")");
	_model->tracer()->trace(Util::TraceLevel::modelSimulationInternal, "Current Entity: " + event->entity()->show());
	this->_currentEntity = event->entity();
	this->_currentComponent = event->component();
	this->_currentInputNumber = event->componentInputNumber();
	_simulatedTime = event->time();
	_model->onEvents()->NotifyProcessEventHandlers(new SimulationEvent(_currentReplicationNumber, event));
	Util::IncIndent();
	try {
		//event->getComponent()->Execute(event->getEntity(), event->getComponent()); // Execute is static
		ModelComponent::Execute(event->entity(), event->component(), event->componentInputNumber());
	} catch (std::exception *e) {
		_model->tracer()->traceError(*e, "Error on processing event (" + event->show() + ")");
	}
	Util::DecIndent();
}

void ModelSimulation::pause() {
}

void ModelSimulation::step() {
	if (_simulationIsInitiated && _replicationIsInitiaded) {
		if (!_isReplicationEndCondition()) {
			try {
				this->_stepSimulation();
			} catch (std::exception *e) {
				_model->tracer()->traceError((*e), "Error on simulation step");
			}
		}
	}

}

void ModelSimulation::stop() {
}

void ModelSimulation::restart() {
}

void ModelSimulation::setPauseOnEvent(bool _pauseOnEvent) {
	this->_pauseOnEvent = _pauseOnEvent;
}

bool ModelSimulation::isPauseOnEvent() const {
	return _pauseOnEvent;
}

void ModelSimulation::setInitializeStatistics(bool _initializeStatistics) {
	this->_initializeStatisticsBetweenReplications = _initializeStatistics;
}

bool ModelSimulation::isInitializeStatistics() const {
	return _initializeStatisticsBetweenReplications;
}

void ModelSimulation::setInitializeSystem(bool _initializeSystem) {
	this->_initializeSystem = _initializeSystem;
}

bool ModelSimulation::isInitializeSystem() const {
	return _initializeSystem;
}

void ModelSimulation::setStepByStep(bool _stepByStep) {
	this->_stepByStep = _stepByStep;
}

bool ModelSimulation::isStepByStep() const {
	return _stepByStep;
}

void ModelSimulation::setPauseOnReplication(bool _pauseOnReplication) {
	this->_pauseOnReplication = _pauseOnReplication;
}

bool ModelSimulation::isPauseOnReplication() const {
	return _pauseOnReplication;
}

double ModelSimulation::simulatedTime() const {
	return _simulatedTime;
}

bool ModelSimulation::isRunning() const {
	return _running;
}

unsigned int ModelSimulation::currentReplicationNumber() const {
	return _currentReplicationNumber;
}

ModelComponent* ModelSimulation::currentComponent() const {
	return _currentComponent;
}

Entity* ModelSimulation::currentEntity() const {
	return _currentEntity;
}

void ModelSimulation::setReporter(SimulationReporter_if* _simulationReporter) {
	this->_simulationReporter = _simulationReporter;
}

SimulationReporter_if* ModelSimulation::reporter() const {
	return _simulationReporter;
}

unsigned int ModelSimulation::currentInputNumber() const {
	return _currentInputNumber;
}

bool ModelSimulation::isPaused() const {
	return _isPaused;
}
