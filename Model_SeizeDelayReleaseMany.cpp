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
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L7_detailed);

	PluginManager* pluginManager = genesys->getPlugins();
	
	StaticComponentConstructor create = pluginManager->insert("create.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor seize = pluginManager->insert("seize.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor delay = pluginManager->insert("delay.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor release = pluginManager->insert("release.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor dispose = pluginManager->insert("dispose.so")->getPluginInfo()->GetComponentConstructor();

	StaticElementConstructor queue = pluginManager->insert("queue.so")->getPluginInfo()->getElementConstructor();
	StaticElementConstructor resource = pluginManager->insert("resource.so")->getPluginInfo()->getElementConstructor();

	Model* m = genesys->getModels()->newModel();
	//m->load("./models/Model_SeizeDelayReleaseMany.txt");
	//genesys->getModels()->current()->getSimulation()->start();
	//return 0;

	EntityType* customer = new EntityType(m);
	Create* create1 = (Create*) create(m, "");
	create1->setEntityType(customer);
	create1->setTimeBetweenCreationsExpression("unif(1,2)");
	Resource* machine1 = (Resource*) resource(m, "");
	Resource* machine2 = (Resource*) resource(m, "");
	Resource* machine3 = (Resource*) resource(m, "");
	Resource* machine4 = (Resource*) resource(m, "");
	Queue* queueSeize1 = (Queue*) queue(m, "");
	queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
	Seize* seize1 = (Seize*) seize(m, "");
	seize1->getSeizeRequests()->insert(new SeizableItemRequest(machine1));
	seize1->getSeizeRequests()->insert(new SeizableItemRequest(machine2));
	seize1->getSeizeRequests()->insert(new SeizableItemRequest(machine3));
	seize1->getSeizeRequests()->insert(new SeizableItemRequest(machine4));
	seize1->setQueue(queueSeize1);
	Delay* delay1 = (Delay*) delay(m, "");
	delay1->setDelayExpression("unif(1,2)");
	Release* release1 = (Release*) release(m, "");
	release1->getReleaseRequests()->insert(new SeizableItemRequest(machine1));
	release1->getReleaseRequests()->insert(new SeizableItemRequest(machine2));
	release1->getReleaseRequests()->insert(new SeizableItemRequest(machine3));
	release1->getReleaseRequests()->insert(new SeizableItemRequest(machine4));
	Dispose* dispose1 = (Dispose*) dispose(m, "");
	// connect model components to create a "workflow"
	create1->getNextComponents()->insert(seize1);
	seize1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(release1);
	release1->getNextComponents()->insert(dispose1);
	// save the model into a text file
	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(30);
	sim->setNumberOfReplications(3);
	m->save("./models/Model_SeizeDelayReleaseMany.txt");
	genesys->getModels()->current()->getSimulation()->start();
	return 0;
};
