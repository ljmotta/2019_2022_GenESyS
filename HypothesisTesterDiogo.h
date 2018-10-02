/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTesterDiogo.h
 * Author: Diogo
 *
 * Created on 7 de Agosto de 2018, 19:03
 */

#ifndef HYPOTHESISTESTERDIOGO_H
#define HYPOTHESISTESTERDIOGO_H

#include "HypothesisTester_if.h"
#include "CollectorDatafile_if.h"
#include "Statistics_if.h"

class HypothesisTesterDiogo: public HypothesisTester_if {
public:
	HypothesisTesterDiogo();
	HypothesisTesterDiogo(const HypothesisTesterDiogo& orig);
	~HypothesisTesterDiogo();
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
	CollectorDatafile_if* _collector;
	Statistics_if* _statistics;
};

#endif /* HYPOTHESISTESTERDIOGO_H */

