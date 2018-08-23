/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:03
 */

#ifndef HYPOTHESISTESTERMYIMPL1_H
#define HYPOTHESISTESTERMYIMPL1_H

#include "HypothesisTester_if.h"

class HypothesisTesterMyImpl1: public HypothesisTester_if {
public:
	HypothesisTesterMyImpl1();
	HypothesisTesterMyImpl1(const HypothesisTesterMyImpl1& orig);
	~HypothesisTesterMyImpl1();
public:
	bool testAverage(double confidencelevel, double avg, H1Comparition comp);
	bool testProportion(double confidencelevel, double prop, H1Comparition comp);
	bool testVariance(double confidencelevel, double var, H1Comparition comp);
	bool testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
	bool testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
	bool testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp);
	void setDataFilename(std::string dataFilename);
	std::string getDataFilename();
private:
};

#endif /* HYPOTHESISTESTERMYIMPL1_H */

