/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 22 de Agosto de 2018, 08:45
 */

#include "ParserMyImpl1.h"

ParserMyImpl1::ParserMyImpl1(Model* model) {
	_model = model;
}

ParserMyImpl1::ParserMyImpl1(const ParserMyImpl1& orig) {
}

ParserMyImpl1::~ParserMyImpl1() {
}

double ParserMyImpl1::parse(const std::string expression) { // may throw exception
	double result = std::atof(expression.c_str()); // change by a real parser
	return result;
}

std::string* ParserMyImpl1::getErrorMessage() {
	std::string* errorMsg = new std::string();	
	return errorMsg; /* @TODO */
}

double ParserMyImpl1::parse(const std::string expression, bool* success, std::string* errorMessage) {
	try {
		double result = this->parse(expression);
                std::string temp("");
		errorMessage= &temp;
		*success = true;
		return result;
	} catch (...) {
                std::string temp("Error parsing...");
		errorMessage= &temp;
		*success = false;
		return 0.0;
	}
}