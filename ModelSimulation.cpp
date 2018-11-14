/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelSimulation.cpp
 * Author: cancian
 * 
 * Created on 7 de Novembro de 2018, 18:04
 */

#include <iostream>
#include "ModelSimulation.h"
#include "Model.h"
#include "Simulator.h"
#include "SourceModelComponent.h"
#include "StatisticsCollector.h"

ModelSimulation::ModelSimulation(Model* model) {
	_model = model;
	_info = model->getInfos();
}

ModelSimulation::ModelSimulation(const ModelSimulation& orig) {
}

ModelSimulation::~ModelSimulation() {
}

bool ModelSimulation::_finishReplicationCondition() {
	return _model->getEvents()->size() == 0
			|| _simulatedTime > _info->getReplicationLength()
			|| _model->parseExpression(_info->getTerminatingCondition());
}

/*!
 * Checks the model and if ok then initialize the simulation, execute repeatedly each replication and then show simulation statistics
 */
void ModelSimulation::startSimulation() {
	if (!_model->checkModel()) {
		_model->getTracer()->trace(Util::TraceLevel::errors, "Model check failed. Cannot start simulation.");
		return;
	}
	_initSimulation();
	_model->getOnEventManager()->NotifySimulationStartListeners(new SimulationEvent(0, nullptr));


	for (_currentReplicationNumber = 1; _currentReplicationNumber <= _info->getNumberOfReplications(); _currentReplicationNumber++) {
		_initReplication();
		_model->getOnEventManager()->NotifyReplicationStartListeners(new SimulationEvent(_currentReplicationNumber, nullptr));

		while (!_finishReplicationCondition()) {
			_stepSimulation();
			if (_pauseOnEvent) {
				std::cout << "[paused] ...press any key to continue...";
				std::cin.get();
				std::cout << std::endl;
			}
		}

		_model->getOnEventManager()->NotifyReplicationEndListeners(new SimulationEvent(_currentReplicationNumber, nullptr));


		std::string causeTerminated = "";
		if (_model->getEvents()->empty()) {
			causeTerminated = "event queue is empty";
		} else if (_stopRequested) {
			causeTerminated = "user requested to stop";
		} else if (!(this->_simulatedTime < _info->getReplicationLength())) {
			causeTerminated = "replication length " + std::to_string(_info->getReplicationLength()) + " was achieved";
		} else if (_model->parseExpression(_info->getTerminatingCondition())) {
			causeTerminated = "termination condition was achieved";
		} else causeTerminated = "unknown";
		std::string message = "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " has finished at time " + std::to_string(_simulatedTime) + " because " + causeTerminated;
		_model->getTracer()->trace(Util::TraceLevel::simulation, message);
		_showReplicationStatistics();
	}
	_showSimulationStatistics();

	std::cout << "Simulation has finished.\n";
	_model->getOnEventManager()->NotifySimulationEndListeners(new SimulationEvent(0, nullptr));

}

/*!
 * Initialize once for all replications
 */
void ModelSimulation::_initSimulation() {
	_model->getTracer()->trace(Util::TraceLevel::simulation, "\nSimulation of model \"" + _info->getName() + "\" is starting.\n");
	/*TODO +-: not implemented*/
}

/*!
 Clear the event list, restarts simulated time, initialize event list and statistics
 */
void ModelSimulation::_initReplication() {
	TraceManager* tm = _model->getTracer();
	tm->traceReport(Util::TraceLevel::simulation, "-----------------------------------------------------");
	tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getName());
	tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getLicense());
	tm->traceReport(Util::TraceLevel::simulation, "Projet Title: " + _info->getProjectTitle());
	tm->traceReport(Util::TraceLevel::simulation, "Analysit Name: " + _info->getAnalystName());
	tm->traceReport(Util::TraceLevel::simulation, "");
	tm->traceReport(Util::TraceLevel::simulation, "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " is starting.\n");

	_model->getEvents()->clear();
	_simulatedTime = 0.0;
	_pauseRequested = false;

	// insert first creation events
	SourceModelComponent *source;
	Entity *newEntity;
	Event *newEvent;
	double creationTime;
	unsigned int numToCreate;
	//for(ModelComponent* comp=_components->first(); comp!=_components->last(); _components->next()) {
	std::list<ModelComponent*>* list = _model->getComponents()->getList();
	for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
		source = dynamic_cast<SourceModelComponent*> (*it);
		if (source != nullptr) {
			creationTime = source->getFirstCreation();
			numToCreate = source->getEntitiesPerCreation();
			for (unsigned int i = 1; i <= numToCreate; i++) {
				newEntity = new Entity();
				newEvent = new Event(creationTime, newEntity, (*it));
				_model->getEvents()->insert(newEvent);
			}
		}
	}

	if (this->_initializeStatisticsBetweenReplications) {
		StatisticsCollector* cstat;
		List<ModelInfrastructure*>* list = _model->getInfraManager()->getInfrastructures(Util::TypeOf<StatisticsCollector>());
		for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
			cstat = (StatisticsCollector*) (*it);
			cstat->getCollector()->clear();
		}
	}
}

