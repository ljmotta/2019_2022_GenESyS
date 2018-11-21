/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCancianImpl.h
 * Author: cancian
 *
 * Created on 2 de Outubro de 2018, 17:33
 */

#ifndef STATISTICSCANCIANIMPL_H
#define STATISTICSCANCIANIMPL_H

#include "../../Statistics_if.h"

class StatisticsCancianImpl : public Statistics_if {
public:
	StatisticsCancianImpl();
	StatisticsCancianImpl(const StatisticsCancianImpl& orig);
	virtual ~StatisticsCancianImpl();
public:
	Collector_if* getCollector();
	void setCollector(Collector_if* collector);
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
	Collector_if* _collector;
};

#endif /* STATISTICSCANCIANIMPL_H */

