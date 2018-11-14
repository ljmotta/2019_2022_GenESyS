/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

using namespace std;


#include "BuildSimulationModel.h"

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
#include "ModelSimulation.h"

void traceHandler(TraceEvent e) {
	std::cout << e.getText() << std::endl;
}

void traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.getText() << std::endl;
}

void onReplicationStartHandler(SimulationEvent* re) {
	//std::cout << "(Handler) Replication " << re->getReplicationNumber() << " starting." << std::endl;
}

void onProcessEventHandler(SimulationEvent* re) {
	//std::cout << "(Handler) Processing event " << re->getEventProcessed()->show()  << std::endl;
}

void onReplicationEndHandler(SimulationEvent* re) {
	//std::cout << "(Handler) Replication " << re->getReplicationNumber() << " ending." << std::endl;
}

void onEntityRemoveHandler(SimulationEvent* re) {
	//std::cout << "(Handler) Entity " << re->getEntity() << " was removed." << std::endl;
}

void buildModel(Model* model) { // buildModelWithAllImplementedComponents
	// traces handle and simulation events to output them
	TraceManager* tm = model->getTracer(); 
	tm->addTraceListener(&traceHandler);
	tm->addTraceReportListener(&traceHandler);
	tm->addTraceSimulationListener(&traceSimulationHandler);

	OnEventManager* ev = model->getOnEventManager();
	ev->addOnReplicationStartListener(&onReplicationStartHandler);
	ev->addOnReplicationEndListener(&onReplicationEndHandler);
	ev->addOnProcessEventListener(&onProcessEventHandler);

	ModelInfo* infos = model->getInfos();
	infos->setAnalystName("Rafael Cancian");
	infos->setProjectTitle("Projeto de simulação orientada a eventos de qualquer coisa simulável");
	infos->setDescription("Esse é um modelo de teste dos componentes já implementados");
	infos->setNumberOfReplications(2);
	infos->setReplicationLength(60);
	infos->setReplicationLengthTimeUnit(Util::TimeUnit::minute);
	
	// create and insert model components to the model
	Create* create1 = new Create(model);
	create1->setTimeBetweenCreationsExpression("NORM(5,1)");
	create1->setTimeUnit(Util::TimeUnit::minute);
	create1->setEntitiesPerCreation(1);
	
	Assign* assign1 = new Assign(model);
	Assign::Assignment* attrib1Assignment = new Assign::Assignment(Assign::DestinationType::Attribute, "Attribute 1", "Variable 1");
	assign1->getAssignments()->insert(attrib1Assignment);
	Assign::Assignment* attrib2Assignment = new Assign::Assignment(Assign::DestinationType::Variable, "Variable 1", "Variable 1 + 1");
	assign1->getAssignments()->insert(attrib2Assignment);

	Seize* seize1 = new Seize(model);
	seize1->setResourceName("Máquina 1");

	Delay* delay1 = new Delay(model);
	delay1->setDelayExpression("NORM(5,1)");
	delay1->setDelayTimeUnit(Util::TimeUnit::minute);

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

BuildSimulationModel::BuildSimulationModel() {

}

void buildSimulationSystem() {
	Simulator* simulator = new Simulator();
	Model* model = new Model(simulator);
	buildModel(model);
	simulator->getModels()->insert(model);
	
	if (model->checkModel()) {
		model->saveModel("./genesysmodel.txt");
		model->getSimulation()->startSimulation();
	}
}

int BuildSimulationModel::main(int argc, char** argv) {
	buildSimulationSystem();
};
