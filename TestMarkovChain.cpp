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
#include "EntityType.h"
#include "Create.h"
#include "MarkovChain.h"
#include "Write.h"
#include "Dispose.h"

TestMarkovChain::TestMarkovChain() {
}

int TestMarkovChain::main(int argc, char** argv) {
    Simulator* simulator = new Simulator();
    TraceManager*tm = simulator->tracer();
    //tm->setTraceLevel(Util::TraceLevel::mostDetailed);
    setDefaultTraceHandlers(tm);
    insertFakePluginsByHand(simulator);
    Model* model = new Model(simulator);
    model->infos()->setNumberOfReplications(5);
    model->infos()->setReplicationLength(100);
    Variable* varInitDist = new Variable(model, "InitialDistribution");
    varInitDist->setValue("0", 0.7);
    varInitDist->setValue("1", 0.1);
    varInitDist->setValue("2", 0.1);
    varInitDist->setValue("3", 0.1);
    varInitDist->dimensionSizes()->insert(4);
    Variable* varTransitProb = new Variable(model,"transitionProbMatrix'");
    varTransitProb->setValue("0,0", 0.1);
    varTransitProb->setValue("0,1", 0.7);
    varTransitProb->setValue("0,2", 0.1);
    varTransitProb->setValue("0,3", 0.1);
    varTransitProb->setValue("1,0", 0.1);
    varTransitProb->setValue("1,1", 0.1);
    varTransitProb->setValue("1,2", 0.7);
    varTransitProb->setValue("1,3", 0.1);
    varTransitProb->setValue("2,0", 0.1);
    varTransitProb->setValue("2,1", 0.1);
    varTransitProb->setValue("2,2", 0.1);
    varTransitProb->setValue("2,3", 0.7);
    varTransitProb->setValue("3,0", 0.7);
    varTransitProb->setValue("3,1", 0.1);
    varTransitProb->setValue("3,2", 0.1);
    varTransitProb->setValue("3,3", 0.1);
    varTransitProb->dimensionSizes()->insert(4);
    varTransitProb->dimensionSizes()->insert(4);
    Variable* varCurrStat = new Variable(model, "currentState");
    EntityType* enttype1 = new EntityType(model);
    Create* create1 = new Create(model);
    create1->setEntityType(enttype1);
    create1->setTimeBetweenCreationsExpression("1");
    MarkovChain* markov1 = new MarkovChain(model);
    markov1->setInitialDistribution(varInitDist);
    markov1->setTransitionProbabilityMatrix(varTransitProb);
    markov1->setCurrentState(varCurrStat);
    Write* write1 = new Write(model);
    write1->setWriteToType(Write::WriteToType::FILE);
    write1->setFilename("./temp/markov1_realizations.txt");
    write1->writeElements()->insert(new WriteElement("tnow", true));
    write1->writeElements()->insert(new WriteElement("\t"));
    write1->writeElements()->insert(new WriteElement("currentState", true, true));
    Dispose* dispose1 = new Dispose(model);
    create1->nextComponents()->insert(markov1);
    markov1->nextComponents()->insert(write1);
    write1->nextComponents()->insert(dispose1);
    simulator->models()->insert(model);
    model->save("./temp/testmarkovchain.txt");
    model->simulation()->start();
    return 0;
}