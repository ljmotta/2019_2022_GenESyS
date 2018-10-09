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

/*!
 * Model is probably the most important class of Genesys kernel. It represents a discrete event-driven simulation model. Each model is responsible for controlling its own simulation, ie, for sequentially processing events and collecting statistical results. A model is mainly represented by a collection of components (ModelComponent), adequately configurated and connected, and a collection of under layered infrastructure (ModelInfrastructure). 
 */
class Model {
public:
	Model(Simulator* simulator);
	Model(const Model& orig);
	virtual ~Model();
public: // simulation control
	void startSimulation(); /*! Starts a sequential execution of a simulation, ie, a set of repliations of this model*/
	void pauseSimulation();
	void stepSimulation(); /*! Executes the processing of a single event, the next one in the future events list */
	void stopSimulation();
	void restartSimulation();
	void showReports();
	void setPauseOnEvent(bool _pauseOnEvent);
	bool isPauseOnEvent() const;
public: // model control
	bool saveModel(std::string filename); /*!  */
	bool loadModel(std::string filename);
	bool checkModel(); /*! Checks the integrity and consistency of the model, possibly corrects some inconsistencies, and returns if the model is in position to the simulated. */
	bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory); /*! Verifies if a symbol defined in a component (ModelComponent) or infrastructure is syntactically valid and addresses existing components or infrastructures. It's used only by and directed by the component that defines the symbol. */
	void removeEntity(Entity* entity, bool collectStatistics);
	void sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay); /*! Used by components (ModelComponent) to send entities to another specific component, usually the next one connected to it, or used by the model itself, when processing an event (Event). */
	double parseExpression(const std::string expression);
	double parseExpression(const std::string expression,  bool* success, std::string* errorMessage);
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
	double getSimulatedTime() const; /*! The current time in the model being simulated, i.e., the instant when the current event was triggered */
	bool isRunning() const;
	bool isSaved() const;
	Util::identitifcation getId() const;
	List<ModelComponent*>* getComponents() const; /*! A list of components that compose this model */
	List<Event*>* getEvents() const;  /*! The future events list chronologically sorted; Events are scheduled by components when processing other events, and a replication evolves over time by sequentially processing the very first event in this list. It's initialized with events first described by source components (SourceComponentModel) */
	List<Entity*>* getEntities() const;
	List<ModelInfrastructure*>* getInfrastructures(std::string infraTypename) const;
	ModelInfrastructure* getInfrastructure(std::string infraTypename, Util::identitifcation id);
	ModelInfrastructure* getInfrastructure(std::string infraTypename, std::string name);
	std::list<std::string>* getInfrastructureTypenames() const;
/*
 
 */	
private: // simulation control
	void _initSimulation();
	void _initReplication();
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
	Entity* _currentEntity;
	ModelComponent* _currentComponent;
	unsigned int _currentReplicationNumber;
	Parser_if* _parser;
	ModelChecker_if* _modelChecker;
	ModelPersistence_if* _modelPersistence;
};

#endif /* SIMULATIONMODEL_H */

