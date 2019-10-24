/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestLSODE.cpp
 * Author: rlcancian
 * 
 * Created on 23 de Outubro de 2019, 13:07
 */

#include "TestLSODE.h"
//
#include "Simulator.h"
#include "Model.h"
#include "Create.h"
#include "Delay.h"
#include "LSODE.h"
#include "Dispose.h"

TestLSODE::TestLSODE() {
}

int TestLSODE::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    TraceManager* tm = simulator->getTraceManager();
    this->setDefaultTraceHandlers(tm);
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    this->insertFakePluginsByHand(simulator);
    Model* model = new Model(simulator);
    ComponentManager* components = model->getComponentManager();
    ElementManager* elements = model->getElementManager();
    //
    EntityType* entityType1 = new EntityType(elements, "EntType_1");
    elements->insert(entityType1); 
    Create* create1 = new Create(model);
    create1->setEntityType(entityType1);
    create1->setTimeBetweenCreationsExpression("1.0"); 
    components->insert(create1); 
    LSODE* ode1 = new LSODE(model);
    components->insert(ode1);
    //Delay* delay1 = new Delay(model);
    //components->insert(delay1); 
    Dispose* dispose1 = new Dispose(model); 
    components->insert(dispose1);
    create1->getNextComponents()->insert(ode1);
    ode1->getNextComponents()->insert(dispose1);
    //delay1->getNextComponents()->insert(dispose1);
    simulator->getModelManager()->insert(model);
    //
    if (model->checkModel()) {
	model->saveModel("./temp/testLSODE.txt");
    }
    model->getSimulation()->startSimulation();
    return 0;    
}
