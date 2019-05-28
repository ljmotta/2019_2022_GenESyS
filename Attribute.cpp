/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 25 de Setembro de 2018, 16:37
 */

#include "Attribute.h"

Attribute::Attribute() : ModelElement(Util::TypeOf<Attribute>()) {
}


Attribute::Attribute(std::string name) : ModelElement(Util::TypeOf<Attribute>()) {
    _name = name;
}

Attribute::Attribute(const Attribute& orig) : ModelElement(orig) {
}

Attribute::~Attribute() {
}

std::string Attribute::show() {
    return ModelElement::show();
}

void Attribute::_loadInstance(std::list<std::string> fields) {
}

std::list<std::string>* Attribute::_saveInstance() {
    std::list<std::string>* fields = ModelElement::_saveInstance();//Util::TypeOf<Attribute>());
    return fields;
}

bool Attribute::_check(std::string* errorMessage) {
    return true;
}