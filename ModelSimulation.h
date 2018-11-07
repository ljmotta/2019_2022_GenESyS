/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelSimulation.h
 * Author: cancian
 *
 * Created on 7 de Novembro de 2018, 18:04
 */

#ifndef MODELSIMULATION_H
#define MODELSIMULATION_H

#include "Event.h"
#include "Entity.h"
#include "ModelInfo.h"

class Model;

class ModelSimulation {
public:
	ModelSimulation(Model* model);
	ModelSimulation(const ModelSimulation& orig);
	virtual ~ModelSimulation();
public: // simulation control
	void startSimulation(); /*! Starts a sequential execution of a simulation, ie, a set of repliations of this model*/
	void pauseSimulation();
	void stepSimulation(); /*! Executes the processing of a single event, the next one in the future events list */
	void stopSimulation();
	void restartSimulation();
public:
	void setPauseOnEvent(bool _pauseOnEvent);
	bool isPauseOnEvent() const;
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

private: // simulation control
	void _initSimulation();
	void _initReplication();
	void _stepSimulation();
	void _processEvent(Event* event);
	void _showReplicationStatistics();
	void _showSimulationStatistics();
private:
	bool _finishReplicationCondition();

private:
	double _simulatedTime = 0.0;
	// list of double double _breakOnTimes;
	// list of modules _breakOnModules;
	bool _stepByStep = false;
	bool _pauseOnReplication = false;
	bool _pauseOnEvent = false;
	bool _initializeStatisticsBetweenReplications = true;
	bool _initializeSystem = true;
	bool _running = false;
	bool _pauseRequested = false;
	bool _stopRequested = false;
	bool _simulationIsInitiated = false;
	bool _replicationIsInitiaded = false;
private:
	Entity* _currentEntity;
	ModelComponent* _currentComponent;
	unsigned int _currentReplicationNumber;
private:
	Model* _model;
	ModelInfo* _info;
};

#endif /* MODELSIMULATION_H */

