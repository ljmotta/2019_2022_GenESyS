/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TraceManager.cpp
 * Author: cancian
 * 
 * Created on 7 de Novembro de 2018, 11:59
 */

#include "TraceManager.h"
#include "Traits.h"


TraceManager::TraceManager(Model* model) {
	_model = model;
	_debugged = Traits<Model>::debugged;
	_traceLevel = Traits<Model>::traceLevel;

}

TraceManager::TraceManager(const TraceManager& orig) {
}

TraceManager::~TraceManager() {
}


void TraceManager::setTraceLevel(Util::TraceLevel _traceLevel) {
	this->_traceLevel = _traceLevel;
}

Util::TraceLevel TraceManager::getTraceLevel() const {
	return _traceLevel;
}

/*
 void TraceManager::traceSimulation(Util::TraceLevel tracelevel, std::string text) {
	if (_traceConditionPassed(tracelevel)) {
		TraceSimulationEvent e = TraceEvent(tracelevel, text);
		for (std::list<traceSimulationListener>::iterator it = this->_traceSimulationListeners->begin(); it != _traceSimulationListeners->end(); it++) {
			(*it)(e);
		}
	}
}
 */

void TraceManager::addTraceListener(traceListener traceListener) {
	this->_traceListeners->insert(_traceListeners->end(), traceListener);
}

//void TraceManager::addTraceSimulationListener(traceListener traceListener) {
//	this->_traceSimulationListeners->insert(_traceSimulationListeners->end(), traceListener);
//}

void TraceManager::addTraceSimulationListener(traceSimulationListener traceSimulationListener) {
	this->_traceSimulationListeners->insert(_traceSimulationListeners->end(), traceSimulationListener);
}

void TraceManager::addTraceErrorListener(traceErrorListener traceErrorListener) {
	this->_traceErrorListeners->insert(_traceErrorListeners->end(), traceErrorListener);
}

void TraceManager::addTraceReportListener(traceListener traceReportListener) {
	this->_traceReportListeners->insert(_traceReportListeners->end(), traceReportListener);
}

void TraceManager::trace(Util::TraceLevel tracelevel, std::string text) {
	if (_traceConditionPassed(tracelevel)) {
		TraceEvent e = TraceEvent(tracelevel, text);
		/* TODO--: somewhere in future it should be interesting to use "auto" and c++17 at least */
		for (std::list<traceListener>::iterator it = this->_traceListeners->begin(); it != _traceListeners->end(); it++) {
			(*it)(e);
		}
	}
}

void TraceManager::traceError(std::exception e, std::string text) {
	TraceErrorEvent exceptEvent = TraceErrorEvent(text, e);
	/* TODO--: somewhere in future it should be interesting to use "auto" and c++17 at least */
	for (std::list<traceErrorListener>::iterator it = this->_traceErrorListeners->begin(); it != _traceErrorListeners->end(); it++) {
		(*it)(exceptEvent);
	}
}

void TraceManager::traceSimulation(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text) {
	if (_traceConditionPassed(tracelevel)) {
		TraceSimulationEvent e = TraceSimulationEvent(tracelevel, time, entity, component, text);
		for (std::list<traceSimulationListener>::iterator it = this->_traceSimulationListeners->begin(); it != _traceSimulationListeners->end(); it++) {
			(*it)(e);
		}
	}
}

void TraceManager::traceReport(Util::TraceLevel tracelevel, std::string text) {
	if (_traceConditionPassed(tracelevel)) {
		TraceEvent e = TraceEvent(tracelevel, text);
		for (std::list<traceListener>::iterator it = this->_traceReportListeners->begin(); it != _traceReportListeners->end(); it++) {
			(*it)(e);
		}
	}
}

List<std::string>* TraceManager::getErrorMessages() const {
	return _errorMessages;
}


bool TraceManager::_traceConditionPassed(Util::TraceLevel level) {
	return this->_debugged && static_cast<int>(this->_traceLevel) >=  static_cast<int>(level);
}
