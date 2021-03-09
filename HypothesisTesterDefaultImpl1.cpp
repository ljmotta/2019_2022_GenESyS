/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 10 de Agosto de 2018, 10:27
 */

#include "HypothesisTesterDefaultImpl1.h"
#include "Traits.h"

HypothesisTesterDefaultImpl1::HypothesisTesterDefaultImpl1() {
	_integrator = new Traits<HypothesisTester_if>::IntegratorImplementation();
}

double HypothesisTesterDefaultImpl1::testAverage(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "") {
	// \todo not implemented yet
}

double HypothesisTesterDefaultImpl1::testProportion(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "") {
	// \todo not implemented yet
}

double HypothesisTesterDefaultImpl1::testVariance(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "") {
	// \todo not implemented yet
}
;

void HypothesisTesterDefaultImpl1::setDataFilename(std::string dataFilename) {
	// \todo not implemented yet
}

std::string HypothesisTesterDefaultImpl1::getDataFilename() {
	return ""; // \todo not implemented yet
}
