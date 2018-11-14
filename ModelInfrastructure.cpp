/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfrastructure.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 19:40
 */

//#include <typeinfo>
#include <iostream>   
#include "ModelInfrastructure.h"

ModelInfrastructure::ModelInfrastructure(std::string thistypename) {
	_id = Util::GenerateNewIdOfType(thistypename);
	_name = thistypename+ " "+std::to_string(_id);
}

ModelInfrastructure::ModelInfrastructure(const ModelInfrastructure& orig) {
}

ModelInfrastructure::~ModelInfrastructure() {
}

std::list<std::string>* ModelInfrastructure::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	words->insert(words->end(), std::to_string(this->_id));
	words->insert(words->end(), this->_name);
	return words;
}

std::list<std::string>* ModelInfrastructure::_saveInstance(std::string type) {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance();
	words->insert(words->end(), type);
	return words;
}

std::string ModelInfrastructure::show(){
	return "id="+std::to_string(_id)+",name=\""+_name+"\"";
}
	
Util::identitifcation ModelInfrastructure::getId() const {
	return _id;
}

void ModelInfrastructure::setName(std::string _name) {
	this->_name = _name;
}

std::string ModelInfrastructure::getName() const {
	return _name;
}

//std::list<std::string>* ModelInfrastructure::_saveInstance() { /* TODO: REMOVE - IS PURE VIRTUAL  TEMP */
//	std::list<std::string>* words = new std::list<std::string>();
//	return words;
//}

std::list<std::string>* ModelInfrastructure::SaveInstance(ModelInfrastructure* infrastructure) {
	std::list<std::string>* words;// = new std::list<std::string>();
	try {
		std::string name = infrastructure->_name; /* TODO: TEST ONLY. REMOVE IT */

		//std::cout << "SALVANDO " << name << std::endl;
		words = infrastructure->_saveInstance();
	} catch (const std::exception& e) {
		//infrastructure->_model->getTrace()->traceError(e, "Error saving infra " + infrastructure->show());
	}
	return words;
}