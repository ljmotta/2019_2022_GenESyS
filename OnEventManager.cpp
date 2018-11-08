/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.cpp
 * Author: cancian
 * 
 * Created on 7 de Novembro de 2018, 12:28
 */

#include "OnEventManager.h"

OnEventManager::OnEventManager() {
}

OnEventManager::OnEventManager(const OnEventManager& orig) {
}

OnEventManager::~OnEventManager() {
}

void OnEventManager::addOnReplicationStartListener(simulationEventListener eventListener) {
	this->_onReplicationStartListeners->insert(this->_onReplicationStartListeners->end(), eventListener);
}

void OnEventManager::addOnReplicationStepListener(simulationEventListener eventListener) {
	this->_onReplicationStepListeners->insert(this->_onReplicationStepListeners->end(), eventListener);
}

void OnEventManager::addOnProcessEventListener(simulationEventListener eventListener) {
	this->_onProcessEventListeners->insert(this->_onProcessEventListeners->end(), eventListener);
}

void OnEventManager::addOnReplicationEndListener(simulationEventListener eventListener) {
	this->_onReplicationEndListeners->insert(this->_onReplicationEndListeners->end(), eventListener);
}

void OnEventManager::addOnSimulationStartListener(simulationEventListener eventListener) {
	this->_onSimulationStartListeners->insert(this->_onSimulationStartListeners->end(), eventListener);
}

void OnEventManager::addOnSimulationEndListener(simulationEventListener eventListener) {
	this->_onSimulationEndListeners->insert(this->_onSimulationEndListeners->end(), eventListener);
}

void OnEventManager::_NotifyListeners(std::list<simulationEventListener>* list, SimulationEvent* se) {
	for (std::list<simulationEventListener>::iterator it = list->begin(); it != list->end(); it++) {
		(*it)(se);
	}
}

void OnEventManager::NotifyReplicationStartListeners(SimulationEvent* se) {
	this->_NotifyListeners(this->_onReplicationStartListeners, se);

}

void OnEventManager::NotifyReplicationStepListeners(SimulationEvent* se) {
	this->_NotifyListeners(this->_onReplicationStepListeners, se);

}

void OnEventManager::NotifyReplicationEndListeners(SimulationEvent* se) {
	this->_NotifyListeners(this->_onReplicationEndListeners, se);
}

void OnEventManager::NotifyProcessEventListeners(SimulationEvent* se) {
	this->_NotifyListeners(this->_onProcessEventListeners, se);
}

void OnEventManager::NotifySimulationStartListeners(SimulationEvent* se) {
	this->_NotifyListeners(this->_onReplicationEndListeners, se);
}

void OnEventManager::NotifySimulationEndListeners(SimulationEvent* se) {

}