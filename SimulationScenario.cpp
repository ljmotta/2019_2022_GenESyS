/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationScenario.cpp
 * Author: cancian
 * 
 * Created on 10 de Outubro de 2018, 18:21
 */

#include "SimulationScenario.h"

SimulationScenario::SimulationScenario() {
}

SimulationScenario::SimulationScenario(const SimulationScenario& orig) {
}

SimulationScenario::~SimulationScenario() {
}

void SimulationScenario::setName(std::string _name) {
	this->_name = _name;
}

std::string SimulationScenario::getName() const {
	return _name;
}

std::list<double>* SimulationScenario::getResponseValues() const {
	return _responseValues;
}

std::list<double>* SimulationScenario::getControlValues() const {
	return _controlValues;
}

void SimulationScenario::setModelFilename(std::string _modelFilename) {
	this->_modelFilename = _modelFilename;
}

std::string SimulationScenario::getModelFilename() const {
	return _modelFilename;
}

double SimulationScenario::getResponseValue(SimulationResponse* value) {
	return 0.0;
}

double SimulationScenario::getControlValue(SimulationControl* control) {
	return 0.0;
}

void SimulationScenario::setControlValue(SimulationControl* control, double value) {

}