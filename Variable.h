/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.h
 * Author: cancian
 *
 * Created on 4 de Setembro de 2018, 18:28
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include "ModelInfrastructure.h"

class Variable : public ModelInfrastructure {
public:
	Variable();
	Variable(const Variable& orig);
	virtual ~Variable();
public:
	virtual std::string show();
public:
	
protected: 
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);

private:

};

#endif /* VARIABLE_H */

