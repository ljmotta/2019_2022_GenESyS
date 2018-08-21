/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seize.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Seize.h"

Seize::Seize(Model* model) :ModelComponent(model, typeid(this).name()) {
}

Seize::Seize(const Seize& orig):ModelComponent(orig) {
}

std::string Seize::show() {
	return ModelComponent::show()+ ",resourceName="+this->_resourceName+", quantity="+this->_quantity+",...";
}

void Seize::_execute(Entity* entity) {
	/* TODO +: not implemented yet */
	_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Seize::setLastMemberSeized(unsigned int _lastMemberSeized) {
	this->_lastMemberSeized = _lastMemberSeized;
}

unsigned int Seize::getLastMemberSeized() const {
	return _lastMemberSeized;
}

void Seize::setSaveAttribute(std::string _saveAttribute) {
	this->_saveAttribute = _saveAttribute;
}

std::string Seize::getSaveAttribute() const {
	return _saveAttribute;
}

void Seize::setRule(Resource::ResourceRule _rule) {
	this->_rule = _rule;
}

Resource::ResourceRule Seize::getRule() const {
	return _rule;
}

void Seize::setQuantity(std::string _quantity) {
	this->_quantity = _quantity;
}

std::string Seize::getQuantity() const {
	return _quantity;
}

void Seize::setResourceName(std::string _resourceName) {
	this->_resourceName = _resourceName;
}

std::string Seize::getResourceName() const {
	return _resourceName;
}

void Seize::setResourceType(Resource::ResourceType _resourceType) {
	this->_resourceType = _resourceType;
}

Resource::ResourceType Seize::getResourceType() const {
	return _resourceType;
}

void Seize::setPriority(unsigned short _priority) {
	this->_priority = _priority;
}

unsigned short Seize::getPriority() const {
	return _priority;
}

void Seize::setAllocationType(unsigned int _allocationType) {
	this->_allocationType = _allocationType;
}

unsigned int Seize::getAllocationType() const {
	return _allocationType;
}

Seize::~Seize() {
}

