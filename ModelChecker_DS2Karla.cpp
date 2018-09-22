/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelChecker_DS2Karla.cpp
 * Author: karla
 * 
 * Created on 19 de Setembro de 2018, 16:01
 */

#include "ModelChecker_DS2Karla.h"
#include "SinkModelComponent.h"
#include "SourceModelComponent.h"

ModelChecker_DS2Karla::ModelChecker_DS2Karla(Model* model) {
    _model = model;
}

ModelChecker_DS2Karla::ModelChecker_DS2Karla(const ModelChecker_DS2Karla& orig) {
}

ModelChecker_DS2Karla::~ModelChecker_DS2Karla() {
}

bool ModelChecker_DS2Karla::checkAll() {
	bool res = checkConnected();
	if (res) res = checkPathway();
	if (res) res = checkSymbols();
	if (res) res = checkAndAddInternalLiterals();
	if (res) res = checkActivationCode();
	return res;
}

bool ModelChecker_DS2Karla::checkAndAddInternalLiterals() {
	return true;
}

bool ModelChecker_DS2Karla::checkConnected() {
    List<ModelComponent*>* components = this->_model->getComponents();
    
    /*From every Create component, it will be verified a path to a Dispose Component.*/
    for (std::list<ModelComponent*>::iterator it= components->getList()->begin(); it!=components->getList()->end(); it++) {
        if(dynamic_cast<SourceModelComponent*>(*it)){
            //
            checkConnectionToDispose((*it)->getNextComponents());
            (*it)->setCheckedConnection((*it)->getNextComponents()->getList()->front()->getCheckedConnection());
        }
    }
    
    /*It will check if all the components were visited and respect the rule*/
    for (std::list<ModelComponent*>::iterator it= components->getList()->begin(); it!=components->getList()->end(); it++) {
        //printf("!!CheckComponent = %s\n", (*it)->getCheckedConnection() ? "true" : "false");
        if(!(*it)->getCheckedConnection()){
            return false;
        }
    }
    return true;
}

/*If the path ends up with dispose returns true, if don't returns false*/
void ModelChecker_DS2Karla::checkConnectionToDispose(List<ModelComponent*>* components){
        
    for (std::list<ModelComponent*>::iterator next = components->getList()->begin(); next!=components->getList()->end(); next++) {
        if(!(*next)->getNextComponents()->empty()){
            checkConnectionToDispose((*next)->getNextComponents());
            (*next)->setCheckedConnection((*next)->getNextComponents()->getList()->front()->getCheckedConnection());
            //return (*next)->getCheckedConnection();
        }
        else if(dynamic_cast<SinkModelComponent*>(*next) || (*next)->getCheckedConnection()){
            (*next)->setCheckedConnection(true);
            //return true;
        }
    }
    //return false;
}

bool ModelChecker_DS2Karla::checkSymbols() {
	bool res = true;
	std::string* errorMessage;  // replaced by errorMessages in model??
	List<ModelComponent*>* components = this->_model->getComponents();
	for (std::list<ModelComponent*>::iterator it= components->getList()->begin(); it!=components->getList()->end(); it++) {
		res &= (*it)->VerifySymbols((*it), errorMessage);
	}
	return res;
}

bool ModelChecker_DS2Karla::checkPathway() {
	/* TODO +-: not implemented yet */
	return true;

}

bool ModelChecker_DS2Karla::checkActivationCode() {
	return true;
}

bool ModelChecker_DS2Karla::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
	bool res = true;
	if (mandatory && expression=="") {
		_model->getErrorMessages()->insert("Error verifying symbol \""+expressionName+"\" of component \""+componentName+"\n: Mandatory symbol is empty");
		res = false;
	}
	/* TODO: Not implemented yet */
	return res;
}