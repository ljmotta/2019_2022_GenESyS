/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analyser.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:03
 */

#ifndef ANALYSER_H
#define ANALYSER_H

enum Comparition {
	LESS_THAN	= 1,
	EQUAL		= 2,
	DIFFERENT	= 3,
	GREATER_THAN	= 4
};


class Analyser {
public:
	Analyser();
	Analyser(const Analyser& orig);
	~Analyser();
public:
	double semiConfidenceInterval(double confidencelevel);
	unsigned int newSampleLenght(double confidencelevel);
	bool isNormalDistribution(double confidencelevel);
	bool testAverageDifference(double confidencelevel, double avg, Comparition comp, bool nullhipothesys);
	bool testProportionDifference(double confidencelevel, double prop, Comparition comp, bool nullhipothesys);
	bool testVarianceDifference(double confidencelevel, double var, Comparition comp, bool nullhipothesys);
	bool testAverageDifference(double confidencelevel, char *filename2, Comparition comp, bool nullhipothesys);
	unsigned int bachSize(double maxcovariance);
private:
	//AnalyserImpl * _a;
};

#endif /* ANALYSER_H */

