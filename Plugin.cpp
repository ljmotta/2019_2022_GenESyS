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

Plugin::Plugin(StaticGetPluginInformation getInformation) {
    this->_getInformation = getInformation;
    try {
	PluginInformation* infos = _getInformation();
	this->_isValidPlugin = true;
    } catch (...) {
	this->_isValidPlugin = false;
    }
}

PluginInformation* Plugin::getPluginInfo() const {
    return _pluginInfo;
}

bool Plugin::isIsValidPlugin() const {
    return _isValidPlugin;
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
    return this->_pluginInfo->loader(model, fields);
}

