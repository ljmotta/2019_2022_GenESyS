/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterDiogo.cpp
 * Author: Diogo
 * 
 * Created on 7 de Agosto de 2018, 19:03
 */

#include "HypothesisTesterDiogo.h"
#include "Traits.h"
#include "Collector_if.h"
#include "Integrator_if.h"
#include "ProbDistrib.h"
#include "math.h"

HypothesisTesterDiogo::HypothesisTesterDiogo() {
	_collector = new Traits<Collector_if>::Implementation();
	_statistics = new Traits<Statistics_if>::Implementation();
	_statistics->setCollector(_collector);
}

HypothesisTesterDiogo::HypothesisTesterDiogo(const HypothesisTesterDiogo& orig) {
}

HypothesisTesterDiogo::~HypothesisTesterDiogo() {
}

bool HypothesisTesterDiogo::testAverage(double confidencelevel, double avg, H1Comparition comp) {
	double significancelevel = 1 - confidencelevel;
	unsigned int n = _statistics->numElements();
	double sampleMean = _statistics->average();
	double sampleSd = _statistics->stddeviation();

	double stdError = sampleSd / std::sqrt(n);
	unsigned int df = n - 1;

	double Z = (sampleMean - avg) / stdError;
	Integrator_if* integrator = new Traits<Integrator_if>::Implementation();
	double cp = integrator->integrate(0.0, std::abs(Z), &ProbDistrib::normal, 0.0, 1.0);
	double pValue = 1 - cp;
	return (pValue >= significancelevel);
}

bool HypothesisTesterDiogo::testProportion(double confidencelevel, double prop, H1Comparition comp) {
}

bool HypothesisTesterDiogo::testVariance(double confidencelevel, double var, H1Comparition comp) {
}

bool HypothesisTesterDiogo::testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

bool HypothesisTesterDiogo::testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

bool HypothesisTesterDiogo::testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

void HypothesisTesterDiogo::setDataFilename(std::string dataFilename) {
	_collector->setDataFilename("./datafile.txt");
}

std::string HypothesisTesterDiogo::getDataFilename() {
	return _collector->getDataFilename();
}