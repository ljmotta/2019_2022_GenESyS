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

// possible implementations
#include "CollectorMyImpl1.h"
#include "SamplerMyImpl1.h"
#include "FitterMyImpl1.h"
#include "ModelCheckerMyImpl1.h"
#include "ParserMyImpl1.h"
#include "StatisticsMyImpl1.h"
#include "IntegratorMyImpl1.h"

template <typename T>
struct Traits {
	static const bool debugged = true;
};

template <> struct Traits<Model> {
};

template <> struct Traits<Sampler_if> {
	typedef SamplerMyImpl1 Implementation;
};

template <> struct Traits<Fitter_if> {
	typedef FitterMyImpl1 Implementation;
};

template <> struct Traits<Collector_if> {
	typedef CollectorMyImpl1 Implementation;
};

template <> struct Traits<ModelChecker_if> {
	typedef ModelCheckerMyImpl1 Implementation;
};

template <> struct Traits<Parser_if> {
	typedef ParserMyImpl1 Implementation;
};

template <> struct Traits<Statistics_if> {
	typedef StatisticsMyImpl1 Implementation;
};

template <> struct Traits<Integrator_if> {
	typedef IntegratorMyImpl1 Implementation;
};

#endif /* TRAITS_H */

