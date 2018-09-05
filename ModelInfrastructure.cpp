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

#include <typeinfo>
#include "ModelInfrastructure.h"
#include <iostream>   
//TEMP

ModelInfrastructure::ModelInfrastructure(std::string thistypename) {
	_id = Util::_GenerateNewIdOfType(thistypename);
	_name = thistypename+ " "+std::to_string(_id);
}

ModelInfrastructure::ModelInfrastructure(const ModelInfrastructure& orig) {
}

ModelInfrastructure::~ModelInfrastructure() {
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

std::list<std::string>* ModelInfrastructure::SaveInstance(ModelInfrastructure* infrastructure) {
	//infrastructure->_model->trace(Util::TraceLevel::TL_blockArrival, "Writing infrastructure \"" + infrastructure->_name + "\""); //std::to_string(component->_id));
	std::cout << "Wrinting infra " << infrastructure->_name << std::endl;
	std::list<std::string>* words;// = new std::list<std::string>();
	try {
		words = infrastructure->_saveInstance();
	} catch (const std::exception& e) {
		//infrastructure->_model->traceError(e, "Error saving infra " + infrastructure->show());
	}
	return words;
}