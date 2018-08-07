/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statistics.cpp
 * Author: cancian
 * 
 * Created on 7 de Agosto de 2018, 18:32
 */

#include "Statistics.h"

Statistics::Statistics() {
}

void Statistics::setFilename(std::string _filename) {
	this->_filename = _filename;
}

std::string Statistics::getFilename() const {
	return _filename;
}

Statistics::Statistics(const Statistics& orig) {
}

Statistics::~Statistics() {
}

