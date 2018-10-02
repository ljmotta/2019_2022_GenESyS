/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileCancianImpl.cpp
 * Author: cancian
 * 
 * Created on 2 de Outubro de 2018, 16:12
 */

#include <fstream>

#include "CollectorDatafileCancianImpl.h"

CollectorDatafileCancianImpl::CollectorDatafileCancianImpl() {
}

CollectorDatafileCancianImpl::CollectorDatafileCancianImpl(const CollectorDatafileCancianImpl& orig) {
}

CollectorDatafileCancianImpl::~CollectorDatafileCancianImpl() {
}

void CollectorDatafileCancianImpl::clear() {
	std::ofstream file;
	file.open(_filename, std::ofstream::out | std::ofstream::trunc);
	file.close();
}

void CollectorDatafileCancianImpl::addValue(double value) {
	try {

		std::ofstream file;
		file.open(this->_filename, std::ios::out | std::ios::app);
		file << value << "\n";
		file.close();
	} catch (const std::exception& e) {

	}
}

double CollectorDatafileCancianImpl::getLastValue() {
}

unsigned long CollectorDatafileCancianImpl::numElements() {
	try {
		std::string line;
		unsigned long count;
		std::ifstream file;
		file.open(_filename, std::ios::in);
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, line);
				count++;
			}
			file.close();
			return count;
		}
	} catch (const std::exception& e) {
	}
	return 0;
}

double CollectorDatafileCancianImpl::getValue(unsigned int num) {
} // same as getValue, or value[num]

std::string CollectorDatafileCancianImpl::getDataFilename() {
	return _filename;
}

void CollectorDatafileCancianImpl::setDataFilename(std::string filename) {
	this->_filename = filename;
}
