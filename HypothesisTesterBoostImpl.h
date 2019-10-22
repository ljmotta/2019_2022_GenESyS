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
    HypothesisTesterBoostImpl(const HypothesisTesterBoostImpl& orig);
    virtual ~HypothesisTesterBoostImpl() = default;
public:
    virtual double testAverage(double confidencelevel, double avg, H1Comparition comp);
    virtual double testProportion(double confidencelevel, double prop, H1Comparition comp);
    virtual double testVariance(double confidencelevel, double var, H1Comparition comp);
    virtual double testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual double testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual double testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
    virtual void setDataFilename(std::string dataFilename);
    virtual std::string getDataFilename();
private:
    Integrator_if* _integrator;
};

#endif /* HYPOTHESISTESTERBOOSTIMPL_H */

