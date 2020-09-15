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
	this->_StatMethodGetInformation = getInformation;
	try {
		PluginInformation* infos = _StatMethodGetInformation();
		this->_pluginInfo = infos;
		this->_isValidPlugin = true;
	} catch (...) {
		this->_isValidPlugin = false;
	}
}

PluginInformation* Plugin::pluginInfo() const {
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

ModelElement* Plugin::loadNew(Model* model, std::map<std::string, std::string>* fields) {
	if (this->_pluginInfo->isComponent()) {
		return _loadNewComponent(model, fields);
	} else {
		return _loadNewElement(model, fields);
	}
}

bool Plugin::loadAndInsertNew(Model* model, std::map<std::string, std::string>* fields) {
	if (this->_pluginInfo->isComponent()) {
		ModelComponent* newComp = _loadNewComponent(model, fields);
		if (newComp != nullptr) {
			//model->getTraceManager()->trace(newComp->show());
			return true; //model->components()->insert(newComp);
		}
	} else {
		ModelElement* newElem = _loadNewElement(model, fields);
		if (newElem != nullptr) {
			//model->getTraceManager()->trace(newElem->show());
			return true; //model->elements()->insert(this->_pluginInfo->pluginTypename(), newElem);
		}
	}
	return false;
}

ModelComponent* Plugin::_loadNewComponent(Model* model, std::map<std::string, std::string>* fields) {
	//return this->_pluginInfo->loader(model, fields);
	StaticLoaderComponentInstance loader = this->_pluginInfo->componentLoader();
	ModelComponent* newElementOrComponent = loader(model, fields);
	return newElementOrComponent;
}

ModelElement* Plugin::_loadNewElement(Model* model, std::map<std::string, std::string>* fields) {
	StaticLoaderElementInstance loader = this->_pluginInfo->elementloader();
	ModelElement* newElementOrComponent = loader(model, fields);
	return newElementOrComponent;
}
