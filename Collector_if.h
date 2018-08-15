/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collector_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 14:16
 */

#ifndef COLLECTOR_IF_H
#define COLLECTOR_IF_H

#include <string>

class Collector_if {
public:
	virtual void clear() = 0;
	virtual void addValue(double value) = 0;
	virtual double value(unsigned int num) = 0;
	virtual unsigned int numElements() = 0;
public:
	virtual std::string getName() = 0;
	virtual void setName(std::string name) = 0;
	virtual std::string getFilename() = 0;
	virtual void setFilename(std::string filename) = 0;
};

#endif /* COLLECTOR_IF_H */

