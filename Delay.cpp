/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 19:49
 */

#include "Delay.h"
#include "Model.h"

Delay::Delay(Model* model):ModelComponent(model, typeid(this).name()) {
}

Delay::Delay(const Delay& orig):ModelComponent(orig) {
}

Delay::~Delay() {
}

std::string Delay::show() {
	return ModelComponent::show()+",delayExpression="+this->_delayExpression + " "+std::to_string(this->_delayTimeUnit);
}

void Delay::setDelayExpression(std::string _delayExpression) {
	this->_delayExpression = _delayExpression;
}

std::string Delay::getDelayExpression() const {
	return _delayExpression;
}

void Delay::setDelayTimeUnit(Util::TimeUnit _delayTimeUnit) {
	this->_delayTimeUnit = _delayTimeUnit;
}

Util::TimeUnit Delay::getDelayTimeUnit() const {
	return _delayTimeUnit;
}

void Delay::_execute(Entity* entity) {
	double delayEndTime = _model->getSimulatedTime() + _model->parseExpression(_delayExpression) * Util::_S_timeUnitConvert(_delayTimeUnit, _model->getReplicationLengthTimeUnit());
	Event* newEvent = new Event(delayEndTime, entity, this->getNextComponents()->first());
	_model->getEvents()->insert(newEvent);
	_model->trace(Util::TraceLevel::TL_blockInternal, "End of delay of entity "+std::to_string(entity->getId())+" schedule to time "+std::to_string(delayEndTime));
}