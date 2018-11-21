/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */

#ifndef TRAITS_H
#define TRAITS_H

// interfaces
#include "Model.h"
#include "Collector_if.h"
#include "Sampler_if.h"
#include "Fitter_if.h"
#include "ModelChecker_if.h"
#include "Parser_if.h"
#include "Statistics_if.h"
#include "Integrator_if.h"
#include "HypothesisTester_if.h"
#include "ModelPersistence_if.h"
#include "GenesysApplication_if.h"
#include "ProcessAnalyser_if.h"
#include "ExperimentDesign_if.h"

// possible implementations

// genesys applications
#include "BuildSimulationModel.h"
#include "TestInputAnalyserTools.h"
#include "TestParser.h"

// dummy implementations
#include "CollectorDummyImpl.h"
#include "SamplerDummyImpl.h"
#include "FitterDummyImpl.h"
#include "ParserDummyImpl.h"
#include "ModelCheckerDummyImpl.h"
#include "IntegratorDummyImpl.h"
#include "ExperimentDesignDummyImpl.h"
#include "StatisticsDummyImpl.h"
#include "ProcessAnalyserDummyImpl.h"
#include "CollectorDatafileDummyImpl.h"
#include "HypothesisTesterDummyImpl.h"
#include "ModelPersistenceDummyImpl.h"

// students implementations

template <typename T>
struct Traits {
};

template <> struct Traits<GenesysApplication_if> {
	//typedef TestInputAnalyserTools Application;  
	typedef BuildSimulationModel Application;  
	//typedef TestParser Application;  
};

template <> struct Traits<Model> {
	static const bool debugged = true;
	static const Util::TraceLevel traceLevel = Util::TraceLevel::mostDetailed; 
};

template <> struct Traits<ModelComponent> {
	typedef CollectorDummyImpl CollectorImplementation;
};

template <> struct Traits<Sampler_if> {
	typedef SamplerDummyImpl Implementation;
	typedef SamplerDummyImpl::MyRNG_Parameters Parameters;
};

template <> struct Traits<Fitter_if> {
	typedef FitterDummyImpl Implementation;
};

template <> struct Traits<Collector_if> {
	typedef CollectorDatafileDummyImpl Implementation;
	typedef CollectorDummyImpl ModelImplementation; //TEMP
};

template <> struct Traits<ModelChecker_if> {
	typedef ModelCheckerDummyImpl Implementation;
};

template <> struct Traits<Parser_if> {
	typedef ParserDummyImpl Implementation;
};

template <> struct Traits<Statistics_if> {
	typedef StatisticsDummyImpl Implementation;
};

template <> struct Traits<Integrator_if> {
	typedef IntegratorDummyImpl Implementation;
	unsigned int MaxIterations = 1000;
	double MaxError = 1e-9;
};

template <> struct Traits<HypothesisTester_if> {
	typedef HypothesisTesterDummyImpl Implementation;
};

template <> struct Traits<ModelPersistence_if> {
	typedef ModelPersistenceDummyImpl Implementation;
};

template <> struct Traits<ExperimentDesign_if> {
	typedef ExperimentDesignDummyImpl Implementation;
};

template <> struct Traits<ProcessAnalyser_if> {
	typedef ProcessAnalyserDummyImpl Implementation;
};

#endif /* TRAITS_H */

