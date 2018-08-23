/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 14 de Agosto de 2018, 19:43
 */

#include "CollectorMyImpl1.h"

CollectorMyImpl1::CollectorMyImpl1() {
}

CollectorMyImpl1::CollectorMyImpl1(const CollectorMyImpl1& orig) {
}

CollectorMyImpl1::~CollectorMyImpl1() {
}

void CollectorMyImpl1::clear() {
}

void CollectorMyImpl1::addValue(double value) {
}

double CollectorMyImpl1::value(unsigned int num) {
}

unsigned int CollectorMyImpl1::numElements() {
}

std::string CollectorMyImpl1::getName() {
	return _name;
}

void CollectorMyImpl1::setName(std::string name) {
	_name = name;
}

std::string CollectorMyImpl1::getDataFilename() {
	return this->_dataFilename;
}

void CollectorMyImpl1::setDataFilename(std::string filename) {
	_dataFilename = filename;
}