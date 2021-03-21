/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hold.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:20
 */

#include "Hold.h"
#include "../../Model.h"

Hold::Hold(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Hold>(), name) {
}

std::string Hold::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Hold::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Hold* newComponent = new Hold(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Hold::_execute(Entity* entity) {
	_parentModel->getTracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

bool Hold::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		//...
	}
	return res;
}

void Hold::_initBetweenReplications() {
}

std::map<std::string, std::string>* Hold::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	//...
	return fields;
}

bool Hold::_check(std::string* errorMessage) {
	bool resultAll = true;
	//...
	return resultAll;
}

PluginInformation* Hold::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Hold>(), &Hold::LoadInstance);
	// ...
	return info;
}

