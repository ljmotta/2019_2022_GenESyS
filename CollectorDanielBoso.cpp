/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDanielBoso.cpp
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:07
 */

#include "CollectorDanielBoso.h"

CollectorDanielBoso::CollectorDanielBoso() {}

CollectorDanielBoso::CollectorDanielBoso(const CollectorDanielBoso& orig) {}

CollectorDanielBoso::~CollectorDanielBoso() {}

void CollectorDanielBoso::clear() {
    _numElements = 0;
}

void CollectorDanielBoso::addValue(double value) {
    _lastValue = value;
    _numElements++;
}

double CollectorDanielBoso::getLastValue() {
    return this->_lastValue;
}

unsigned long CollectorDanielBoso::numElements() {
    return this->_numElements;
}