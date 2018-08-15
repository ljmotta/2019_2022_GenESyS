/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 12:47
 */

#include <cstdlib>
#include <iostream>
#include "Simulator.h"
#include "Create.h"
#include "Delay.h"
#include "Listener.h"
#include "Dispose.h"


using namespace std;

void traceHandler(TraceEvent e) {
	std::cout << e.getText() << std::endl;
}

void traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.getText() << std::endl;
}

void buildSimpleCreateDelayDisposeModel(Model* model) {
	// traces handle simulation events to output them
	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);
	// create and insert model components to the model
	
	Create* create1 = new Create(model);
	create1->setTimeBetweenCreationsExpression("1.5");
	create1->setTimeUnit(Util::TimeUnit::TU_minute);
	Delay* delay1 = new Delay(model);
	delay1->setDelayExpression("30");
	Dispose* dispose1 = new Dispose(model);
	List<ModelComponent*>* components = model->getComponents();
	components->insert(create1);
	components->insert(delay1);
	components->insert(dispose1);
	// connect model components to create a "workflow"
	// should always start from a SourceModelComponent and end at a SinkModelComponent (it will be checked)
	create1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(dispose1);	
}

void buildModel(Model* model) {
	// change next command to build different models
	buildSimpleCreateDelayDisposeModel(model);
}

void buildSimulationSystem() {
	//OldObserver* traceObserver = new OldObserver();
	Simulator* simulator = new Simulator();
	Model* model = 	new Model(simulator);
	buildModel(model);
	simulator->getModels()->insert(model);
	model->startSimulation();
	model->showReports();
}

/*
 * 
 */
int main(int argc, char** argv) {
	buildSimulationSystem();
	return 0;
}

