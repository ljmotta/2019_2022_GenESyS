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

// Model Components
#include "Create.h"
#include "Delay.h"
#include "Dispose.h"
#include "Seize.h"
#include "Release.h"
#include "Assign.h"
#include "Record.h"
#include "Decide.h"
#include "Dummy.h"
#include "Route.h"
#include "Enter.h"
#include "Leave.h"

// Model elements
#include "EntityType.h"
#include "Attribute.h"
#include "Variable.h"
#include "ProbDistrib.h"
#include "Group.h"
#include "Station.h"
#include "Formula.h"
#include "ODE.h"

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
    // model elements
    simulator->getPluginManager()->insert("./plugins/attribute.so");
    simulator->getPluginManager()->insert("./plugins/counter.so");
    simulator->getPluginManager()->insert("./plugins/entitytype.so");
    simulator->getPluginManager()->insert("./plugins/queue.so");
    simulator->getPluginManager()->insert("./plugins/resource.so");
    simulator->getPluginManager()->insert("./plugins/statisticscollector.so");
    simulator->getPluginManager()->insert("./plugins/variable.so");
    simulator->getPluginManager()->insert("./plugins/group.so");
    simulator->getPluginManager()->insert("./plugins/station.so");
    simulator->getPluginManager()->insert("./plugins/formula.so");
    simulator->getPluginManager()->insert("./plugins/ode.so");
    // model components
    simulator->getPluginManager()->insert("./plugins/assign.so");
    simulator->getPluginManager()->insert("./plugins/create.so");
    simulator->getPluginManager()->insert("./plugins/decide.so");
    simulator->getPluginManager()->insert("./plugins/delay.so");
    simulator->getPluginManager()->insert("./plugins/dispose.so");
    simulator->getPluginManager()->insert("./plugins/dummy.so");
    simulator->getPluginManager()->insert("./plugins/record.so");
    simulator->getPluginManager()->insert("./plugins/release.so");
    simulator->getPluginManager()->insert("./plugins/seize.so");
    simulator->getPluginManager()->insert("./plugins/route.so");
    simulator->getPluginManager()->insert("./plugins/enter.so");
    simulator->getPluginManager()->insert("./plugins/leave.so");
    /*
    // model elements
    simulator->getPluginManager()->insert(new Plugin(&Attribute::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Counter::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&EntityType::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Queue::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Resource::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&StatisticsCollector::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Variable::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Group::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Station::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Formula::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&ODE::GetPluginInformation));
    // model components
    simulator->getPluginManager()->insert(new Plugin(&Assign::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Create::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Decide::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Delay::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Dispose::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Dummy::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Record::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Release::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Seize::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Route::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Enter::GetPluginInformation));
    simulator->getPluginManager()->insert(new Plugin(&Leave::GetPluginInformation));
    */
}