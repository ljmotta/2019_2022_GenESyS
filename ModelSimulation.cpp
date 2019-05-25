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
#include "Traits.h"
#include "SimulationControl.h"

ModelSimulation::ModelSimulation(Model* model) {
    _model = model;
    _info = model->getInfos(); // why?
    _simulationReporter = new Traits<SimulationReporter_if>::Implementation(this, model);
}

ModelSimulation::ModelSimulation(const ModelSimulation& orig) {
}

ModelSimulation::~ModelSimulation() {
}

bool ModelSimulation::_isReplicationEndCondition() {
    bool finish = _model->getEvents()->size() == 0;
    finish |= _model->parseExpression(_info->getTerminatingCondition()) != 0.0;
    if (_model->getEvents()->size() > 0 && !finish) {
        // replication length has not been achieve (sor far), but next event will happen after that, so it's just fine to set tnow as the replicationLength 
        finish |= _model->getEvents()->first()->getTime() > _info->getReplicationLength();
    }
    return finish;
}

/*!
 * Checks the model and if ok then initialize the simulation, execute repeatedly each replication and then show simulation statistics
 */
void ModelSimulation::startSimulation() {
    if (!_model->checkModel()) {
        _model->getTracer()->trace(Util::TraceLevel::errors, "Model check failed. Cannot start simulation.");
        return;
    }
    Util::SetIndent(0);
    _initSimulation();
    _model->getOnEventManager()->NotifySimulationStartHandlers(new SimulationEvent(0, nullptr));
    for (_currentReplicationNumber = 1; _currentReplicationNumber <= _info->getNumberOfReplications(); _currentReplicationNumber++) {
        Util::SetIndent(1);
        _initReplication();
        _model->getOnEventManager()->NotifyReplicationStartHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));

        Util::IncIndent();
        {
            while (!_isReplicationEndCondition()) {
                _stepSimulation();
                if (_pauseOnEvent) {
                    std::cout << "[paused] ...press any key to continue...";
                    std::cin.get();
                    std::cout << std::endl;
                }
            }
        }
        Util::DecIndent;
        Util::SetIndent(1); // force

        _model->getOnEventManager()->NotifyReplicationEndHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
        std::string causeTerminated = "";
        if (_model->getEvents()->empty()) {
            causeTerminated = "event queue is empty";
        } else if (_stopRequested) {
            causeTerminated = "user requested to stop";
        } else if (_model->getEvents()->first()->getTime() > _info->getReplicationLength()) {
            causeTerminated = "replication length " + std::to_string(_info->getReplicationLength()) + " was achieved";
        } else if (_model->parseExpression(_info->getTerminatingCondition())) {
            causeTerminated = "termination condition was achieved";
        } else causeTerminated = "unknown";     
        std::string message = "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " has finished at time " + std::to_string(_simulatedTime) + " because " + causeTerminated;
        _model->getTracer()->trace(Util::TraceLevel::simulation, message);
        _simulationReporter->showReplicationStatistics();
        _actualizeSimulationStatistics();
    }
    _simulationReporter->showSimulationStatistics(_cStatsSimulation);
    Util::DecIndent();

    _model->getTracer()->trace(Util::TraceLevel::simulation, "Simulation of model \"" + _info->getName() + "\" has finished.\n");
    _model->getOnEventManager()->NotifySimulationEndHandlers(new SimulationEvent(0, nullptr));

}

void ModelSimulation::_actualizeSimulationStatistics() {
    StatisticsCollector* cstat;
    int i = 0;
    List<ModelElement*>* cstats = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
    for (std::list<ModelElement*>::iterator it = cstats->getList()->begin(); it != cstats->getList()->end(); it++) {
        cstat = static_cast<StatisticsCollector*> ((*it));
        this->_cStatsSimulation->getAtRank(i)->getStatistics()->getCollector()->addValue(cstat->getStatistics()->average());
        i++;
    }
}

/*!
 * Initialize once for all replications
 */
