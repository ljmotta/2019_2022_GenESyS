/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decide.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 9 de Agosto de 2018, 20:39
 */

#include "Decide.h"
#include "Model.h"

Decide::Decide(Model* model) : ModelComponent(model, Util::TypeOf<Decide>()) {
}

List<std::string>* Decide::getConditions() const {
    return _conditions;
}


std::string Decide::show() {
    return ModelComponent::show() + "";
}

void Decide::_execute(Entity* entity) {
    double value;
    unsigned short i = 0;
    for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++) {
	value = _parentModel->parseExpression((*it));
	_parentModel->tracer()->traceSimulation(_parentModel->simulation()->simulatedTime(), entity, this, std::to_string(i + 1) + "th condition evaluated to " + std::to_string(value) + "  // " + (*it));
	if (value) {
	    _parentModel->sendEntityToComponent(entity, this->nextComponents()->getConnectionAtRank(i), 0.0);
	    return;
	}
	i++;
    }
    _parentModel->tracer()->traceSimulation(_parentModel->simulation()->simulatedTime(), entity, this, "No condition has been evaluated true");
    _parentModel->sendEntityToComponent(entity, this->nextComponents()->getConnectionAtRank(i), 0.0);
}

void Decide::_initBetweenReplications() {
}

bool Decide::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	unsigned int nv = std::stoi((*(fields->find("conditions"))).second);
	for (unsigned int i = 0; i < nv; i++) {
	    this->_conditions->insert((*(fields->find("condition" + std::to_string(i)))).second);
	}
    }
    return res;
}

std::map<std::string, std::string>* Decide::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Decide>());
    unsigned short i = 0;
    fields->emplace("conditions", std::to_string(_conditions->size()));
    for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++) {
	fields->emplace("condition" + std::to_string(i++), (*it));
    }
    return fields;
}

bool Decide::_check(std::string* errorMessage) {
    bool allResult = true;
    std::string condition;
    for (std::list<std::string>::iterator it = _conditions->list()->begin(); it != _conditions->list()->end(); it++) {
	condition = (*it);
	allResult &= _parentModel->checkExpression(condition, "condition", errorMessage);
    }
    return allResult;
}

PluginInformation* Decide::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Decide>(), &Decide::LoadInstance);
    return info;
}

ModelComponent* Decide::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Decide* newComponent = new Decide(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}