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

void buildSimulationSystem() {
	//OldObserver* traceObserver = new OldObserver();

	Simulator* simulator = new Simulator();
	Model* model = new Model(simulator);

	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);

	simulator->getModels()->insert(model);
	ModelComponent* create1 = new Create();
	ModelComponent* delay1 = new Delay();
	ModelComponent* dispose1 = new Dispose();
	List<ModelComponent*>* components = model->getComponents();
	components->insert(create1);
	components->insert(delay1);
	components->insert(dispose1);
	create1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(dispose1);
	model->startSimulation();
}

/*
 * 
 */
int main(int argc, char** argv) {
	buildSimulationSystem();
	return 0;
}

