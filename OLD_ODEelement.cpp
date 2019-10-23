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

#include "OLD_ODEelement.h"
#include "Model.h"

OLD_ODEelement::OLD_ODEelement(ElementManager* elems) : ModelElement(Util::TypeOf<OLD_ODEelement>()) {
    _elems = elems;
}


std::string OLD_ODEelement::show() {
    std::string txt =  ModelElement::show();
    unsigned short i=0;
    for (std::list<ODEfunction*>::iterator it = _ODEfunctions->getList()->begin(); it != _ODEfunctions->getList()->end(); it++) {
	txt += ",func["+std::to_string(i)+"]=\""+(*it)->expression+"\",(func["+std::to_string(i)+"]["+std::to_string((*it)->initialPoint)+"]="+std::to_string((*it)->initialValue)+")";
    }
    return txt;
}

double OLD_ODEelement::solve() {
    ////
    return 0.0; // dummy
}


void OLD_ODEelement::setStepH(double _h) {
    this->_stepH = _h;
}

double OLD_ODEelement::getStepH() const {
    return _stepH;
}

void OLD_ODEelement::setEndTime(double _endTime) {
    this->_endTime = _endTime;
}

double OLD_ODEelement::getEndTime() const {
    return _endTime;
}

List<ODEfunction*>* OLD_ODEelement::getODEfunctions() const {
    return _ODEfunctions;
}

PluginInformation* OLD_ODEelement::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<OLD_ODEelement>(), &OLD_ODEelement::LoadInstance); 
    return info;
}

ModelElement* OLD_ODEelement::LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields) {
    OLD_ODEelement* newElement = new OLD_ODEelement(elems);
    try {
	newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool OLD_ODEelement::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelElement::_loadInstance(fields);    
}

std::map<std::string, std::string>* OLD_ODEelement::_saveInstance() {
    return ModelElement::_saveInstance();
}

bool OLD_ODEelement::_check(std::string* errorMessage) {
    bool result = true;
    unsigned short i=0;
    ODEfunction* func;
    for (std::list<ODEfunction*>::iterator it = _ODEfunctions->getList()->begin(); it != _ODEfunctions->getList()->end(); it++) {
	func = (*it);
	result &= _elems->getParentModel()->checkExpression(func->expression, "expression["+std::to_string(i++)+"]", errorMessage);
    }
    return result;
}
