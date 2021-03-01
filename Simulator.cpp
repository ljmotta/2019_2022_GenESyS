/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Genesys.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 12:48
 */

#include "Simulator.h"
#include "LicenceManager.h"
//#include "ToolManager.h"

extern "C" GenesysSimulator CreateSimulator2() {
	return new /*GenesysKernel::*/Simulator();
}

extern "C" /*GenesysKernel::*/Simulator* CreateSimulator() {
	return new /*GenesysKernel::*/Simulator();
}

extern "C" void DestroySimulator2(GenesysSimulator p) {
	delete p; // Can use a base class or derived class pointer here
}

extern "C" void DestroySimulator(/*GenesysKernel::*/Simulator* p) {
	delete p; // Can use a base class or derived class pointer here
}


//using namespace GenesysKernel;

Simulator::Simulator() {
	// This is the ONLY method in the entire software where std::cout is allowed.
	std::cout << "STARTING " << _name << ", version " << _version << std::endl;
	_licenceManager = new LicenceManager(this);
	_pluginManager = new PluginManager(this);
	_modelManager = new ModelManager(this);
	//_toolManager = new ToolManager(this);
	_traceManager = new TraceManager(this);
	std::cout << '|' << '\t' << _licenceManager->showLicence() << std::endl;
	//std::cout << '|' << '\t' << _licenceManager->showActivationCode() << std::endl;
	//std::cout << '|' << '\t' << _licenceManager->showLimits() << std::endl;
}

PluginManager* Simulator::plugins() const {
	return _pluginManager;
}

ModelManager* Simulator::models() const {
	return _modelManager;
}

TraceManager* Simulator::tracer() const {
	return _traceManager;
}

ParserManager* Simulator::parser() const {
	return _parserManager;
}

std::string Simulator::version() const {
	return _version;
}

std::string Simulator::name() const {
	return _name;
}

LicenceManager* Simulator::licenceManager() const {
	return _licenceManager;
}

