/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SourceModelCOmponent.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:50
 */

#include "SourceModelComponent.h"
#include "Model.h"
#include "Attribute.h"

SourceModelComponent::SourceModelComponent(Model* model, std::string componentTypename) : ModelComponent(model, componentTypename) {
}

SourceModelComponent::SourceModelComponent(const SourceModelComponent& orig) : ModelComponent(orig) {
}

SourceModelComponent::~SourceModelComponent() {
}

std::string SourceModelComponent::show() {
    std::string text = ModelComponent::show() +
            ",entityType=\"" + _entityType->getName() + "\"" +
            ",firstCreation=" + std::to_string(_firstCreation);
    return text;
}

void SourceModelComponent::_loadInstance(std::list<std::string> fields) {
}

std::list<std::string>* SourceModelComponent::_saveInstance() {
    std::list<std::string>* fields = ModelComponent::_saveInstance();
    fields->push_back("entitiesPerCreation="+std::to_string(this->_entitiesPerCreation));
    fields->push_back("firstCreation="+std::to_string(this->_firstCreation));
    fields->push_back("timeBetweenCreations="+this->_timeBetweenCreationsExpression);
    fields->push_back("timeBetweenCreationsTimeUnit="+std::to_string(static_cast<int> (this->_timeBetweenCreationsTimeUnit)));
    fields->push_back("maxCreations="+std::to_string(this->_maxCreations));
    fields->push_back("entitypeName="+(this->_entityType->getName())); // save the name
    fields->push_back("collectStatistics="+std::to_string(this->_collectStatistics));
    return fields;
}

bool SourceModelComponent::_check(std::string* errorMessage) {
    /* include attributes needed */
    ElementManager* elements = _model->getElementManager();
    std::vector<std::string> neededNames = {"Entity.ArrivalTime", "Entity.VATime", "Entity.NVAlTime", "Entity.WaitTime", "Entity.TransferTime", "Entity.OtherTime"};
    std::string neededName;
    for (int i = 0; i < neededNames.size(); i++) {
        neededName = neededNames[i];
        if (elements->getElement(Util::TypeOf<Attribute>(), neededName) == nullptr) {
            Attribute* attr1 = new Attribute(neededName);
            elements->insert(Util::TypeOf<Attribute>(), attr1);
        }
    }
    bool resultAll = true;
    resultAll &= _model->checkExpression(this->_timeBetweenCreationsExpression, "time between creations", errorMessage);
    resultAll &= _model->getElementManager()->check(Util::TypeOf<EntityType>(), _entityType, "entitytype", errorMessage);
    return resultAll;
}

void SourceModelComponent::setFirstCreation(double _firstCreation) {
    this->_firstCreation = _firstCreation;
}

double SourceModelComponent::getFirstCreation() const {
    return _firstCreation;
}

void SourceModelComponent::setCollectStatistics(bool _collectStatistics) {
    this->_collectStatistics = _collectStatistics;
}

bool SourceModelComponent::isCollectStatistics() const {
    return _collectStatistics;
}

void SourceModelComponent::setEntityType(EntityType* entityType) {
    _entityType = entityType;
}

EntityType* SourceModelComponent::getEntityType() const {
    return _entityType;
}

void SourceModelComponent::setTimeUnit(Util::TimeUnit _timeUnit) {
    this->_timeBetweenCreationsTimeUnit = _timeUnit;
}

Util::TimeUnit SourceModelComponent::getTimeUnit() const {
    return this->_timeBetweenCreationsTimeUnit;
}

void SourceModelComponent::setTimeBetweenCreationsExpression(std::string _timeBetweenCreations) {
    this->_timeBetweenCreationsExpression = _timeBetweenCreations;
}

std::string SourceModelComponent::getTimeBetweenCreationsExpression() const {
    return _timeBetweenCreationsExpression;
}

void SourceModelComponent::setMaxCreations(unsigned int _maxCreations) {
    this->_maxCreations = _maxCreations;
}

unsigned int SourceModelComponent::getMaxCreations() const {
    return _maxCreations;
}

unsigned int SourceModelComponent::getEntitiesCreated() const {
    return _entitiesCreatedSoFar;
}

void SourceModelComponent::setEntitiesCreated(unsigned int _entitiesCreated) {
    this->_entitiesCreatedSoFar = _entitiesCreated;
}

void SourceModelComponent::setEntitiesPerCreation(unsigned int _entitiesPerCreation) {
    this->_entitiesPerCreation = _entitiesPerCreation;
}

unsigned int SourceModelComponent::getEntitiesPerCreation() const {
    return _entitiesPerCreation;
}

