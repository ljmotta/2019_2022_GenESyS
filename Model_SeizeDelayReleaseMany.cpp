/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model_SeizeDelayReleaseMany.cpp
 * Author: rlcancian
 * 
 * Created on 9 de abril de 2021, 18:09
 */

#include "Model_SeizeDelayReleaseMany.h"

// you have to included need libs

// GEnSyS Simulator
#include "Simulator.h"

// Model Components
#include "Create.h"
#include "Seize.h"
#include "Delay.h"
#include "Release.h"
#include "Dispose.h"

// Model elements
#include "EntityType.h"

Model_SeizeDelayReleaseMany::Model_SeizeDelayReleaseMany() {
}

/**
 * This is the main function of the application.
 * It instanciates the simulator, builds a simulation model and then simulate that model.
 */
int Model_SeizeDelayReleaseMany::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::everythingMostDetailed);
	this->insertFakePluginsByHand(genesys);
	Model* m = genesys->getModels()->newModel();
	m->getInfos()->setReplicationLength(20);
	EntityType* customer = new EntityType(m);
	Create* create1 = new Create(m);
	create1->setEntityType(customer);
	Resource* machine1 = new Resource(m);
	Resource* machine2 = new Resource(m);
	Resource* machine3 = new Resource(m);
	Resource* machine4 = new Resource(m);
	Queue* queueSeize1 = new Queue(m);
	queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize1 = new Seize(m);
	seize1->getSeizeRequest()->insert(new ResourceItemRequest(machine1));
	seize1->getSeizeRequest()->insert(new ResourceItemRequest(machine2));
	seize1->getSeizeRequest()->insert(new ResourceItemRequest(machine3));
	seize1->getSeizeRequest()->insert(new ResourceItemRequest(machine4));
	seize1->setQueue(queueSeize1);
	Delay* delay1 = new Delay(m);
	Release* release1 = new Release(m);
	release1->setReleaseRequest(new ResourceItemRequest(machine1));
	Dispose* dispose1 = new Dispose(m);
	// connect model components to create a "workflow"
	create1->getNextComponents()->insert(seize1);
	seize1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(release1);
	release1->getNextComponents()->insert(dispose1);
	// save the model into a text file
	m->save("./models/Model_SeizeDelayReleaseMany.txt");
	genesys->getModels()->current()->getSimulation()->start();
	return 0;
};
