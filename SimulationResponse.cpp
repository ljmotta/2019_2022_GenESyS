/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationResponse.cpp
 * Author: cancian
 * 
 * Created on 10 de Outubro de 2018, 16:18
 */

#include "SimulationResponse.h"


SimulationResponse::SimulationResponse(std::string type, std::string name, GetFunctor getFunctor) {
	_type = type;
	_name = name;
	_memberFunctionGetDoubleHandler = getFunctor;
}

SimulationResponse::SimulationResponse(const SimulationResponse& orig) {
}

SimulationResponse::~SimulationResponse() {
}

std::string SimulationResponse::getName() const {
	return _name;
}

std::string SimulationResponse::getType() const {
	return _type;
}


double SimulationResponse::getValue() {
	return this->_memberFunctionGetDoubleHandler();
}