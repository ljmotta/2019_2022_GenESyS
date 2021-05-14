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
