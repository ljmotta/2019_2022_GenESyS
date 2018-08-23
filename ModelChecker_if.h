/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelChecker_if.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 15:48
 */

#ifndef MODELCHECKER_IF_H
#define MODELCHECKER_IF_H

//#include "Model.h"
//class Model;

class ModelChecker_if {
public:
	virtual bool checkAll()=0;
	virtual bool checkAndAddInternalLiterals()=0;
	virtual bool checkConnected()=0;
	virtual bool checkSymbols()=0;
	virtual bool checkPathway()=0;
	virtual bool checkActivationCode()=0;
};

#endif /* MODELCHECKER_IF_H */

