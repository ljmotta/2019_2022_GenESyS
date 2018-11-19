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

#include <string>

#include "List.h"
#include "ModelComponent.h"
#include "Event.h"
#include "ModelChecker_if.h"
#include "Parser_if.h"
#include "ModelPersistence_if.h"
#include "InfrastructureManager.h"
#include "TraceManager.h"
#include "OnEventManager.h"
#include "ModelInfo.h"
#include "ModelSimulation.h"
//for PAN
#include "SimulationResponse.h"
#include "SimulationControl.h"

class Simulator;

/*!
 * Model is probably the most important class of Genesys kernel. It represents a discrete event-driven simulation model. Each model is responsible for controlling its own simulation, ie, for sequentially processing events and collecting statistical results. A model is mainly represented by a collection of components (ModelComponent), adequately configurated and connected, and a collection of under layered infrastructure (ModelInfrastructure). 
 */
class Model {
public:
	Model(Simulator* simulator);
	Model(const Model& orig);
	virtual ~Model();
public: // model control
	void showReports();
	bool saveModel(std::string filename); /*!  */
	bool loadModel(std::string filename);
	bool checkModel(); /*! Checks the integrity and consistency of the model, possibly corrects some inconsistencies, and returns if the model is in position to the simulated. */
	bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory); /*! Verifies if a symbol defined in a component (ModelComponent) or infrastructure is syntactically valid and addresses existing components or infrastructures. It's used only by and directed by the component that defines the symbol. */
	void removeEntity(Entity* entity, bool collectStatistics);
	void sendEntityToComponent(Entity* entity, ModelComponent* component, double timeDelay); /*! Used by components (ModelComponent) to send entities to another specific component, usually the next one connected to it, or used by the model itself, when processing an event (Event). */
	double parseExpression(const std::string expression);
	double parseExpression(const std::string expression, bool* success, std::string* errorMessage);

public: // only gets	
	Util::identitifcation getId() const;
	// 1:1
	List<SimulationControl*>* getControls() const;
	List<SimulationResponse*>* getResponses() const;
	TraceManager* getTracer() const;
	OnEventManager* getOnEventManager() const;
	InfrastructureManager* getInfraManager() const;
	ModelInfo* getInfos() const;
	Simulator* getParent() const;
	ModelSimulation* getSimulation() const;
	// 1:n
	List<ModelComponent*>* getComponents() const; /*! A list of components that compose this model */
	List<Event*>* getEvents() const; /*! The future events list chronologically sorted; Events are scheduled by components when processing other events, and a replication evolves over time by sequentially processing the very first event in this list. It's initialized with events first described by source components (SourceComponentModel) */
	//List<Entity*>* getEntities() const;

	/*
	 * PRIVATE
	 */
private:
	void _showComponents();

private: // read only public access (gets)
	Util::identitifcation _id;
	Simulator* _parentSimulator; /*! The parente of the model */
	// 1:1 (associted classes)
	TraceManager* _trace;
	OnEventManager* _eventHandler;
	InfrastructureManager* _infrastructureManager;
	ModelInfo* _infos;
	ModelSimulation* _simulation;  
	// 1:n
	List<ModelComponent*>* _components;
	List<Event*>* _events;
	// for process analyser
	List<SimulationResponse*>* _responses;
	List<SimulationControl*>* _controls;

private: // no public access (no gets / sets)	
	ModelChecker_if* _modelChecker;
	ModelPersistence_if* _modelPersistence;
	Parser_if* _parser;
};

#endif /* SIMULATIONMODEL_H */

