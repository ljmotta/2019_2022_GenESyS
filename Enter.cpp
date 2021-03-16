/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enter.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:14
 */

#include "Enter.h"
#include "Model.h"
#include "Counter.h"

Enter::Enter(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Enter>(), name) {
}

std::string Enter::show() {
	return ModelComponent::show() + ",station=" + this->_station->name();
}

ModelComponent* Enter::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Enter* newComponent = new Enter(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void Enter::setStation(Station* _station) {
	this->_station = _station;
}

Station* Enter::getStation() const {
	return _station;
}

void Enter::_execute(Entity* entity) {
	if (_reportStatistics)
		_numberIn->incCountValue();
	_station->enter(entity);
	_parentModel->sendEntityToComponent(entity, this->nextComponents()->frontConnection(), 0.0);
}

bool Enter::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		std::string stationName = ((*(fields->find("stationName"))).second);
		Station* station = dynamic_cast<Station*> (_parentModel->elements()->element(Util::TypeOf<Station>(), stationName));
		this->_station = station;
	}
	return res;
}

void Enter::_initBetweenReplications() {
	_numberIn->clear();
}

std::map<std::string, std::string>* Enter::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	fields->emplace("stationName", (this->_station->name()));
	return fields;
}

bool Enter::_check(std::string* errorMessage) {
	bool resultAll = true;
	resultAll &= _parentModel->elements()->check(Util::TypeOf<Station>(), _station, "Station", errorMessage);
	if (resultAll) {
		_station->setEnterIntoStationComponent(this); // this component will be executed when an entity enters into the station
	}
	return resultAll;
}

PluginInformation* Enter::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Enter>(), &Enter::LoadInstance);
	info->setReceiveTransfer(true);
	info->insertDynamicLibFileDependence("station.so");
	return info;
}

void Enter::_createInternalElements() {
	if (_reportStatistics) {
		if (_numberIn == nullptr) {
			_numberIn = new Counter(_parentModel, _name + "." + "CountNumberIn", this);
			_childrenElements->insert({"CountNumberIn", _numberIn});
		}
	} else
		if (_numberIn != nullptr) {
		_removeChildrenElements();
	}
}