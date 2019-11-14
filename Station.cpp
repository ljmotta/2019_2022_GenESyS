/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Station.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:12
 */

#include "Station.h"
#include "Entity.h"
#include "Model.h"
#include "Attribute.h"

Station::Station(Model* model, std::string name) : ModelElement(model, Util::TypeOf<Station>(),name) {
    _initCStats();
}

void Station::_initCStats() {
    _cstatNumberInStation = new StatisticsCollector(_parentModel, _name+"."+"Number_In_Station", this);
    _cstatTimeInStation = new StatisticsCollector(_parentModel, _name+"."+"Time_In_Station", this);
    _childrenElements->insert({"NumberInStation", _cstatNumberInStation});
    _childrenElements->insert({"TimeInStation", _cstatTimeInStation});

}
Station::~Station() {
    //_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), _cstatNumberInStation);
    //_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), _cstatTimeInStation);
}

std::string Station::show() {
    std::string msg = ModelElement::show() + ",enterIntoStationComponent=";
    if (_enterIntoStationComponent == nullptr)
	msg += "NULL";
    else
	msg += _enterIntoStationComponent->name();
    return msg;
}

void Station::initBetweenReplications() {
    //this->_list->clear();
}

void Station::enter(Entity* entity) {
    std::string attributeName = "Entity.ArrivalAt" + this->name();
    trimwithin(attributeName);
    entity->setAttributeValue(attributeName, _parentModel->simulation()->simulatedTime());
    entity->attributeValue("Entity.Station", _id);
    _numberInStation++;
    this->_cstatNumberInStation->getStatistics()->getCollector()->addValue(_numberInStation);
}

void Station::leave(Entity* entity) {
    std::string attributeName = "Entity.ArrivalAt" + this->name();
    trimwithin(attributeName);
    double arrivalTime = entity->attributeValue(attributeName);
    double timeInStation = _parentModel->simulation()->simulatedTime() - arrivalTime;
    _cstatTimeInStation->getStatistics()->getCollector()->addValue(timeInStation);
    entity->entityType()->statisticsCollector("Time in Stations")->getStatistics()->getCollector()->addValue(timeInStation);
    entity->attributeValue("Entity.Station", 0.0);
    _numberInStation--;
    _cstatNumberInStation->getStatistics()->getCollector()->addValue(_numberInStation);
}

void Station::setEnterIntoStationComponent(ModelComponent* _enterIntoStationComponent) {
    this->_enterIntoStationComponent = _enterIntoStationComponent;
}

ModelComponent* Station::getEnterIntoStationComponent() const {
    return _enterIntoStationComponent;
}

PluginInformation* Station::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Station>(), &Station::LoadInstance);
    return info;
}

ModelElement* Station::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Station* newElement = new Station(model);
    try {
	newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool Station::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelElement::_loadInstance(fields);
    if (res) {
	try {
	} catch (...) {
	}
    }
    return res;
}

std::map<std::string, std::string>* Station::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Station>());
    return fields;
}

bool Station::_check(std::string* errorMessage) {
    /* include attributes needed */
    std::vector<std::string> neededNames = {"Entity.Station"};
    neededNames.insert(neededNames.begin(), "Entity.ArrivalAt" + this->name());
    std::string neededName;
    for (unsigned int i = 0; i < neededNames.size(); i++) {
	neededName = neededNames[i];
	if (_parentModel->elements()->element(Util::TypeOf<Attribute>(), neededName) == nullptr) {
	    Attribute* attr1 = new Attribute(_parentModel, neededName);
	    //_parentModel->insert(attr1);
	}
    }
    // include StatisticsCollector needed in EntityType
    std::list<ModelElement*>* enttypes = _parentModel->elements()->elementList(Util::TypeOf<EntityType>())->list();
    for (std::list<ModelElement*>::iterator it = enttypes->begin(); it != enttypes->end(); it++) {
	static_cast<EntityType*> ((*it))->statisticsCollector("Time in Stations"); // force create this CStat before simulation starts
    }
    //
    return true;
}

void Station::_createInternalElements() {
    //_initCStats();
}

