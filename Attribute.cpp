/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.cpp
 * Author: cancian
 * 
 * Created on 25 de Setembro de 2018, 16:37
 */

#include "Attribute.h"

Attribute::Attribute() : ModelInfrastructure(Util::TypeOf<Attribute>()) {
}

Attribute::Attribute(const Attribute& orig) : ModelInfrastructure(orig) {
}

Attribute::~Attribute() {
}

std::string Attribute::show() {
	return ModelInfrastructure::show(); 
}

void Attribute::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Attribute::_saveInstance() {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance(Util::TypeOf<Attribute>());
	return words;
}

bool Attribute::_verifySymbols(std::string* errorMessage) {
	return true;
}