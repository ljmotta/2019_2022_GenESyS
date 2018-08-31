/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafile_if.h
 * Author: cancian
 *
 * Created on 30 de Agosto de 2018, 16:45
 */

#ifndef COLLECTORDATAFILE_IF_H
#define COLLECTORDATAFILE_IF_H

#include "Collector_if.h"

/**
 * Interface for collecting values of a stochastic variable that will be stores in a datafile. 
 */
class CollectorDatafile_if: public Collector_if {
public:
	virtual double getValue(unsigned int num) = 0; // same as getValue, or value[num]
	virtual std::string getDataFilename() = 0;
	virtual void setDataFilename(std::string filename) = 0;
};

#endif /* COLLECTORDATAFILE_IF_H */

