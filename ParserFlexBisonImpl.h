/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserFlexBisonImpl.h
 * Author: Joao Ortigara
 *
 * 
 */

#ifndef PARSERFLEXBISONIMPL_H
#define PARSERFLEXBISONIMPL_H

#include <string>
#include "Parser_if.h"
#include "Genesys++-driver.h"
#include "Model.h"

class ParserFlexBisonImpl : public Parser_if {
public:
	ParserFlexBisonImpl(Model* model);
	ParserFlexBisonImpl(Model* model, bool throws);
	ParserFlexBisonImpl(const ParserFlexBisonImpl& orig);
	virtual ~ParserFlexBisonImpl();
public:
	double parse(const std::string expression); // may throw exception
	double parse(const std::string expression, bool* success, std::string* errorMessage);
	std::string* getErrorMessage();
private:
	Model* _model;
	genesyspp_driver driver;
};

#endif /* PARSERFLEXBISONIMPL_H */

