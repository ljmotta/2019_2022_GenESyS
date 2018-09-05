/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser_if.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 15:57
 */

#ifndef PARSER_IF_H
#define PARSER_IF_H

class Parser_if {
public:
	virtual double parse(const std::string expression) = 0; // may throw exception
	virtual double parse(const std::string expression,  bool* success, std::string* errorMessage) = 0; // does not throw exceptions
	// ...?
};

#endif /* PARSER_IF_H */

