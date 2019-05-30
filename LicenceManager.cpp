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
}

LicenceManager::LicenceManager(const LicenceManager& orig) {
}

LicenceManager::~LicenceManager() {
}

const std::string LicenceManager::getLicense() const {
    return _license;
}

