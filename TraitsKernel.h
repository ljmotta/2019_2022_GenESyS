/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */


#ifndef TRAITS_H
#define TRAITS_H


// interfaces
#include "Model.h"
#include "Collector_if.h"
#include "ModelChecker_if.h"
#include "Parser_if.h"
#include "Statistics_if.h"
#include "ModelPersistence_if.h"
#include "SimulationReporter_if.h"
#include "PluginConnector_if.h"
#include "Sampler_if.h"

//model and parts
#include "PluginConnectorDummyImpl1.h"
#include "SimulationReporterDefaultImpl1.h"
#include "ModelCheckerDefaultImpl1.h"
#include "ModelPersistenceDefaultImpl1.h"
#include "parserBisonFlex/ParserDefaultImpl2.h"
#include "StatisticsDefaultImpl1.h"
#include "CollectorDefaultImpl1.h"
#include "SamplerDefaultImpl1.h"

namespace GenesysKernel {

	template <typename T>
	struct Traits {
	};

	/*
	 *  Model and Model Parts
	 */

	template <> struct Traits<Model> {
		static const bool debugged = true;
		static const Util::TraceLevel traceLevel = Util::TraceLevel::modelSimulationEvent;
	};

	template <> struct Traits<ModelPersistence_if> {
		typedef ModelPersistenceDefaultImpl1 Implementation;
	};

	template <> struct Traits<SimulationReporter_if> {
		typedef SimulationReporterDefaultImpl1 Implementation;
	};

	template <> struct Traits<ModelChecker_if> {
		typedef ModelCheckerDefaultImpl1 Implementation;
	};

	template <> struct Traits<ModelComponent> {
		typedef StatisticsDefaultImpl1 StatisticsCollector_StatisticsImplementation;
		typedef CollectorDefaultImpl1 StatisticsCollector_CollectorImplementation;
	};

	template <> struct Traits<Sampler_if> {
		typedef SamplerDefaultImpl1 Implementation;
		typedef SamplerDefaultImpl1::DefaultImpl1RNG_Parameters Parameters;
	};

	template <> struct Traits<Parser_if> {
		typedef ParserDefaultImpl2 Implementation;
	};

	template <> struct Traits<PluginConnector_if> {
		typedef PluginConnectorDummyImpl1 Implementation;
	};
}

#endif /* TRAITS_H */

