/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alocate.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:16
 */

#include "Allocate.h"

#include "Model.h"

Allocate::Allocate(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Allocate>(),name) {
}


std::string Allocate::show() {
    return ModelComponent::show() + "";
}

ModelComponent* Allocate::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Allocate* newComponent = new Allocate(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void Allocate::_execute(Entity* entity) {
    _parentModel->tracer()->trace("I'm just a dummy model and I'll just send the entity forward");
    this->_parentModel->sendEntityToComponent(entity, this->nextComponents()->frontConnection(), 0.0);
}

bool Allocate::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	//...
    }
    return res;
}

void Allocate::_initBetweenReplications() {
}

std::map<std::string, std::string>* Allocate::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    //...
    return fields;
}

bool Allocate::_check(std::string* errorMessage) {
    bool resultAll = true;
    //...
    return resultAll;
}

PluginInformation* Allocate::GetPluginInformation(){
    PluginInformation* info = new PluginInformation(Util::TypeOf<Allocate>(), &Allocate::LoadInstance);
    // ...
    return info;
}


