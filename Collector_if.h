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

/**
 * Interface for collecting values of a single stochastic variable.  Values collected can be used as base for statistical analysis. 
 */
class Collector_if {
public:
	virtual void clear() = 0;
	virtual void addValue(double value) = 0;
	virtual double getLastValue() = 0;
	virtual unsigned long numElements() = 0;
};

#endif /* COLLECTOR_IF_H */

