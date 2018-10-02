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

// possible implementations
#include "CollectorMyImpl1.h"
#include "CollectorDatafileMyImpl1.h"
#include "CollectorDatafileCancianImpl.h"
#include "SamplerMyImpl1.h"
#include "Sampler_BruFabJoa.h"
#include "FitterMyImpl1.h"
#include "ModelCheckerMyImpl1.h"
#include "ParserMyImpl1.h"
#include "IntegratorMyImpl1.h"
#include "IntegratorDiogoImpl.h"
#include "HypothesisTesterMyImpl1.h"
//#include "HypothesisTesterDiogo.h"
#include "ModelPersistenceMyImpl1.h"
#include "StatisticsMyImpl1.h"
#include "StatisticsCancianImpl.h"
#include "BuildSimpleModel1.h"
//#include "testInputAnalyserTools.h"

template <typename T>
struct Traits {
	static const bool debugged = true;
	static const Util::TraceLevel traceLevel = Util::TraceLevel::TL_mostDetailed; 
};

template <> struct Traits<GenesysApplication_if> {
	//typedef TestInputAnalyserTool Application;  
	typedef BuildSimpleModel Application;  
};

template <> struct Traits<Model> {
};

template <> struct Traits<ModelComponent> {
	typedef CollectorMyImpl1 CollectorImplementation;
};

template <> struct Traits<Sampler_if> {
	//typedef SamplerMyImpl1 Implementation;
	//typedef SamplerMyImpl1::MyRNG_Parameters Parameters;
	typedef Sampler_BruFabJoa Implementation;
	typedef Sampler_BruFabJoa::MyRNG_Parameters Parameters;
};

template <> struct Traits<Fitter_if> {
	typedef FitterMyImpl1 Implementation;
};

template <> struct Traits<Collector_if> {
	//typedef CollectorDatafileMyImpl1 Implementation;
	typedef CollectorMyImpl1 ModelImplementation; //TEMP
	typedef CollectorDatafileCancianImpl Implementation;
};

template <> struct Traits<ModelChecker_if> {
	typedef ModelCheckerMyImpl1 Implementation;
};

template <> struct Traits<Parser_if> {
	typedef ParserMyImpl1 Implementation;
};

template <> struct Traits<Statistics_if> {
	//typedef StatisticsMyImpl1 Implementation;
	typedef StatisticsCancianImpl Implementation;
};

template <> struct Traits<Integrator_if> {
	//typedef IntegratorMyImpl1 Implementation;
	typedef IntegratorDiogoImpl Implementation;
};

template <> struct Traits<HypothesisTester_if> {
	typedef HypothesisTesterMyImpl1 Implementation;
	//typedef HypothesisTesterDiogo Implementation;
};

template <> struct Traits<ModelPersistence_if> {
	typedef ModelPersistenceMyImpl1 Implementation;
};

#endif /* TRAITS_H */

