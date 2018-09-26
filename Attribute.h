/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.h
 * Author: cancian
 *
 * Created on 25 de Setembro de 2018, 16:37
 */

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include <list>


#include "ModelInfrastructure.h"

class Attribute : public ModelInfrastructure  {
public:
	Attribute();
	Attribute(const Attribute& orig);
	virtual ~Attribute();
public:
	virtual std::string show();
	
protected: 
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);

};

#endif /* ATTRIBUTE_H */

