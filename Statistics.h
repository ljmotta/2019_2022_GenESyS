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
#include "Statistics_if.h"

class Statistics : public Statistics_if {
public:
	Statistics(Statistics_if* statistics_impl) {
		_statistics_impl = statistics_impl;
	};
	Statistics(const Statistics& orig);
	virtual ~Statistics();
public: // get & set
	void setFilename(std::string filename){
		_statistics_impl->setFilename(filename);
	};
	std::string getFilename() const {
		return _statistics_impl->getFilename();
	};
public:
	unsigned int numElements(){
		return _statistics_impl->numElements();
	};
	double min(){
		return _statistics_impl->min();
	};
	double max(){
		return _statistics_impl->max();
	};
	double average(){
		return _statistics_impl->average();
	};
	double mode(){
		return _statistics_impl->mode();
	};
	double mediane(){
		return _statistics_impl->mediane();
	};
	double variance(){
		return _statistics_impl->variance();
	};
	double stddeviation(){
		return _statistics_impl->stddeviation();
	};
	double variationCoef(){
		return _statistics_impl->variationCoef();
	};
	double halfWidth(double alpha){
		return _statistics_impl->halfWidth(alpha);
	};
	double quartil(unsigned short num){
		return _statistics_impl->quartil(num);
	};
	double decil(unsigned short num){
		return _statistics_impl->decil(num);
	};
	double centil(unsigned short num){
		return _statistics_impl->centil(num);
	};
	void setHistogramNumClasses(unsigned short num){
		_statistics_impl->setHistogramNumClasses(num);
	};
	unsigned short histogramNumClasses(){
		return _statistics_impl->histogramNumClasses();
	};
	double histogramClassLowerLimit(unsigned short classNum) {
		return _statistics_impl->histogramClassLowerLimit();
	};
	double histogramClassFrequency(unsigned short classNum){
		return _statistics_impl->histogramClassFrequency(classNum);
	};
private:
	Statistics_if* _statistics_impl;
};

#endif /* STATISTICS_H */

