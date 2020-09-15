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
#include "Variable.h"
#include "ProbDistribDefaultImpl1.h"
#include "Simulator.h"

MarkovChain::MarkovChain(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<MarkovChain>(),name) {
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

void MarkovChain::setTransitionProbabilityMatrix(Variable* _transitionMatrix) {
    this->_transitionProbMatrix = _transitionMatrix;
}

Variable* MarkovChain::getTransitionMatrix() const {
    return _transitionProbMatrix;
}

Variable* MarkovChain::getCurrentState() const {
    return _currentState;
}

void MarkovChain::setCurrentState(Variable* _currentState) {
        this->_currentState = _currentState;
    }

void MarkovChain::setInitialDistribution(Variable* _initialDistribution) {
    this->_initialDistribution = _initialDistribution;
}

Variable* MarkovChain::getInitialState() const {
    return _initialDistribution;
}

void MarkovChain::setInitilized(bool _initilized) {
    this->_initilized = _initilized;
}

bool MarkovChain::isInitilized() const {
    return _initilized;
}

void MarkovChain::_execute(Entity* entity) {
    //_parentModel->tracer()->trace("I'm just a dummy model and I'll just send the entity forward");
    unsigned int size;
    double rnd, sum, value;
    if (!_initilized) {
	// define the initial state based on initial probabilities
	size = _initialDistribution->dimensionSizes()->front();
	rnd = _parentModel->parentSimulator()->tools()->sampler()->random();
	sum = 0.0;
	for (unsigned int i = 0; i < size; i++) {
	    value = _initialDistribution->value(std::to_string(i));
	    sum += value;
	    if (sum > rnd) {
		_currentState->setValue(i); // _currentState =  i;
		break;
	    }
	}
	_parentModel->tracer()->trace("Initial current state=" + std::to_string(_currentState->value()));
	_initilized = true;
    } else {
	size = _transitionProbMatrix->dimensionSizes()->front();
	rnd = _parentModel->parentSimulator()->tools()->sampler()->random();
	sum = 0.0;
	for (unsigned int i = 0; i < size; i++) {
	    std::string index = std::to_string(static_cast<unsigned int>(_currentState->value())) + "," + std::to_string(i);
	    value = _transitionProbMatrix->value(index);
	    sum += value;
	    if (sum > rnd) {
		_currentState->setValue(i);
		break;
	    }
	}
	_parentModel->tracer()->trace("Current state=" + std::to_string(_currentState->value()));
    }
    _parentModel->sendEntityToComponent(entity, this->nextComponents()->frontConnection(), 0.0);
}

bool MarkovChain::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
	//...
    }
    return res;
}

void MarkovChain::_initBetweenReplications() {
    this->_initilized = false;
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

PluginInformation* MarkovChain::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<MarkovChain>(), &MarkovChain::LoadInstance);
    // ...
    return info;
}

