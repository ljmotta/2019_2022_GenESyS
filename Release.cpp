/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Release.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Release.h"
#include "Model.h"
#include "Resource.h"
#include "Attribute.h"
#include <assert.h>

Release::Release(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Release>(), name) {
}

std::string Release::show() {
	std::string txt = ModelComponent::show() +
			"priority=" + std::to_string(_priority) +
			"releaseRequests={";
	unsigned short i = 0;
	for (std::list<SeizableItemRequest*>::iterator it = _releaseRequests->list()->begin(); it != _releaseRequests->list()->end(); it++, i++) {
		txt += "request" + std::to_string(i) + "=[" + _releaseRequests->show() + "],";
	}
	txt = txt.substr(0, txt.length() - 1) + "}";
	return txt;
}

void Release::setPriority(unsigned short _priority) {
	this->_priority = _priority;
}

unsigned short Release::priority() const {
	return _priority;
}

List<SeizableItemRequest*>* Release::getReleaseRequests() const {
	return _releaseRequests;
}

//void Release::setResource(Resource* _resource) {
//	this->_resource = _resource;
//}

//Resource* Release::resource() const {
//	return _resource;
//}

void Release::_execute(Entity* entity) {
	for (std::list<SeizableItemRequest*>::iterator it = _releaseRequests->list()->begin(); it != _releaseRequests->list()->end(); it++) {
		Resource* resource = (*it)->getResource();
		unsigned int quantity = _parentModel->parseExpression((*it)->getQuantityExpression());
		assert((*it)->getResource()->getNumberBusy() >= quantity);
		_parentModel->getTracer()->traceSimulation(_parentModel->getSimulation()->getSimulatedTime(), entity, this, "Entity frees " + std::to_string(quantity) + " units of resource \"" + resource->getName() + "\" seized on time " + std::to_string((*it)->getResource()->getLastTimeSeized()));
		(*it)->getResource()->release(quantity, _parentModel->getSimulation()->getSimulatedTime()); //{releases and sets the 'LastTimeSeized'property}
	}
	_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

void Release::_initBetweenReplications() {
	for (std::list<SeizableItemRequest*>::iterator it = _releaseRequests->list()->begin(); it != _releaseRequests->list()->end(); it++) {
		(*it)->getResource()->initBetweenReplications();
	}
}

bool Release::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_priority = std::stoi((*(fields->find("priority"))).second);
		//Util::identitifcation resourceId = std::stoi((*(fields->find("resourceId"))).second);
		//Resource* res = dynamic_cast<Resource*> (_model->elements()->element(Util::TypeOf<Resource>(), resourceId));

		unsigned short numRequests = std::stoi((*(fields->find("releaseResquestSize"))).second);
		for (unsigned short i = 0; i < numRequests; i++) {
			//std::string resRequest = ((*(fields->find("resourceItemRequest"))).second);
			SeizableItemRequest::ResourceType resourceType = static_cast<SeizableItemRequest::ResourceType> (std::stoi((*(fields->find("resourceType" + std::to_string(i)))).second));
			std::string resourceName = ((*(fields->find("resourceName" + std::to_string(i)))).second);
			Resource* resource = dynamic_cast<Resource*> (_parentModel->getElements()->getElement(Util::TypeOf<Resource>(), resourceName));
			std::string quantityExpression = ((*(fields->find("quantity" + std::to_string(i)))).second);
			SeizableItemRequest::SelectionRule rule = static_cast<SeizableItemRequest::SelectionRule> (std::stoi((*(fields->find("selectionRule" + std::to_string(i)))).second));
			std::string saveAttribute = ((*(fields->find("saveAttribute" + std::to_string(i)))).second);
			unsigned int index = std::stoi((*(fields->find("index" + std::to_string(i)))).second);
			this->_releaseRequests->insert(new SeizableItemRequest(resource, quantityExpression, resourceType, rule, saveAttribute, index));
		}
	}
	return res;
}

std::map<std::string, std::string>* Release::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Release>());
	fields->emplace("priority", std::to_string(this->_priority));
	fields->emplace("releaseResquestSize", std::to_string(_releaseRequests->size()));
	unsigned short i = 0;
	for (std::list<SeizableItemRequest*>::iterator it = _releaseRequests->list()->begin(); it != _releaseRequests->list()->end(); it++, i++) {
		fields->emplace("resourceType" + std::to_string(i), std::to_string(static_cast<int> ((*it)->getResourceType())));
		//fields->emplace("resourceItemRequest" + std::to_string(i), "{" + map2str((*it)->_saveInstance()) + "}");
		fields->emplace("resourceId" + std::to_string(i), std::to_string((*it)->getResource()->getId()));
		fields->emplace("resourceName" + std::to_string(i), ((*it)->getResource()->getName()));
		fields->emplace("quantity" + std::to_string(i), (*it)->getQuantityExpression());
		fields->emplace("selectionRule" + std::to_string(i), std::to_string(static_cast<int> ((*it)->getSelectionRule())));
		fields->emplace("saveAttribute" + std::to_string(i), (*it)->getSaveAttribute());
	}
	return fields;
}

bool Release::_check(std::string* errorMessage) {
	bool resultAll = true;

	for (std::list<SeizableItemRequest*>::iterator it = _releaseRequests->list()->begin(); it != _releaseRequests->list()->end(); it++) {
		resultAll &= _parentModel->checkExpression((*it)->getQuantityExpression(), "quantity", errorMessage);
		resultAll &= _parentModel->getElements()->check(Util::TypeOf<Resource>(), (*it)->getResource(), "Resource", errorMessage);
		resultAll &= _parentModel->getElements()->check(Util::TypeOf<Attribute>(), (*it)->getSaveAttribute(), "SaveAttribute", false, errorMessage);
	}
	return resultAll;
}

//void Release::setResourceName(std::string resourceName) throw () {
//	ModelElement* resource = _parentModel->elements()->element(Util::TypeOf<Resource>(), resourceName);
//	if (resource != nullptr) {
//		this->_resource = dynamic_cast<Resource*> (resource);
//	} else {
//		throw std::invalid_argument("Resource does not exist");
//	}
//}

//std::string Release::resourceName() const {
//	return _resource->name();
//}

PluginInformation* Release::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Release>(), &Release::LoadInstance);
	info->insertDynamicLibFileDependence("resource.so");
	return info;
}

ModelComponent* Release::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Release* newComponent = new Release(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;

}
