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

class Assign : public ModelComponent {
public:
	Assign(Model* model);
	Assign(const Assign& orig);
	virtual ~Assign();
public:
	virtual std::string show();
public:
	void setExpression(std::string _expression);
	std::string getExpression() const;
	void setDestination(std::string _destination);
	std::string getDestination() const;

protected:
	virtual void _execute(Entity* entity);
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);
private:
private:
	std::string _destination = "";
	std::string _expression = "";

};

#endif /* ASSIGN_H */

