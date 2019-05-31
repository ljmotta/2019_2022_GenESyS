/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LicenceManager.cpp
 * Author: rlcancian
 * 
 * Created on 29 de Maio de 2019, 11:45
 */

#include "LicenceManager.h"

LicenceManager::LicenceManager(Simulator* simulator) {
    _simulator = simulator;
    _licence = "Academic Mode. In academic mode this software has full functionality and executing training-size simulation models. This software may be duplicated and used for educational purposes only; any commercial application is a violation of the license agreement. Designed and developed by prof. Dr. Ing Rafael Luiz Cancian";
    _activationCode = "";
    _components = 100;
    _elements = 100;
    _entities = 150;
    _hosts = 2;
    _threads = 1;
}

LicenceManager::LicenceManager(const LicenceManager& orig) {
}

LicenceManager::~LicenceManager() {
}

const std::string LicenceManager::showLicense() const {
    return _licence;
}

bool LicenceManager::lookforActivationCode() {
}

bool LicenceManager::insertActivationCode() {
}

void LicenceManager::removeActivationCode() {
}

unsigned int LicenceManager::getModelComponentsLimit() {
    return this->_components;
}

unsigned int LicenceManager::getModelElementsLimit() {
    return this->_elements;
}

unsigned int LicenceManager::getEntityLimit() {
    return this->_entities;
}

unsigned int LicenceManager::getHostsLimit() {
    return this->_hosts;
}

unsigned int LicenceManager::getThreadsLimit() {
    return this->_threads;
}
