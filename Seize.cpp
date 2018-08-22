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

Seize::Seize(Model* model) : ModelComponent(model) {
	_name = "Seize "+std::to_string(Util::_S_generateNewIdOfType(typeid(this).name()));
	_queue = _model->getInfrastructure(typeid (Queue).name(), _name + "_Queue");
	if (_queue == nullptr) {
		_queue = new Queue();
		_queue->setName(_name + "_Queue");
	}
	_resource = _model->getInfrastructure(typeid (Resource).name(), "Resource 1");
	if (_resource == nullptr) {
		_resource = new Resource();
		_resource->setName("Resource 1");
	}
}

Seize::Seize(const Seize& orig) : ModelComponent(orig) {
}

std::string Seize::show() {
	return ModelComponent::show() + ", quantity=" + this->_quantity + ",...";
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

void Seize::setQueueName(std::string _queueName) {
	if (_queue->getName() != _queueName) {
		Queue* queueNewName = _model->getInfrastructure(typeid (Queue).name(), _queueName);
		if (queueNewName == nullptr) { // there is no queue with the new name
			if (!_queue->isLinked()) { // no one else uses it. Only change the name
				_queue->setName(_queueName);
			} else { // it is linked. Create a new one
				_queue = new Queue();
				_queue->setName(_queueName);
			}
		} else { // there is another queue with the same name
			if (!_queue->isLinked()) { // no one else uses it. It can be removed
				_queue->~Queue();
			} else { // there is another one using the queue with old name. Let it there
				_queue->removeLink();
			}
			_queue = queueNewName;
			_queue->addLink();
		}
	}
}

void Seize::setResourceName(std::string _resourceName) {
	if (_resource->getName() != _resourceName) {
		Resource* resourceNewName = _model->getInfrastructure(typeid (Resource).name(), _resourceName);
		if (resourceNewName == nullptr) { // there is no resource with the new name
			if (!_resource->isLinked()) { // no one else uses it. Only change the name
				_resource->setName(_resourceName);
			} else { // it is linked. Create a new one
				_resource = new Resource();
				_resource->setName(_resourceName);
			}
		} else { // there is another resource with the same name
			if (!_resource->isLinked()) { // no one else uses it. It can be removed
				_resource->~Resource();
			} else { // there is another one using the resource with old name. Let it there
				_resource->removeLink();
			}
			_resource = resourceNewName;
			_resource->addLink();
		}
	}
}

std::string Seize::getResourceName() const {
	return _resource->getName();
}

std::string Seize::getQueueName() const {
	return _queue->getName();
}

Seize::~Seize() {
}

