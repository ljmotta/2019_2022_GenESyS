/*
 * HypothesisTesterar.h
 *
 *  Created on: 25 de set de 2018
 *      Author: ribeiro
 */

#ifndef HYPOTHESISTESTER_AR_H_
#define HYPOTHESISTESTER_AR_H_

#include "HypothesisTester_if.h"
#include "Integrator_ar.h"
#include <fstream>


class HypothesisTester_ar: public HypothesisTester_if {
public:
	HypothesisTester_ar();
	HypothesisTester_ar(const HypothesisTester_ar& orig);
	~HypothesisTester_ar();
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
	std::string fileName;

};

#endif /* HYPOTHESISTESTER_AR_H_ */
