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

LSODE::LSODE(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<LSODE>(), name) {
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
	//std::list<std::string>* eqs = _diffEquations->formulaExpressions()->list();
	unsigned int i, numEqs = _diffEquations->size();
	double k1[numEqs], k2[numEqs], k3[numEqs], k4[numEqs], valVar[numEqs];
	time = _timeVariable->value();
	initTime = time;
	tnow = _parentModel->simulation()->simulatedTime();
	bool res = time + _step <= tnow + 1e-15; // \todo: numerical error treatment by just adding 1e-15
	if (res) {
	halfStep = _step * 0.5;
	for (i = 0; i < numEqs; i++) {//(std::list<std::string>::iterator it = eqs->begin(); it != eqs->end(); it++) {
		std::string expression = _diffEquations->expression(std::to_string(i));
		valVar[i] = _variables->value(std::to_string(i));
		eqResult = _parentModel->parseExpression(expression);
		k1[i] = eqResult;
	}
	time += halfStep;
	_timeVariable->setValue(time);
	for (i = 0; i < numEqs; i++) {
		_variables->setValue(std::to_string(i), valVar[i] + k1[i] * halfStep);
	}
	for (i = 0; i < numEqs; i++) {
		eqResult = _parentModel->parseExpression(_diffEquations->expression(std::to_string(i)));
		k2[i] = eqResult;
	}
	for (i = 0; i < numEqs; i++) {
		_variables->setValue(std::to_string(i), valVar[i] + k2[i] * halfStep);
	}
	for (i = 0; i < numEqs; i++) {
		eqResult = _parentModel->parseExpression(_diffEquations->expression(std::to_string(i)));
		k3[i] = eqResult;
	}
	for (i = 0; i < numEqs; i++) {
		_variables->setValue(std::to_string(i), valVar[i] + k3[i] * halfStep);
	}
	for (i = 0; i < numEqs; i++) {
		eqResult = _parentModel->parseExpression(_diffEquations->expression(std::to_string(i)));
		k4[i] = eqResult;
	}
	for (i = 0; i < numEqs; i++) {
		eqResult = _variables->value(std::to_string(i)) +(_step / 6) * (k1[i] + 2 * (k2[i] + k3[i]) + k4[i]);
		_variables->setValue(std::to_string(i), eqResult);
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
	std::string message = "time=" + std::to_string(_timeVariable->value());
	for (unsigned int i = 0; i < _variables->dimensionSizes()->front(); i++) {
		message += " ,y[" + std::to_string(i) + "]=" + std::to_string(_variables->value(std::to_string(i)));
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
