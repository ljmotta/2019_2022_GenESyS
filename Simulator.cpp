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
#include "ToolManager.h"

Simulator::Simulator() {
    std::cout << "Now running " << _name << std::endl; // The ONLY cout allowed "inside" the simulator (including model and other classes, pls
    _licenceManager = new LicenceManager(this);
    _pluginManager = new PluginManager(this);
    _modelManager = new ModelManager(this);
    _toolManager = new ToolManager(this);
    
}

PluginManager* Simulator::getPluginManager() const {
    return _pluginManager;
}

ModelManager* Simulator::getModelManager() const {
    return _modelManager;
}

ToolManager* Simulator::getToolManager() const {
    return _toolManager;
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

std::string Simulator::getVersion() const {
    return _version;
}

std::string Simulator::getName() const {
    return _name;
}

LicenceManager* Simulator::getLicenceManager() const {
    return _licenceManager;
}

