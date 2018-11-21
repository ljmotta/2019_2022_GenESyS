/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileCancianImpl.h
 * Author: cancian
 *
 * Created on 2 de Outubro de 2018, 16:12
 */

#ifndef COLLECTORDATAFILECANCIANIMPL_H
#define COLLECTORDATAFILECANCIANIMPL_H

#include "../../CollectorDatafile_if.h"
#include <string>

class CollectorDatafileCancianImpl : public CollectorDatafile_if {
public:
	CollectorDatafileCancianImpl();
	CollectorDatafileCancianImpl(const CollectorDatafileCancianImpl& orig);
	~CollectorDatafileCancianImpl();
public:
	void clear();
	void addValue(double value);
	double getLastValue();
	unsigned long numElements();
public:
	double getValue(unsigned int num); // same as getValue, or value[num]
	std::string getDataFilename();
	void setDataFilename(std::string filename);
private:
	std::string _filename="";
};

#endif /* COLLECTORDATAFILECANCIANIMPL_H */

