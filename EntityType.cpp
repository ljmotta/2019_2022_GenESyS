/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntityType.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 14 de Agosto de 2018, 19:24
 */

#include "EntityType.h"
#include "Model.h"
#include "SimulationResponse.h"

//using namespace GenesysKernel;

//EntityType::EntityType(Model* model) : ModelElement(model, Util::TypeOf<EntityType>()) {
//    //_elemManager = elemManager;
//    _initCostsAndStatistics();
//}

EntityType::EntityType(Model* model, std::string name) : ModelElement(model, Util::TypeOf<EntityType>(), name) {
	_initCostsAndStatistics();
}

void EntityType::_initCostsAndStatistics() {
	_initialWaitingCost = 0.0;
	_initialVACost = 0.0;
	_initialNVACost = 0.0;
	_initialOtherCost = 0.0;
	// add cstats as elements
	//_cstatWaitingTime = new StatisticsCollector("Waiting Time", this);
	//_cstatTransferTime = new StatisticsCollector("Transfer Time", this);
	//_cstatOtherTime = new StatisticsCollector("Other Time", this);
	//_cstatVATime = new StatisticsCollector("Value Added Time", this);
	//_cstatNVATime = new StatisticsCollector("Non Value Added Time", this);
	//_cstatTotalTime = new StatisticsCollector("Time In System", this);
	//_elemManager->insert(_cstatNVATime);
	//_elemManager->insert(_cstatOtherTime);
	//_elemManager->insert(_cstatTotalTime);
	//_elemManager->insert(_cstatTransferTime);
	//_elemManager->insert(_cstatVATime);
	//_elemManager->insert(_cstatWaitingTime);
	// insert cstats as simulation responses

	//    List<::SimulationResponse*>* responses = this->_elemManager->getParentModel()->getResponses();
	//    responses->insert(new SimulationResponse(Util::TypeOf<EntityType>(), "Waiting time",
	//            DefineGetterMember<StatisticsDefaultImpl1>(this->_cstatWaitingTime, &StatisticsDefaultImpl1::average)));
}

EntityType::~EntityType() {
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatNVATime);
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatOtherTime);
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatTotalTime);
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatTransferTime);
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatVATime);
	//_elemManager->remove(Util::TypeOf<StatisticsCollector>(), _cstatWaitingTime);
	// remove all CStats
	for (std::list<StatisticsCollector*>::iterator it = this->_statisticsCollectors->list()->begin(); it != this->_statisticsCollectors->list()->end(); it++) {
		_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), (*it));
	}
}

std::string EntityType::show() {
	return ModelElement::show() +
			",initialPicture=" + this->_initialPicture; // add more...
}

void EntityType::setInitialWaitingCost(double _initialWaitingCost) {
	this->_initialWaitingCost = _initialWaitingCost;
}

double EntityType::initialWaitingCost() const {
	return _initialWaitingCost;
}

void EntityType::setInitialOtherCost(double _initialOtherCost) {
	this->_initialOtherCost = _initialOtherCost;
}

double EntityType::initialOtherCost() const {
	return _initialOtherCost;
}

void EntityType::setInitialNVACost(double _initialNVACost) {
	this->_initialNVACost = _initialNVACost;
}

double EntityType::initialNVACost() const {
	return _initialNVACost;
}

void EntityType::setInitialVACost(double _initialVACost) {
	this->_initialVACost = _initialVACost;
}

double EntityType::initialVACost() const {
	return _initialVACost;
}

void EntityType::setInitialPicture(std::string _initialPicture) {
	this->_initialPicture = _initialPicture;
}

std::string EntityType::initialPicture() const {
	return _initialPicture;
}

//StatisticsCollector* EntityType::getCstatTotalTime() const {
//    return _cstatTotalTime;
//}

//StatisticsCollector* EntityType::getCstatNVATime() const {
//    return _cstatNVATime;
//}

//StatisticsCollector* EntityType::getCstatVATime() const {
//    return _cstatVATime;
//}

//StatisticsCollector* EntityType::getCstatOtherTime() const {
//    return _cstatOtherTime;
//}

//StatisticsCollector* EntityType::getCstatTransferTime() const {
//    return _cstatTransferTime;
//}

//StatisticsCollector* EntityType::getCstatWaitingTime() const {
//    return _cstatWaitingTime;
//}

StatisticsCollector* EntityType::statisticsCollector(std::string name) {
	StatisticsCollector* cstat;
	for (std::list<StatisticsCollector*>::iterator it = _statisticsCollectors->list()->begin(); it != _statisticsCollectors->list()->end(); it++) {
		cstat = (*it);
		if (cstat->name() == name) {
			return cstat;
		}
	}
	// not found. Create it, insert it into the list of cstats, into the model element manager, and then return it
	cstat = new StatisticsCollector(_parentModel, name, this);
	_statisticsCollectors->insert(cstat);
	//_parentModel->insert(cstat); // unnecessary
	return cstat;
}

PluginInformation* EntityType::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<EntityType>(), &EntityType::LoadInstance);
	return info;
}

ModelElement* EntityType::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	EntityType* newElement = new EntityType(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

bool EntityType::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		this->_initialNVACost = std::stod((*(fields->find("initialNVACost"))).second);
		this->_initialOtherCost = std::stod((*(fields->find("initialOtherCost"))).second);
		this->_initialPicture = ((*(fields->find("initialPicture"))).second);
		this->_initialVACost = std::stod((*(fields->find("initialVACost"))).second);
		this->_initialWaitingCost = std::stod((*(fields->find("initialWaitingCost"))).second);
	}
	return res;
}

std::map<std::string, std::string>* EntityType::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<EntityType>());
	fields->emplace("initialNVACost", std::to_string(this->_initialNVACost));
	fields->emplace("initialOtherCost", std::to_string(this->_initialOtherCost));
	fields->emplace("initialPicture", this->_initialPicture);
	fields->emplace("initialVACost", std::to_string(this->_initialVACost));
	fields->emplace("initialWaitingCost", std::to_string(this->_initialWaitingCost));
	return fields;
}

bool EntityType::_check(std::string* errorMessage) {
	return true;
}


