/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessAnalyserDummyImpl.h
 * Author: cancian
 *
 * Created on 10 de Outubro de 2018, 18:27
 */

#ifndef PROCESSANALYSERDUMMYIMPL_H
#define PROCESSANALYSERDUMMYIMPL_H

#include "ProcessAnalyser_if.h"
#include "SimulationScenario.h"
#include "SimulationResponse.h"
#include "SimulationControl.h"

class ProcessAnalyserDummyImpl: public ProcessAnalyser_if {
public:
	ProcessAnalyserDummyImpl();
	ProcessAnalyserDummyImpl(const ProcessAnalyserDummyImpl& orig);
	~ProcessAnalyserDummyImpl();
public:
	List<SimulationScenario*>* getScenarios() const;
	List<SimulationControl*>* getControls() const;
	List<SimulationResponse*>* getResponses() const;
	List<SimulationControl*>* extractControlsFromModel(std::string modelFilename) const;
	List<SimulationResponse*>* extractResponsesFromModel(std::string modelFilename) const;
	void startSimulationOfScenario(SimulationScenario* scenario);
	void startSimulation();
	void stopSimulation();
	void addTraceSimulationListener(traceSimulationProcessListener traceSimulationProcessListener);
private:
	List<SimulationControl*>* _controls = new List<SimulationControl*>();
};

#endif /* PROCESSANALYSERDUMMYIMPL_H */

