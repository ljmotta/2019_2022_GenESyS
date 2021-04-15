/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seize.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Seize.h"
#include "Resource.h"
#include "Attribute.h"
#include <assert.h>

Seize::Seize(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Seize>(), name) {
}

std::string Seize::show() {
	std::string txt = ModelComponent::show() +
			"priority=" + std::to_string(_priority) +
			"seizeRequests={";
	unsigned short i = 0;
	for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++, i++) {
		txt += "request" + std::to_string(i) + "=[" + _seizeRequests->show() + "],";
	}
	txt = txt.substr(0, txt.length() - 1) + "}";
	return txt;
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

void Seize::setQueueName(std::string queueName) throw () {
	Queue* queue = dynamic_cast<Queue*> (_parentModel->getElements()->getElement(Util::TypeOf<Queue>(), queueName));
	if (queue != nullptr) {
		_queue = queue;
	} else {
		throw std::invalid_argument("Queue does not exist");
	}
}

void Seize::_handlerForResourceEvent(Resource* resource) {
	Waiting* first = _queue->first();
	if (first != nullptr) { // there are entities waiting in the queue
		// find quantity requested for such resource
		for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++) {
			if ((*it)->getResource() == resource) {
				unsigned int quantity = _parentModel->parseExpression((*it)->getQuantityExpression());
				if ((resource->getCapacity() - resource->getNumberBusy()) >= quantity) { //enought quantity to seize
					double tnow = _parentModel->getSimulation()->getSimulatedTime();
					resource->seize(quantity, tnow);
					_parentModel->getFutureEvents()->insert(new Event(tnow, first->getEntity(), this->getNextComponents()->getFrontConnection()));
					_queue->removeElement(first);
					_parentModel->getTracer()->traceSimulation(tnow, first->getEntity(), this, "Waiting entity " + std::to_string(first->getEntity()->entityNumber()) + " now seizes " + std::to_string(quantity) + " elements of resource \"" + resource->getName() + "\"");
				}
			}
		}
	}
}

//void Seize::setResourceName(std::string resourceName) throw () {
//	Resource* resource = dynamic_cast<Resource*> (_parentModel->elements()->element(Util::TypeOf<Resource>(), resourceName));
//	if (resource != nullptr) {
//		_resource = resource;
//	} else {
//		throw std::invalid_argument("Resource does not exist");
//	}
//}

//std::string Seize::getResourceName() const {
//	return _seizeRequest->resource()->name();
//}

std::string Seize::getQueueName() const {
	return _queue->getName();
}

//void Seize::setResource(Resource* resource) {
//	this->_resource = resource;
//	_resource->addReleaseResourceEventHandler(Resource::SetResourceEventHandler<Seize>(&Seize:://_handlerForResourceEvent, this));
//}

//Resource* Seize::getResource() const {
//	return _resource;
//}

void Seize::setQueue(Queue* queue) {
	this->_queue = queue;
}

Queue* Seize::getQueue() const {
	return _queue;
}

List<SeizableItemRequest*>* Seize::getSeizeRequests() const {
	return _seizeRequests;
}

void Seize::_execute(Entity* entity) {
	for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++) {
		Resource* resource = (*it)->getResource();
		unsigned int quantity = _parentModel->parseExpression((*it)->getQuantityExpression());
		if (resource->getCapacity() - resource->getNumberBusy() < quantity) { // not enought free quantity to allocate. Entity goes to the queue
			WaitingResource* waitingRec = new WaitingResource(entity, this, _parentModel->getSimulation()->getSimulatedTime(), quantity);
			this->_queue->insertElement(waitingRec); // ->list()->insert(waitingRec);
			_parentModel->getTracer()->traceSimulation(_parentModel->getSimulation()->getSimulatedTime(), entity, this, "Entity starts to wait for resource in queue \"" + _queue->getName() + "\" with " + std::to_string(_queue->size()) + " elements");
			return;
		} else { // alocate the resource
			resource->seize(quantity, _parentModel->getSimulation()->getSimulatedTime());
			_parentModel->getTracer()->traceSimulation(_parentModel->getSimulation()->getSimulatedTime(), entity, this, "Entity seizes " + std::to_string(quantity) + " elements of resource \"" + resource->getName() + "\" (capacity:" + std::to_string(resource->getCapacity()) + ", numberbusy:" + std::to_string(resource->getNumberBusy()) + ")");
		}
	}
	_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

void Seize::_initBetweenReplications() {
	this->_queue->initBetweenReplications();
	for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++) {
		(*it)->setLastMemberSeized(0);
		(*it)->getResource()->initBetweenReplications();
	}
}

bool Seize::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_allocationType = std::stoi(LoadField(fields, "allocationType", DEFAULT.allocationType));
		this->_priority = std::stoi(LoadField(fields, "priority", DEFAULT.priority));
		std::string queueName = LoadField(fields, "queueName", "");
		Queue* queue = dynamic_cast<Queue*> (_parentModel->getElements()->getElement(Util::TypeOf<Queue>(), queueName));
		this->_queue = queue;
		unsigned short numRequests = std::stoi(LoadField(fields, "seizeResquestSize", 0));
		for (unsigned short i = 0; i < numRequests; i++) {
			SeizableItemRequest* itemRequest = new SeizableItemRequest(nullptr);
			itemRequest->_loadInstance(fields, i);
			this->_seizeRequests->insert(itemRequest);
		}

	}
	return res;
}

std::map<std::string, std::string>* Seize::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Seize>());
	SaveField(fields, "allocationType", _allocationType, DEFAULT.allocationType);
	SaveField(fields, "priority=", _priority, DEFAULT.priority);
	SaveField(fields, "queueId", _queue->getId());
	SaveField(fields, "queueName", _queue->getName());
	SaveField(fields, "seizeResquestSize", _seizeRequests->size(), 0u);
	unsigned short i = 0;
	for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++, i++) {
		std::map<std::string, std::string>* seizablefields = (*it)->_saveInstance(i);
		fields->insert(seizablefields->begin(), seizablefields->end());

	}
	return fields;
}

bool Seize::_check(std::string* errorMessage) {
	bool resultAll = true;
	for (std::list<SeizableItemRequest*>::iterator it = _seizeRequests->list()->begin(); it != _seizeRequests->list()->end(); it++) {
		resultAll &= _parentModel->checkExpression((*it)->getQuantityExpression(), "quantity", errorMessage);
		resultAll &= _parentModel->getElements()->check(Util::TypeOf<Resource>(), (*it)->getResource(), "Resource", errorMessage);
	}
	resultAll &= _parentModel->getElements()->check(Util::TypeOf<Queue>(), _queue, "Queue", errorMessage);
	// \todo implement check of each ResourceItemReuest
	//resultAll &= _parentModel->getElements()->check(Util::TypeOf<Attribute>(), _saveAttribute, "SaveAttribute", false, errorMessage);
	return resultAll;
}

PluginInformation* Seize::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Seize>(), &Seize::LoadInstance);
	info->insertDynamicLibFileDependence("queue.so");
	info->insertDynamicLibFileDependence("resource.so");
	return info;
}

ModelComponent* Seize::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Seize* newComponent = new Seize(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;

}

