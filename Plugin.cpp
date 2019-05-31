/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plugin.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 12:58
 */

#include "Plugin.h"
#include "Model.h"
#include "SourceModelComponent.h"
#include "SinkModelComponent.h"
#include "Assign.h"
#include <assert.h>

Plugin::Plugin(StaticLoaderComponentInstance loader) {
    _loader = loader;
    Model* newTempModel = new Model(nullptr);
    std::map<std::string, std::string>* newTempMap = new std::map<std::string, std::string>();
    try {
	ModelComponent* newTempComponent = _loader(newTempModel, newTempMap);
	assert(newTempComponent != nullptr);
	this->_pluginTypename = newTempComponent->getTypename();
	this->_isElement = (dynamic_cast<ModelElement*> (newTempComponent) != nullptr);
	this->_isComponent = (dynamic_cast<ModelComponent*> (newTempComponent) != nullptr);
	this->_drain = (dynamic_cast<SinkModelComponent*> (newTempComponent) != nullptr);
	this->_drain = (dynamic_cast<SinkModelComponent*> (newTempComponent) != nullptr);
	this->_source = (dynamic_cast<SourceModelComponent*> (newTempComponent) != nullptr);
	this->_isValidPlugin = true;
	newTempModel->~Model();
    } catch (...) {
	this->_isValidPlugin = false;
    }

}

bool Plugin::isValidPlugin() const {
    return _isValidPlugin;
}

bool Plugin::isComponent() const {
    return _isComponent;
}

//Plugin::Plugin(std::string pluginTypename, bool source, bool drain) {
//    //_fullfilename = fullfilename;
//    _source = source;
//    _drain = drain;
//}

Plugin::Plugin(const Plugin& orig) {
}

Plugin::~Plugin() {
}

ModelComponent* Plugin::loadNewComponent(Model* model, std::map<std::string, std::string>* fields) {
    _loader(model, fields);
}

bool Plugin::isDrain() const {
    return _drain;
}

bool Plugin::isSource() const {
    return _source;
}

std::string Plugin::getPluginTypename() const {
    return _pluginTypename;
}

std::string Plugin::getFullfilename() const {
    return _fullfilename;
}


