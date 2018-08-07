/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttributeValue.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 16:36
 */

#include "AttributeValue.h"

AttributeValue::AttributeValue() {
}

AttributeValue::AttributeValue(const AttributeValue& orig) {
}

AttributeValue::~AttributeValue() {
}

void AttributeValue::setValue(double value) {
	this->value = value;
}

double AttributeValue::getValue() const {
	return value;
}

