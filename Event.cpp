/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 19:41
 */

#include "Event.h"

Event::Event(double time, Entity* entity, ModelComponent* component) {
	_time = time;
	_entity = entity;
	_component = component;
}

Event::Event(const Event& orig) {
}

Event::~Event() {
}

std::string Event::show() {
	return "{time="+std::to_string(_time)+",entity="+std::to_string(_entity->getId())+",comp="+std::to_string(_component->getId())+"}";
}

double Event::getTime() const {
	return _time;
}

ModelComponent* Event::getComponent() const {
	return _component;
}

Entity* Event::getEntity() const {
	return _entity;
}

