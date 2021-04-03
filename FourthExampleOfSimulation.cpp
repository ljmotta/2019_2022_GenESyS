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
	PluginLoader* pluginLoader = new PluginLoader("/home/luiz/Documents/modsim/2019_2022_GenESyS/");
	PluginLoader::AssignPlugin* assignPlugin = pluginLoader->getAssign();
	PluginLoader::WritePlugin* writePlugin = pluginLoader->getWrite();
	PluginLoader::SetPlugin* setPlugin = pluginLoader->getSet();
	PluginLoader::DisposePlugin* disposePlugin = pluginLoader->getDispose();
	PluginLoader::DelayPlugin* delayPlugin = pluginLoader->getDelay();
	PluginLoader::CreatePlugin* createPlugin = pluginLoader->getCreate();

	Simulator* simulator = new Simulator();
	simulator->getTracer()->setTraceLevel(Util::TraceLevel::everythingMostDetailed); //modelResult); //componentArrival);
	this->setDefaultTraceHandlers(simulator->getTracer());
	this->insertFakePluginsByHand(simulator);
	bool wantToCreateNewModelAndSaveInsteadOfJustLoad = true; //true;
	Model* model;

	Assign* assign;
	Assign::Assignment* assigment1;
	Assign::Assignment* assigment2;

	Write* write1;
	WriteElement* writeElement1;
	WriteElement* writeElement2;
	WriteElement* writeElement3;
	WriteElement* writeElement4;
	WriteElement* writeElement5;
	WriteElement* writeElement6;
	WriteElement* writeElement7;
	WriteElement* writeElement8;
	WriteElement* writeElement9;
	WriteElement* writeElement10;

	Set* machSet;

	Dispose* dispose1;

	Delay* delay1;
	Delay* delay2;
	Delay* delay3;

	Create* create1;

	if (wantToCreateNewModelAndSaveInsteadOfJustLoad) {
		model = new Model(simulator);
		// build the simulation model
		ModelInfo* infos = model->getInfos();
		infos->setNumberOfReplications(5);
		infos->setReplicationLength(100);
		EntityType* part = new EntityType(model, "Part");
		// model->insert(part);
		create1 = createPlugin->create(model);
		create1->setEntityType(part);
		create1->setTimeBetweenCreationsExpression("norm(1.5,0.5)");
		create1->setTimeUnit(Util::TimeUnit::second);
		create1->setEntitiesPerCreation(1);
		// model->insert(create1);

		assign = assignPlugin->create(model);
		assigment1 = assignPlugin->getAssignment()->create("varNextIndex", "varNextIndex+1");
		assigment2 = assignPlugin->getAssignment()->create("index", "varNextIndex");
		assign->assignments()->insert(assigment1);
		assign->assignments()->insert(assigment2);
		// model->insert(assign1);
		Attribute* attr1 = new Attribute(model, "index");
		// model->insert(attr1);
		Variable* var1 = new Variable(model, "varNextIndex");
		// model->insert(var1);
		write1 = writePlugin->create(model);
		writeElement1 = writePlugin->getWriteElement()->create("Atributo index: ");
		writeElement2 = writePlugin->getWriteElement()->create("index", true, true);
		writeElement3 = writePlugin->getWriteElement()->create("varNextIndex", true, true);
		writeElement4 = writePlugin->getWriteElement()->create("Quantidade ocupada das máquinas: ");
		writeElement5 = writePlugin->getWriteElement()->create("NR( Machine_1 )", true);
		writeElement6 = writePlugin->getWriteElement()->create(", ");
		writeElement7 = writePlugin->getWriteElement()->create("NR(Machine_2)", true);
		writeElement8 = writePlugin->getWriteElement()->create(", ");
		writeElement9 = writePlugin->getWriteElement()->create("NR(Machine_3)", true, true);
		writeElement10 = writePlugin->getWriteElement()->create("Estado das máquinas: ");

		write1->setWriteToType(Write::WriteToType::SCREEN);
		write1->writeElements()->insert(writeElement1);
		write1->writeElements()->insert(writeElement2);
		write1->writeElements()->insert(writeElement3);
		write1->writeElements()->insert(writeElement4);
		write1->writeElements()->insert(writeElement5);
		write1->writeElements()->insert(writeElement6);
		write1->writeElements()->insert(writeElement7);
		write1->writeElements()->insert(writeElement8);
		write1->writeElements()->insert(writeElement9);
		write1->writeElements()->insert(writeElement10);
//		write1->writeElements()->insert(new WriteElement("Estado das máquinas: "));
//		write1->writeElements()->insert(new WriteElement("STATE(Machine_1)", true));
//		write1->writeElements()->insert(new WriteElement(", "));
//		write1->writeElements()->insert(new WriteElement("STATE(Machine_2)", true));
//		write1->writeElements()->insert(new WriteElement(", "));
//		write1->writeElements()->insert(new WriteElement("STATE(Machine_3)", true, true));
//		write1->writeElements()->insert(new WriteElement("Quantidade de máquinas ocupadas no Set: "));
//		write1->writeElements()->insert(new WriteElement("SETSUM(Machine_Set)", true, true));
//		write1->writeElements()->insert(new WriteElement("Quantidade de entidades na fila 3: "));
//		write1->writeElements()->insert(new WriteElement("NQ(Queue_Seize_3)", true, true));
//		write1->writeElements()->insert(new WriteElement("Somatório do atributo 'index' das entidades na fila 3: "));
//		write1->writeElements()->insert(new WriteElement("SAQUE(Queue_Seize_3,index)", true, true));
//		write1->writeElements()->insert(new WriteElement("Valor do atributo 'index' da 2ª entidade na fila 3: "));
//		write1->writeElements()->insert(new WriteElement("AQUE(Queue_Seize_3,2,index)", true, true));
//		write1->writeElements()->insert(new WriteElement("Tempo médio das entidades na fila 3: "));
//		write1->writeElements()->insert(new WriteElement("TAVG(Queue_Seize_3.TimeInQueue)", true, true));
		// model->insert(write1);
		//
		Resource* machine1 = new Resource(model, "Machine_1");
		machine1->setCapacity(1);
		// model->insert(machine1);
		Resource* machine2 = new Resource(model, "Machine_2");
		machine2->setCapacity(2);
		// model->insert(machine2);
		Resource* machine3 = new Resource(model, "Machine_3");
		machine3->setCapacity(3);
		// model->insert(machine3);

		machSet = setPlugin->create(model, "Machine_Set");
		machSet->setSetOfType(Util::TypeOf<Resource>());
		machSet->getElementSet()->insert(machine1);
		machSet->getElementSet()->insert(machine2);
		machSet->getElementSet()->insert(machine3);
		// model->insert(machSet);
		Decide* decide1 = new Decide(model);
		decide1->getConditions()->insert("NR(Machine_1) < MR(Machine_1)");
		decide1->getConditions()->insert("NR(Machine_2) < MR(Machine_2)");
		// model->insert(decide1);
		Queue* queueSeize1 = new Queue(model, "Queue_Seize_1");
		queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize1);
		Seize* seize1 = new Seize(model);
		seize1->setSeizeRequest(new ResourceItemRequest(machine1));
		seize1->setQueue(queueSeize1);
		// model->insert(seize1);
		delay1 = delayPlugin->create(model);
		delay1->setDelayExpression("norm(15,1)");
		delay1->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay1);
		Release* release1 = new Release(model);
		release1->setReleaseRequest(new ResourceItemRequest(machine1));
		// model->insert(release1);
		Queue* queueSeize2 = new Queue(model, "Queue_Seize_2");
		queueSeize2->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize2);
		Seize* seize2 = new Seize(model);
		seize2->setSeizeRequest(new ResourceItemRequest(machine2));
		seize2->setQueue(queueSeize2);
		// model->insert(seize2);
		delay2 = delayPlugin->create(model);
		delay2->setDelayExpression("norm(15,1)");
		delay2->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay2);
		Release* release2 = new Release(model);
		release2->setReleaseRequest(new ResourceItemRequest(machine2));
		// model->insert(release2);
		Queue* queueSeize3 = new Queue(model, "Queue_Seize_3");
		queueSeize3->setOrderRule(Queue::OrderRule::FIFO);
		// model->insert(queueSeize3);
		Seize* seize3 = new Seize(model);
		seize3->setSeizeRequest(new ResourceItemRequest(machine3));
		seize3->setQueue(queueSeize3);
		// model->insert(seize3);
		delay3 = delayPlugin->create(model);
		delay3->setDelayExpression("norm(15,1)");
		delay3->setDelayTimeUnit(Util::TimeUnit::second);
		// model->insert(delay3);
		Release* release3 = new Release(model);
		release3->setReleaseRequest(new ResourceItemRequest(machine3));
		// model->insert(release3);
		dispose1 = disposePlugin->create(model);
		// model->insert(dispose1);
		//
		create1->getNextComponents()->insert(assign);
		assign->getNextComponents()->insert(write1);
		write1->getNextComponents()->insert(decide1);
		decide1->getNextComponents()->insert(seize1);
		decide1->getNextComponents()->insert(seize2);
		decide1->getNextComponents()->insert(seize3);
		seize1->getNextComponents()->insert(delay1);
		delay1->getNextComponents()->insert(release1);
		release1->getNextComponents()->insert(dispose1);
		seize2->getNextComponents()->insert(delay2);
		delay2->getNextComponents()->insert(release2);
		release2->getNextComponents()->insert(dispose1);
		seize3->getNextComponents()->insert(delay3);
		delay3->getNextComponents()->insert(release3);
		release3->getNextComponents()->insert(dispose1);
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

	assignPlugin->destroy(assign);
	assignPlugin->getAssignment()->destroy(assigment1);
	assignPlugin->getAssignment()->destroy(assigment2);
	writePlugin->destroy(write1);
	writePlugin->getWriteElement()->destroy(writeElement1);
	writePlugin->getWriteElement()->destroy(writeElement2);
	writePlugin->getWriteElement()->destroy(writeElement3);
	writePlugin->getWriteElement()->destroy(writeElement4);
	writePlugin->getWriteElement()->destroy(writeElement5);
	writePlugin->getWriteElement()->destroy(writeElement6);
	writePlugin->getWriteElement()->destroy(writeElement7);
	writePlugin->getWriteElement()->destroy(writeElement8);
	writePlugin->getWriteElement()->destroy(writeElement9);
	writePlugin->getWriteElement()->destroy(writeElement10);

    setPlugin->destroy(machSet);
	disposePlugin->destroy(dispose1);
	delayPlugin->destroy(delay1);
	delayPlugin->destroy(delay2);
	delayPlugin->destroy(delay3);
	createPlugin->destroy(create1);

	dlclose(assignPlugin->getHandle());
	dlclose(writePlugin->getHandle());
	dlclose(setPlugin->getHandle());
	dlclose(disposePlugin->getHandle());
	dlclose(delayPlugin->getHandle());
	dlclose(createPlugin->getHandle());
	return 0;
}
