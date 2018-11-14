/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperementDesign_BrunoBonotto_JoaoSouto.cpp
 * Author: Bruno Bonotto and João Vicente Souto
 * 
 * Created on October 30, 2018, 2:31 PM
 */

#include "ExperementDesign_BrunoBonotto_JoaoSouto.h"
#include "SimulationScenario.h"
#include "Assign.h"
#include "Traits.h"

#include <iostream>
#include <map>
#include <set>

ExperementDesign_BrunoBonotto_JoaoSouto::ExperementDesign_BrunoBonotto_JoaoSouto() {
	_processAnalyser = new Traits<ProcessAnalyser_if>::Implementation();
}

std::list<FactorOrInteractionContribution*>* ExperementDesign_BrunoBonotto_JoaoSouto::getContributions() const {
	return _contributions;
}

ExperementDesign_BrunoBonotto_JoaoSouto::ExperementDesign_BrunoBonotto_JoaoSouto(const ExperementDesign_BrunoBonotto_JoaoSouto& orig) {
}

ExperementDesign_BrunoBonotto_JoaoSouto::~ExperementDesign_BrunoBonotto_JoaoSouto() {
}

bool ExperementDesign_BrunoBonotto_JoaoSouto::generate2krScenarioExperiments() {
	return true;
}

ProcessAnalyser_if* ExperementDesign_BrunoBonotto_JoaoSouto::getProcessAnalyser() const {
	return _processAnalyser;
}

/*
	Makes the n fatorial
 */
int factorial(int n) {
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

/*
	Makes the combination of n s to s
 */
int combination(int n, int s) {
	return factorial(n) / (factorial(s) * factorial(n - s));
}

/*
	Makes the sum of all combinations of n from 1 to n whitout repetition
 */
int total_combination(int n) {
	int total = 0;

	for (int s = 1; s <= n; s++)
		total += combination(n, s);

	return total;
}

/*
	Generates the table with all factors and their combinations
 */
std::map<SimulationScenario*, std::map<FactorOrInteractionContribution*, double>> ExperementDesign_BrunoBonotto_JoaoSouto::create_table() {
	auto scenarios = _processAnalyser->getScenarios()->getList();
	auto responses = _processAnalyser->getResponses()->getList();
	auto controls = _processAnalyser->getControls()->getList();

	std::map<SimulationControl*, std::map<double, double>> levels;

	for (auto scenario : *scenarios)
		for (auto control : *controls)
			levels[control][scenario->getControlValue(control)] = 0;

	for (auto l : levels) {
		auto control = l.first;
		auto it = l.second.begin();

		levels[control][it->first] = -1;
		levels[control][(++it)->first] = 1;
	}

	//! Build combination
	std::set<std::set < SimulationControl*>> sets;
	int k = _processAnalyser->getControls()->size();

	for (auto control : *controls)
		sets.insert({control});

	while (sets.size() != total_combination(k))
		for (auto control : *controls)
			for (std::set<SimulationControl*> set : sets) {
				set.insert(control);
				sets.insert(set);
			}

	std::map<SimulationScenario*, std::map < FactorOrInteractionContribution*, double>> table;

	for (auto set : sets) {
		auto combination = new FactorOrInteractionContribution(0, 0, new std::list<SimulationControl*>(set.begin(), set.end()));
		_contributions->push_back(combination);

		for (auto scenario : *scenarios) {
			double x = 1;
			for (auto control : set)
				x *= levels[control][scenario->getControlValue(control)];

			table[scenario][combination] = x;
		}
	}

	return table;
}

/*
	Calculates the contribution and coefficient to each factor
 */
bool ExperementDesign_BrunoBonotto_JoaoSouto::calculateContributionAndCoefficients() {
	auto scenarios = _processAnalyser->getScenarios()->getList();
	auto responses = _processAnalyser->getResponses()->getList();

	auto table = create_table();

	//! Calculate responses
	std::map<SimulationScenario*, double> responses_sum;
	for (auto scenario : *scenarios) {
		responses_sum[scenario] = 0;
		for (auto response : *responses)
			responses_sum[scenario] += scenario->getResponseValue(response);

		responses_avg += responses_sum[scenario];
	}

	//! Calculates responses average
	responses_avg /= (responses->size() * scenarios->size());

	//! Calculates SST
	double SST = 0;
	for (auto scenario : *scenarios)
		for (auto response : *responses)
			SST += pow(scenario->getResponseValue(response) - responses_avg, 2);

	int k = _processAnalyser->getControls()->size();

	//! Calculates the contribution and coefficient for each factor
	for (auto combination : *_contributions) {
		double coef = 0;
		for (auto scenario : *scenarios)
			coef += table[scenario][combination] * responses_sum[scenario];

		double SS = pow(coef, 2) / (pow(2, k) * responses->size());
		double contribution = SS / SST;
		coef /= (4 * pow(responses->size(), 2)); // CONFERIR

		auto list = combination->getControls();
		*combination = FactorOrInteractionContribution(contribution, coef, new std::list<SimulationControl*>(list->begin(), list->end()));
	}

	return true;
}


