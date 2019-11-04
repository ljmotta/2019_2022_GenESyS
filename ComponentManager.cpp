/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComponentManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 28 de Maio de 2019, 10:41
 */

#include "ComponentManager.h"
#include "List.h"
#include "Model.h"

ComponentManager::ComponentManager(Model* model) {
    _parentModel = model;
    _components = new List<ModelComponent*>();
    _components->setSortFunc([](const ModelComponent* a, const ModelComponent * b) {
	return a->id() < b->id(); /// Components are sorted by ID
    });
}


bool ComponentManager::insert(ModelComponent* comp) {
    if (_components->find(comp) == _components->list()->end()) {
	_components->insert(comp);
	this->_parentModel->tracer()->trace(Util::TraceLevel::mostDetailed, "Component \""+comp->name()+"\" successfully inserted.");
	return true;
    }
    return false;
}

void ComponentManager::remove(ModelComponent* comp) {
    _components->remove(comp);
}

void ComponentManager::clear() {
    this->_components->clear();
}

//ModelComponent* ComponentManager::getComponent(Util::identification id) {
//}

//ModelComponent* ComponentManager::getComponent(std::string name) {
//}

unsigned int ComponentManager::numberOfComponents() {
    return _components->size();
}

std::list<ModelComponent*>::iterator ComponentManager::begin() {
    return _components->list()->begin();
}

std::list<ModelComponent*>::iterator ComponentManager::end() {
    return _components->list()->end();
}