/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Element.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 15:56
 */

#include "ModelComponent.h"
#include "Model.h"

ModelComponent::ModelComponent(Model* model) : ModelInfrastructure(typeid (this).name()) {
	_model = model;
	_nextComponents = new List<ModelComponent*>();
    //_checkedConnection = false; // ????????????????
}

ModelComponent::ModelComponent(const ModelComponent& orig) : ModelInfrastructure(orig) {
}

ModelComponent::~ModelComponent() {
}

void ModelComponent::Execute(Entity* entity, ModelComponent* component) {
	component->_model->getTracer()->trace(Util::TraceLevel::blockArrival, "Entity " + std::to_string(entity->getId()) + " has arrived at component \"" + component->_name + "\""); //std::to_string(component->_id));
	try {
		component->_execute(entity);
	} catch (const std::exception& e) {
		component->_model->getTracer()->traceError(e, "Error executing component " + component->show());
	}
}

std::list<std::string>* ModelComponent::SaveInstance(ModelComponent* component) {
	component->_model->getTracer()->trace(Util::TraceLevel::blockArrival, "Writing component \"" + component->_name + "\""); //std::to_string(component->_id));
	std::list<std::string>* words = new std::list<std::string>();
	try {
		words = component->_saveInstance();
	} catch (const std::exception& e) {
		component->_model->getTracer()->traceError(e, "Error executing component " + component->show());
	}
	return words;
}

bool ModelComponent::VerifySymbols(ModelComponent* component, std::string* errorMessage) {
	component->_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verifying symbols of component " + component->_name); //std::to_string(component->_id));
	bool res = false;
	try {
		res = component->_verifySymbols(errorMessage);
		if (!res) {
			component->_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verification of symbols of component \"" + component->_name + "\" has failed with message " + *errorMessage);
		}
	} catch (const std::exception& e) {
		component->_model->getTracer()->traceError(e, "Error executing component " + component->show());
	}
	return res;
}

List<ModelComponent*>* ModelComponent::getNextComponents() const {
	return _nextComponents;
}

std::string ModelComponent::show() {
	return ModelInfrastructure::show(); // "{id=" + std::to_string(this->_id) + ",name=\""+this->_name + "\"}"; // , nextComponents[]=(" + _nextComponents->show() + ")}";
}

bool ModelComponent::getCheckedConnection(){
    return this->_checkedConnection;
}

void ModelComponent::setCheckedConnection( bool _checkedConnection){
    this->_checkedConnection = _checkedConnection;
}
