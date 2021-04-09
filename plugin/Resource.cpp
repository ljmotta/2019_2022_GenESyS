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

#include "../Resource.h"
#include "../Counter.h"
#include "../Model.h"

extern "C" StaticGetPluginInformation getPluginInformation() {
	return &Resource::GetPluginInformation;
}

Resource::Resource(Model* model, std::string name) : ModelElement(model, Util::TypeOf<Resource>(), name) {
	GetterMember getter = DefineGetterMember<Resource>(this, &Resource::getCapacity);
	SetterMember setter = DefineSetterMember<Resource>(this, &Resource::setCapacity);
	model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), _name + ".Capacity", getter, setter));

	GetterMember getter2 = DefineGetterMember<Resource>(this, &Resource::getCostPerUse);
	SetterMember setter2 = DefineSetterMember<Resource>(this, &Resource::setCostPerUse);
	model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), _name + ".CostPerUse", getter2, setter2));
	// ...

}

Resource::~Resource() {
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
	if (_reportStatistics)
		_numSeizes->incCountValue(quantity);
	_lastTimeSeized = tnow;
	_resourceState = Resource::ResourceState::BUSY;
	// \todo implement costs
}

void Resource::release(unsigned int quantity, double tnow) {
	if (_numberBusy >= quantity) {
		_numberBusy -= quantity;
	} else {
		_numberBusy = 0;
	}
	if (_numberBusy == 0) {
		_resourceState = Resource::ResourceState::IDLE;
	}
	double timeSeized = tnow - _lastTimeSeized;
	if (_reportStatistics) {
		_numReleases->incCountValue(quantity);
		_cstatTimeSeized->getStatistics()->getCollector()->addValue(timeSeized);
	}
	//
	_lastTimeSeized = timeSeized;
	_notifyReleaseEventHandlers();
}

void Resource::initBetweenReplications() {
	this->_lastTimeSeized = 0.0;
	this->_numberBusy = 0;
	if (_reportStatistics) {
		this->_numSeizes->clear();
		this->_numReleases->clear();
	}
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

void Resource::addReleaseResourceEventHandler(ResourceEventHandler eventHandler) {
	this->_resourceEventHandlers->insert(eventHandler); // \todo: priority should be registered as well, so handlers are invoqued ordered by priority
}

double Resource::getLastTimeSeized() const {
	return _lastTimeSeized;
}

void Resource::_notifyReleaseEventHandlers() {
	for (std::list<ResourceEventHandler>::iterator it = this->_resourceEventHandlers->list()->begin(); it != _resourceEventHandlers->list()->end(); it++) {
		(*it)(this);
	}
}

PluginInformation* Resource::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Resource>(), &Resource::LoadInstance, &Resource::CreateInstance);
	return info;
}

ModelElement* Resource::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Resource* newElement = new Resource(model);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

ModelElement* Resource::CreateInstance(Model* model, std::string name) {
	return new Resource(model, name);;
}

bool Resource::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelElement::_loadInstance(fields);
	if (res) {
		this->_capacity = std::stoi((*(fields->find("capacity"))).second);
		this->_costBusyHour = std::stod((*(fields->find("costBusyHour"))).second);
		this->_costIdleHour = std::stod((*(fields->find("costIdleHour"))).second);
		this->_costPerUse = std::stod((*(fields->find("costPerUse"))).second);
	}
	return res;
}

std::map<std::string, std::string>* Resource::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Resource>());
	fields->emplace("capacity", std::to_string(this->_capacity));
	fields->emplace("costBusyHour", std::to_string(this->_costBusyHour));
	fields->emplace("costIdleHour", std::to_string(this->_costIdleHour));
	fields->emplace("costPerUse", std::to_string(this->_costPerUse));
	return fields;
}

bool Resource::_check(std::string* errorMessage) {
	return true;
}

void Resource::_createInternalElements() {
	if (_reportStatistics && _cstatTimeSeized == nullptr) {
		_cstatTimeSeized = new StatisticsCollector(_parentModel, _name + "." + "TimeSeized", this);
		_numSeizes = new Counter(_parentModel, _name + "." + "Seizes", this);
		_numReleases = new Counter(_parentModel, _name + "." + "Releases", this);
		_childrenElements->insert({"TimeSeized", _cstatTimeSeized});
		_childrenElements->insert({"Seizes", _numSeizes});
		_childrenElements->insert({"Releases", _numReleases});
	} else if (!_reportStatistics && _cstatTimeSeized != nullptr) {
		_removeChildrenElements();
	}
}