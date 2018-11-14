/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationResponse.h
 * Author: cancian
 *
 * Created on 10 de Outubro de 2018, 16:18
 */

#ifndef SIMULATIONRESPONSE_H
#define SIMULATIONRESPONSE_H

#include <string>
//#include "OnEventManager.h"
#include "Functor.h"
/*!
 * Represents any possible response of a simulation. Any infrastructure or event the model can declare one of its own attribute as a simulation response. It just have to create a SimulationResponse object, passing the access to the method that gets the response value and including this SimulationResponse in the corresponding list of the model
 */
class SimulationResponse {
public:
	SimulationResponse(std::string type, std::string name, GetFunctor getFunctor);
	SimulationResponse(const SimulationResponse& orig);
	virtual ~SimulationResponse();
public:
	double getValue();
    std::string getName() const;
    std::string getType() const;
protected:
	std::string _type;
	std::string _name;
	GetFunctor _memberFunctionGetDoubleHandler;
};

#endif /* SIMULATIONRESPONSE_H */

