/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Access.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:14
 */

#include "Access.h"

#include "Model.h"

Access::Access(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Access>(), name) {
}

std::string Access::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Access::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Access* newComponent = new Access(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Access::_execute(Entity* entity) {
	_parentModel->tracer()->trace("I'm just a dummy model and I'll just send the entity forward");
	this->_parentModel->sendEntityToComponent(entity, this->nextComponents()->frontConnection(), 0.0);
}

bool Access::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		//...
	}
	return res;
}

void Access::_initBetweenReplications() {
}

std::map<std::string, std::string>* Access::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	//...
	return fields;
}

bool Access::_check(std::string* errorMessage) {
	bool resultAll = true;
	//...
	return resultAll;
}

PluginInformation* Access::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Access>(), &Access::LoadInstance);
	// ...
	return info;
}


