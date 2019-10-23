/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 12:28
 */

#include "OnEventManager.h"

OnEventManager::OnEventManager() {
}

void OnEventManager::_addOnHandler(List<simulationEventHandler>* list, simulationEventHandler EventHandler) {
    if (list->find(EventHandler) == list->getList()->end())
	list->insert(EventHandler);
}

void OnEventManager::addOnReplicationStartHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onReplicationStartHandlers, EventHandler);
}

void OnEventManager::addOnReplicationStepHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onReplicationStepHandlers, EventHandler);
}

void OnEventManager::addOnProcessEventHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onEntityMoveHandlers, EventHandler);
}

void OnEventManager::addOnEntityMoveHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onEntityMoveHandlers, EventHandler);
}

void OnEventManager::addOnReplicationEndHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onReplicationEndHandlers, EventHandler);
}

void OnEventManager::addOnSimulationStartHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onSimulationStartHandlers, EventHandler);
}

void OnEventManager::addOnSimulationEndHandler(simulationEventHandler EventHandler) {
    _addOnHandler(_onSimulationEndHandlers, EventHandler);
}

void OnEventManager::_NotifyHandlers(List<simulationEventHandler>* list, SimulationEvent* se) {
    for (std::list<simulationEventHandler>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
	(*it)(se);
    }
}

void OnEventManager::_NotifyHandlerMethods(List<simulationEventHandlerMethod>* list, SimulationEvent* se) {
    for (std::list<simulationEventHandlerMethod>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
	(*it)(se);
    }
}

void OnEventManager::NotifyReplicationStartHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onReplicationStartHandlers, se);

}

void OnEventManager::NotifyReplicationStepHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onReplicationStepHandlers, se);
}

void OnEventManager::NotifyReplicationEndHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onReplicationEndHandlers, se);
}

void OnEventManager::NotifyEntityMoveHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onEntityMoveHandlers, se);
}

void OnEventManager::NotifyProcessEventHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onProcessEventHandlers, se);
    this->_NotifyHandlerMethods(this->_onProcessEventHandlerMethods, se);
}

void OnEventManager::NotifySimulationStartHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onReplicationEndHandlers, se);
}

void OnEventManager::NotifySimulationEndHandlers(SimulationEvent* se) {
    this->_NotifyHandlers(this->_onSimulationEndHandlers, se);
}