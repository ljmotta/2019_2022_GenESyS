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
		_resourceType = static_cast<SeizableItemRequest::ResourceType> (std::stoi(LoadField(fields, "resourceType", static_cast<int> (DEFAULT.resourceType))));
		_resourceName = LoadField(fields, "resourceName", "");
		_quantityExpression = LoadField(fields, "quantityExpression", DEFAULT.quantityExpression);
		_selectionRule = static_cast<SeizableItemRequest::SelectionRule> (std::stoi(LoadField(fields, "selectionRule", static_cast<int> (DEFAULT.selectionRule))));
		_saveAttribute = LoadField(fields, "saveAttribute", DEFAULT.saveAttribute);
		_index = std::stoi(LoadField(fields, "index", DEFAULT.index));
	} catch (...) {
		res = false;
	}
	return res;
}

bool SeizableItemRequest::_loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex) {
	bool res = true;
	std::string num = std::to_string(parentIndex);
	try {
		_resourceType = static_cast<SeizableItemRequest::ResourceType> (std::stoi(LoadField(fields, "resourceType" + num, static_cast<int> (DEFAULT.resourceType))));
		_resourceName = LoadField(fields, "resourceName" + num, "");
		_quantityExpression = LoadField(fields, "quantityExpression" + num, DEFAULT.quantityExpression);
		_selectionRule = static_cast<SeizableItemRequest::SelectionRule> (std::stoi(LoadField(fields, "selectionRule" + num, static_cast<int> (DEFAULT.selectionRule))));
		_saveAttribute = LoadField(fields, "saveAttribute" + num, DEFAULT.saveAttribute);
		_index = std::stoi(LoadField(fields, "index" + num, DEFAULT.index));
	} catch (...) {
		res = false;
	}
	return res;
}

std::map<std::string, std::string>* SeizableItemRequest::_saveInstance(unsigned int parentIndex) {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	std::string num = std::to_string(parentIndex);
	SaveField(fields, "resourceType" + num, static_cast<int> (_resourceType), static_cast<int> (DEFAULT.resourceType));
	//SaveField(fields, "resourceId" + num, _resourceOrSet->getId());
	SaveField(fields, "resourceName" + num, _resourceOrSet->getName(), "");
	SaveField(fields, "quantityExpression" + num, _quantityExpression, DEFAULT.quantityExpression);
	SaveField(fields, "selectionRule" + num, static_cast<int> (_selectionRule), static_cast<int> (DEFAULT.selectionRule));
	SaveField(fields, "saveAttribute" + num, _saveAttribute, DEFAULT.saveAttribute);
	SaveField(fields, "index" + num, _index, DEFAULT.index);
	return fields;

}

std::map<std::string, std::string>* SeizableItemRequest::_saveInstance() {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	SaveField(fields, "resourceType", static_cast<int> (_resourceType), static_cast<int> (DEFAULT.resourceType));
	SaveField(fields, "resourceId", _resourceOrSet->getId());
	SaveField(fields, "resourceName", _resourceOrSet->getName(), "");
	SaveField(fields, "quantityExpression", _quantityExpression, DEFAULT.quantityExpression);
	SaveField(fields, "selectionRule", static_cast<int> (_selectionRule), static_cast<int> (DEFAULT.selectionRule));
	SaveField(fields, "saveAttribute", _saveAttribute, DEFAULT.saveAttribute);
	SaveField(fields, "index", _index, DEFAULT.index);
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

