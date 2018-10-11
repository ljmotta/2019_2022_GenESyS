/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorMyImpl1.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:43
 */

#ifndef COLLECTORMYIMPL1_H
#define COLLECTORMYIMPL1_H

#include <string>
#include "Collector_if.h"

class CollectorMyImpl1 : public Collector_if {
public:
	CollectorMyImpl1();
	CollectorMyImpl1(const CollectorMyImpl1& orig);
	~CollectorMyImpl1();
public:
	void clear();
	void addValue(double value);
	double getLastValue();
	unsigned long numElements();

private:
	double _lastValue;
	unsigned long _numElements = 0;
};

#endif /* COLLECTORMYIMPL1_H */

