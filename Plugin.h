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

/*!
 * A Plugin represents a dynamically linked component class (ModelComponent) or element class (ModelElement); It gives access to a ModelComponent so it can be used by the model. Classes like Create, Delay, and Dispose are examples of PlugIns.  It corresponds directly to the  "Expansible" part (the capitalized 'E') of the GenESyS acronymous
PlugIns are NOT implemented yet
 */
class Plugin {
public:
    Plugin(StaticLoaderComponentInstance loader); //std::string pluginTypename, bool source, bool drain);
    Plugin(const Plugin& orig);
    virtual ~Plugin();
public:
    bool isDrain() const;
    bool isSource() const;
    bool isComponent() const;
    bool isValidPlugin() const;
    std::string getPluginTypename() const;
    std::string getFullfilename() const;
public:
    ModelComponent* loadNewComponent(Model* model, std::map<std::string, std::string>* fields);
    ModelElement* loadNewElement(ElementManager* elems, std::map<std::string, std::string>* fields);
private: // read only
    std::string _fullfilename;
    std::string _pluginTypename;
    bool _source;
    bool _drain;
    bool _isElement; // should be always true
    bool _isComponent;
    bool _isValidPlugin;
private:
    StaticLoaderComponentInstance _loader;
};

#endif /* PLUGIN_H */

