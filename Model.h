/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationModel.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 15:01
 */

#ifndef SIMULATIONMODEL_H
#define SIMULATIONMODEL_H

#include "Util.h"
#include <string>
#include "List.h"
#include "ModelComponent.h"
#include "ModelInfrastructure.h"
#include "Event.h"
#include "Listener.h"
#include "ModelChecker_if.h"
#include "Parser_if.h"
#include "ModelPersistence_if.h"

class Simulator;

class Model {
public:
	Model(Simulator* simulator);
	Model(const Model& orig);
	virtual ~Model();
public: // simulation control
	void startSimulation();
	void pauseSimulation();
	void stepSimulation();
	void stopSimulation();
	void restartSimulation();
	void showReports();
	void setPauseOnEvent(bool _pauseOnEvent);
	bool isPauseOnEvent() const;
public: // model control
	bool saveModel(std::string filename);
	bool loadModel(std::string filename);
	bool checkModel();
	bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory); 
	void removeEntity(Entity* entity, bool collectStatistics);
	void sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay);
	double parseExpression(const std::string expression);
public: // traces
	void addTraceListener(traceListener traceListener);
	void addTraceErrorListener(traceErrorListener traceErrorListener);
	void addTraceReportListener(traceListener traceReportListener);
	//void addTraceSimulationListener(traceListener traceListener);
	void addTraceSimulationListener(traceSimulationListener traceSimulationListener);
	void trace(Util::TraceLevel tracelevel, std::string text);
	void traceError(std::exception e, std::string text);
	//void traceSimulation(Util::TraceLevel tracelevel, std::string text);
	void traceSimulation(Util::TraceLevel tracelevel, double time, Entity* entity, ModelComponent* component, std::string text);
	void traceReport(Util::TraceLevel tracelevel, std::string text);
	List<std::string>* getErrorMessages() const;
public: // gets and sets
	void setName(std::string _name);
	std::string getName() const;
	void setAnalystName(std::string _analystName);
	std::string getAnalystName() const;
	void setDescription(std::string _description);
	std::string getDescription() const;
	void setProjectTitle(std::string _projectTitle);
	std::string getProjectTitle() const;
	void setVersion(std::string _version);
	std::string getVersion() const;
	void setNumberOfReplications(unsigned int _numberOfReplications);
	unsigned int getNumberOfReplications() const;
	void setReplicationLength(double _replicationLength);
	double getReplicationLength() const;
	void setReplicationLengthTimeUnit(Util::TimeUnit _replicationLengthTimeUnit);
	Util::TimeUnit getReplicationLengthTimeUnit() const;
	void setWarmUpPeriod(double _warmUpPeriod);
	double getWarmUpPeriod() const;
	void setWarmUpPeriodTimeUnit(Util::TimeUnit _warmUpPeriodTimeUnit);
	Util::TimeUnit getWarmUpPeriodTimeUnit() const;
	void setTerminatingCondition(std::string _terminatingCondition);
	std::string getTerminatingCondition() const;
	void setTraceLevel(Util::TraceLevel _traceLevel);
	Util::TraceLevel getTraceLevel() const;
	void setStepByStep(bool _stepByStep);
	bool isStepByStep() const;
	void setInitializeStatistics(bool _initializeStatistics);
	bool isInitializeStatistics() const;
	void setInitializeSystem(bool _initializeSystem);
	bool isInitializeSystem() const;
	void setPauseOnReplication(bool _pauseBetweenReplications);
	bool isPauseOnReplication() const;
public: // only gets	
	double getSimulatedTime() const; // TNOW
	bool isRunning() const;
	bool isSaved() const;
	Util::identitifcation getId() const;
	List<ModelComponent*>* getComponents() const;
	List<Event*>* getEvents() const;
	List<Entity*>* getEntities() const;
	List<ModelInfrastructure*>* getInfrastructures(std::string infraTypename) const;
	ModelInfrastructure* getInfrastructure(std::string infraTypename, Util::identitifcation id);
	ModelInfrastructure* getInfrastructure(std::string infraTypename, std::string name);
private: // simulation control
	void _initSimulation();
	void _initReplication(unsigned int currentReplicationNumber);
	void _stepSimulation();
	void _processEvent(Event* event);
	void _showReplicationStatistics();
	void _showSimulationStatistics();
private:
	bool _finishReplicationCondition();
	void _showModel();
	void _showInfrastructures();
private:
	std::list<traceListener>* _traceListeners = new std::list<traceListener>();
	std::list<traceErrorListener>* _traceErrorListeners = new std::list<traceErrorListener>();
	std::list<traceListener>* _traceReportListeners = new std::list<traceListener>();
	std::list<traceSimulationListener>* _traceSimulationListeners = new std::list<traceSimulationListener>();
private: // with public access (get & set)
	// model general information
	std::string _name;
	std::string _analystName = "";
	std::string _description = "";
	std::string _projectTitle = "";
	std::string _version = "1.0";

	// replication and warmup duration
	unsigned int _numberOfReplications = 1;
	double _replicationLength = 3600.0; // by default, 3600 s
	Util::TimeUnit _replicationLengthTimeUnit = Util::TimeUnit::TU_second;
	double _warmUpPeriod = 0.0;
	Util::TimeUnit _warmUpPeriodTimeUnit = Util::TimeUnit::TU_second;
	std::string _terminatingCondition = "";

	// debug and statistics
	Util::TraceLevel _traceLevel = Util::TraceLevel::TL_mostDetailed;
	// list of double double _breakOnTimes;
	// list of modules _breakOnModules;
	bool _stepByStep = false;
	bool _pauseOnReplication = false;
	bool _pauseOnEvent = false;
	bool _initializeStatisticsBetweenReplications = true;
	bool _initializeSystem = true;

	// 
	bool _checked = false;

private: // read only public access (gets)
	Util::identitifcation _id;
	double _simulatedTime = 1.0;
	bool _running = false;
	bool _saved = false;
	// 1:n
	List<std::string>* _errorMessages; /* todo: 18/08/24 this is a new one. several methods should use it */
	List<ModelComponent*>* _components;
	List<Event*>* _events;
	// infrastructures
	std::map<std::string, List<ModelInfrastructure*>*>* _infrastructures;

private: // no public access (no gets / sets)	
	Simulator* _simulator;
	bool _pauseRequested = false;
	bool _stopRequested = false;
	bool _simulationIsInitiated = false;
	bool _replicationIsInitiaded = false;
	std::exception* _excepcionHandled = nullptr;
	double _lastTimeTraceSimulation = -1.0;
	Util::identitifcation _lastEntityTraceSimulation = 0;
	Util::identitifcation _lastModuleTraceSimulation = 0;
	// needed?
	Entity* _currentEntity;
	ModelComponent* _currentComponent;
	Parser_if* _parser;
	ModelChecker_if* _modelChecker;
	ModelPersistence_if* _modelPersistence;
};

#endif /* SIMULATIONMODEL_H */

