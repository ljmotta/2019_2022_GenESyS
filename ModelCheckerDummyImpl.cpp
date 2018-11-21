/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerDummyImpl.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 15:52
 */

#include <list>

#include "ModelCheckerDummyImpl.h"

ModelCheckerDummyImpl::ModelCheckerDummyImpl(Model* model) {
	_model = model;
}

ModelCheckerDummyImpl::ModelCheckerDummyImpl(const ModelCheckerDummyImpl& orig) {
}

ModelCheckerDummyImpl::~ModelCheckerDummyImpl() {
}

bool ModelCheckerDummyImpl::checkAll() {
	bool res = true;
	res &= checkConnected();
	res &= checkPathway();
	res &= checkSymbols();
	res &= checkAndAddInternalLiterals();
	res &= checkActivationCode();
	return res;
}

bool ModelCheckerDummyImpl::checkAndAddInternalLiterals() {
	return true;
}

bool ModelCheckerDummyImpl::checkConnected() {
	return true;
}

bool ModelCheckerDummyImpl::checkSymbols() {
	bool res = true;
	std::string* errorMessage;  // replaced by errorMessages in model??
	List<ModelComponent*>* components = this->_model->getComponents();
	for (std::list<ModelComponent*>::iterator it= components->getList()->begin(); it!=components->getList()->end(); it++) {
		res &= (*it)->VerifySymbols((*it), errorMessage);
	}
	return res;
}

bool ModelCheckerDummyImpl::checkPathway() {
	/* TODO +-: not implemented yet */
	return true;

}

bool ModelCheckerDummyImpl::checkActivationCode() {
	return true;
}

bool ModelCheckerDummyImpl::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
	bool res = true;
	if (mandatory && expression=="") {
		_model->getTracer()->getErrorMessages()->insert("Error verifying symbol \""+expressionName+"\" of component \""+componentName+"\n: Mandatory symbol is empty");
		res = false;
	}
	/* TODO: Not implemented yet */
	return res;
}