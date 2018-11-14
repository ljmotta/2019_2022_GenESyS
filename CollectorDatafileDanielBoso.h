/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDanielBoso.h
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:07
 */

#ifndef COLLECTORDATAFILEDANIELBOSO_H
#define COLLECTORDATAFILEDANIELBOSO_H

#include "CollectorDatafile_if.h"

class CollectorDatafileDanielBoso : public CollectorDatafile_if {
public:
    CollectorDatafileDanielBoso();
    CollectorDatafileDanielBoso(const CollectorDatafileDanielBoso& orig);
    ~CollectorDatafileDanielBoso();
public:
    void clear();
    void addValue(double value);
    double getLastValue();
    unsigned long numElements();
public:
    double getValue(unsigned int num) override;
    std::string getDataFilename() override ;
    void setDataFilename(std::string filename) override;

private:
    std::string     _filename = "";
    double          _lastValue;
    unsigned int    _numElements;
};

#endif /* COLLECTORDATAFILEDANIELBOSO_H */
