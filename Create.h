/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Create.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 20:12
 */

#ifndef CREATE_H
#define CREATE_H

#include <string>
#include <limits>
#include "SourceModelComponent.h"

class Create : public SourceModelComponent {
public:
	Create(Model* model);
	Create(const Create& orig);
	virtual ~Create();
public:
	virtual std::string show();
protected:
	virtual void _execute(Entity* entity);
	virtual void _readComponent(std::list<std::string> words);
	virtual std::list<std::string>* _writeComponent();
	virtual bool _verifySymbols(std::string* errorMessage);
};

#endif /* CREATE_H */

