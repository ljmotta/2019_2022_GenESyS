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
#include "List.cpp"  // tell the compiler where is the implementation of the template class and avoid link error 


using namespace std;

void traceHandler(TraceEvent e) {
	std::cout << e.getText() << std::endl;
}

void traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.getText() << std::endl;
}

void buildSimpleCreateDelayDisposeModel(Model* model) {
	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);
	// create and insert model components
	ModelComponent* create1 = new Create(model);
	ModelComponent* delay1 = new Delay(model);
	ModelComponent* dispose1 = new Dispose(model);
	List<ModelComponent*>* components = model->getComponents();
	components->insert(create1);
	components->insert(delay1);
	components->insert(dispose1);
	// connect model components
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
}

/*
 * 
 */
int main(int argc, char** argv) {
	buildSimulationSystem();
	return 0;
}

