/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 16:52
 */

#include "Resource.h"

Resource::Resource(ElementManager* elems) : ModelElement(Util::TypeOf<Resource>()) {
    _elems = elems;
    _initCStats();
}

Resource::Resource(ElementManager* elems, std::string name) : ModelElement(Util::TypeOf<Resource>()) {
    _name = name;
    _elems = elems;
    _initCStats();
}

void Resource::_initCStats() {
    _cstatTimeSeized = new StatisticsCollector("Time Seized", this);
    _elems->insert(Util::TypeOf<StatisticsCollector>(), _cstatTimeSeized);

}

Resource::Resource(const Resource& orig) : ModelElement(orig) {
}

Resource::~Resource() {
    _elems->remove(Util::TypeOf<StatisticsCollector>(), _cstatTimeSeized);
    _cstatTimeSeized->~StatisticsCollector();
}

std::string Resource::show() {
    return ModelElement::show() +
            ",capacity=" + std::to_string(_capacity) +
            ",costBusyByour=" + std::to_string(_costBusyHour) +
            ",costIdleByour=" + std::to_string(_costIdleHour) +
            ",costPerUse=" + std::to_string(_costPerUse) +
            ",state=" + std::to_string(static_cast<int> (_resourceState));
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
    this->_cstatTimeSeized->getStatistics()->getCollector()->addValue(timeSeized);
    //
    _lastTimeSeized = timeSeized; 
    _notifyEventHandlers();
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

void Resource::addResourceEventHandler(ResourceEventHandler eventHandler) { 
    this->_resourceEventHandlers->insert(eventHandler); // TODO: priority should be registered as well, so handlers are invoqued ordered by priority
}

void Resource::_notifyEventHandlers() {
    for (std::list<ResourceEventHandler>::iterator it = this->_resourceEventHandlers->getList()->begin(); it != _resourceEventHandlers->getList()->end(); it++) {
        (*it)(this);
    }
}

void Resource::_loadInstance(std::list<std::string> fields) {

}

std::list<std::string>* Resource::_saveInstance() {
    std::list<std::string>* fields = ModelElement::_saveInstance();//Util::TypeOf<Resource>());
    fields->push_back("capacity="+std::to_string(this->_capacity));
    fields->push_back("costBusyHour="+std::to_string(this->_costBusyHour));
    fields->push_back("costIdleHour="+std::to_string(this->_costIdleHour));
    fields->push_back("costPerUse="+std::to_string(this->_costPerUse));
    return fields;
}

bool Resource::_check(std::string* errorMessage) {
    return true;
}