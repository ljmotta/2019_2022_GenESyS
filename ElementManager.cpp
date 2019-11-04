/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElementManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 12:48
 */

#include "ElementManager.h"
#include "Model.h"

ElementManager::ElementManager(Model* model) {
    _parentModel = model;
    /* TODO: -- Sort methods for elements should be a decorator */
    _elements = new std::map<std::string, List<ModelElement*>*>(); /// Elements are organized as a map from a string (key), the type of an element, and a list of elements of that type 
    //_elements->setSortFunc([](const ModelElement* a, const ModelElement * b) {
    //	return a->getId() < b->getId();
    //});

}

bool ElementManager::insert(ModelElement* infra) {
    std::string infraTypename = infra->classname();
    return insert(infraTypename, infra);
}

bool ElementManager::insert(std::string infraTypename, ModelElement* infra) {
    List<ModelElement*>* listElements = elementList(infraTypename);
    if (listElements->find(infra) == listElements->list()->end()) { //not found
	listElements->insert(infra);
	this->_parentModel->tracer()->trace(Util::TraceLevel::mostDetailed, "Element "+infra->name()+" successfully inserted.");
	return true;
    }
    return false;
}

void ElementManager::remove(ModelElement* infra) {
    std::string infraTypename = infra->classname();
    List<ModelElement*>* listElements = elementList(infraTypename);
    listElements->remove(infra);
}

void ElementManager::remove(std::string infraTypename, ModelElement* infra) {
    List<ModelElement*>* listElements = elementList(infraTypename);
    listElements->remove(infra);
}

bool ElementManager::check(std::string infraTypename, std::string infraName, std::string expressionName, bool mandatory, std::string* errorMessage) {
    if (infraName == "" && !mandatory) {
	return true;
    }
    bool result = element(infraTypename, infraName) != nullptr;
    if (!result) {
	std::string msg = infraTypename + " \"" + infraName + "\" for '" + expressionName + "' is not in the model.";
	errorMessage->append(msg);
    }
    return result;
}

bool ElementManager::check(std::string infraTypename, ModelElement* infra, std::string expressionName, std::string* errorMessage) {
    bool result = infra != nullptr;
    if (!result) {
	std::string msg = infraTypename + " for '" + expressionName + "' is null.";
	errorMessage->append(msg);
    } else {
	result = check(infraTypename, infra->name(), expressionName, true, errorMessage);
    }
    return result;
}

void ElementManager::clear() {
    this->_elements->clear();
}

unsigned int ElementManager::numberOfElements(std::string infraTypename) {
    List<ModelElement*>* listElements = elementList(infraTypename);
    return listElements->size();
}

unsigned int ElementManager::numberOfElements() {
    unsigned int total = 0;
    for (std::map<std::string, List<ModelElement*>*>::iterator it = _elements->begin(); it != _elements->end(); it++) {
	total += (*it).second->size();
    }
    return total;
}

void ElementManager::show() {
    _parentModel->tracer()->trace(Util::TraceLevel::mostDetailed, "Model Elements:");
    //std::map<std::string, List<ModelElement*>*>* _elements;
    std::string key;
    List<ModelElement*>* list;
    Util::IncIndent();
    {
	for (std::map<std::string, List<ModelElement*>*>::iterator infraIt = _elements->begin(); infraIt != _elements->end(); infraIt++) {
	    key = (*infraIt).first;
	    list = (*infraIt).second;
	    _parentModel->tracer()->trace(Util::TraceLevel::mostDetailed, key + ": (" + std::to_string(list->size()) + ")");
	    Util::IncIndent();
	    {
		for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
		    _parentModel->tracer()->trace(Util::TraceLevel::mostDetailed, (*it)->show());
		}
	    }
	    Util::DecIndent();
	}
    }
    Util::DecIndent();
}

Model* ElementManager::parentModel() const {
    return _parentModel;
}

List<ModelElement*>* ElementManager::elementList(std::string infraTypename) const {
    std::map<std::string, List<ModelElement*>*>::iterator it = this->_elements->find(infraTypename);
    if (it == this->_elements->end()) {
	// list does not exists yet. Create it and set a valid iterator
	List<ModelElement*>* newList = new List<ModelElement*>();
	newList->setSortFunc([](const ModelElement* a, const ModelElement * b) {
	    return a->id() < b->id();
	});
	_elements->insert(std::pair<std::string, List<ModelElement*>*>(infraTypename, newList));
	it = this->_elements->find(infraTypename);
    }
    List<ModelElement*>* infras = it->second;
    return infras;
}

ModelElement* ElementManager::element(std::string infraTypename, Util::identification id) {
    List<ModelElement*>* list = elementList(infraTypename);
    for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
	if ((*it)->id() == id) { // found
	    return (*it);
	}
    }
    return nullptr;
}

int ElementManager::rankOf(std::string infraTypename, std::string name) {
    int rank = 0;
    List<ModelElement*>* list = elementList(infraTypename);
    for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
	if ((*it)->name() == name) { // found
	    return rank;
	} else {
	    rank++;
	}
    }
    return -1;
}

std::list<std::string>* ElementManager::elementClassnames() const {
    std::list<std::string>* keys = new std::list<std::string>();
    for (std::map<std::string, List<ModelElement*>*>::iterator it = _elements->begin(); it != _elements->end(); it++) {
	keys->insert(keys->end(), (*it).first);
    }
    return keys;
}

ModelElement* ElementManager::element(std::string infraTypename, std::string name) {
    List<ModelElement*>* list = elementList(infraTypename);
    for (std::list<ModelElement*>::iterator it = list->list()->begin(); it != list->list()->end(); it++) {
	if ((*it)->name() == name) { // found
	    return (*it);
	}
    }
    return nullptr;
}