/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

using namespace std;


#include "BuildSimpleModel1.h"

// GEnSyS Simulator
#include "Simulator.h"

// Configuration
#include "Traits.h"


// Model Components
#include "Create.h"
#include "Delay.h"
#include "Dispose.h"
#include "Seize.h"
#include "Release.h"
#include "Assign.h"

void traceHandler(TraceEvent e) {
	std::cout << e.getText() << std::endl;
}

void traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.getText() << std::endl;
}

void onReplicationStartHandler(ReplicationEvent* re) {
	std::cout << "Replication " << re->getReplicationNumber() << " starting.";
}

void onReplicationEndHandler(ReplicationEvent* re) {
	std::cout << "Replication " << re->getReplicationNumber() << " ending.";
}

/*
void buildSimpleCreateDelayDisposeModel(Model* model) {
	// traces handle simulation events to output them
	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);

	// create and insert model components to the model
	Create* create1 = new Create(model);
	create1->setTimeBetweenCreationsExpression("1.5");
	create1->setTimeUnit(Util::TimeUnit::minute);
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
 */

void buildModel(Model* model) { // buildModelWithAllImplementedComponents
	// traces handle simulation events to output them
	model->addTraceListener(&traceHandler);
	model->addTraceReportListener(&traceHandler);
	model->addTraceSimulationListener(&traceSimulationHandler);

	model->addOnReplicationStartListener(&onReplicationStartHandler);
	model->addOnReplicationEndListener(&onReplicationEndHandler);

	// create and insert model components to the model
	Create* create1 = new Create(model);
	create1->setTimeBetweenCreationsExpression("1.5");
	create1->setTimeUnit(Util::TimeUnit::minute);

	Assign* assign1 = new Assign(model);
	Assign::Assignment* attrib1Assignment = new Assign::Assignment(Assign::DestinationType::Attribute, "Attribute 1", "Variable 1");
	assign1->getAssignments()->insert(attrib1Assignment);
	Assign::Assignment* attrib2Assignment = new Assign::Assignment(Assign::DestinationType::Variable, "Variable 1", "Variable 1 + 1");
	assign1->getAssignments()->insert(attrib2Assignment);

	Seize* seize1 = new Seize(model);
	seize1->setResourceName("Máquina 1");

	Delay* delay1 = new Delay(model);
	delay1->setDelayExpression("30");

	Release* release1 = new Release(model);
	release1->setResourceName("Máquina 1");
	release1->setQueueName(seize1->getQueueName());

	Dispose* dispose1 = new Dispose(model);

	// add the components to the model
	List<ModelComponent*>* components = model->getComponents();
	components->insert(create1);
	components->insert(assign1);
	components->insert(seize1);
	components->insert(delay1);
	components->insert(release1);
	components->insert(dispose1);

	// connect model components to create a "workflow" -- should always start from a SourceModelComponent and end at a SinkModelComponent (it will be checked)
	create1->getNextComponents()->insert(assign1);
	assign1->getNextComponents()->insert(seize1);
	seize1->getNextComponents()->insert(delay1);
	delay1->getNextComponents()->insert(release1);
	release1->getNextComponents()->insert(dispose1);
}


void buildSimulationSystem() {
	Simulator* simulator = new Simulator();
	Model* model = new Model(simulator);
	buildModel(model);
	simulator->getModels()->insert(model);
	if (model->checkModel()) {
		model->saveModel("./genesysmodel.txt");
		model->startSimulation();
	}
}

BuildSimpleModel1::BuildSimpleModel1() {

}

int BuildSimpleModel1::main(int argc, char** argv) {
	buildSimulationSystem();
};
