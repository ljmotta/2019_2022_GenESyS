/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterBoostImpl.h
 * Author: rlcancian
 *
 * Created on 22 de Outubro de 2019, 13:31
 */

#ifndef HYPOTHESISTESTERBOOSTIMPL_H
#define HYPOTHESISTESTERBOOSTIMPL_H

#include "HypothesisTester_if.h"
#include "Integrator_if.h"

class HypothesisTesterBoostImpl : public HypothesisTester_if {
public:
	HypothesisTesterBoostImpl();
	virtual ~HypothesisTesterBoostImpl() = default;
public:
	virtual double testAverage(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "");
	virtual double testProportion(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "");
	virtual double testVariance(double confidencelevel, H1Comparition comp, std::string secondPopulationDataFilename = "");
	virtual void setDataFilename(std::string dataFilename);
	virtual std::string getDataFilename();
private:
	Integrator_if* _integrator;
};

#endif /* HYPOTHESISTESTERBOOSTIMPL_H */

