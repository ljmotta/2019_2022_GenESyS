/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Separate.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Separate.h"

#include "Model.h"

Separate::Separate(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Separate>(), name) {
}

std::string Separate::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Separate::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Separate* newComponent = new Separate(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Separate::_execute(Entity* entity) {
	//Entity* cloned = new Entity(entity);
	this->_parentModel->sendEntityToComponent(entity, nextComponents()->frontConnection(), 0.0);
	//this->_parentModel->sendEntityToComponent(cloned, nextComponents()->getConnectionAtRank(1), 0.0);
}

bool Separate::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		//...
	}
	return res;
}

void Separate::_initBetweenReplications() {
}

std::map<std::string, std::string>* Separate::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	//...
	return fields;
}

bool Separate::_check(std::string* errorMessage) {
	bool resultAll = true;
	//...
	return resultAll;
}

PluginInformation* Separate::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Separate>(), &Separate::LoadInstance);
	// ...
	return info;
}

