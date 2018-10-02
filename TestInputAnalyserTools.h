/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testInputAnalyserTools.h
 * Author: cancian
 *
 * Created on 2 de Outubro de 2018, 19:31
 */

#ifndef TESTINPUTANALYSERTOOLS_H
#define TESTINPUTANALYSERTOOLS_H

using namespace std;

#include "GenesysApplication_if.h"

// GEnSyS Simulator
#include "Simulator.h"

// Configuration
#include "Traits.h"

// Simulator tool objects
#include "Sampler_if.h" // old MMC
#include "Fitter_if.h"

// Tools and Utils
//#include "Collector_if.h"
//#include "CollectorDatafile_if.h"
#include "HypothesisTester_if.h"
#include "Integrator_if.h"
#include "ProbDistrib.h"
#include "Sampler_if.h"
#include "Statistics_if.h"

class TestInputAnalyserTools : public GenesysApplication_if {
public: 
	TestInputAnalyserTools();
public:
	int main(int argc, char** argv);
};

#endif /* TESTINPUTANALYSERTOOLS_H */

