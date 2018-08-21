/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntityType.cpp
 * Author: cancian
 * 
 * Created on 14 de Agosto de 2018, 19:24
 */

#include "EntityType.h"
#include "Collector.h"
#include "CollectorImpl1.h" /////
#include "Traits.h"

EntityType::EntityType(): ModelInfrastructure(typeid(this).name()) {
	//Collector_if _coll = Traits<Collector_if>::Collector_Impl(); // uses the Collector implementation defined in Traits
	
	//Collector_if* _cstatWaitingTime = new Collector(new Traits<Collector_if>::Collector());
	Collector_if* _cstatTransferTime = new CollectorImpl1();
	Collector_if* _cstatOtherTime;
	Collector_if* _cstatVATime;
	Collector_if* _cstatNVATime;
	Collector_if* _cstatTimeInSystem;
}

EntityType::EntityType(const EntityType& orig):ModelInfrastructure(orig) {
}

EntityType::~EntityType() {
}

void EntityType::setInitialWaitingCost(double _initialWaitingCost) {
	this->_initialWaitingCost = _initialWaitingCost;
}

double EntityType::getInitialWaitingCost() const {
	return _initialWaitingCost;
}

void EntityType::setInitialOtherCost(double _initialOtherCost) {
	this->_initialOtherCost = _initialOtherCost;
}

double EntityType::getInitialOtherCost() const {
	return _initialOtherCost;
}

void EntityType::setInitialNVACost(double _initialNVACost) {
	this->_initialNVACost = _initialNVACost;
}

double EntityType::getInitialNVACost() const {
	return _initialNVACost;
}

void EntityType::setInitialVACost(double _initialVACost) {
	this->_initialVACost = _initialVACost;
}

double EntityType::getInitialVACost() const {
	return _initialVACost;
}

void EntityType::setInitialPicture(std::string _initialPicture) {
	this->_initialPicture = _initialPicture;
}

std::string EntityType::getInitialPicture() const {
	return _initialPicture;
}

Collector_if* EntityType::getCstatTimeInSystem() const {
	return _cstatTimeInSystem;
}

Collector_if* EntityType::getCstatNVATime() const {
	return _cstatNVATime;
}

Collector_if* EntityType::getCstatVATime() const {
	return _cstatVATime;
}

Collector_if* EntityType::getCstatOtherTime() const {
	return _cstatOtherTime;
}

Collector_if* EntityType::getCstatTransferTime() const {
	return _cstatTransferTime;
}

Collector_if* EntityType::getCstatWaitingTime() const {
	return _cstatWaitingTime;
}

