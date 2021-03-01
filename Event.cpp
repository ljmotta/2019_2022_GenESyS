/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:41
 */

#include "Event.h"

//using namespace GenesysKernel;

Event::Event(double time, Entity* entity, ModelComponent* component, unsigned int componentInputNumber) {
	_time = time;
	_entity = entity;
	_component = component;
	_componentInputNumber = componentInputNumber;
}

Event::Event(double time, Entity* entity, Connection* connection) {
	_time = time;
	_entity = entity;
	_component = connection->first;
	_componentInputNumber = connection->second;
}

std::string Event::show() {
	return "time=" + std::to_string(_time) +
			",entity=" + std::to_string(_entity->entityNumber()) +
			",comp=\"" + _component->name() + "\""; //+std::to_string(_component->getId())+"}";
}

unsigned int Event::componentInputNumber() const {
	return _componentInputNumber;
}

double Event::time() const {
	return _time;
}

ModelComponent* Event::component() const {
	return _component;
}

Entity* Event::entity() const {
	return _entity;
}

