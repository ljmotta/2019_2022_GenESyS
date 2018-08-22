/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: cancian
 * 
 * Created on 22 de Agosto de 2018, 08:45
 */

#include "Parser.h"

Parser::Parser(Model* model) {
	_model = model;
}

Parser::Parser(const Parser& orig) {
}

Parser::~Parser() {
}

double Parser::parse(const std::string expression) {
	double result = std::atof(expression.c_str());
	return result;
}