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
#include "CollectorMyImpl1.h"
//#include "Collector_if.h"
//#include "Traits.h"

class StatisticsMyImpl1 : public Statistics_if {
public:
	StatisticsMyImpl1();
	StatisticsMyImpl1(const StatisticsMyImpl1& orig);
	virtual ~StatisticsMyImpl1();
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
	Collector_if* _collector = new CollectorMyImpl1();
	/* TODO:  WTF? Why the next lines do not compile? */
	//Collector_if* _collector = new Traits<ModelComponent>::CollectorImplementation();
	//Collector_if* _collector = new Traits<Collector_if>::ModelImplementation();

};

#endif /* STATISTICSMYIMPL1_H */

