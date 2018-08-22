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
}

ModelComponent::ModelComponent(const ModelComponent& orig) : ModelInfrastructure(orig) {
}

ModelComponent::~ModelComponent() {
}

void ModelComponent::execute(Entity* entity, ModelComponent* component) {
	this->_model->trace(Util::TraceLevel::TL_blockArrival, "Entity " + std::to_string(entity->getId()) + " has arrived at component \"" + component->_name + "\""); //std::to_string(component->_id));
	try {
		component->_execute(entity);
	} catch (const std::exception& e) {
		this->_model->traceError(e, "Error executing component " + component->show());
	}
}

List<ModelComponent*>* ModelComponent::getNextComponents() const {
	return _nextComponents;
}

std::string ModelComponent::show() {
	return ModelInfrastructure::show(); // "{id=" + std::to_string(this->_id) + ",name=\""+this->_name + "\"}"; // , nextComponents[]=(" + _nextComponents->show() + ")}";
}