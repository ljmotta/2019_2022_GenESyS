/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statistics_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 13:47
 */

#ifndef STATISTICS_IF_H
#define STATISTICS_IF_H

#include <string>
#include "Collector_if.h"

/**
 * Interface for statisct synthesis of a stochastic variable collected by a Collector_if. The statistics generated may be updated based only on the previous statistics and the single newest added value or they may be updated based on a datafile, depending on the Collector implementation.
 */
class Statistics_if {
public:
	virtual Collector_if* getCollector() = 0;
	virtual void setCollector(Collector_if* collector) = 0;
public:
	virtual unsigned int numElements() = 0;
	virtual double min() = 0;
	virtual double max() = 0;
	virtual double average() = 0;
	virtual double mode() = 0;
	virtual double mediane() = 0;
	virtual double variance() = 0;
	virtual double stddeviation() = 0;
	virtual double variationCoef() = 0;
	virtual double halfWidthConfidenceInterval(double confidencelevel) = 0;
	virtual unsigned int newSampleSize(double confidencelevel, double halfWidth) = 0;
	virtual double quartil(unsigned short num) = 0;
	virtual double decil(unsigned short num) = 0;
	virtual double centil(unsigned short num) = 0;
	virtual void setHistogramNumClasses(unsigned short num) = 0;
	virtual unsigned short histogramNumClasses() = 0;
	virtual double histogramClassLowerLimit(unsigned short classNum) = 0;
	virtual unsigned int histogramClassFrequency(unsigned short classNum) = 0;
};

#endif /* STATISTICS_IF_H */

