/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ParserFlexBisonImpl.cpp
 * Author: Joao Ortigara
 *
 *
 */

#include "ParserFlexBisonImpl.h"

ParserFlexBisonImpl::ParserFlexBisonImpl(Model* model) {
	_model = model;
	driver = genesyspp_driver(_model, false);
}

ParserFlexBisonImpl::ParserFlexBisonImpl(Model* model, bool throws) {
	_model = model;
	driver = genesyspp_driver(_model, throws);
}

ParserFlexBisonImpl::ParserFlexBisonImpl(const ParserFlexBisonImpl& orig) {
}

ParserFlexBisonImpl::~ParserFlexBisonImpl() {
}

double ParserFlexBisonImpl::parse(const std::string expression) { // may throw exception
	driver.setThrowsException(true);
	try {
		int res = driver.parse_str(expression);
		if (res == 0) {
			return driver.getResult();
		} else {
			throw std::string("Bison Error");
		}
	} catch (std::string e) {
		std::cout << e << "\n";
		_model->getTracer()->trace(Util::TraceLevel::errors, e);
		return driver.getResult();
	}
}

std::string* ParserFlexBisonImpl::getErrorMessage() {
	std::string* errorMsg = new std::string();
	return errorMsg; /* @TODO */
}

double ParserFlexBisonImpl::parse(const std::string expression, bool* success, std::string* errorMessage) {
	driver.setThrowsException(false);
	int res = driver.parse_str(expression);
	if (res == 0) {
		*success = true;
		return driver.getResult();
	} else {
		*success = false;
		*errorMessage = driver.getErrorMessage();
		return driver.getResult();
	}
}
