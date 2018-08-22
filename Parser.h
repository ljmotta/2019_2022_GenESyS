/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.h
 * Author: cancian
 *
 * Created on 22 de Agosto de 2018, 08:45
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>

class Model;

class Parser {
public:
	Parser(Model* model);
	Parser(const Parser& orig);
	virtual ~Parser();
public:
	double parse(const std::string expression);
private:
	Model* _model;
};

#endif /* PARSER_H */

