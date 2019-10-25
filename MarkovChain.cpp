/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MarkovChain.cpp
 * Author: rlcancian
 * 
 * Created on 24 de Outubro de 2019, 18:26
 */

#include "MarkovChain.h"

#include "Model.h"

MarkovChain::MarkovChain(Model* model) : ModelComponent(model, Util::TypeOf<MarkovChain>()) {
}


std::string MarkovChain::show() {
    return ModelComponent::show() + "";
}

ModelComponent* MarkovChain::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    MarkovChain* newComponent = new MarkovChain(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void MarkovChain::_execute(Entity* entity) {
    _model->tracer()->trace(Util::TraceLevel::blockInternal, "I'm just a dummy model and I'll just send the entity forward");
    this->_model->sendEntityToComponent(entity, this->getNextComponents()->frontConnection(), 0.0);
}

bool MarkovChain::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	//...
    }
    return res;
}

void MarkovChain::_initBetweenReplications() {
}

std::map<std::string, std::string>* MarkovChain::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    //...
    return fields;
}

bool MarkovChain::_check(std::string* errorMessage) {
    bool resultAll = true;
    //...
    return resultAll;
}

PluginInformation* MarkovChain::GetPluginInformation(){
    PluginInformation* info = new PluginInformation(Util::TypeOf<MarkovChain>(), &MarkovChain::LoadInstance);
    // ...
    return info;
}

