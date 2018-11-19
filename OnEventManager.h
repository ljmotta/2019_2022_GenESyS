/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.h
 * Author: cancian
 *
 * Created on 7 de Novembro de 2018, 12:28
 */

#ifndef ONEVENTMANAGER_H
#define ONEVENTMANAGER_H

#include <list>
#include "Event.h"

/* TODO: To implement as item (1) for DS3
 * used to get and set values no matter the class (for process analyser)
 * should be a wait to invoke a getter or setter no matter the class (a pointer to a member function without specifying the class 
 */
typedef double (*memberFunctionGetDoubleVarHandler)(); //template<> ... typedef double (T::*getDoubleVarHandler)() or something like that
typedef void (*memberFunctionSetDoubleVarHandler)(double);

class SimulationEvent {
public:
	SimulationEvent(unsigned int replicationNumber, Event* event) {
		_replicationNumber = replicationNumber;
		_event = event;
	}
public:
	unsigned int getReplicationNumber() const {
		return _replicationNumber;
	}
	Event* getEventProcessed() const {
		return _event;
	}
private:
	unsigned int _replicationNumber;
	Event* _event;
};

typedef void (*simulationEventListener)(SimulationEvent*);

/*!
 * OnEventManager allows external methods to hook interval simulation events as listeners (or observers) of pecific events.
 * All methods added as listeners of an event will be invovked when that event is triggered.
 */
class OnEventManager {
public:
	OnEventManager();
	OnEventManager(const OnEventManager& orig);
	virtual ~OnEventManager();
public: // event listeners (handlers)
	void addOnReplicationStartListener(simulationEventListener eventListener);
	void addOnReplicationStepListener(simulationEventListener eventListener);
	void addOnReplicationEndListener(simulationEventListener eventListener);
	void addOnProcessEventListener(simulationEventListener eventListener);
	void addOnSimulationStartListener(simulationEventListener eventListener);
	void addOnSimulationEndListener(simulationEventListener eventListener);
public:
	void NotifyReplicationStartListeners(SimulationEvent* se);
	void NotifyReplicationStepListeners(SimulationEvent* se);
	void NotifyReplicationEndListeners(SimulationEvent* se);
	void NotifyProcessEventListeners(SimulationEvent* se);
	void NotifySimulationStartListeners(SimulationEvent* se);
	void NotifySimulationEndListeners(SimulationEvent* se);
private:
	void _NotifyListeners(std::list<simulationEventListener>* list, SimulationEvent* se);
private: // events listener
	std::list<simulationEventListener>* _onReplicationStartListeners = new std::list<simulationEventListener>();
	std::list<simulationEventListener>* _onReplicationStepListeners = new std::list<simulationEventListener>();
	std::list<simulationEventListener>* _onReplicationEndListeners = new std::list<simulationEventListener>();
	std::list<simulationEventListener>* _onProcessEventListeners = new std::list<simulationEventListener>();
	std::list<simulationEventListener>* _onSimulationStartListeners = new std::list<simulationEventListener>();
	std::list<simulationEventListener>* _onSimulationEndListeners = new std::list<simulationEventListener>();
private:
};

#endif /* ONEVENTMANAGER_H */

