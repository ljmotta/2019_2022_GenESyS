/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 16:30
 */

#include <typeinfo>
#include "Entity.h"

Entity::Entity() : ModelInfrastructure(Util::TypeOf<Entity>()) {
	_name = "Entity " + Util::GenerateNewIdOfType<Entity>();
	// 1:n
	_attributeValues = new std::map<std::string, AttributeValue*>();
	// create default attributes
	_attributeValues->insert(std::pair<std::string, AttributeValue*>("Entity.ArrivalTime", new AttributeValue()));
	_attributeValues->insert(std::pair<std::string, AttributeValue*>("Entity.EntityType", new AttributeValue()));
	_attributeValues->insert(std::pair<std::string, AttributeValue*>("Entity.EntityPicture", new AttributeValue()));
	// ...
}

Entity::Entity(const Entity& orig) : ModelInfrastructure(orig) {
}

Entity::~Entity() {
}

std::map<std::string, AttributeValue*>* Entity::getAttributeValues() const {
	return _attributeValues;
}

void Entity::setEntityTypeName(std::string _entityTypeName) {
	this->_entityTypeName = _entityTypeName;
}

std::string Entity::getEntityTypeName() const {
	return _entityTypeName;
}

std::string Entity::show() {
	return ModelInfrastructure::show() +
			",entityTypeName=" + this->_entityTypeName; //+ ",attributeValues="+std::to_string(this->_attributeValues);
}

void Entity::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Entity::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Entity::_verifySymbols(std::string* errorMessage) {
	//this->_
}
