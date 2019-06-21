/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ODE.cpp
 * Author: rlcancian
 * 
 * Created on 13 de Junho de 2019, 19:12
 */

#include "ODE.h"

ODE::ODE() : ModelElement(Util::TypeOf<ODE>()) {
}

ODE::ODE(const ODE& orig) : ModelElement(orig) {
}

ODE::~ODE() {
}

void ODE::setExpression(std::string expression) {
    this->expression = expression;
}

std::string ODE::getExpression() const {
    return expression;
}

std::string ODE::show() {
    return ModelElement::show() + ",ODE=.";
}

bool ODE::_loadInstance(std::map<std::string, std::string>* fields) {
}

std::map<std::string, std::string>* ODE::_saveInstance() {
}

bool ODE::_check(std::string* errorMessage) {
}
