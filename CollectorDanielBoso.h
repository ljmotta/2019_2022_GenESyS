/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDanielBoso.h
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:07
 */

#ifndef COLLECTORDANIELBOSO_H
#define COLLECTORDANIELBOSO_H

#include "Collector_if.h"

class CollectorDanielBoso : public Collector_if {
public:
    CollectorDanielBoso();
    CollectorDanielBoso(const CollectorDanielBoso& orig);
    ~CollectorDanielBoso();
public:
    void clear();
    void addValue(double value);
    double getLastValue();
    unsigned long numElements();

private:
    double _lastValue;
    unsigned int _numElements = 0;
};

#endif /* COLLECTORDANIELBOSO_H */

