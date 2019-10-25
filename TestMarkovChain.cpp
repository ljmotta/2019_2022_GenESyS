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

TestMarkovChain::TestMarkovChain() {
}

int TestMarkovChain::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    TraceManager*tm = simulator->tracer();
    this->setDefaultTraceHandlers(tm);
    tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    //
    Model* model = new Model(simulator);
    ComponentManager* comps = model->components();
    ElementManager* elems = model->elements();
    Variable* var1 = new Variable("InitCond");
    var1->setValue("0", 0.1);
    var1->setValue("1", 0.4);
    var1->setValue("2", 0.4);
    var1->setValue("3", 0.1);
    elems->insert(var1);
    Variable* var2 = new Variable("ProcessState");
    elems->insert(var2);
    return 0;
}