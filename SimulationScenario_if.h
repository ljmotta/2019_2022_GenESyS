/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationScenario.h
 * Author: cancian
 *
 * Created on 2 de Outubro de 2018, 22:42
 */

#ifndef SIMULATIONSCENARIO_IF_H
#define SIMULATIONSCENARIO_IF_H

#include <string>

/*!
 * This class specifies a simulation scenario. The simulation scenario has only a name and an associated model to be simulated. The model will be simulated after one or model SimulationControl be set to a specific value, and one or more SimulationResponses will be collected.  
 */
class SimulationScenario_if {
public:
	virtual std::string getName() = 0;
	virtual void setName(std::string name) = 0;
	virtual std::string getModelFilename() = 0;
	virtual void setModelFilename(std::string modelFilename) = 0;
};

#endif /* SIMULATIONSCENARIO_IF_H */

