/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsMyImpl1.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 16:52
 */

#ifndef STATISTICSMYIMPL1_H
#define STATISTICSMYIMPL1_H

#include "Statistics_if.h"

class StatisticsMyImpl1: public Statistics_if {
public:
	StatisticsMyImpl1();
	StatisticsMyImpl1(const StatisticsMyImpl1& orig);
	~StatisticsMyImpl1();
public:
    void setDataFilename(std::string _filename);
    std::string getDataFilename() const;
public:
	unsigned int numElements();
	double min();
	double max();
	double average();
	double mode();
	double mediane();
	double variance();
	double stddeviation();
	double variationCoef();
	double halfWidthConfidenceInterval(double confidencelevel);
	unsigned int newSampleSize(double confidencelevel, double halfWidth);
	double quartil(unsigned short num);
	double decil(unsigned short num);
	double centil(unsigned short num);
	void setHistogramNumClasses(unsigned short num);
	unsigned short histogramNumClasses();
	double histogramClassLowerLimit(unsigned short classNum);
	unsigned int histogramClassFrequency(unsigned short classNum);
private:

};

#endif /* STATISTICSMYIMPL1_H */

