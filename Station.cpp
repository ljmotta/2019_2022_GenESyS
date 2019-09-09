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

Station::Station(ElementManager* elems) : ModelElement(Util::TypeOf<Station>()) {
    _elems = elems;
    _initCStats(); 
}

Station::Station(ElementManager* elems, std::string name) : ModelElement(Util::TypeOf<Station>()) {
    _name = name;
    _elems = elems;
    _initCStats();
}

void Station::_initCStats() {
//    _cstatNumberInStation = new StatisticsCollector("Number In Station", this); /* TODO: ++ WHY THIS INSERT "DISPOSE" AND "10ENTITYTYPE" STATCOLL ?? */
//    _cstatTimeInStation = new StatisticsCollector("Time In Station", this);
//    _elems->insert(Util::TypeOf<StatisticsCollector>(), _cstatNumberInStation);
//    _elems->insert(Util::TypeOf<StatisticsCollector>(), _cstatTimeInStation);

}

Station::Station(const Station& orig) : ModelElement(orig) {
}

Station::~Station() {
    //_elems->remove(Util::TypeOf<StatisticsCollector>(), _cstatNumberInStation);
    //_elems->remove(Util::TypeOf<StatisticsCollector>(), _cstatTimeInStation);
}

std::string Station::show() {
    return ModelElement::show() +
	    "";
}

void Station::initBetweenReplications() {
    //this->_list->clear();
}


PluginInformation* Station::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Station>(), &Station::LoadInstance); return info;
}

ModelElement* Station::LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields) {
    Station* newElement = new Station(elems);
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
	    //this->_attributeName = (*fields->find("attributeName")).second;
	    //this->_orderRule = static_cast<OrderRule> (std::stoi((*fields->find("orderRule")).second));
	} catch (...) {
	}
    }
    return res;
}

std::map<std::string, std::string>* Station::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Station>());
    //fields->emplace("orderRule", std::to_string(static_cast<int> (this->_orderRule)));
    //fields->emplace("attributeName", this->_attributeName);
    return fields;
}

bool Station::_check(std::string* errorMessage) {
    return true; //_elems->check(Util::TypeOf<Attribute>(), _attributeName, "AttributeName", false, errorMessage);
}

