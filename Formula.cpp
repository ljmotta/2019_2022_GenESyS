/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formula.cpp
 * Author: rlcancian
 * 
 * Created on 20 de Junho de 2019, 00:56
 */

#include "Formula.h"
#include <iostream>
#include "ElementManager.h"
#include "Model.h"
#include "Traits.h"

Formula::Formula(Model* model) : ModelElement(model, Util::TypeOf<Formula>()) {
    //_elements = elements;
    _myPrivateParser = new Traits<Parser_if>::Implementation(_parentModel);
}

double Formula::getValue(unsigned int index = 0) const {
    std::string expression = this->_formulaExpressions->getAtRank(index);
    double value = _parentModel->parseExpression(expression);
}

std::string Formula::show() {
    std::string expressions = "";
    unsigned int i=0;
    for (std::list<std::string>::iterator it = _formulaExpressions->list()->begin(); it != _formulaExpressions->list()->end(); it++) {
	expressions += "expression["+std::to_string(i++)+"]=\""+(*it)+"\"; "; 
    }
    
    return ModelElement::show() + expressions;
}

PluginInformation* Formula::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Formula>(), &Formula::LoadInstance);
    return info;
}

ModelElement* Formula::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Formula* newElement = new Formula(model);
    try {
	newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

List<std::string>* Formula::getFormulaExpressions() const {
    return _formulaExpressions;
}

bool Formula::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelElement::_loadInstance(fields);
}

std::map<std::string, std::string>* Formula::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelElement::_saveInstance();
    //fields->emplace("...", std::to_string(this->_...));
    return fields;
}

bool Formula::_check(std::string* errorMessage) {
    std::string errorMsg = "";
    bool res, resAll = true;
    unsigned int i = 0;
    for (std::list<std::string>::iterator it = _formulaExpressions->list()->begin(); it != _formulaExpressions->list()->end(); it++) {
	res= _parentModel->checkExpression((*it), "formula expression["+std::to_string(i++)+"]", &errorMsg);
	if (!res) {
	    _parentModel->tracer()->trace(Util::TraceLevel::errors, "Error parsing expression \""+(*it)+"\"");
	}
	resAll &= res;
    }
    return resAll;
}
