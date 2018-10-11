/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentDesignMyImpl1.h
 * Author: cancian
 *
 * Created on 10 de Outubro de 2018, 18:32
 */

#ifndef EXPERIMENTDESIGNMYIMPL1_H
#define EXPERIMENTDESIGNMYIMPL1_H

#include "ExperimentDesign_if.h"

/*!
 *
 */
class ExperimentDesignMyImpl1 : public ExperimentDesign_if {
public:
	ExperimentDesignMyImpl1();
	ExperimentDesignMyImpl1(const ExperimentDesignMyImpl1& orig);
	virtual ~ExperimentDesignMyImpl1();
public:
	ProcessAnalyser_if* getProcessAnalyser() const;
public:
	bool generate2krScenarioExperiments();
	bool calculateContributionAndCoefficients();
	std::list<FactorOrInteractionContribution*>* getContributions() const;
private:
	ProcessAnalyser_if* _processAnalyser; //= new Traits<ExperimentDesign_if>::ProcessAnalyserImplementation();
	std::list<FactorOrInteractionContribution*>* _contributions = new std::list<FactorOrInteractionContribution*>();
};
#endif /* EXPERIMENTDESIGNMYIMPL1_H */
