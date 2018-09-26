/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserMyImpl1.h
 * Author: cancian
 *
 * Created on 22 de Agosto de 2018, 08:45
 */

#ifndef PARSERMYIMPL1_H
#define PARSERMYIMPL1_H

#include <string>
#include "Parser_if.h"

class Model;

class ParserMyImpl1 : public Parser_if {
public:
	ParserMyImpl1(Model* model);
	ParserMyImpl1(const ParserMyImpl1& orig);
	virtual ~ParserMyImpl1();
public:
	double parse(const std::string expression);  // may throw exception
	double parse(const std::string expression,  bool* success, std::string* errorMessage);
	std::string* getErrorMessage(); 
private:
	Model* _model;
};

#endif /* PARSERMYIMPL1_H */

