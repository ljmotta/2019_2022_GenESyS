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

#include <string>
#include <fstream>

#include "CollectorDatafileDanielBoso.h"

CollectorDatafileDanielBoso::CollectorDatafileDanielBoso() { }

CollectorDatafileDanielBoso::CollectorDatafileDanielBoso(const CollectorDatafileDanielBoso& orig) { }

CollectorDatafileDanielBoso::~CollectorDatafileDanielBoso() { }

void CollectorDatafileDanielBoso::clear() {
    std::ofstream file;
    file.open(_filename, std::ofstream::out | std::ofstream::trunc);
    file.close();
    _numElements = 0;
}

void CollectorDatafileDanielBoso::addValue(double value) {
    std::ofstream file;
    file.open(_filename, std::ofstream::out | std::ofstream::app);
    file << value << "\n";
    file.close();
    _lastValue = value;
    _numElements++;
}

double CollectorDatafileDanielBoso::getLastValue() {
    return _lastValue;
}

unsigned long CollectorDatafileDanielBoso::numElements() {
    return _numElements;
}

double CollectorDatafileDanielBoso::getValue(unsigned int num) {
    std::ifstream file;
    file.open(_filename, std::ifstream::in);
  
    std::string value;
    
    // Jump num lines
    for (int i = 0; i < num-1 && (!file.eof()); i++) {
        std::getline(file, value);
    }
    std::getline(file, value);
    file.close();
    return std::stod(value);
}

std::string CollectorDatafileDanielBoso::getDataFilename() {
    return _filename;
}

void CollectorDatafileDanielBoso::setDataFilename(std::string filename) {
    _filename = filename;
}
