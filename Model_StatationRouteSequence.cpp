/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FifthExampleOfSimulation.cpp
 * Author: rlcancian
 * 
 * Created on 12 de março de 2021, 15:39
 */

#include "Model_StatationRouteSequence.h"
#include "BaseConsoleGenesysApplication.h"
#include "Simulator.h"
#include "EntityType.h"
#include "Sequence.h"

Model_StatationRouteSequence::Model_StatationRouteSequence() {
}

int Model_StatationRouteSequence::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	
	PluginManager* pluginManager = genesys->getPlugins();
	
	StaticComponentConstructor create = pluginManager->insert("create.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor assign = pluginManager->insert("assign.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor delay = pluginManager->insert("delay.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor dispose = pluginManager->insert("dispose.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor route = pluginManager->insert("route.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor enter = pluginManager->insert("enter.so")->getPluginInfo()->GetComponentConstructor();
	StaticComponentConstructor leave = pluginManager->insert("leave.so")->getPluginInfo()->GetComponentConstructor();

	StaticElementConstructor station = pluginManager->insert("station.so")->getPluginInfo()->getElementConstructor();
	
	this->setDefaultTraceHandlers(genesys->getTracer());
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::L5_arrival);
	//genesys->getModels()->loadModel("./models/Model_StatationRouteSequence.txt");
	//genesys->getModels()->current()->getSimulation()->start();
	//return;
	Model* m = genesys->getModels()->newModel();
	m->getSimulation()->setReplicationLength(60);
	Create* c1 = (Create*) create(m, "");
	c1->setEntityType(new EntityType(m));
	c1->setTimeBetweenCreationsExpression("10");
	Station* s1 = (Station*) station(m, "");
	Route* r0 = (Route*) route(m, "");
	r0->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r0->setStation(s1);
	r0->setRouteTimeExpression("0.1");
	Enter* e1 = (Enter*) enter(m, "");
	e1->setStation(s1);
	Delay* d1 = (Delay*) delay(m, "");
	Station* s2 = (Station*) station(m, "");
	Leave* l1 = (Leave*) leave(m, "");
	l1->setStation(s1);
	Route* r1 = (Route*) route(m, "");
	r1->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r1->setStation(s2);
	r1->setRouteTimeExpression("0.2");
	Enter* e2 = (Enter*) enter(m, "");
	e2->setStation(s2);
	Delay* d2 = (Delay*) delay(m, "");
	d2->setDelayExpression("2");
	Leave* l2 = (Leave*) leave(m, "");
	l2->setStation(s2);
	Station* s3 = (Station*) station(m, "");
	Route* r2 = (Route*) route(m, "");
	r2->setRouteDestinationType(Route::DestinationType::BySequence); //(Route::DestinationType::Station);
	//r2->setStation(s3);
	r2->setRouteTimeExpression("0.3");
	Enter* e3 = (Enter*) enter(m, "");
	e3->setStation(s3);
	Dispose* dp1 = (Dispose*) dispose(m, "");

	Sequence* seq = new Sequence(m);
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s2));
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s1));
	seq->getSteps()->insert(new SequenceStep(s3));

	Assign* a1 = (Assign*) assign(m, "");
	a1->getAssignments()->insert(new Assign::Assignment("Entity.Sequence", std::to_string(seq->getId())));

	c1->getNextComponents()->insert(a1);
	a1->getNextComponents()->insert(r0);
	e1->getNextComponents()->insert(d1);
	d1->getNextComponents()->insert(l1);
	l1->getNextComponents()->insert(r1);
	e2->getNextComponents()->insert(d2);
	d2->getNextComponents()->insert(l2);
	l2->getNextComponents()->insert(r2);
	e3->getNextComponents()->insert(dp1);

	ModelSimulation* sim = m->getSimulation();
	sim->getBreakpointsOnComponent()->insert(a1);
	sim->getBreakpointsOnComponent()->insert(l2);
	sim->getBreakpointsOnTime()->insert(40.0);
	sim->getBreakpointsOnTime()->insert(20.0);
	sim->setShowReportsAfterReplication(false);
	sim->setShowReportsAfterSimulation(false);

	m->save("./models/Model_StatationRouteSequence.txt");

	do {
		sim->start();
	} while (sim->isPaused());
	return 0;
}