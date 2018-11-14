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
#include "CollectorMyImpl1.h" /////
//#include "Traits.h"

EntityType::EntityType(Model* model) : ModelInfrastructure(typeid (EntityType).name()) {
	// add cstats as infrastructures
	_cstatWaitingTime = new StatisticsCollector("Waiting Time", this);
	_cstatTransferTime = new StatisticsCollector("Transfer Time", this);
	_cstatOtherTime = new StatisticsCollector("Other Time", this);
	_cstatVATime = new StatisticsCollector("Value Added Time", this);
	_cstatNVATime = new StatisticsCollector("Non Value Added Time", this);
	_cstatTimeInSystem = new StatisticsCollector("Time In System", this);
	//List<ModelInfrastructure*>* infras = model->getInfraManager()->getInfrastructures(Util::TypeOf<StatisticsCollector>());
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatNVATime);
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatOtherTime);
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatTimeInSystem);
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatTransferTime);
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatVATime);
	model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatWaitingTime);
}

EntityType::EntityType(const EntityType& orig) : ModelInfrastructure(orig) {
}

EntityType::~EntityType() {
	/*
	List<ModelInfrastructure*>* infras = model->getInfrastructure()->getInfrastructures(Util::TypeOf<StatisticsCollector>());
	infras->remove(); ///// TODOS OS ACESSOS A LISTAS DEVERIAM SER MEDIADOS. AO EXCLUIR UM CSTAT, ELE DEVERIA SER EXCLUÍDO DA LISTA
	_cstatWaitingTime->~StatisticsCollector();
	_cstatTransferTime->~StatisticsCollector();
	_cstatOtherTime->~StatisticsCollector();
	_cstatVATime->~StatisticsCollector();
	_cstatNVATime ->~StatisticsCollector();
	_cstatTimeInSystem->~StatisticsCollector();
	 */
}

std::string EntityType::show() {
	return ModelInfrastructure::show() +
			",initialPicture=" + this->_initialPicture; // add more...
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

StatisticsCollector* EntityType::getCstatTimeInSystem() const {
	return _cstatTimeInSystem;
}

StatisticsCollector* EntityType::getCstatNVATime() const {
	return _cstatNVATime;
}

StatisticsCollector* EntityType::getCstatVATime() const {
	return _cstatVATime;
}

StatisticsCollector* EntityType::getCstatOtherTime() const {
	return _cstatOtherTime;
}

StatisticsCollector* EntityType::getCstatTransferTime() const {
	return _cstatTransferTime;
}

StatisticsCollector* EntityType::getCstatWaitingTime() const {
	return _cstatWaitingTime;
}

void EntityType::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* EntityType::_saveInstance() {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance(Util::TypeOf<EntityType>());
	return words;
}

bool EntityType::_verifySymbols(std::string* errorMessage) {
	return true;
}


