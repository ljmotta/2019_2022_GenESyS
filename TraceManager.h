/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TraceManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 11:59
 */

#ifndef TRACEMANAGER_H
#define TRACEMANAGER_H

#include "List.h"
#include <functional>

class Model;
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

class TraceErrorEvent : public TraceEvent {
public:

    TraceErrorEvent(std::string text, std::exception e) : TraceEvent(Util::TraceLevel::errors, text) {
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

    TraceSimulationEvent(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text) : TraceEvent(tracelevel, text) {
	_time = time;
	_entity = entity;
	_component = component;
    }

    ModelComponent* getComponent() const {
	return _component;
    }

    Entity* getEntity() const {
	return _entity;
    }

    double getTime() const {
	return _time;
    }

private:
    double _time;
    Entity* _entity;
    ModelComponent* _component;
};

/*!
 * Events related to simulation "process" (usually process analyser), associated to entire replication or simulation events (begin/end/pause of replication/simulation) 
 * TODO: CLASS NOT FULLY IMPLEMENTED (to be implemented for process analyser)
 */
class TraceSimulationProcess : public TraceEvent {
public:

    TraceSimulationProcess(Util::TraceLevel tracelevel, std::string text) : TraceEvent(tracelevel, text) {
    }
};

// for handlers that are simple functions
typedef void (*traceListener)(TraceEvent);
typedef void (*traceErrorListener)(TraceErrorEvent);
typedef void (*traceSimulationListener)(TraceSimulationEvent);
typedef void (*traceSimulationProcessListener)(TraceSimulationProcess);
// for handlers that are class members (methods)
typedef std::function<void(TraceEvent) > traceListenerMethod;
typedef std::function<void(TraceErrorEvent) > traceErrorListenerMethod;
typedef std::function<void(TraceSimulationEvent) > traceSimulationListenerMethod;
typedef std::function<void(TraceSimulationProcess) > traceSimulationProcessListenerMethod;

/*!
 * The TraceManager is used to trace back model simulation information and track/debug the simulation. 
 * It works as the model simulation output (cout) and allows external methods to hook up such output as listeners.
 */
class TraceManager {
public:
    TraceManager(Simulator* simulator); //(Model* model);
    virtual ~TraceManager() = default;
public: // add trace handlers
    // for handlers that are simple functions
    void addTraceHandler(traceListener traceListener);
    void addTraceReportHandler(traceListener traceReportListener);
    void addTraceSimulationHandler(traceSimulationListener traceSimulationListener);
    void addTraceErrorHandler(traceErrorListener traceErrorListener);
    // for handlers that are class members (methods)
    template<typename Class> void addTraceHandler(Class * object, void (Class::*function)(TraceEvent));
    template<typename Class> void addTraceErrorHandler(Class * object, void (Class::*function)(TraceErrorEvent));
    template<typename Class> void addTraceReportHandler(Class * object, void (Class::*function)(TraceEvent));
    template<typename Class> void addTraceSimulationHandler(Class * object, void (Class::*function)(TraceSimulationEvent));
public: // traces (invoke trace handlers)
    void trace(Util::TraceLevel tracelevel, std::string text);
    void traceError(std::exception e, std::string text);
    void traceReport(Util::TraceLevel tracelevel, std::string text);
    void traceSimulation(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text);
public:
    List<std::string>* errorMessages() const;
    void setTraceLevel(Util::TraceLevel _traceLevel);
    Util::TraceLevel traceLevel() const;
    Simulator* parentSimulator() const;
private:
    //void _addHandler(List<traceListener>* list, )
    bool _traceConditionPassed(Util::TraceLevel level);
private: // trace listener
    // for handlers that are simple functions
    List<traceListener>* _traceHandlers = new List<traceListener>();
    List<traceErrorListener>* _traceErrorHandlers = new List<traceErrorListener>();
    List<traceListener>* _traceReportHandlers = new List<traceListener>();
    List<traceSimulationListener>* _traceSimulationHandlers = new List<traceSimulationListener>();
    // for handlers that are class members (methods)
    List<traceListenerMethod>* _traceHandlersMethod = new List<traceListenerMethod>();
    List<traceErrorListenerMethod>* _traceErrorHandlersMethod = new List<traceErrorListenerMethod>();
    List<traceListenerMethod>* _traceReportHandlersMethod = new List<traceListenerMethod>();
    List<traceSimulationListenerMethod>* _traceSimulationHandlersMethod = new List<traceSimulationListenerMethod>();
private:
    //Model* _model;
    Simulator* _simulator;
private:
    Util::TraceLevel _traceLevel; // = Util::TraceLevel::mostDetailed;
    bool _debugged;
    double _lastTimeTraceSimulation = -1.0;
    Util::identification _lastEntityTraceSimulation = 0;
    Util::identification _lastModuleTraceSimulation = 0;
    List<std::string>* _errorMessages; /* todo: 18/08/24 this is a new one. several methods should use it */

};

// implementation for template methods

template<typename Class> void TraceManager::addTraceHandler(Class * object, void (Class::*function)(TraceEvent)) {
    this->_traceHandlersMethod->insert(std::bind(function, object, std::placeholders::_1));
}

template<typename Class> void TraceManager::addTraceErrorHandler(Class * object, void (Class::*function)(TraceErrorEvent)) {
    this->_traceErrorHandlersMethod->insert(std::bind(function, object, std::placeholders::_1));
}

template<typename Class> void TraceManager::addTraceReportHandler(Class * object, void (Class::*function)(TraceEvent)) {
    this->_traceReportHandlersMethod->insert(std::bind(function, object, std::placeholders::_1));
}

template<typename Class> void TraceManager::addTraceSimulationHandler(Class * object, void (Class::*function)(TraceSimulationEvent)) {
    this->_traceSimulationHandlersMethod->insert(std::bind(function, object, std::placeholders::_1));
}

#endif /* TRACEMANAGER_H */