void ModelSimulation::_initSimulation() {
    TraceManager* tm = _model->getTracer();
    tm->traceReport(Util::TraceLevel::simulation, "\n-----------------------------------------------------");
    tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getName());
    tm->traceReport(Util::TraceLevel::simulation, _model->getParent()->getLicense());
    tm->traceReport(Util::TraceLevel::simulation, "Project Title: " + _info->getProjectTitle());
    tm->traceReport(Util::TraceLevel::simulation, "Analyst Name: " + _info->getAnalystName());
    tm->traceReport(Util::TraceLevel::simulation, "");
    //tm->traceReport(Util::TraceLevel::simulation, "Trace Level: "+static_cast<unsigned int>(_model->getTracer()->getTraceLevel()));
    //tm->traceReport(Util::TraceLevel::simulation, "");
    tm->trace(Util::TraceLevel::simulation, "Simulation of model \"" + _info->getName() + "\" is starting.");
    // copy all CStats (used in a replication) to CStats for the whole simulation
    this->_cStatsSimulation->clear();
    StatisticsCollector* cstat;
    List<ModelElement*>* cstats = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
    for (std::list<ModelElement*>::iterator it = cstats->getList()->begin(); it != cstats->getList()->end(); it++) {
        cstat = static_cast<StatisticsCollector*> ((*it));
        StatisticsCollector* newCStatSimul = new StatisticsCollector("Simul." + cstat->getName(), cstat->getParent());
        this->_cStatsSimulation->insert(newCStatSimul);
    }
}

/*!
 Clear the event list, restarts simulated time, initialize event list and statistics
 */
void ModelSimulation::_initReplication() {
    TraceManager* tm = _model->getTracer();
    tm->traceReport(Util::TraceLevel::simulation, "");
    tm->traceReport(Util::TraceLevel::simulation, "Replication " + std::to_string(_currentReplicationNumber) + " of " + std::to_string(_info->getNumberOfReplications()) + " is starting.");

    _model->getEvents()->clear();
    _simulatedTime = 0.0;
    _pauseRequested = false;

    // insert first creation events
    SourceModelComponent *source;
    Entity *newEntity;
    Event *newEvent;
    double creationTime;
    unsigned int numToCreate;
    std::list<ModelComponent*>* list = _model->getComponents()->getList();
    for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
        source = dynamic_cast<SourceModelComponent*> (*it);
        if (source != nullptr) {
            creationTime = source->getFirstCreation();
            numToCreate = source->getEntitiesPerCreation();
            for (unsigned int i = 1; i <= numToCreate; i++) {
                newEntity = new Entity(_model->getElementManager());
                newEntity->setEntityType(source->getEntityType());
                newEvent = new Event(creationTime, newEntity, (*it));
                _model->getEvents()->insert(newEvent);
            }
        }
    }

    if (this->_initializeStatisticsBetweenReplications) {
        StatisticsCollector* cstat;
        List<ModelElement*>* list = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>());
        for (std::list<ModelElement*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
            cstat = (StatisticsCollector*) (*it);
            cstat->getStatistics()->getCollector()->clear();
        }
    }
}

void ModelSimulation::_stepSimulation() {
    // process one single event
    Event* nextEvent;
    nextEvent = _model->getEvents()->first();
    if (nextEvent->getTime() <= _info->getReplicationLength()) {
        _model->getEvents()->pop_front();
        _model->getOnEventManager()->NotifyReplicationStepHandlers(new SimulationEvent(_currentReplicationNumber, nullptr));
        _processEvent(nextEvent);
    } else {
        this->_simulatedTime = _model->getInfos()->getReplicationLength();////nextEvent->getTime(); // just to advance time to beyond simulatedTime
    }
}

void ModelSimulation::_processEvent(Event* event) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "");
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Processing event=(" + event->show() + ")");
    _model->getTracer()->trace(Util::TraceLevel::blockInternal, "Current Entity: " + event->getEntity()->show());
    this->_currentEntity = event->getEntity();
    this->_currentComponent = event->getComponent();
    _simulatedTime = event->getTime();
    _model->getOnEventManager()->NotifyProcessEventHandlers(new SimulationEvent(_currentReplicationNumber, event));
    Util::IncIndent();
    try {
        event->getComponent()->Execute(event->getEntity(), event->getComponent()); // Execute is static
    } catch (std::exception *e) {
        _model->getTracer()->traceError(*e, "Error on processing event (" + event->show() + ")");
    }
    Util::DecIndent();
}

void ModelSimulation::pauseSimulation() {
}

void ModelSimulation::stepSimulation() {
    if (_simulationIsInitiated && _replicationIsInitiaded) {
        if (!_isReplicationEndCondition()) {
            try {
                this->_stepSimulation();
            } catch (std::exception *e) {
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

unsigned int ModelSimulation::getCurrentReplicationNumber() const {
    return _currentReplicationNumber;
}

ModelComponent* ModelSimulation::getCurrentComponent() const {
    return _currentComponent;
}

Entity* ModelSimulation::getCurrentEntity() const {
    return _currentEntity;
}
