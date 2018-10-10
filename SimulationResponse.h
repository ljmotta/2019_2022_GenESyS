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
#include "Listener.h"

class SimulationResponse {
public:
	SimulationResponse(std::string type, std::string name, void* getHandler);
	SimulationResponse(const SimulationResponse& orig);
	virtual ~SimulationResponse();
public:
	double getValue();
    std::string getName() const;
    std::string getType() const;
private:
	std::string _type;
	std::string _name;
	void* _getHandler;
	//setDoubleVarHandler _setHandler;
};

#endif /* SIMULATIONRESPONSE_H */

