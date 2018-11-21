/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorDatafileDummyImpl.cpp
 * Author: cancian
 * 
 * Created on 30 de Agosto de 2018, 16:53
 */

#include "CollectorDatafileDummyImpl.h"

CollectorDatafileDummyImpl::CollectorDatafileDummyImpl() {
}

CollectorDatafileDummyImpl::CollectorDatafileDummyImpl(const CollectorDatafileDummyImpl& orig) {
}

CollectorDatafileDummyImpl::~CollectorDatafileDummyImpl() {
}

void CollectorDatafileDummyImpl::clear() {
}

void CollectorDatafileDummyImpl::addValue(double value) {
}

double CollectorDatafileDummyImpl::getLastValue() {
}

unsigned long CollectorDatafileDummyImpl::numElements() {
}

double CollectorDatafileDummyImpl::getValue(unsigned int num) {
}

std::string CollectorDatafileDummyImpl::getDataFilename() {
	return _filename;
}

void CollectorDatafileDummyImpl::setDataFilename(std::string filename) {
	_filename = filename;
}
