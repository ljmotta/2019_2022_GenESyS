/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 15:52
 */

#include <list>

#include "ModelCheckerMyImpl1.h"

ModelCheckerMyImpl1::ModelCheckerMyImpl1(Model* model) {
	_model = model;
}

ModelCheckerMyImpl1::ModelCheckerMyImpl1(const ModelCheckerMyImpl1& orig) {
}

ModelCheckerMyImpl1::~ModelCheckerMyImpl1() {
}

bool ModelCheckerMyImpl1::checkAll() {
	bool res = checkConnected();
	if (res) res = checkPathway();
	if (res) res = checkSymbols();
	if (res) res = checkAndAddInternalLiterals();
	if (res) res = checkActivationCode();
	return res;
}

bool ModelCheckerMyImpl1::checkAndAddInternalLiterals() {
	return true;
}

bool ModelCheckerMyImpl1::checkConnected() {
	return true;
}

bool ModelCheckerMyImpl1::checkSymbols() {
	bool res = true;
	std::string* errorMessage;  // replaced by errorMessages in model??
	List<ModelComponent*>* components = this->_model->getComponents();
	for (std::list<ModelComponent*>::iterator it= components->getList()->begin(); it!=components->getList()->end(); it++) {
		res &= (*it)->VerifySymbols((*it), errorMessage);
	}
	return res;
}

bool ModelCheckerMyImpl1::checkPathway() {
	/* TODO +-: not implemented yet */
	std::list<ModelComponent*>* list = _model->getComponents()->getList();
	for (std::list<ModelComponent*>::iterator it = list->begin(); it != list->end(); it++) {
		_model->trace(Util::TraceLevel::TL_mostDetailed, (*it)->show()); ////
	}
	return true;

}

bool ModelCheckerMyImpl1::checkActivationCode() {
	return true;
}

bool ModelCheckerMyImpl1::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
	bool res = true;
	if (mandatory && expression=="") {
		_model->getErrorMessages()->insert("Error verifying symbol \""+expressionName+"\" of component \""+componentName+"\n: Mandatory symbol is empty");
		res = false;
	}
	/* TODO: Not implemented yet */
	return res;
}