/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseConsoleGenesysApplication.cpp
 * Author: rlcancian
 * 
 * Created on 3 de Setembro de 2019, 16:25
 */

#include "BaseConsoleGenesysApplication.h"
#include <iostream>


// GEnSyS Simulator
#include "Simulator.h"


BaseConsoleGenesysApplication::BaseConsoleGenesysApplication() {
}

BaseConsoleGenesysApplication::BaseConsoleGenesysApplication(const BaseConsoleGenesysApplication& orig) {
}

BaseConsoleGenesysApplication::~BaseConsoleGenesysApplication() {
}

// default Trace Handlers

void BaseConsoleGenesysApplication::traceHandler(TraceEvent e) {
    std::cout << e.getText() << std::endl;
}

void BaseConsoleGenesysApplication::traceErrorHandler(TraceErrorEvent e) {
    std::cout << e.getText() << std::endl; 
}

void BaseConsoleGenesysApplication::traceReportHandler(TraceEvent e) {
    std::cout << "" << e.getText() << "" << std::endl;
}

void BaseConsoleGenesysApplication::traceSimulationHandler(TraceSimulationEvent e) {
    std::cout << e.getText() << std::endl;
}


// default Event Handlers

void BaseConsoleGenesysApplication::onSimulationStartHandler(SimulationEvent* re) {
    std::cout << "(Event Handler) " << "Simulation is starting" << std::endl;
}

void BaseConsoleGenesysApplication::onReplicationStartHandler(SimulationEvent* re) {
    std::cout << "(Event Handler) " << "Replication " << re->getReplicationNumber() << " starting." << std::endl;
}

void BaseConsoleGenesysApplication::onProcessEventHandler(SimulationEvent* re) {
    std::cout << "(Event Handler) " << "Processing event " << re->getEventProcessed()->show() << std::endl;
}

void BaseConsoleGenesysApplication::onReplicationEndHandler(SimulationEvent* re) {
    std::cout << "(Event Handler) " << "Replication " << re->getReplicationNumber() << " ending." << std::endl;
}

void BaseConsoleGenesysApplication::onSimulationEndHandler(SimulationEvent* re) {
    std::cout << "Event (Handler) " << "Replication " << re->getReplicationNumber() << " ending." << std::endl;
}

void BaseConsoleGenesysApplication::onEntityRemoveHandler(SimulationEvent* re) {
    std::cout << "(Event Handler) " << "Entity " << re->getEventProcessed()->getEntity() << " was removed." << std::endl;
}

void BaseConsoleGenesysApplication::setDefaultTraceHandlers(TraceManager* tm) {
    tm->addTraceHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceHandler);
    tm->addTraceErrorHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceErrorHandler);
    tm->addTraceReportHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceReportHandler);
    tm->addTraceSimulationHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceSimulationHandler);
}

void BaseConsoleGenesysApplication::insertFakePluginsByHand(Simulator* simulator) {
    // model components
    simulator->getPluginManager()->insert("assign.so");
    simulator->getPluginManager()->insert("create.so");
    simulator->getPluginManager()->insert("decide.so");
    simulator->getPluginManager()->insert("delay.so");
    simulator->getPluginManager()->insert("dispose.so");
    simulator->getPluginManager()->insert("dummy.so");
    simulator->getPluginManager()->insert("record.so");
    simulator->getPluginManager()->insert("release.so");
    simulator->getPluginManager()->insert("seize.so");
    simulator->getPluginManager()->insert("route.so");
    simulator->getPluginManager()->insert("enter.so");
    simulator->getPluginManager()->insert("leave.so");
    // model elements
    simulator->getPluginManager()->insert("attribute.so");
    simulator->getPluginManager()->insert("counter.so");
    simulator->getPluginManager()->insert("entitytype.so");
    simulator->getPluginManager()->insert("queue.so");
    simulator->getPluginManager()->insert("resource.so");
    simulator->getPluginManager()->insert("statisticscollector.so");
    simulator->getPluginManager()->insert("variable.so");
    simulator->getPluginManager()->insert("group.so");
    simulator->getPluginManager()->insert("station.so");
    simulator->getPluginManager()->insert("formula.so");
    simulator->getPluginManager()->insert("ode.so");
}