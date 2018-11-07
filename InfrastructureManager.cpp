/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfrastructureManager.cpp
 * Author: cancian
 * 
 * Created on 7 de Novembro de 2018, 12:48
 */

#include "InfrastructureManager.h"
#include "Model.h"


InfrastructureManager::InfrastructureManager(Model* model) {
	_model = model;
		/* TODO: -- Sort methods for infrastructures should be a decorator */
	_infrastructures = new std::map<std::string, List<ModelInfrastructure*>*>(); /// Infrastructures are organized as a map from a string (key), the type of an infrastructure, and a list of infrastructures of that type 
	//_infrastructures->setSortFunc([](const ModelInfrastructure* a, const ModelInfrastructure * b) {
	//	return a->getId() < b->getId();
	//});

}

InfrastructureManager::InfrastructureManager(const InfrastructureManager& orig) {
}

InfrastructureManager::~InfrastructureManager() {
}

void InfrastructureManager::show() {
	_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Model Infrastructures:");
	//std::map<std::string, List<ModelInfrastructure*>*>* _infrastructures;
	std::string key;
	List<ModelInfrastructure*>* list;
	for (std::map<std::string, List<ModelInfrastructure*>*>::iterator infraIt = _infrastructures->begin(); infraIt != _infrastructures->end(); infraIt++) {
		key = (*infraIt).first;
		list = (*infraIt).second;
		_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "   " + key + ": ("+std::to_string(list->size())+")");
		for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
			_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "      " + (*it)->show());
		}
	}
}

List<ModelInfrastructure*>* InfrastructureManager::getInfrastructures(std::string infraTypename) const {
	std::map<std::string, List<ModelInfrastructure*>*>::iterator it = this->_infrastructures->find(infraTypename);
	if (it == this->_infrastructures->end()) {
		// list does not exists yet. Create it and set a valid iterator
		List<ModelInfrastructure*>* newList = new List<ModelInfrastructure*>();
		newList->setSortFunc([](const ModelInfrastructure* a, const ModelInfrastructure * b) {
			return a->getId() < b->getId();
		});
		_infrastructures->insert(std::pair<std::string, List<ModelInfrastructure*>*>(infraTypename, newList));
		it = this->_infrastructures->find(infraTypename);
	}
	List<ModelInfrastructure*>* infras = it->second;
	return infras;
}

ModelInfrastructure* InfrastructureManager::getInfrastructure(std::string infraTypename, Util::identitifcation id) {
	List<ModelInfrastructure*>* list = getInfrastructures(infraTypename);
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		if ((*it)->getId() == id) { // found
			return (*it);
		}
	}
	return nullptr;
}

std::list<std::string>* InfrastructureManager::getInfrastructureTypenames() const {
	std::list<std::string>* keys = new std::list<std::string>();
	for (std::map<std::string, List<ModelInfrastructure*>*>::iterator it = _infrastructures->begin(); it != _infrastructures->end(); it++) {
		keys->insert(keys->end(), (*it).first);
	}
	return keys;
}


ModelInfrastructure* InfrastructureManager::getInfrastructure(std::string infraTypename, std::string name) {
	List<ModelInfrastructure*>* list = getInfrastructures(infraTypename);
	for (std::list<ModelInfrastructure*>::iterator it = list->getList()->begin(); it != list->getList()->end(); it++) {
		if ((*it)->getName() == name) { // found
			return (*it);
		}
	}
	return nullptr;
}