/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 30 de Maio de 2019, 17:49
 */

#include "PluginManager.h"
#include "Simulator.h"

PluginManager::PluginManager(Simulator* simulator) {
    _simulator = simulator;
}

PluginManager::PluginManager(const PluginManager& orig) {
}

PluginManager::~PluginManager() {
}

bool PluginManager::check(Plugin* plugin){
    //@TODO
    return true;
}

bool PluginManager::insert(Plugin* plugin) {
    PluginInformation *plugInfo = plugin->getPluginInfo();
    if (plugin->isIsValidPlugin() && plugInfo != nullptr) {
	this->_plugins->insert(plugin);
	std::string msg = "Plugin for ";
	if (plugInfo->isComponent) {
	    msg+= "component";
	} else {
	    msg+="element";
	}
	msg+=" \"" + plugin->getPluginInfo()->pluginTypename + "\" successfully inserted";
	this->_simulator->getTraceManager()->trace(Util::TraceLevel::blockInternal, msg);
	return true;
    } else {
	plugin->~Plugin(); // destroy the invalid plugin
	return false;
    }
}

void PluginManager::remove(Plugin* plugin) {
}

Plugin* PluginManager::find(std::string pluginTypeName) {
    for (std::list<Plugin*>::iterator it = this->_plugins->getList()->begin(); it != _plugins->getList()->end(); it++) {
	if ((*it)->getPluginInfo()->pluginTypename == pluginTypeName) {
	    return (*it);
	}
    }
    return nullptr;
}

Plugin* PluginManager::front() {
    return this->_plugins->front();
}

Plugin* PluginManager::next() {
    return _plugins->next();
}

Plugin* PluginManager::last() {
    return this->_plugins->last();
}