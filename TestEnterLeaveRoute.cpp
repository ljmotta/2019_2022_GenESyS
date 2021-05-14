/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestEnterLeaveRoute.cpp
 * Author: rlcancian
 * 
 * Created on 9 de Setembro de 2019, 18:04
 */

#include "TestEnterLeaveRoute.h"
#include "ComponentManager.h"


// you have to included need libs

// GEnSyS Simulator
#include "Simulator.h"

// Model elements
#include "EntityType.h"

TestEnterLeaveRoute::TestEnterLeaveRoute() {
}

int TestEnterLeaveRoute::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	// creates an empty model
	Model* model = new Model(genesys);
	// Handle traces and simulation events to output them
	TraceManager* tm = model->getTracer();
	this->setDefaultTraceHandlers(tm);
	// set the trace level of simulation to "blockArrival" level, which is an intermediate level of tracing
	tm->setTraceLevel(Util::TraceLevel::L5_arrival);

	PluginManager* pluginManager = genesys->getPlugins();

	StaticComponentConstructor delay = pluginManager->insert("delay.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor dispose = pluginManager->insert("dispose.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor route = pluginManager->insert("route.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor enter = pluginManager->insert("enter.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor leave = pluginManager->insert("leave.so")->getPluginInfo()->GetComponentConstructor();

	StaticElementConstructor station = pluginManager->insert("station.so")->getPluginInfo()->getElementConstructor();
	// get easy access to classes used to insert components and elements into a model
	ComponentManager* components = model->getComponents();
	ElementManager* elements = model->getElements();
	//
	// build the simulation model
	//
	// set general info about the model
	ModelSimulation* sim = model->getSimulation();
	sim->setReplicationLength(30);
	sim->setNumberOfReplications(3);
	// create a (Source)ModelElement of type EntityType, used by a ModelComponent that follows
	EntityType* entityType1 = new EntityType(model, "AnyEntityType");
	elements->insert(entityType1);
	// create a ModelComponent of type Create, used to insert entities into the model
	// Create* create1 = new Create(model);
	// create1->setEntityType(entityType1);
	// create1->setTimeBetweenCreationsExpression("5.0");
	// create1->setEntitiesPerCreation(1);
	// components->insert(create1);
	// create stations to enter and route to
	Station* station1 = (Station*) station(model, "Station 1");
	Station* station2 = (Station*) station(model, "Station 2");
	Station* station3 = (Station*) station(model, "Station 3");
	elements->insert(station1);
	elements->insert(station2);
	elements->insert(station3);
	// create components to Enter into Stations
	Enter* enter1 = (Enter*) enter(model, "");
	enter1->setStation(station1);
	components->insert(enter1);
	Enter* enter2 = (Enter*) enter(model, "");
	enter2->setStation(station2);
	components->insert(enter2);
	Enter* enter3 = (Enter*) enter(model, "");
	enter3->setStation(station3);
	components->insert(enter3);
	// create components to Leave stations
	Leave* leave1 = (Leave*) leave(model, "");
	leave1->setStation(station1);
	components->insert(leave1);
	Leave* leave2 = (Leave*) leave(model, "");
	leave2->setStation(station2);
	components->insert(leave2);
	Leave* leave3 = (Leave*) leave(model, "");
	leave3->setStation(station3);
	components->insert(leave3);
	// crete route components
	Route* route0 = (Route*) route(model, "");
	route0->setStation(station1);
	route0->setRouteTimeExpression("0.5");
	components->insert(route0);
	Route* route1 = (Route*) route(model, "");
	route1->setStation(station2);
	route1->setRouteTimeExpression("0.5");
	components->insert(route1);
	Route* route2 = (Route*) route(model, "");
	route2->setStation(station3);
	route2->setRouteTimeExpression("0.5");
	components->insert(route2);
	// create delay components
	// Delay* delay1 = new Delay(model);
	// delay1->setDelayExpression("1.0");
	// components->insert(delay1);
	// Delay* delay2 = new Delay(model);
	// delay2->setDelayExpression("1.0");
	// components->insert(delay2);
	// Delay* delay3 = new Delay(model);
	// delay3->setDelayExpression("1.0");
	//components->insert(delay3);
	// create a (Sink)ModelComponent of type Dispose, used to remove entities from the model
	// Dispose* dispose1 = new Dispose(model);
	// components->insert(dispose1);
	// connect model components to create a "workflow"
	//create1->getNextComponents()->insert(route0);
	//
	//enter1->getNextComponents()->insert(delay1);
	//delay1->getNextComponents()->insert(leave1);
	leave1->getNextComponents()->insert(route1);
	//
	//enter2->getNextComponents()->insert(delay2);
	//delay2->getNextComponents()->insert(leave2);
	leave2->getNextComponents()->insert(route2);
	//
	//enter3->getNextComponents()->insert(delay3);
	//delay3->getNextComponents()->insert(leave3);
	// leave3->getNextComponents()->insert(dispose1);
	// insert the model into the simulator
	genesys->getModels()->insert(model);
	// check the model
	model->check();
	// save the model into a text file
	model->save("./temp/testEnterLeaveRoute.txt");
	// show the model
	model->show();
	// execute the simulation
	sim->start();
	return 0;
}

