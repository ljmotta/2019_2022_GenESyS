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

void LSODE::setDiffEquations(Formula* formula) {
    _diffEquations = formula;
}

Formula* LSODE::getDiffEquations() const {
    return _diffEquations;
}

void LSODE::setTimeVariable(Variable* timeVariable) {
    _timeVariable = timeVariable;
}

Variable* LSODE::getTimeVariable() const {
    return _timeVariable;
}

void LSODE::setStep(double step) {
    _step = step;
}

double LSODE::getStep() const {
    return _step;
}

void LSODE::setVariables(Variable* variables) {
    _variables = variables;
}

Variable* LSODE::getVariables() const {
    return _variables;
}

bool LSODE::_doStep() {
    double initTime, time, tnow, eqResult, halfStep;
    std::list<std::string>* eqs = _diffEquations->getFormulaExpressions()->list();
    unsigned int i, numEqs = eqs->size();
    double k1[numEqs], k2[numEqs], k3[numEqs], k4[numEqs], valVar[numEqs];
    time = _timeVariable->getValue();
    initTime = time;
    tnow = _parentModel->simulation()->simulatedTime();
    bool res = time + _step <= tnow + 1e-15; // TODO: numerical error treatment by just adding 1e-15
    if (res) {
	halfStep = _step * 0.5;
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    valVar[i] = _variables->getValue(std::to_string(i));
	    eqResult = _parentModel->parseExpression((*it));
	    k1[i++] = eqResult;
	}
	time += halfStep;
	_timeVariable->setValue(time);
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    _variables->setValue(std::to_string(i), valVar[i] + k1[i] * halfStep);
	    i++;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    eqResult = _parentModel->parseExpression((*it));
	    k2[i++] = eqResult;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    _variables->setValue(std::to_string(i), valVar[i] + k2[i] * halfStep);
	    i++;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    eqResult = _parentModel->parseExpression((*it));
	    k3[i++] = eqResult;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    _variables->setValue(std::to_string(i), valVar[i] + k3[i] * halfStep);
	    i++;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    eqResult = _parentModel->parseExpression((*it));
	    k4[i++] = eqResult;
	}
	i = 0;
	for (std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
	    eqResult = _variables->getValue(std::to_string(i)) +(_step / 6) * (k1[i] + 2 * (k2[i] + k3[i]) + k4[i]);
	    _variables->setValue(std::to_string(i++), eqResult);
	}
	time = initTime + _step;
	_timeVariable->setValue(time);
    }
    return res;
}

void LSODE::_execute(Entity* entity) {
    //_parentModel->tracer()->trace("I'm just a dummy model and I'll just send the entity forward");
    //for (std::list<std::string>::iterator it = _diffEquations->getFormulaExpressions()->list()->begin(); it != _diffEquations->getFormulaExpressions()->list()->end(); it++) {
    //double value = _parentModel->parseExpression((*it));
    //_parentModel->tracer()->trace("Expression \"" + (*it) + "\" evaluates to " + std::to_string(value));
    //}
    while (_doStep()) {// execute solve ODE step by step until reach TNOW
	std::string message = "time=" + std::to_string(_timeVariable->getValue());
	for (unsigned int i = 0; i < _variables->getDimensionSizes()->front(); i++) {
	    message += " ,y[" + std::to_string(i) + "]=" + std::to_string(_variables->getValue(std::to_string(i)));
	}
	_parentModel->tracer()->trace(message);
    }
    _parentModel->sendEntityToComponent(entity, nextComponents()->frontConnection(), 0.0);
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
