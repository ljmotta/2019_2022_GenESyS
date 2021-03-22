/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentDesignDummyImpl.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 10 de Outubro de 2018, 18:32
 */

#include "ExperimentDesignDummyImpl.h"
#include "plugins/Assign.h"

ExperimentDesignDummyImpl::ExperimentDesignDummyImpl() {
}

std::list<FactorOrInteractionContribution*>* ExperimentDesignDummyImpl::getContributions() const {
	return _contributions;
}

bool ExperimentDesignDummyImpl::generate2krScenarioExperiments() {
	return true;
}

bool ExperimentDesignDummyImpl::calculateContributionAndCoefficients() {
	return true;
}

ExperimentManager_if* ExperimentDesignDummyImpl::getProcessAnalyser() const {
	return _processAnalyser;
}

