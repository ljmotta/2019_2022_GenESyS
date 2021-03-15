/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:49
 */

#include "Delay.h"
#include "Model.h"
#include "Attribute.h"

Delay::Delay(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Delay>(), name) {
}

std::string Delay::show() {
	return ModelComponent::show() +
			",delayExpression=" + this->_delayExpression +
			",timeUnit=" + std::to_string(static_cast<int> (this->_delayTimeUnit));
}

ModelComponent* Delay::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Delay* newComponent = new Delay(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Delay::setDelayExpression(std::string _delayExpression) {
	this->_delayExpression = _delayExpression;
}

std::string Delay::delayExpression() const {
	return _delayExpression;
}

void Delay::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	this->_delayTimeUnit = _delayTimeUnit;
}

Util::TimeUnit Delay::delayTimeUnit() const {
	return _delayTimeUnit;
}

void Delay::_execute(Entity* entity) {
	double waitTime = _parentModel->parseExpression(_delayExpression) * Util::TimeUnitConvert(_delayTimeUnit, _parentModel->infos()->replicationLengthTimeUnit());
	if (_reportStatistics)
		entity->entityType()->addGetStatisticsCollector(_name + "." + "Waiting_Time")->getStatistics()->getCollector()->addValue(waitTime);
	entity->setAttributeValue("Entity.WaitTime", entity->attributeValue("Entity.WaitTime") + waitTime);
	double delayEndTime = _parentModel->simulation()->simulatedTime() + waitTime;
	Event* newEvent = new Event(delayEndTime, entity, this->nextComponents()->frontConnection());
	_parentModel->futureEvents()->insert(newEvent);
	_parentModel->tracer()->trace("End of delay of entity " + std::to_string(entity->entityNumber()) + " scheduled to time " + std::to_string(delayEndTime));
}

bool Delay::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_delayExpression = (*fields->find("delayExpression")).second;
		this->_delayTimeUnit = static_cast<Util::TimeUnit> (std::stoi((*fields->find("delayExpressionTimeUnit")).second));
	}
	return res;
}

void Delay::_initBetweenReplications() {
}

std::map<std::string, std::string>* Delay::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance(); //Util::TypeOf<Delay>());
	fields->emplace("delayExpression", "\"" + this->_delayExpression + "\"");
	fields->emplace("delayExpressionTimeUnit", std::to_string(static_cast<int> (this->_delayTimeUnit)));
	return fields;
}

bool Delay::_check(std::string* errorMessage) {
	//include attributes needed
	ElementManager* elements = _parentModel->elements();
	std::vector<std::string> neededNames = {"Entity.WaitTime"};
	std::string neededName;
	for (unsigned int i = 0; i < neededNames.size(); i++) {
		neededName = neededNames[i];
		if (elements->element(Util::TypeOf<Attribute>(), neededName) == nullptr) {
			Attribute* attr1 = new Attribute(_parentModel, neededName);
			elements->insert(attr1);
		}
	}
	return _parentModel->checkExpression(_delayExpression, "Delay expression", errorMessage);
}

void Delay::_createInternalElements() {
	if (_reportStatistics) {
		// include StatisticsCollector needed in EntityType
		ElementManager* elements = _parentModel->elements();
		std::list<ModelElement*>* enttypes = elements->elementList(Util::TypeOf<EntityType>())->list();
		for (std::list<ModelElement*>::iterator it = enttypes->begin(); it != enttypes->end(); it++) {
			EntityType* enttype = static_cast<EntityType*> ((*it));
			enttype->addGetStatisticsCollector(_name + "." + "Waiting_Time"); // force create this CStat before simulation starts
		}
	} else {
		// \todo remove StatisticsCollector needed in EntityType
	}
}

PluginInformation* Delay::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Delay>(), &Delay::LoadInstance);
	return info;
}
