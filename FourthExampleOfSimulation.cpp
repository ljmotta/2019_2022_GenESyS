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

// Model elements
#include "ElementManager.h"
#include "EntityType.h"
#include "Attribute.h"
#include "Variable.h"
#include "ProbDistrib.h"
#include "EntityGroup.h"
#include "Set.h"

FourthExampleOfSimulation::FourthExampleOfSimulation() {
}

int FourthExampleOfSimulation::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    //
    TraceManager* tm = simulator->getTraceManager();
    this->setDefaultTraceHandlers(tm);
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    //
    this->insertFakePluginsByHand(simulator);
    Model* model = new Model(simulator);
    ComponentManager* components = model->getComponentManager();
    ElementManager* elements = model->getElementManager();
    //
    // build the simulation model
    ModelInfo* infos = model->getInfos();
    infos->setReplicationLength(60);
    infos->setReplicationLengthTimeUnit(Util::TimeUnit::second);
    infos->setNumberOfReplications(1);
    //
    EntityType* part = new EntityType(elements, "Part");
    elements->insert(Util::TypeOf<EntityType>(), part);
    //
    Create* create1 = new Create(model);
    create1->setEntityType(part);
    create1->setTimeBetweenCreationsExpression("norm(3,1)");
    create1->setTimeUnit(Util::TimeUnit::second);
    create1->setEntitiesPerCreation(1);
    components->insert(create1);
    //
    Assign* assign1 = new Assign(model);
    assign1->getAssignments()->insert(new Assign::Assignment(Assign::DestinationType::Attribute, "index", "1"));
    assign1->getAssignments()->insert(new Assign::Assignment(Assign::DestinationType::Variable, "nextIndex", "nextIndex+1"));
    components->insert(assign1);
    //
    Attribute* attr1 = new Attribute("index");
    elements->insert(Util::TypeOf<Attribute>(), attr1);
    //
    Variable* var1 = new Variable("nextIndex");
    elements->insert(Util::TypeOf<Variable>(), var1);
    //
    Write* write1 = new Write(model);
    write1->setWriteToType(Write::WriteToType::SCREEN);
    write1->getWriteElements()->insert(new Write::WriteElement("Valor de index: ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("index",true,true));
    write1->getWriteElements()->insert(new Write::WriteElement("Valor de nextIndex: ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("nextIndex",true,true));
    write1->getWriteElements()->insert(new Write::WriteElement("Quantidade de entidades na fila: ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("NQ(Queue_Seize_1)",true,true));
    write1->getWriteElements()->insert(new Write::WriteElement("Quantidade ocupada das máquinas: ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("NR(Machine_1)",true));
    write1->getWriteElements()->insert(new Write::WriteElement(", ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("NR(Machine_2)",true));
    write1->getWriteElements()->insert(new Write::WriteElement(", ",false));
    write1->getWriteElements()->insert(new Write::WriteElement("NR(Machine_3)",true, true));
    components->insert(write1);
    //
    Resource* machine1 = new Resource(elements, "Machine_1");
    machine1->setCapacity(1);
    elements->insert(Util::TypeOf<Resource>(), machine1);
    //
    Resource* machine2 = new Resource(elements, "Machine_2");
    machine2->setCapacity(1);
    elements->insert(Util::TypeOf<Resource>(), machine2);
    //
    Resource* machine3 = new Resource(elements, "Machine_3");
    machine3->setCapacity(1);
    elements->insert(Util::TypeOf<Resource>(), machine3);
    // 
    Set* machSet = new Set(elements, "Machine_Set");
    machSet->setSetOfType(Util::TypeOf<Resource>());
    machSet->getElementSet()->insert(machine1);
    machSet->getElementSet()->insert(machine2);
    machSet->getElementSet()->insert(machine3);
    elements->insert(Util::TypeOf<Set>(), machSet);
    //
    Queue* queueSeize1 = new Queue(elements, "Queue_Seize_1");
    queueSeize1->setOrderRule(Queue::OrderRule::FIFO);
    elements->insert(Util::TypeOf<Queue>(), queueSeize1);
    //
    Seize* seize1 = new Seize(model);
    seize1->setResource(machine1);
    seize1->setQueue(queueSeize1);
    components->insert(seize1);
    //
    Delay* delay1 = new Delay(model);
    delay1->setDelayExpression("norm(6,1)");
    delay1->setDelayTimeUnit(Util::TimeUnit::second);
    components->insert(delay1);
    //
    Release* release1 = new Release(model);
    release1->setResource(machine1);
    components->insert(release1);
    //
    Dispose* dispose1 = new Dispose(model);
    components->insert(dispose1);
    //
    create1->getNextComponents()->insert(assign1);
    assign1->getNextComponents()->insert(write1);
    write1->getNextComponents()->insert(seize1);
    seize1->getNextComponents()->insert(delay1);
    delay1->getNextComponents()->insert(release1);
    release1->getNextComponents()->insert(dispose1);
    //
    //
    simulator->getModelManager()->insert(model);
    if (model->checkModel()) {
	model->saveModel("./temp/forthExampleOfSimulation.txt");
    }
    model->getSimulation()->startSimulation();
    return 0;
}