void ModelSimulation::_stepSimulation() {
	// process one single event
	_model->getTracer()->trace(Util::TraceLevel::simulation, ""); // just a new line?
	//trace(Util::TraceLevel::mostDetailed, "\ntime=" + std::to_string(this->_simulatedTime) + ",events=" + _events->show()); // + ",entities=" + _entities->show());
	_model->getOnEventManager()->NotifyReplicationStepListeners(new SimulationEvent(_currentReplicationNumber, nullptr));

	Event* nextEvent;
	nextEvent = _model->getEvents()->first();
	_model->getEvents()->pop_front();
	if (nextEvent->getTime() <= _info->getReplicationLength()) {
		_processEvent(nextEvent);
	} else {
		this->_simulatedTime = nextEvent->getTime();
	}
}

void ModelSimulation::_processEvent(Event* event) {
	_model->getTracer()->trace(Util::TraceLevel::simulation, "Processing event=(" + event->show() + ")");
	this->_currentEntity = event->getEntity();
	this->_currentComponent = event->getComponent();
	_simulatedTime = event->getTime();

	_model->getOnEventManager()->NotifyProcessEventListeners(new SimulationEvent(_currentReplicationNumber, event));

	try {
		event->getComponent()->Execute(event->getEntity(), event->getComponent()); // Execute is static
	} catch (std::exception *e) {
		////////////////////_model->_excepcionHandled = e;
		_model->getTracer()->traceError(*e, "Error on processing event (" + event->show() + ")");
	}
}

void ModelSimulation::_showReplicationStatistics() {
	_model->getTracer()->traceReport(Util::TraceLevel::report, "\nReport for replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()));

	/*TODO: + To implement -- each infrastructure should know how to show its own statistics */


	// show statistics
	_model->getTracer()->traceReport(Util::TraceLevel::report, "Statistics:");
	StatisticsCollector* cstat;
	List<ModelInfrastructure*>* list = _model->getInfraManager()->getInfrastructures(Util::TypeOf<StatisticsCollector>());
	Util::IncIndent();
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		cstat = (StatisticsCollector*) (*it);
		std::string message = cstat->getName() + "\t N=" + std::to_string(cstat->numElements()) + ", avg=" + std::to_string(cstat->average()) + ", stddev=" + std::to_string(cstat->stddeviation()) + ", varCoef=" + std::to_string(cstat->variationCoef()) + ", min=" + std::to_string(cstat->min()) + ", max=" + std::to_string(cstat->max()) + ", e0_95%=" + std::to_string(cstat->halfWidthConfidenceInterval(0.95));
		_model->getTracer()->traceReport(Util::TraceLevel::report,  message);
	}
	Util::DecIndent();
}

void ModelSimulation::_showSimulationStatistics() {
	_model->getTracer()->traceReport(Util::TraceLevel::report, "\nReport for simulation\n");
	/* TODO */
}

void ModelSimulation::pauseSimulation() {
}

void ModelSimulation::stepSimulation() {
	if (_simulationIsInitiated && _replicationIsInitiaded) {
		if (!_finishReplicationCondition()) {
			try {
				this->_stepSimulation();
			} catch (std::exception *e) {
				////////////_model->_excepcionHandled = e;
				_model->getTracer()->traceError((*e), "Error on simulation step");
			}

		}
	}

}

void ModelSimulation::stopSimulation() {
}

void ModelSimulation::restartSimulation() {
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

double ModelSimulation::getSimulatedTime() const {
	return _simulatedTime;
}

bool ModelSimulation::isRunning() const {
	return _running;
}
