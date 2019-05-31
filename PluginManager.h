/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginManager.h
 * Author: rlcancian
 *
 * Created on 30 de Maio de 2019, 17:49
 */

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "List.h"
#include "Plugin.h"

class Simulator;

class PluginManager {
public:
    PluginManager(Simulator* simulator);
    PluginManager(const PluginManager& orig);
    virtual ~PluginManager();
public:
    bool insert(Plugin* plugin);
    void remove(Plugin* plugin);
    Plugin* find(std::string pluginTypeName);
private:
    List<Plugin*>* _plugins;
    Simulator* _simulator;
};

#endif /* PLUGINMANAGER_H */

