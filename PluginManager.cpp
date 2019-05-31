/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginManager.cpp
 * Author: rlcancian
 * 
 * Created on 30 de Maio de 2019, 17:49
 */

#include "PluginManager.h"

PluginManager::PluginManager(Simulator* simulator) {
    _simulator = simulator;
}

PluginManager::PluginManager(const PluginManager& orig) {
}

PluginManager::~PluginManager() {
}

bool PluginManager::insert(Plugin* plugin) {
}

void PluginManager::remove(Plugin* plugin) {
}

Plugin* PluginManager::find(std::string pluginTypeName) {
}