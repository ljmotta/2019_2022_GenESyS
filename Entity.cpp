/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 16:30
 */

#include <typeinfo>
#include "Entity.h"
#include "Attribute.h"
#include "Model.h"

Entity::Entity(Model* model) : ModelElement(model, Util::TypeOf<Entity>()) {
    //_elements = elements;
    _entityNumber = Util::GetLastIdOfType(Util::TypeOf<Entity>());
    unsigned int numAttributes = _parentModel->elements()->numberOfElements(Util::TypeOf<Attribute>());
    for (unsigned i = 0; i < numAttributes; i++) {
	std::map<std::string, double>* map = new std::map<std::string, double>();
	_attributeValues->insert(map);
    }
}

void Entity::setEntityTypeName(std::string entityTypeName) throw () {
    EntityType* entitytype = dynamic_cast<EntityType*> (_parentModel->elements()->element(Util::TypeOf<EntityType>(), entityTypeName));
    if (entitytype != nullptr) {
	this->_entityType = entitytype;
    } else {
	throw std::invalid_argument("EntityType does not exist");
    }
}

std::string Entity::getEntityTypeName() const {
    return this->_entityType->name();
}

void Entity::setEntityType(EntityType* entityType) {
    _entityType = entityType;
}

EntityType* Entity::getEntityType() const {
    return _entityType;
}

std::string Entity::show() {
    std::string message = ModelElement::show();
    if (this->_entityType != nullptr) {
	message += ",entityType=\"" + this->_entityType->name() + "\"";
    }
    message += ",attributeValues=[";
    _attributeValues->front();
    for (unsigned int i = 0; i < _attributeValues->size(); i++) {
	std::map<std::string, double>* map = _attributeValues->current();
	if (map->size() <= 1) { // scalar
	    message += std::to_string(map->begin()->second) + ";";
	} else {
	    // array or matrix
	    message += "[";
	    for (std::map<std::string, double>::iterator valIt = map->begin(); valIt != map->end(); valIt++) {
		message += (*valIt).first + "=>" + std::to_string((*valIt).second) + ",";
	    }
	    message += "];";
	}
	_attributeValues->next();
    }
    message += "]";
    return message;
}

double Entity::getAttributeValue(std::string attributeName) {
    return getAttributeValue("", attributeName);
}

double Entity::getAttributeValue(std::string index, std::string attributeName) {
    int rank = _parentModel->elements()->rankOf(Util::TypeOf<Attribute>(), attributeName);
    if (rank >= 0) {
	std::map<std::string, double>* map = this->_attributeValues->getAtRank(rank);
	std::map<std::string, double>::iterator mapIt = map->find(index);
	if (mapIt != map->end()) {//found
	    return (*mapIt).second;
	} else { // not found
	    return 0.0;
	}
    } else
	return 0.0; /* TODO: !! Never should happen. check how to report */
}

double Entity::getAttributeValue(Util::identification attributeID) {
    return getAttributeValue("", attributeID);
}

double Entity::getAttributeValue(std::string index, Util::identification attributeID) {
    ModelElement* element = _parentModel->elements()->element(Util::TypeOf<Attribute>(), attributeID);
    if (element != nullptr) {
	return getAttributeValue(index, element->name());
    }
    return 0.0; // attribute not found
}

void Entity::setAttributeValue(std::string attributeName, double value) {
    setAttributeValue("", attributeName, value);
}

void Entity::setAttributeValue(std::string index, std::string attributeName, double value) {
    int rank = _parentModel->elements()->rankOf(Util::TypeOf<Attribute>(), attributeName);
    if (rank >= 0) {
	std::map<std::string,double>* map = _attributeValues->getAtRank(rank);
	std::map<std::string,double>::iterator mapIt = map->find(index);
	if (mapIt!=map->end()) {//found
	    (*mapIt).second = value;
	} else { // not found
	    map->insert(map->end(), std::pair<std::string,double>(index, value));
	}
	//this->_attributeValues->setAtRank(rank, value);
    }
    /*
    std::map<std::string, AttributeValue*>::iterator it = entity->getAttributeValues()->find('Entity.ArrivalTime');
    if (it != entity->getAttributeValues()::end()) {
	(*it)->second->setValue(this->_model->getSimulationTime());
    }
     */
}

Util::identification Entity::getEntityNumber() const {
    return _entityNumber;
}

bool Entity::_loadInstance(std::map<std::string, std::string>* fields) {
    // never lods an entity
    return true;
}

std::map<std::string, std::string>* Entity::_saveInstance() {
    return new std::map<std::string, std::string>();
}

bool Entity::_check(std::string* errorMessage) {
    return true;
}
