/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelChecker_DS2Karla.h
 * Author: karla
 *
 * Created on 19 de Setembro de 2018, 16:01
 */

#ifndef MODELCHECKER_DS2KARLA_H
#define MODELCHECKER_DS2KARLA_H

#include "ModelChecker_if.h"
#include "Model.h"

class ModelChecker_DS2Karla: public ModelChecker_if {
public:
	ModelChecker_DS2Karla(Model* model);
	ModelChecker_DS2Karla(const ModelChecker_DS2Karla& orig);
	~ModelChecker_DS2Karla();
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
        bool checkConnectionToDispose(List<ModelComponent*>* components);
};

#endif /* MODELCHECKER_DS2KARLA_H */

