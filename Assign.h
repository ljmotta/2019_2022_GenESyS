/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.h
 * Author: cancian
 *
 * Created on 31 de Agosto de 2018, 10:10
 */

#ifndef ASSIGN_H
#define ASSIGN_H

#include "ModelComponent.h"

class Assign: public ModelComponent {
public:
	Assign(Model* model);
	Assign(const Assign& orig);
	virtual ~Assign();
public:
	virtual std::string show();
	
protected:
	virtual void _execute(Entity* entity);
	virtual void _readComponent(std::list<std::string> words);
	virtual std::list<std::string>* _writeComponent();
	virtual bool _verifySymbols(std::string* errorMessage);
private:
private:

};

#endif /* ASSIGN_H */

