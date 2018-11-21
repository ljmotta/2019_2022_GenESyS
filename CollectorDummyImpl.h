/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDummyImpl.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:43
 */

#ifndef COLLECTORDUMMYIMPL_H
#define COLLECTORDUMMYIMPL_H

#include <string>
#include "Collector_if.h"

class CollectorDummyImpl : public Collector_if {
public:
	CollectorDummyImpl();
	CollectorDummyImpl(const CollectorDummyImpl& orig);
	~CollectorDummyImpl();
public:
	void clear();
	void addValue(double value);
	double getLastValue();
	unsigned long numElements();

private:
	double _lastValue;
	unsigned long _numElements = 0;
};

#endif /* COLLECTORDUMMYIMPL_H */

