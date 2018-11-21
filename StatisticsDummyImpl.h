/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsDummyImpl.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 16:52
 */

#ifndef STATISTICSDUMMYIMPL_H
#define STATISTICSDUMMYIMPL_H

#include "Statistics_if.h"
#include "CollectorDummyImpl.h"
//#include "Collector_if.h"
//#include "Traits.h"

class StatisticsDummyImpl : public Statistics_if {
public:
	StatisticsDummyImpl();
	StatisticsDummyImpl(const StatisticsDummyImpl& orig);
	virtual ~StatisticsDummyImpl();
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
	Collector_if* _collector = new CollectorDummyImpl();
	/* TODO:  WTF? Why the next lines do not compile? */
	//Collector_if* _collector = new Traits<ModelComponent>::CollectorImplementation();
	//Collector_if* _collector = new Traits<Collector_if>::ModelImplementation();

};

#endif /* STATISTICSDUMMYIMPL_H */

