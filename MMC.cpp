/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MMC.cpp
 * Author: cancian
 * 
 * Created on 7 de Agosto de 2018, 18:22
 */

#include "MMC.h"

MMC::MMC() {
}

void MMC::setModule(unsigned long _module) {
	this->_module = _module;
}

unsigned long MMC::getModule() const {
	return _module;
}

void MMC::setMultiplier(unsigned long _multiplier) {
	this->_multiplier = _multiplier;
}

unsigned long MMC::getMultiplier() const {
	return _multiplier;
}

void MMC::setSeed(unsigned long _seed) {
	this->_seed = _seed;
}

unsigned long MMC::getSeed() const {
	return _seed;
}

MMC::MMC(const MMC& orig) {
}

MMC::~MMC() {
}

