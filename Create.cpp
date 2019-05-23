/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Create.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 20:12
 */

#include "Create.h"
#include "Model.h"
#include "EntityType.h"
#include "ElementManager.h"
#include "Attribute.h"

Create::Create(Model* model) : SourceModelComponent(model, Util::TypeOf<Create>()) {
    model->getControls()->insert(new SimulationControl(Util::TypeOf<Create>(), "Entities Per Creation",
            DefineGetterMember<SourceModelComponent>(this, &Create::getEntitiesPerCreation),
            DefineSetterMember<SourceModelComponent>(this, &Create::setEntitiesPerCreation))
            );
    /*
    model->getControls()->insert(new SimulationControl(Util::TypeOf<Create>(), "Time Between Creations",
            DefineGetterMember<SourceModelComponent>(this, &Create::getTimeBetweenCreationsExpression),
            DefineSetterMember<SourceModelComponent>(this, &Create::setTimeBetweenCreationsExpression))
            );
    */
}

Create::Create(const Create& orig) : SourceModelComponent(orig) {
}

Create::~Create() {
}

std::string Create::show() {
    return SourceModelComponent::show();
}

void Create::_execute(Entity* entity) {
    double tnow = _model->getSimulation()->getSimulatedTime();
    entity->setAttributeValue("Entity.ArrivalTime", tnow); // ->find("Entity.ArrivalTime")->second->setValue(tnow);
    entity->setAttributeValue("Entity.Picture", 1); // ->find("Entity.ArrivalTime")->second->setValue(tnow);
    double timeBetweenCreations, timeScale, newArrivalTime;
    for (unsigned int i = 0; i<this->_entitiesPerCreation; i++) {
        if (_entitiesCreatedSoFar < _maxCreations) {
            _entitiesCreatedSoFar++;
            Entity* newEntity = new Entity(this->_model->getElementManager());
            newEntity->setEntityType(entity->getEntityType());
            _model->getElementManager()->insertElement(Util::TypeOf<Entity>(), newEntity); // ->getEntities()->insert(newEntity);
            timeBetweenCreations = _model->parseExpression(this->_timeBetweenCreationsExpression);
            timeScale = Util::TimeUnitConvert(this->_timeBetweenCreationsTimeUnit, _model->getInfos()->getReplicationLengthTimeUnit());
            newArrivalTime = tnow + timeBetweenCreations*timeScale;
            Event* newEvent = new Event(newArrivalTime, newEntity, this);
            _model->getEvents()->insert(newEvent);
            _model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, tnow, entity, this, "Arrival of entity " + std::to_string(newEntity->getId()) + " schedule for time " + std::to_string(newArrivalTime));
            //_model->getTrace()->trace(Util::TraceLevel::blockInternal, "Arrival of entity "+std::to_string(entity->getId()) + " schedule for time " +std::to_string(newArrivalTime));
        }
    }
    _model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Create::_loadInstance(std::list<std::string> words) {
    // the first word (CREATE) have to be deleted before. It begins on the second word
    std::list<std::string>::iterator it = words.begin();
    this->_entitiesPerCreation = std::stoi((*it++));
    this->_firstCreation = std::stoi((*it++));
    this->_timeBetweenCreationsExpression = (*it++);
    this->_timeBetweenCreationsTimeUnit = static_cast<Util::TimeUnit> (std::stoi((*it++))); /*TODO: + how to set a enum class based on a string? */ //std::stoi((*it++)); // bad enum convertion!
    this->_maxCreations = std::stoi((*it++));
    std::string entityTypeName = (*it++); // retrieves the entitytype based on name
    EntityType* entityType = static_cast<EntityType*> (_model->getElementManager()->getElement(Util::TypeOf<EntityType>(), entityTypeName));
    this->_entityType = entityType;
    this->_collectStatistics = std::stoi(*it++);
}

std::list<std::string>* Create::_saveInstance() {
    std::list<std::string>* words = ModelComponent::_saveInstance(Util::TypeOf<Create>());
    words->insert(words->end(), std::to_string(this->_entitiesPerCreation));
    words->insert(words->end(), std::to_string(this->_firstCreation));
    words->insert(words->end(), (this->_timeBetweenCreationsExpression));
    words->insert(words->end(), std::to_string(static_cast<int> (this->_timeBetweenCreationsTimeUnit)));
    words->insert(words->end(), std::to_string(this->_maxCreations));
    words->insert(words->end(), (this->_entityType->getName())); // save the name
    words->insert(words->end(), std::to_string(this->_collectStatistics));
    return words;
}

bool Create::_check(std::string* errorMessage) {
    bool resultAll =  SourceModelComponent::_check(errorMessage); 
    return resultAll;
}
