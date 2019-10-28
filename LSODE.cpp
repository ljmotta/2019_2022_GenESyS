/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LSODE.cpp
 * Author: rlcancian
 * 
 * Created on 22 de Outubro de 2019, 22:28
 */

#include "LSODE.h"
#include "Model.h"

LSODE::LSODE(Model* model) : ModelComponent(model, Util::TypeOf<LSODE>()) {
}

std::string LSODE::show() {
    return ModelComponent::show() + "";
}

ModelComponent* LSODE::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    LSODE* newComponent = new LSODE(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void LSODE::setFormula(Formula* formula) {
    this->_formula = formula;
}

Formula* LSODE::getFormula() const {
    return _formula;
}

void LSODE::_execute(Entity* entity) {
    //_parentModel->tracer()->trace("I'm just a dummy model and I'll just send the entity forward");
    for (std::list<std::string>::iterator it = _formula->getFormulaExpressions()->list()->begin(); it != _formula->getFormulaExpressions()->list()->end(); it++) {
	double value = _parentModel->parseExpression((*it));
	_parentModel->tracer()->trace("Expression \""+(*it)+"\" evaluates to "+std::to_string(value));
    }
    this->_parentModel->sendEntityToComponent(entity, this->nextComponents()->frontConnection(), 0.0);
}

bool LSODE::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	//...
    }
    return res;
}

void LSODE::_initBetweenReplications() {
}

std::map<std::string, std::string>* LSODE::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    //...
    return fields;
}

bool LSODE::_check(std::string* errorMessage) {
    bool resultAll = true;
    //...
    return resultAll;
}

PluginInformation* LSODE::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<LSODE>(), &LSODE::LoadInstance);
    // ...
    return info;
}
