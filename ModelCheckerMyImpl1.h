/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerMyImpl1.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 15:52
 */

#ifndef MODELCHECKERMYIMPL1_H
#define MODELCHECKERMYIMPL1_H

#include "ModelChecker_if.h"
#include "Model.h"

/*!
 * Just an example of possible implementation of the ModelChecker interface. Developers can implement their own class
 */
class ModelCheckerMyImpl1: public ModelChecker_if {
public:
	ModelCheckerMyImpl1(Model* model);
	ModelCheckerMyImpl1(const ModelCheckerMyImpl1& orig);
	~ModelCheckerMyImpl1();
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

#endif /* MODELCHECKERMYIMPL1_H */

