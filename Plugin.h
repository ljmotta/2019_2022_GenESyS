/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plugin.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 12:58
 */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "Util.h"
#include <string>
#include <functional>

class ModelElement;
class ModelComponent;
class Model;
class ElementManager;

typedef ModelElement* (*StaticLoaderComponentInstance)(Model*, std::map<std::string, std::string>*);

class PluginInformation {
public:

    PluginInformation(std::string pluginTypename, bool isComponent, StaticLoaderComponentInstance loader) {
	this->loader = loader;
	//this->drain = drain;
	this->isComponent = isComponent;
	this->pluginTypename = pluginTypename;
	//this->source = source;
    }
    std::string pluginTypename;
    bool source;
    bool drain;
    bool isComponent;
    StaticLoaderComponentInstance loader;
};

typedef PluginInformation* (*StaticGetPluginInformation)();

/*!
 * A Plugin represents a dynamically linked component class (ModelComponent) or element class (ModelElement); It gives access to a ModelComponent so it can be used by the model. Classes like Create, Delay, and Dispose are examples of PlugIns.  It corresponds directly to the  "Expansible" part (the capitalized 'E') of the GenESyS acronymous
PlugIns are NOT implemented yet
 */
class Plugin {
public:
    Plugin(StaticGetPluginInformation getInformation); //std::string pluginTypename, bool source, bool drain);
    Plugin(const Plugin& orig);
    virtual ~Plugin();
public:
    ModelComponent* loadNewComponent(Model* model, std::map<std::string, std::string>* fields);
    ModelElement* loadNewElement(ElementManager* elems, std::map<std::string, std::string>* fields);
public:
    bool isIsValidPlugin() const;
    PluginInformation* getPluginInfo() const;
private: // read only
    bool _isValidPlugin;
    PluginInformation* _pluginInfo;
private:
    StaticGetPluginInformation _getInformation;
};

#endif /* PLUGIN_H */

