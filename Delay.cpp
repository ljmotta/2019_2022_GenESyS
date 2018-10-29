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

Delay::Delay(Model* model) : ModelComponent(model) {
	_name = "Delay "+std::to_string(Util::GenerateNewIdOfType<Delay>());
}

Delay::Delay(const Delay& orig) : ModelComponent(orig) {
}

Delay::~Delay() {
}

std::string Delay::show() {
	return ModelComponent::show() + 
			",delayExpression=" + this->_delayExpression +
			",timeUnit=" + std::to_string(static_cast<int>(this->_delayTimeUnit));
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
	double delayEndTime = _model->getSimulatedTime() + _model->parseExpression(_delayExpression) * Util::TimeUnitConvert(_delayTimeUnit, _model->getReplicationLengthTimeUnit());
	Event* newEvent = new Event(delayEndTime, entity, this->getNextComponents()->first());
	_model->getEvents()->insert(newEvent);
	_model->trace(Util::TraceLevel::blockInternal, "End of delay of entity " + std::to_string(entity->getId()) + " scheduled to time " + std::to_string(delayEndTime));
}



void Delay::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Delay::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;

}

bool Delay::_verifySymbols(std::string* errorMessage) {
    bool result = true;
    this->_model->parseExpression(getDelayExpression(), &result, errorMessage);
    return result;
}