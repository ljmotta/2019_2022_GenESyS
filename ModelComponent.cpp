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
#include "List.cpp"

void ModelComponent::execute(Entity* entity, ModelComponent* component) {
	try {
		component->doExecute(entity);
	} catch (const std::exception& e) {

	}
}

List<ModelComponent*>* ModelComponent::getNextComponents() const {
	return _nextComponents;
}

ModelComponent::ModelComponent(Model* model) {
	_model = model;
	_nextComponents = new List<ModelComponent*>();
}

ModelComponent::ModelComponent(const ModelComponent& orig) {
}

ModelComponent::~ModelComponent() {
}

std::string ModelComponent::show() {
	return _nextComponents->show();
}