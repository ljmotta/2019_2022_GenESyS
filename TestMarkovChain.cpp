/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestMarkovChain.cpp
 * Author: rlcancian
 * 
 * Created on 24 de Outubro de 2019, 18:22
 */

#include "TestMarkovChain.h"

#include "Simulator.h"
#include "Variable.h"
#include "Create.h"
#include "MarkovChain.h"
#include "Dispose.h"

TestMarkovChain::TestMarkovChain() {
}

int TestMarkovChain::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    TraceManager*tm = simulator->tracer();
    this->setDefaultTraceHandlers(tm);
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    //
    Model* model = new Model(simulator);
    Variable* var1 = new Variable(model, "InitCond");
    var1->setValue("0", 0.1);
    var1->setValue("1", 0.4);
    var1->setValue("2", 0.4);
    var1->setValue("3", 0.1);
    // model->insert(var1);
    Variable* var2 = new Variable(model,"ProcessState");
    // model->insert(var2);
    Create* create1 = new Create(model);
    //// model->insert(create1);
    MarkovChain* markov1 = new MarkovChain(model);
    //// model->insert(markov1);
    Dispose* dispose1 = new Dispose(model);
    std::cout << "size:" << model->components()->numberOfComponents() << std::endl;
    create1->~Create();
    std::cout << "size:" << model->components()->numberOfComponents() << std::endl;
    markov1->~MarkovChain();
    std::cout << "size:" << model->components()->numberOfComponents() << std::endl;
    //model->
    return 0;
}