/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationControl.cpp
 * Author: cancian
 * 
 * Created on 10 de Outubro de 2018, 18:01
 */

#include "SimulationControl.h"

SimulationControl::SimulationControl(std::string type, std::string name, GetFunctor getFunctor, SetFunctor setFunctor): SimulationResponse(type, name, getFunctor) {
	this->_type = type;
    this->_memberFunctionSetDoubleHandler = setFunctor;
}

SimulationControl::SimulationControl(const SimulationControl& orig): SimulationResponse(orig) {
}

SimulationControl::~SimulationControl() {
}

void SimulationControl::setValue(double value) {
	this->_memberFunctionSetDoubleHandler(value);
}

