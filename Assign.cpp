/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.cpp
 * Author: cancian
 * 
 * Created on 31 de Agosto de 2018, 10:10
 */

#include "Assign.h"
#include "Model.h" // to avoid compile error: invalid use of incomplete type ‘class Model’

Assign::Assign(Model* model) : ModelComponent(model) {
	_name = "Assign " + std::to_string(Util::GenerateNewIdOfType<Assign>());
}

Assign::Assign(const Assign& orig) : ModelComponent(orig) {
}

Assign::~Assign() {
}

std::string Assign::show() {
	return ModelComponent::show()+
			"";
}

void Assign::setExpression(std::string _expression) {
	this->_expression = _expression;
}

std::string Assign::getExpression() const {
	return _expression;
}

void Assign::setDestination(std::string _destination) {
	this->_destination = _destination;
}

std::string Assign::getDestination() const {
	return _destination;
}

void Assign::_execute(Entity* entity) {
	/* TODO +: implement */
	this->_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Assign::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Assign::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Assign::_verifySymbols(std::string* errorMessage) {
	return true;
}