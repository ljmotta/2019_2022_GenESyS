/*
 * HypothesisTesterar.cpp
 *
 *  Created on: 25 de set de 2018
 *      Author: ribeiro
 */

#include "HypothesisTester_ar.h"

HypothesisTester_ar::HypothesisTester_ar() {
	// TODO Auto-generated constructor stub

}

HypothesisTester_ar::HypothesisTester_ar(const HypothesisTester_ar& orig) {
}

HypothesisTester_ar::~HypothesisTester_ar() {
	// TODO Auto-generated destructor stub
}

bool HypothesisTester_ar::testAverage(double confidencelevel, double avg, H1Comparition comp) {

	double alfa = 1 - confidencelevel;
	double z = 0;
	//z = integrator
	switch (comp) {
		case 1:
			if (avg < -z)
				return comp;
			else {
				if (avg < z)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (avg > -z and avg < z)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (avg > -z and avg < z)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (avg > z)
				return comp;
			else {
				if (avg < -z)
					return 1;
				else
					return 2;
			}

	}
}

bool HypothesisTester_ar::testProportion(double confidencelevel, double prop, H1Comparition comp) {
	double alfa = 1 - confidencelevel;
	double z = 0;
	//z = integrator
	switch (comp) {
		case 1:
			if (prop < -z)
				return comp;
			else {
				if (prop < z)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (prop > -z and prop < z)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (prop > -z and prop < z)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (prop > z)
				return comp;
			else {
				if (prop < -z)
					return 1;
				else
					return 2;
			}
	}
}

bool HypothesisTester_ar::testVariance(double confidencelevel, double var, H1Comparition comp) {
	double alfa = 1 - confidencelevel;
	double z = 0;
	//z = integrator
	switch (comp) {
		case 1:
			if (var < -z)
				return comp;
			else {
				if (var < z)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (var > -z and var < z)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (var > -z and var < z)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (var > z)
				return comp;
			else {
				if (var < -z)
					return 1;
				else
					return 2;
			}

	}
}

bool HypothesisTester_ar::testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
	double alfa = 1 - confidencelevel;
	double z1 = 0;
	double z2 = 0;
	//z1 = integrator
	//z2 integrator
	switch (comp) {
		case 1:
			if (z1 < z2)
				return comp;
			else {
				if (z1 == z2)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (z1 == z2)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (z1 == z2)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (z1 > z2)
				return comp;
			else {
				if (z1 != z2)
					return 1;
				else
					return 2;
			}

	}
}

bool HypothesisTester_ar::testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
	double alfa = 1 - confidencelevel;
	double z1 = 0;
	double z2 = 0;
	//z1 = integrator
	//z2 integrator
	switch (comp) {
		case 1:
			if (z1 < z2)
				return comp;
			else {
				if (z1 == z2)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (z1 == z2)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (z1 == z2)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (z1 > z2)
				return comp;
			else {
				if (z1 != z2)
					return 1;
				else
					return 2;
			}

	}
}

bool HypothesisTester_ar::testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
	double alfa = 1 - confidencelevel;
	double z1 = 0;
	double z2 = 0;
	//z1 = integrator
	//z2 integrator
	switch (comp) {
		case 1:
			if (z1 < z2)
				return comp;
			else {
				if (z1 == z2)
					return 2;
				else
					return 4;
			}
			break;
		case 2:
			if (z1 == z2)
				return comp;
			else
				return 3;
			break;
		case 3:
			if (z1 == z2)
				return 2;
			else
				return comp;
			break;
		case 4:
			if (z1 > z2)
				return comp;
			else {
				if (z1 != z2)
					return 1;
				else
					return 2;
			}

	}
}

void HypothesisTester_ar::setDataFilename(std::string dataFilename) {
	fileName = dataFilename;
}

std::string HypothesisTester_ar::getDataFilename() {
	return fileName;
}
