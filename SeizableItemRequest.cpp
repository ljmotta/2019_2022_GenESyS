/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SeizableItemRequest.cpp
 * Author: rlcancian
 * 
 * Created on 10 de abril de 2021, 08:45
 */

#include "SeizableItemRequest.h"
#include "ModelElement.h"

SeizableItemRequest::SeizableItemRequest(ModelElement* resourceOrSet, std::string quantityExpression, SeizableItemRequest::ResourceType resourceType, SeizableItemRequest::SelectionRule selectionRule, std::string saveAttribute, unsigned int index) {
	_resourceType = resourceType;
	_resourceOrSet = resourceOrSet;
	_quantityExpression = quantityExpression;
	_selectionRule = selectionRule;
	_saveAttribute = saveAttribute;
	_index = index;
}

bool SeizableItemRequest::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = true;
	try {
		_resourceType = static_cast<SeizableItemRequest::ResourceType> (std::stoi((*(fields->find("resourceType"))).second));
		_resourceName = ((*(fields->find("resourceName"))).second);
		//Resource* resource = dynamic_cast<Resource*> (_parentModel->getElements()->getElement(Util::TypeOf<Resource>(), resourceName));
		_quantityExpression = ((*(fields->find("quantity"))).second);
		_selectionRule = static_cast<SeizableItemRequest::SelectionRule> (std::stoi((*(fields->find("rule"))).second));
		_saveAttribute = ((*(fields->find("saveAttribute"))).second);
		_index = std::stoi((*(fields->find("index"))).second);
	} catch (const std::exception& e) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* SeizableItemRequest::_saveInstance() {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	fields->emplace("resourceType", std::to_string(static_cast<int> (_resourceType)));
	fields->emplace("resourceId", std::to_string(_resourceOrSet->getId()));
	fields->emplace("resourceName", _resourceOrSet->getName());
	fields->emplace("quantityExpression", _quantityExpression);
	fields->emplace("selectionRule", std::to_string(static_cast<int> (_selectionRule)));
	fields->emplace("saveAttribute", _saveAttribute);
	fields->emplace("index", std::to_string(_index));
	return fields;
}

std::string SeizableItemRequest::show() {
	return "resourceType=" + std::to_string(static_cast<int> (_resourceType)) + ",resource=\"" + _resourceOrSet->getName() + "\",quantityExpression=\"" + _quantityExpression + "\", selectionRule=" + std::to_string(static_cast<int> (_selectionRule)) + ", _saveAttribute=\"" + _saveAttribute + "\",index=" + std::to_string(_index);
}

void SeizableItemRequest::setIndex(unsigned int index) {
	this->_index = _index;
}

unsigned int SeizableItemRequest::getIndex() const {
	return _index;
}

void SeizableItemRequest::setSaveAttribute(std::string saveAttribute) {
	this->_saveAttribute = _saveAttribute;
}

std::string SeizableItemRequest::getSaveAttribute() const {
	return _saveAttribute;
}

void SeizableItemRequest::setSelectionRule(SeizableItemRequest::SelectionRule selectionRule) {
	this->_selectionRule = _selectionRule;
}

SeizableItemRequest::SelectionRule SeizableItemRequest::getSelectionRule() const {
	return _selectionRule;
}

void SeizableItemRequest::setQuantityExpression(std::string quantityExpression) {
	this->_quantityExpression = _quantityExpression;
}

std::string SeizableItemRequest::getQuantityExpression() const {
	return _quantityExpression;
}

std::string SeizableItemRequest::getResourceName() const {
	return _resourceName;
}

void SeizableItemRequest::setResource(Resource* resource) {
	this->_resourceOrSet = resource;
}

Resource* SeizableItemRequest::getResource() const {
	return static_cast<Resource*> (_resourceOrSet);
}

void SeizableItemRequest::setSet(Set* set) {
	this->_resourceOrSet = set;
}

Set* SeizableItemRequest::getSet() const {
	return static_cast<Set*> (_resourceOrSet);
}

void SeizableItemRequest::setResourceType(SeizableItemRequest::ResourceType resourceType) {
	this->_resourceType = _resourceType;
}

SeizableItemRequest::ResourceType SeizableItemRequest::getResourceType() const {
	return _resourceType;
}

void SeizableItemRequest::setLastMemberSeized(unsigned int lastMemberSeized) {
	this->_lastMemberSeized = lastMemberSeized;
}

unsigned int SeizableItemRequest::getLastMemberSeized() const {
	return _lastMemberSeized;
}

