/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.cpp
 * Author: cancian
 * 
 * Created on 4 de Setembro de 2018, 18:28
 */

#include "Variable.h"

Variable::Variable() : ModelInfrastructure(Util::TypeOf<Variable>()) {
}

Variable::Variable(const Variable& orig) : ModelInfrastructure(orig) {
}

Variable::~Variable() {
}

std::string Variable::show() {
	return ModelInfrastructure::show(); // @TODO: include values
}

double Variable::getValue() {
	return getValue("");
}

double Variable::getValue(std::string index) {
	std::map<std::string, double>::iterator it = _values->find(index);
	if (it == _values->end()) {
		return 0.0; // index does not exist. Assuming sparse matrix, it's zero. 
	} else {
		return it->second;
	}
}

void Variable::setValue(double value) {
	setValue("", value);
}

void Variable::setValue(std::string index, double value) {
	std::map<std::string, double>::iterator it = _values->find(index);
	if (it == _values->end()) {
		// index does not exist. Create it.
		_values->insert(std::pair<std::string, double>(index, value));
	} else {
		it->second = value;
	}
}

void Variable::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Variable::_saveInstance() {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance(Util::TypeOf<Variable>());
	return words;
}

bool Variable::_verifySymbols(std::string* errorMessage) {
	return true;
}
