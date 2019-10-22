/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterBoostImpl.cpp
 * Author: rlcancian
 * 
 * Created on 22 de Outubro de 2019, 13:31
 */

#include "HypothesisTesterBoostImpl.h"

HypothesisTesterBoostImpl::HypothesisTesterBoostImpl() {
}

HypothesisTesterBoostImpl::HypothesisTesterBoostImpl(const HypothesisTesterBoostImpl& orig) {
}
// default destructor


double HypothesisTesterBoostImpl::testAverage(double confidencelevel, double avg, H1Comparition comp) {
    return 0.0; //todo
}

double HypothesisTesterBoostImpl::testProportion(double confidencelevel, double prop, H1Comparition comp) {
    return 0.0; //todo
}

double HypothesisTesterBoostImpl::testVariance(double confidencelevel, double var, H1Comparition comp) {
    return 0.0; //todo
}

double HypothesisTesterBoostImpl::testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
    return 0.0; //todo
}

double HypothesisTesterBoostImpl::testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
    return 0.0; //todo
}

double HypothesisTesterBoostImpl::testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
    return 0.0; //todo
}

void HypothesisTesterBoostImpl::setDataFilename(std::string dataFilename) {
}

std::string HypothesisTesterBoostImpl::getDataFilename() {
    return ""; //todo
}
