/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statistics.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 18:32
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>

class Statistics {
public:
	Statistics();
	Statistics(const Statistics& orig);
	virtual ~Statistics();
//public:
	//void clear();
	//void addValue(double value);
public: // get & set
    void setFilename(std::string _filename);
    std::string getFilename() const;
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
	double halfWidth(double alpha);
	double quartil(unsigned short num);
	double decil(unsigned short num);
	double centil(unsigned short num);
	void setHistogramNumClasses(unsigned short num);
	unsigned short histogramNumClasses();
	double histogramClassLowerLimit(unsigned short classNum);
	double histogramClassFrequency(unsigned short classNum);
private:
	std::string _filename="";
};

#endif /* STATISTICS_H */

