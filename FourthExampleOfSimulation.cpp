/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FourthExampleOfSimulation.cpp
 * Author: rlcancian
 *
 * Created on 24 de Setembro de 2019, 20:56
 */

#include "FourthExampleOfSimulation.h"

// GEnSyS Simulator
#include "Simulator.h"

// Model Components
#include "Create.h"
#include "Delay.h"
#include "Dispose.h"
#include "Seize.h"
#include "Release.h"
#include "Assign.h"
#include "Record.h"
#include "Decide.h"
#include "Write.h"
#include "Resource.h"
#include "PluginLoader.h"

// Model elements
#include "ElementManager.h"
#include "EntityType.h"
#include "Attribute.h"
#include "Variable.h"
#include "ProbDistribDefaultImpl1.h"
#include "EntityGroup.h"
#include "Set.h"
#include <dlfcn.h>

FourthExampleOfSimulation::FourthExampleOfSimulation() {
}

int FourthExampleOfSimulation::main(int argc, char** argv) {
	PluginLoader* pluginLoader = new PluginLoader("./plugin/build/");
	PluginLoader::SetPlugin* setPlugin = pluginLoader->getSet();
	PluginLoader::DisposePlugin* disposePlugin = pluginLoader->getDispose();
	PluginLoader::DelayPlugin* delayPlugin = pluginLoader->getDelay();
	PluginLoader::ResourcePlugin* resourcePlugin = pluginLoader->getResource();
	PluginLoader::DecidePlugin* decidePlugin = pluginLoader->getDecide();
	PluginLoader::QueuePlugin* queuePlugin = pluginLoader->getQueue();
	PluginLoader::VariablePlugin* variablePlugin = pluginLoader->getVariable();

	Simulator* simulator = new Simulator();
	simulator->getTracer()->setTraceLevel(Util::TraceLevel::everythingMostDetailed); //modelResult); //componentArrival);
	this->setDefaultTraceHandlers(simulator->getTracer());
	this->insertFakePluginsByHand(simulator);
	bool wantToCreateNewModelAndSaveInsteadOfJustLoad = true; //true;
	Model* model;


	Set* machSet;

	Dispose* dispose1;

	Delay* delay1;
	Delay* delay2;
	Delay* delay3;

	Resource* machine1;
	Resource* machine2;
	Resource* machine3;

	Decide* decide1;

	Queue* queueSeize1;
	Queue* queueSeize2;
	Queue* queueSeize3;

	Variable* var1;
	PluginManager* pluginManager = simulator->getPlugins();
	

	if (wantToCreateNewModelAndSaveInsteadOfJustLoad) {
		model = new Model(simulator);
		// build the simulation model
		ModelInfo* infos = model->getInfos();
		infos->setNumberOfReplications(5);
		infos->setReplicationLength(100);
		EntityType* part = new EntityType(model, "Part");
		// model->insert(part);
		StaticComponentInstance findCreate = pluginManager->find("Create")->getPluginInfo()->GetComponentInstance();
		Create* create1 = (Create*) findCreate(model, "");

		create1->setEntityType(part);
		create1->setTimeBetweenCreationsExpression("norm(1.5,0.5)");
		create1->setTimeUnit(Util::TimeUnit::second);
		create1->setEntitiesPerCreation(1);
		// model->insert(create1);

		StaticComponentInstance findAssign = pluginManager->find("Assign")->getPluginInfo()->GetComponentInstance();
		Assign* assign1 = (Assign*) findAssign(model, "");

		assign1->assignments()->insert(new Assign::Assignment("varNextIndex", "varNextIndex + 1"));
		assign1->assignments()->insert(new Assign::Assignment("index", "varNextIndex"));
		// model->insert(assign1);
		Attribute* attr1 = new Attribute(model, "index");
		// model->insert(attr1);
		var1 = variablePlugin->create(model, "varNextIndex");
		// model->insert(var1);
		StaticComponentInstance write = pluginManager->find("Write")->getPluginInfo()->GetComponentInstance();
		Write* write1 = (Write*) write(model, "");
		write1->setWriteToType(Write::WriteToType::SCREEN);
		write1->writeElements()->insert(new WriteElement("Atributo index: "));
		write1->writeElements()->insert(new WriteElement("index", true, true));
		write1->writeElements()->insert(new WriteElement("Variável nextIndex: "));
		write1->writeElements()->insert(new WriteElement("varNextIndex", true, true));
		write1->writeElements()->insert(new WriteElement("Quantidade ocupada das máquinas: "));
		write1->writeElements()->insert(new WriteElement("NR( Machine_1 )", true));
		write1->writeElements()->insert(new WriteElement(", "));
		write1->writeElements()->insert(new WriteElement("NR(Machine_2)", true));
		write1->writeElements()->insert(new WriteElement(", "));
		write1->writeElements()->insert(new WriteElement("NR(Machine_3)", true, true));
		write1->writeElements()->insert(new WriteElement("Estado das máquinas: "));
		write1->writeElements()->insert(new WriteElement("STATE(Machine_1)", true));
		write1->writeElements()->insert(new WriteElement(", "));
		write1->writeElements()->insert(new WriteElement("STATE(Machine_2)", true));
		write1->writeElements()->insert(new WriteElement(", "));
		write1->writeElements()->insert(new WriteElement("STATE(Machine_3)", true, true));
		write1->writeElements()->insert(new WriteElement("Quantidade de máquinas ocupadas no Set: "));
		write1->writeElements()->insert(new WriteElement("SETSUM(Machine_Set)", true, true));
		write1->writeElements()->insert(new WriteElement("Quantidade de entidades na fila 3: "));
		write1->writeElements()->insert(new WriteElement("NQ(Queue_Seize_3)", true, true));
		write1->writeElements()->insert(new WriteElement("Somatório do atributo 'index' das entidades na fila 3: "));
		write1->writeElements()->insert(new WriteElement("SAQUE(Queue_Seize_3,index)", true, true));
		write1->writeElements()->insert(new WriteElement("Valor do atributo 'index' da 2ª entidade na fila 3: "));
		write1->writeElements()->insert(new WriteElement("AQUE(Queue_Seize_3,2,index)", true, true));
		write1->writeElements()->insert(new WriteElement("Tempo médio das entidades na fila 3: "));
		write1->writeElements()->insert(new WriteElement("TAVG(Queue_Seize_3.TimeInQueue)", true, true));

		// model->insert(write1);
		//
		machine1 = resourcePlugin->create(model, "Machine_1");
		machine1->setCapacity(1);
		// model->insert(machine1);
		machine2 = resourcePlugin->create(model, "Machine_2");
		machine2->setCapacity(2);
		// model->insert(machine2);
		machine3 = resourcePlugin->create(model, "Machine_3");
		machine3->setCapacity(3);
		// model->insert(machine3);

		machSet = setPlugin->create(model, "Machine_Set");
		machSet->setSetOfType(Util::TypeOf<Resource>());
		machSet->getElementSet()->insert(machine1);
		machSet->getElementSet()->insert(machine2);
		machSet->getElementSet()->insert(machine3);
		// model->insert(machSet);
		decide1 = decidePlugin->create(model);
		decide1->getConditions()->insert("NR(Machine_1) < MR(Machine_1)");
		decide1->getConditions()->insert("NR(Machine_2) < MR(Machine_2)");
		// model->insert(decide1);
		queueSeize1 = queuePlugin->create(model, "Queue_Seize_1");
		queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize1);
		StaticComponentInstance seize = pluginManager->find("Seize")->getPluginInfo()->GetComponentInstance();
		Seize* seize1 = (Seize*) seize(model, "");
		seize1->setSeizeRequest(new ResourceItemRequest(machine1));
		seize1->setQueue(queueSeize1);
		// model->insert(seize1);
		delay1 = delayPlugin->create(model);
		delay1->setDelayExpression("norm(15,1)");
		delay1->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay1);

		StaticComponentInstance findRelease = pluginManager->find("Release")->getPluginInfo()->GetComponentInstance();
		Release* release1 = (Release*) findRelease(model, "");
		
		// ->getPluginInfo()->GetComponentInstance()(model, "");
		release1->setReleaseRequest(new ResourceItemRequest(machine1));
		// model->insert(release1);
		queueSeize2 = queuePlugin->create(model, "Queue_Seize_2");
		queueSeize2->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize2);
		Seize* seize2 = (Seize*) seize(model, "");
		seize2->setSeizeRequest(new ResourceItemRequest(machine2));
		seize2->setQueue(queueSeize2);
		// model->insert(seize2);
		delay2 = delayPlugin->create(model);
		delay2->setDelayExpression("norm(15,1)");
		delay2->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay2);
		//Release* release2 = new Release(model);
		Release* release2 = (Release*) findRelease(model, "");
		release2->setReleaseRequest(new ResourceItemRequest(machine2));
		// model->insert(release2);
		queueSeize3 = queuePlugin->create(model, "Queue_Seize_3");
		queueSeize3->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize3);

		Seize* seize3 = (Seize*) seize(model, "");
		seize3->setSeizeRequest(new ResourceItemRequest(machine3));
		seize3->setQueue(queueSeize3);
		// model->insert(seize3);
		delay3 = delayPlugin->create(model);
		delay3->setDelayExpression("norm(15,1)");
		delay3->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay3);
		Release* release3 = (Release*) findRelease(model, "");
		release3->setReleaseRequest(new ResourceItemRequest(machine3));
		// model->insert(release3);
		dispose1 = disposePlugin->create(model);
		// model->insert(dispose1);
		//
		create1->getNextComponents()->insert(assign1);
		assign1->getNextComponents()->insert(write1);
		write1->getNextComponents()->insert(decide1);
		decide1->getNextComponents()->insert(seize1);
		decide1->getNextComponents()->insert(seize2);
		decide1->getNextComponents()->insert(seize3);
		seize1->getNextComponents()->insert(delay1);
		delay1->getNextComponents()->insert(release1);
		release1->getNextComponents()->insert(dispose1);
		// seize2->getNextComponents()->insert(delay2);
		// delay2->getNextComponents()->insert(release2);
		// release2->getNextComponents()->insert(dispose1);
		// seize3->getNextComponents()->insert(delay3);
		// delay3->getNextComponents()->insert(release3);
		// release3->getNextComponents()->insert(dispose1);
		//
		simulator->getModels()->insert(model);
		model->save("./temp/forthExampleOfSimulation.txt");


	} else { // load previously saved model
		simulator->getModels()->loadModel("./temp/forthExampleOfSimulation.txt");
		model = simulator->getModels()->current();
	}
	// std::cout << "abc" << std::endl;
	this->setDefaultEventHandlers(model->getOnEvents());
	model->getSimulation()->start();

  	setPlugin->destroy(machSet);
	disposePlugin->destroy(dispose1);
	delayPlugin->destroy(delay1);
	delayPlugin->destroy(delay2);
	delayPlugin->destroy(delay3);

	resourcePlugin->destroy(machine1);
	resourcePlugin->destroy(machine2);
	resourcePlugin->destroy(machine3);
	decidePlugin->destroy(decide1);
	queuePlugin->destroy(queueSeize1);
	queuePlugin->destroy(queueSeize2);
	queuePlugin->destroy(queueSeize3);
	variablePlugin->destroy(var1);

	dlclose(setPlugin->getHandle());
	dlclose(resourcePlugin->getHandle());
	dlclose(decidePlugin->getHandle());
	dlclose(queuePlugin->getHandle());
	dlclose(variablePlugin->getHandle());
 	dlclose(disposePlugin->getHandle());
	dlclose(delayPlugin->getHandle());
	return 0;
}
