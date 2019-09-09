/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enter.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Enter.h"
#include "Model.h"

Enter::Enter(Model* model) : ModelComponent(model, Util::TypeOf<Enter>()) {
}

Enter::Enter(const Enter& orig) : ModelComponent(orig) {
}

Enter::~Enter() {
}

std::string Enter::show() {
    return ModelComponent::show() + "";
}

ModelComponent* Enter::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Enter* newComponent = new Enter(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void Enter::setStation(Station* _station) {
    this->_station = _station;
}

Station* Enter::getStation() const {
    return _station;
}

void Enter::_execute(Entity* entity) {
    _model->sendEntityToComponent(entity, this->getNextComponents()->frontConnection(), 0.0);
}

bool Enter::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
    }
    return res;
}

void Enter::_initBetweenReplications() {
}

std::map<std::string, std::string>* Enter::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    return fields;
}

bool Enter::_check(std::string* errorMessage) {
    return true;
}

PluginInformation* Enter::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Enter>(), &Enter::LoadInstance);
    info->setReceiveTransfer(true);
    return info;
}

