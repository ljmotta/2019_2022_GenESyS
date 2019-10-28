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
    Variable* var1 = new Variable(model,"var1");
    var1->getDimensionSizes()->insert(2);
    Variable* var2 = new Variable(model, "var2");
    var1->setInitialValue("0",1.0);
    var1->setInitialValue("1",1.1);
    var2->getDimensionSizes()->insert(2);
    var2->setInitialValue("0",2.0);
    var2->setInitialValue("1",2.1);
    Formula* formula1 = new Formula(model);
    formula1->getFormulaExpressions()->insert("var1[2]");    
    formula1->getFormulaExpressions()->insert("var2[2]");    
    formula1->getFormulaExpressions()->insert("var1[2] = var1[0] + var1[1]");
    formula1->getFormulaExpressions()->insert("var2[2] = var2[1] + var2[0]");    
    formula1->getFormulaExpressions()->insert("var1[2]");    
    formula1->getFormulaExpressions()->insert("var2[2]");    
    LSODE* ode1 = new LSODE(model);
    ode1->setFormula(formula1);
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
