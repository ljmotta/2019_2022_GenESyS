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
	return ModelInfrastructure::show();
}

void Variable::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Variable::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Variable::_verifySymbols(std::string* errorMessage) {
}
