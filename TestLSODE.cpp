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
#include "Assign.h"
#include "Formula.h"
#include "Delay.h"
#include "LSODE.h"
#include "Dispose.h"
#include "Variable.h"

TestLSODE::TestLSODE() {
}

int TestLSODE::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    TraceManager* tm = simulator->tracer();
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    this->setDefaultTraceHandlers(tm);
    this->insertFakePluginsByHand(simulator);
    Model* model = new Model(simulator);
    EntityType* entityType1 = new EntityType(model, "EntType_1");
    Create* create1 = new Create(model);
    create1->setEntityType(entityType1);
    create1->setTimeBetweenCreationsExpression("1.0"); 
    /*
    new Variable(model, "var1");
    Variable* var2 = new Variable(model, "var2");
    var2->setValue(1.0);
    Formula* formula1 = new Formula(model);
    formula1->getFormulaExpressions()->insert("var1 + cos(var2)");
    formula1->getFormulaExpressions()->insert("var1*var1 -6*var2");    
    */
    Variable* varTime = new Variable(model,"x");
    Variable* varY = new Variable(model,"y");
    varY->setInitialValue("0",1.0);
    varY->setInitialValue("1",0.0);
    varY->getDimensionSizes()->insert(2);
    Variable* varDy = new Variable(model, "dy");
    varDy->getDimensionSizes()->insert(2);
    Formula* diffeq1 = new Formula(model);
    diffeq1->getFormulaExpressions()->insert("dy[0]=y[1]");
    diffeq1->getFormulaExpressions()->insert("dy[1]=y[0]+exp(x)");    
    LSODE* ode1 = new LSODE(model);
    ode1->setDiffEquations(diffeq1);
    ode1->setVariables(varY);
    ode1->setTimeVariable(varTime);
    ode1->setStep(0.1);
    //Delay* delay1 = new Delay(model);
    Dispose* dispose1 = new Dispose(model); 
    create1->nextComponents()->insert(ode1);
    ode1->nextComponents()->insert(dispose1);
    //delay1->getNextComponents()->insert(dispose1);
    simulator->models()->insert(model);
    model->save("./temp/testLSODE.txt");
    model->simulation()->startSimulation();
    return 0;    
}
