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
#include "Listener.h"
#include "Traits.h"

// Simulator objects
#include "Sampler_if.h" // old MMC
#include "Fitter_if.h"

// Tools and Utils
#include "Collector_if.h"
#include "CollectorDatafile_if.h"
#include "Statistics_if.h"
#include "Integrator_if.h"
#include "HypothesisTester_if.h"
#include "ProbDistrib.h"
#include "Sampler_if.h"

// Model Components
#include "Create.h"
#include "Delay.h"
#include "Dispose.h"
#include "Seize.h"
#include "Release.h"
#include "Assign.h"


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

void buildModelWithAllImplementedComponents(Model* model) {
	// traces handle simulation events to output them
	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);
	// create and insert model components to the model

	Create* create1 = new Create(model);
	create1->setTimeBetweenCreationsExpression("1.5");
	create1->setTimeUnit(Util::TimeUnit::TU_minute);
	
	Assign* assign1 = new Assign(model);

	Seize* seize1 = new Seize(model);
	seize1->setResourceName("Máquina 1");

	Delay* delay1 = new Delay(model);
	delay1->setDelayExpression("30");

	Release* release1 = new Release(model);
	release1->setResourceName("Máquina 1");
	release1->setQueueName(seize1->getQueueName());

	Dispose* dispose1 = new Dispose(model);

	List<ModelComponent*>* components = model->getComponents();
	components->insert(create1);
	components->insert(assign1);
	components->insert(seize1);
	components->insert(delay1);
	components->insert(release1);
	components->insert(dispose1);
	// connect model components to create a "workflow"
	// should always start from a SourceModelComponent and end at a SinkModelComponent (it will be checked)
	create1->getNextComponents()->insert(assign1);
	assign1->getNextComponents()->insert(seize1);
	seize1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(release1);
	release1->getNextComponents()->insert(dispose1);
}

void buildModel(Model* model) {
	// change next command to build different models
	//buildSimpleCreateDelayDisposeModel(model);
	buildModelWithAllImplementedComponents(model);
}

void buildSimulationSystem() {
	Simulator* simulator = new Simulator();
	Model* model = new Model(simulator);
	buildModel(model);
	simulator->getModels()->insert(model);
	if (model->checkModel()) {
		model->saveModel("./genesysmodel.txt");
		model->startSimulation();
		model->showReports();
	}
}

void testStudentSoftwareDevelopments() {
	Simulator* simulator = new Simulator();
	Sampler_if* mmc = simulator->getSampler(); // Sampler is the new MMC
	CollectorDatafile_if* collector = new Traits<Collector_if>::Implementation();
	collector->setDataFilename("./datafile.txt");
	// just to show how to change MMC parameters
	Traits<Sampler_if>::Parameters*  parameters = (Traits<Sampler_if>::Parameters*) mmc->getRNGparameters(); 
	parameters->module = 2147483648;
	parameters->multiplier = 1103515245;
	parameters->seed = 1234;
	mmc->setRNGparameters(parameters);

	// generate a datafile with a thousand values that should be normal distributed == NORM(5000,350)
	double value;
	for (unsigned int i = 0; i < 1e3; i++) {
		value = mmc->sampleNormal(5000, 350);
		collector->addValue(value);
	}

	// generate statistics about that datafile 
	Statistics_if* statistics = new Traits<Statistics_if>::Implementation();
	statistics->setCollector(collector); //setDataFilename(collector->getDataFilename());
	double statVal;
	statVal = statistics->numElements();
	statVal = statistics->average();
	statVal = statistics->stddeviation();
	statVal = statistics->halfWidthConfidenceInterval(0.05);
	statVal = statistics->quartil(2);
	statVal = statistics->mediane();
	unsigned int numclasses = statistics->histogramNumClasses();
	for (unsigned int i = 0; i < numclasses; i++) {
		statVal = statistics->histogramClassFrequency(i);
	}

	// fit datafile to different probability distributions
	Fitter_if* fitter = simulator->getFitter();
	fitter->setDataFilename(collector->getDataFilename());
	double sqrerror, p1, p2, p3, p4;
	std::string distribName;
	bool res;
	res = fitter->isNormalDistributed(0.95);
	fitter->fitUniform(&sqrerror, &p1, &p2);
	fitter->fitTriangular(&sqrerror, &p1, &p2, &p3);
	fitter->fitNormal(&sqrerror, &p1, &p2);
	fitter->fitAll(&sqrerror, &distribName);

	// get some values from the PDF (Probability Density Functions)
	value = ProbDistrib::uniform(0.25, 0.0, 1.0);
	value = ProbDistrib::uniform(0.5, 0.0, 1.0); // should return the same value than above
	value = ProbDistrib::uniform(0.75, 0.0, 1.0); // should return the same value than above
	value = ProbDistrib::normal(10.0, 50.0, 20.0);
	value = ProbDistrib::normal(30.0, 50.0, 20.0); // should return a greater value than above
	value = ProbDistrib::normal(50.0, 50.0, 20.0); // should return a greater value than above

	// calculate some integrals just for fun
	Integrator_if* integrator = new Traits<Integrator_if>::Implementation();
	value = integrator->integrate(0.0, 0.4, &ProbDistrib::uniform, 0.0, 0.1); // should return 0.4
	value = integrator->integrate(0.0, 100, &ProbDistrib::normal, 100, 10); // should return 0.5
	
	// Test some hypothesis about the datafile
	HypothesisTester_if* tester = new Traits<HypothesisTester_if>::Implementation();
	tester->setDataFilename(collector->getDataFilename());
	res = tester->testAverage(0.95, 5500, HypothesisTester_if::GREATER_THAN);
	res = tester->testAverage(0.95, 4500, HypothesisTester_if::LESS_THAN);
	res = tester->testAverage(0.95, 3000, HypothesisTester_if::EQUAL);
	res = tester->testAverage(0.95, 5000, HypothesisTester_if::EQUAL);
	res = tester->testAverage(0.95, 5100, HypothesisTester_if::DIFFERENT);
	res = tester->testVariance(0.95, 350*350, HypothesisTester_if::EQUAL);
	res = tester->testVariance(0.95, 350*350, HypothesisTester_if::LESS_THAN);

}

/*
 * 
 */
int main(int argc, char** argv) {
	// uncomment bellow to execute a simulation
	buildSimulationSystem();
	
	// uncomment bellow to test Software Development (DS) implementations
	//testStudentSoftwareDevelopments();
	
	return 0;
}

