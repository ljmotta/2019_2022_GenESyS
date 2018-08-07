/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 19:49
 */

#include "Delay.h"

Delay::Delay() {
}

Delay::Delay(const Delay& orig) {
}

Delay::~Delay() {
}

void Delay::setDelayExpression(std::string _delayExpression) {
	this->_delayExpression = _delayExpression;
}

std::string Delay::getDelayExpression() const {
	return _delayExpression;
}

void Delay::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	this->_delayTimeUnit = _delayTimeUnit;
}

Util::TimeUnit Delay::getDelayTimeUnit() const {
	return _delayTimeUnit;
}

