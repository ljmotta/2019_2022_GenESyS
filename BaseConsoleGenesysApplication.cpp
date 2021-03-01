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

#include "Simulator.h"

BaseConsoleGenesysApplication::BaseConsoleGenesysApplication() {
}


// default Trace Handlers

void BaseConsoleGenesysApplication::traceHandler(TraceEvent e) {
	std::cout << e.text() << std::endl;
}

void BaseConsoleGenesysApplication::traceErrorHandler(TraceErrorEvent e) {
	std::cout << e.text() << std::endl;
}

void BaseConsoleGenesysApplication::traceReportHandler(TraceEvent e) {
	std::cout << "" << e.text() << "" << std::endl;
}

void BaseConsoleGenesysApplication::traceSimulationHandler(TraceSimulationEvent e) {
	std::cout << e.text() << std::endl;
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
	std::cout << "(Event Handler) " << "Entity " << re->getEventProcessed()->entity() << " was removed." << std::endl;
}

void BaseConsoleGenesysApplication::setDefaultEventHandlers(OnEventManager* oem) {
	//oem->addOnSimulationStartHandler(this, &BaseConsoleGenesysApplication::onSimulationStartHandler);
	//oem->addOnReplicationStartHandler(this, BaseConsoleGenesysApplication::onReplicationStartHandler);
	oem->addOnProcessEventHandler(this, &BaseConsoleGenesysApplication::onProcessEventHandler);
	//oem->addOnReplicationEndHandler(this, &BaseConsoleGenesysApplication::onReplicationEndHandler);
	//oem->addOnSimulationEndHandler(this, &BaseConsoleGenesysApplication::onSimulationEndHandler);
	//oem->addOnEntityRemoveHandler(this, &BaseConsoleGenesysApplication::onEntityRemoveHandler);
}

void BaseConsoleGenesysApplication::setDefaultTraceHandlers(TraceManager* tm) {
	tm->addTraceHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceHandler);
	tm->addTraceErrorHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceErrorHandler);
	tm->addTraceReportHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceReportHandler);
	tm->addTraceSimulationHandler<BaseConsoleGenesysApplication>(this, &BaseConsoleGenesysApplication::traceSimulationHandler);
}

void BaseConsoleGenesysApplication::insertFakePluginsByHand(Simulator* simulator) {
	// model components
	// arena basic process
	simulator->plugins()->insert("create.so");
	simulator->plugins()->insert("dispose.so");
	simulator->plugins()->insert("decide.so");
	simulator->plugins()->insert("batch.so");
	simulator->plugins()->insert("separate.so");
	simulator->plugins()->insert("assign.so");
	simulator->plugins()->insert("record.so");
	simulator->plugins()->insert("submodel.so");
	simulator->plugins()->insert("entitytype.so");
	simulator->plugins()->insert("entitygroup.so");
	simulator->plugins()->insert("attribute.so");
	simulator->plugins()->insert("counter.so");
	simulator->plugins()->insert("queue.so");
	simulator->plugins()->insert("set.so");
	simulator->plugins()->insert("resource.so");
	simulator->plugins()->insert("variable.so");
	simulator->plugins()->insert("schedule.so");
	simulator->plugins()->insert("entitygroup.so");
	// arena advanced process
	simulator->plugins()->insert("delay.so");
	simulator->plugins()->insert("dropoff.so");
	simulator->plugins()->insert("hold.so");
	simulator->plugins()->insert("match.so");
	simulator->plugins()->insert("pickup.so");
	simulator->plugins()->insert("read.so");
	simulator->plugins()->insert("write.so");
	simulator->plugins()->insert("release.so");
	simulator->plugins()->insert("remove.so");
	simulator->plugins()->insert("seize.so");
	simulator->plugins()->insert("search.so");
	simulator->plugins()->insert("signal.so");
	simulator->plugins()->insert("store.so");
	simulator->plugins()->insert("unstore.so");
	simulator->plugins()->insert("expression.so");
	simulator->plugins()->insert("failure.so");
	simulator->plugins()->insert("file.so");
	simulator->plugins()->insert("statisticscollector.so");
	simulator->plugins()->insert("storage.so");
	// arena transfer station
	simulator->plugins()->insert("enter.so");
	simulator->plugins()->insert("leave.so");
	simulator->plugins()->insert("pickstation.so");
	simulator->plugins()->insert("route.so");
	simulator->plugins()->insert("sequence.so");
	simulator->plugins()->insert("station.so");
	// arena transfer conveyour
	simulator->plugins()->insert("access.so");
	simulator->plugins()->insert("exit.so");
	simulator->plugins()->insert("start.so");
	simulator->plugins()->insert("stop.so");
	simulator->plugins()->insert("conveyour.so");
	simulator->plugins()->insert("segment.so");
	// arena transfer transport
	simulator->plugins()->insert("alocate.so");
	simulator->plugins()->insert("free.so");
	simulator->plugins()->insert("halt.so");
	simulator->plugins()->insert("move.so");
	simulator->plugins()->insert("request.so");
	simulator->plugins()->insert("transporter.so");
	simulator->plugins()->insert("distance.so");
	simulator->plugins()->insert("network.so");
	simulator->plugins()->insert("networklink.so");
	// others
	simulator->plugins()->insert("dummy.so");
	simulator->plugins()->insert("lsode.so");
	simulator->plugins()->insert("biochemical.so");
	simulator->plugins()->insert("markovchain.so");
	simulator->plugins()->insert("cellularautomata.so");
	simulator->plugins()->insert("cppforgenesys.so");
}