/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 16:52
 */

#include "Resource.h"

Resource::Resource(Model* model) : ModelInfrastructure(Util::TypeOf<Resource>()) {
	_cstatTimeSeized = new StatisticsCollector("Time Seized", this);
	List<ModelInfrastructure*>* infras = model->getInfraManager()->getInfrastructures(Util::TypeOf<StatisticsCollector>());
	infras->insert(_cstatTimeSeized);
}

Resource::Resource(const Resource& orig) : ModelInfrastructure(orig) {
}

Resource::~Resource() {
	_cstatTimeSeized->~StatisticsCollector();
}

std::string Resource::show() {
	return ModelInfrastructure::show() +
			",capacity=" + std::to_string(_capacity) +
			",costBusyByour=" + std::to_string(_costBusyHour) +
			",costIdleByour=" + std::to_string(_costIdleHour) +
			",costPerUse=" + std::to_string(_costPerUse) +
			",state=" + std::to_string(_resourceState);
}

void Resource::seize(unsigned int quantity, double tnow) {
	_numberBusy += quantity;
	_seizes++;
	_whenSeized = tnow;
}

void Resource::release(unsigned int quantity, double tnow) {
	if (_numberBusy >= quantity) {
		_numberBusy -= quantity;
	} else {
		_numberBusy = 0;
	}
	_numberOut++;
	double timeSeized = tnow - _whenSeized;
	// Collect statistics about time seized
	//cstats := Genesys.Model.SIMAN._GetModuleStructuresByKind(cCSTAT);
	//i := cstats.IndexOf(IntToStr(aCSTATTimeSeizedID));
	//TCStat(cstats.Objects[i]).AddValue(timeSeized);
	this->_cstatTimeSeized->getCollector()->addValue(timeSeized);
	//
	_lastTimeSeized = timeSeized; // check. Isn't it TNOW?	
}

void Resource::setResourceState(ResourceState _resourceState) {
	this->_resourceState = _resourceState;
}

Resource::ResourceState Resource::getResourceState() const {
	return _resourceState;
}

void Resource::setCapacity(unsigned int _capacity) {
	this->_capacity = _capacity;
}

unsigned int Resource::getCapacity() const {
	return _capacity;
}

void Resource::setCostBusyHour(double _costBusyHour) {
	this->_costBusyHour = _costBusyHour;
}

double Resource::getCostBusyHour() const {
	return _costBusyHour;
}

void Resource::setCostIdleHour(double _costIdleHour) {
	this->_costIdleHour = _costIdleHour;
}

double Resource::getCostIdleHour() const {
	return _costIdleHour;
}

void Resource::setCostPerUse(double _costPerUse) {
	this->_costPerUse = _costPerUse;
}

double Resource::getCostPerUse() const {
	return _costPerUse;
}

unsigned int Resource::getNumberBusy() const {
	return _numberBusy;
}

unsigned int Resource::getNumberOut() const {
	return _numberOut;
}


void Resource::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Resource::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Resource::_verifySymbols(std::string* errorMessage) {

}