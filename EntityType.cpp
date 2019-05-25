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

EntityType::EntityType(ElementManager* elemManager) : ModelElement(Util::TypeOf<EntityType>()) {
    _elemManager = elemManager;
    _initCostsAndStatistics();
}

EntityType::EntityType(ElementManager* elemManager, std::string name) : ModelElement(Util::TypeOf<EntityType>()) {
    _elemManager = elemManager;
    _name = name;
    _initCostsAndStatistics();
}

void EntityType::_initCostsAndStatistics() {
    _initialWaitingCost = 0.0;
    _initialVACost = 0.0;
    _initialNVACost = 0.0;
    _initialOtherCost = 0.0;
    // add cstats as elements
    _cstatWaitingTime = new StatisticsCollector("Waiting Time", this);
    _cstatTransferTime = new StatisticsCollector("Transfer Time", this);
    _cstatOtherTime = new StatisticsCollector("Other Time", this);
    _cstatVATime = new StatisticsCollector("Value Added Time", this);
    _cstatNVATime = new StatisticsCollector("Non Value Added Time", this);
    _cstatTotalTime = new StatisticsCollector("Time In System", this);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatNVATime);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatOtherTime);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatTotalTime);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatTransferTime);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatVATime);
    _elemManager->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatWaitingTime);

}

EntityType::EntityType(const EntityType& orig) : ModelElement(orig) {
}

EntityType::~EntityType() {
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatNVATime);
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatOtherTime);
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatTotalTime);
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatTransferTime);
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatVATime);
    _elemManager->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatWaitingTime);
}

std::string EntityType::show() {
    return ModelElement::show() +
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

StatisticsCollector* EntityType::getCstatTotalTime() const {
    return _cstatTotalTime;
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
    std::list<std::string>* words = ModelElement::_saveInstance();//Util::TypeOf<EntityType>());
    words->insert(words->end(), std::to_string(this->_initialNVACost));
    words->insert(words->end(), std::to_string(this->_initialOtherCost));
    words->insert(words->end(), this->_initialPicture);
    words->insert(words->end(), std::to_string(this->_initialVACost));
    words->insert(words->end(), std::to_string(this->_initialWaitingCost));
    return words;
}

bool EntityType::_check(std::string* errorMessage) {
    return true;
}


