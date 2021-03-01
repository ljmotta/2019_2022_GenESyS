/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationReporterDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 8 de Agosto de 2018, 10:59
 */

#ifndef SIMULATIONREPORTERDEFAULTIMPL1_H
#define SIMULATIONREPORTERDEFAULTIMPL1_H

#include "SimulationReporter_if.h"
#include "ModelSimulation.h"
#include "Model.h"

//namespace GenesysKernel {

	/*!
	 * Class that implements SimulationReporter_if interface and is responsible for building and showing replication and simulation reports
	 */
	class SimulationReporterDefaultImpl1 : public SimulationReporter_if {
	public:
		SimulationReporterDefaultImpl1(ModelSimulation* simulation, Model* model, List<ModelElement*>* statsCountersSimulation);
		virtual ~SimulationReporterDefaultImpl1() = default;
	public:
		virtual void showReplicationStatistics();
		virtual void showSimulationStatistics(); //List<StatisticsCollector*>* cstatsSimulation);
	private:
		//List<StatisticsCollector*>* getStatisticsFromParent( std::string parent );
	private:
		ModelSimulation* _simulation;
		Model* _model;
	private:
		List<ModelElement*>* _statsCountersSimulation;
	private:
		const unsigned short _w = 12;
		const unsigned short _nameW = 40;
	};
//namespace\\}
#endif /* SIMULATIONREPORTERDEFAULTIMPL1_H */

