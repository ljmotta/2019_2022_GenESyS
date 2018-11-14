/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 30 de Agosto de 2018, 16:53
 */

#include "CollectorDatafileMyImpl1.h"

CollectorDatafileMyImpl1::CollectorDatafileMyImpl1() {
}

CollectorDatafileMyImpl1::CollectorDatafileMyImpl1(const CollectorDatafileMyImpl1& orig) {
}

CollectorDatafileMyImpl1::~CollectorDatafileMyImpl1() {
}

void CollectorDatafileMyImpl1::clear() {
}

void CollectorDatafileMyImpl1::addValue(double value) {
}

double CollectorDatafileMyImpl1::getLastValue() {
}

unsigned long CollectorDatafileMyImpl1::numElements() {
}

double CollectorDatafileMyImpl1::getValue(unsigned int num) {
}

std::string CollectorDatafileMyImpl1::getDataFilename() {
	return _filename;
}

void CollectorDatafileMyImpl1::setDataFilename(std::string filename) {
	_filename = filename;
}
