/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperementDesign_BrunoBonotto_JoaoSouto.h
 * Author: Bruno Bonotto and João Vicente Souto
 *
 * Created on October 30, 2018, 2:30 PM
 */

#ifndef EXPEREMENTDESIGN_BRUNOBONOTTO_JOAOSOUTO_H
#define EXPEREMENTDESIGN_BRUNOBONOTTO_JOAOSOUTO_H

#include "ExperimentDesign_if.h"
#include "ProcessAnalyser_if.h"
//#include "Traits.h"

class ExperementDesign_BrunoBonotto_JoaoSouto : public ExperimentDesign_if {
public:
	ExperementDesign_BrunoBonotto_JoaoSouto();
	ExperementDesign_BrunoBonotto_JoaoSouto(const ExperementDesign_BrunoBonotto_JoaoSouto& orig);
	virtual ~ExperementDesign_BrunoBonotto_JoaoSouto();

public:
	ProcessAnalyser_if* getProcessAnalyser() const;

public:
	bool generate2krScenarioExperiments();
	bool calculateContributionAndCoefficients();
	std::list<FactorOrInteractionContribution*>* getContributions() const;

private:
	double responses_avg;
	ProcessAnalyser_if* _processAnalyser; //= new Traits<ProcessAnalyser_if>::Implementation();

	std::list<FactorOrInteractionContribution*>* _contributions = new std::list<FactorOrInteractionContribution*>();

	std::map<SimulationScenario*, std::map<FactorOrInteractionContribution*, double>> create_table();

};

#endif /* EXPEREMENTDESIGN_BRUNOBONOTTO_JOAOSOUTO_H */
