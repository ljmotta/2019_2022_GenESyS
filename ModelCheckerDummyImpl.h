/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerDummyImpl.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 15:52
 */

#ifndef MODELCHECKERDUMMYIMPL_H
#define MODELCHECKERDUMMYIMPL_H

#include "ModelChecker_if.h"
#include "Model.h"

/*!
 * Just an example of possible implementation of the ModelChecker interface. Developers can implement their own class
 */
class ModelCheckerDummyImpl: public ModelChecker_if {
public:
	ModelCheckerDummyImpl(Model* model);
	ModelCheckerDummyImpl(const ModelCheckerDummyImpl& orig);
	~ModelCheckerDummyImpl();
public: 
	bool checkAll();
	bool checkAndAddInternalLiterals();
	bool checkConnected();
	bool checkSymbols();
	bool checkPathway();
	bool checkActivationCode();
	bool verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory);
private:
	Model* _model = nullptr;
};

#endif /* MODELCHECKERDUMMYIMPL_H */

