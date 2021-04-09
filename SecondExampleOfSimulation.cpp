/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SecondExampleOfSimulation.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 18:59
 */

#include "SecondExampleOfSimulation.h"
#include "SinkModelComponent.h"

// you have to included need libs

// GEnSyS Simulator
#include "Simulator.h"

// Model Components
#include "plugin/Create.h"
#include "plugin/Delay.h"
#include "plugin/Dispose.h"

// Model elements
#include "EntityType.h"

SecondExampleOfSimulation::SecondExampleOfSimulation() {
}

/**
 * This is the main function of the application. 
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int SecondExampleOfSimulation::main(int argc, char** argv) {
	Simulator* simulator = new Simulator();
	// set the trace level of simulation to "blockArrival" level, which is an intermediate level of tracing
	simulator->getTracer()->setTraceLevel(Util::TraceLevel::componentArrival);
	// Handle traces and simulation events to output them
	this->setDefaultTraceHandlers(simulator->getTracer());
	// insert "fake plugins" since plugins based on dynamic loaded library are not implemented yet
	this->insertFakePluginsByHand(simulator);
	bool wantToCreateNewModelAndSaveInsteadOfJustLoad = true;
	Model* model;
	if (wantToCreateNewModelAndSaveInsteadOfJustLoad) {
		// // creates an empty model
		// model = new Model(simulator);
		// // build the simulation model
		// // set general info about the model
		// ModelInfo* infos = model->getInfos();
		// infos->setAnalystName("Your name");
		// infos->setProjectTitle("The title of the project");
		// infos->setDescription("This simulation model tests one of the most basic models possible.");
		// infos->setReplicationLength(30);
		// infos->setReplicationLengthTimeUnit(Util::TimeUnit::minute); // each replication will last 30 minutes (simulated time)
		// infos->setNumberOfReplications(3); // replicates the simulation 3 times
		// // create a (Source)ModelElement of type EntityType, used by a ModelComponent that follows
		// EntityType* entityType1 = new EntityType(model, "Type_of_Representative_Entity");
		// // model->insert(entityType1);
		// // create a ModelComponent of type Create, used to insert entities into the model
		// Create* create1 = new Create(model);
		// create1->setEntityType(entityType1);
		// create1->setTimeBetweenCreationsExpression("Expo(2)");
		// create1->setTimeUnit(Util::TimeUnit::minute);
		// create1->setEntitiesPerCreation(1);
		// // model->insert(create1);
		// // create a ModelComponent of type Delay, used to represent a time delay
		// Delay* delay1 = new Delay(model);
		// delay1->setDelayExpression("NORM(1,0.2)");
		// delay1->setDelayTimeUnit(Util::TimeUnit::minute);
		// // model->insert(delay1);
		// // create a (Sink)ModelComponent of type Dispose, used to remove entities from the model
		// Dispose* dispose1 = new Dispose(model);
		// // model->insert(dispose1);
		// // connect model components to create a "workflow"
		// create1->getNextComponents()->insert(delay1);
		// delay1->getNextComponents()->insert(dispose1);
		// // insert the model into the simulator
		// simulator->getModels()->insert(model);
		// // save the model into a text file
		// model->save("./temp/secondExampleOfSimulation.txt");
	} else {
		simulator->getModels()->loadModel("./temp/secondExampleOfSimulation.txt");
		model = simulator->getModels()->current();
	}
	// execute the simulation
	model->getSimulation()->start();

	return 0;
};

