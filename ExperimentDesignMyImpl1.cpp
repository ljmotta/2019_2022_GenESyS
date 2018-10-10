/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExperimentDesignMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 10 de Outubro de 2018, 18:32
 */

#include "ExperimentDesignMyImpl1.h"

ExperimentDesignMyImpl1::ExperimentDesignMyImpl1() {
}

std::list<FactorOrInteractionContribution*>* ExperimentDesignMyImpl1::getContributions() const {
	return _contributions;
}

ExperimentDesignMyImpl1::ExperimentDesignMyImpl1(const ExperimentDesignMyImpl1& orig) {
}

ExperimentDesignMyImpl1::~ExperimentDesignMyImpl1() {
}

ProcessAnalyser_if* ExperimentDesignMyImpl1::getProcessAnalyser() const {
	return _processAnalyser;
}

