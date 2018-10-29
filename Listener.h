/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Listener.h
 * Author: cancian
 *
 * Created on 22 de Junho de 2018, 18:53
 */

#ifndef LISTENER_H
#define LISTENER_H

#include <string>

#include "Util.h"

class Entity;
class ModelComponent;

class TraceEvent {
public:
	TraceEvent(Util::TraceLevel tracelevel, std::string text) {
		_tracelevel = tracelevel;
		_text = text;
	}
	Util::TraceLevel getTracelevel() const {
		return _tracelevel;
	}
	std::string getText() const {
		return _text;
	}
private:
	Util::TraceLevel _tracelevel;
	std::string _text;
};

class TraceErrorEvent: public TraceEvent {
public:
	TraceErrorEvent(std::string text,std::exception e): TraceEvent(Util::TraceLevel::errors, text) {
		_e = e;
	}

    std::exception getException() const {
    	return _e;
    }
private:
	std::exception _e;
};

class TraceSimulationEvent : public TraceEvent {
public:
	ModelComponent* getComponent() const {
		return _component;
	}
	Entity* getEntity() const {
		return _entity;
	}
	double getTime() const {
		return _time;
	}
	TraceSimulationEvent(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text) : TraceEvent(tracelevel, text) {
		_time = time;
		_entity = entity;
		_component = component;
	}
private:
	double _time;
	Entity* _entity;
	ModelComponent* _component;
};

/*!
 * Events related to simulation "process" (usually process analyser), associated to entire replication or simulation events (begin/end/pause of replication/simulation) 
 * TODO: CLASS NOT COMPLETE
 */
class TraceSimulationProcess : public TraceEvent {
public:
	TraceSimulationProcess(Util::TraceLevel tracelevel, std::string text):TraceEvent(tracelevel, text) {
	}
};

typedef void (*traceListener)(TraceEvent);
typedef void (*traceErrorListener)(TraceErrorEvent);
typedef void (*traceSimulationListener)(TraceSimulationEvent);
typedef void (*traceSimulationProcessListener)(TraceSimulationProcess);

/* TODO: To implement as item (1) for DS3
 * used to get and set values no matter the class (for process analyser)
 * should be a wait to invoke a getter or setter no matter the class (a pointer to a member function without specifying the class 
 */
typedef double (*memberFunctionGetDoubleVarHandler)(); //template<> ... typedef double (T::*getDoubleVarHandler)() or something like that
typedef void (*memberFunctionSetDoubleVarHandler)(double); 


class ReplicationEvent {
public:
unsigned int getReplicationNumber() const {
	return _replicationNumber;
	}
private:
	unsigned int _replicationNumber;
};

typedef void (*replicationEventListener)(ReplicationEvent*);

#endif /* LISTENER_H */

