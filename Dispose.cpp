/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dispose.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 20:13
 */

#include "Dispose.h"
#include "Model.h"

Dispose::Dispose(Model* model, std::string name) : SinkModelComponent(model, Util::TypeOf<Dispose>(),name) {
    _numberOut = new Counter(_parentModel, _name + "." + "Count_number_out", this);
    _parentModel->elements()->insert(_numberOut);
    _connections->setMinOutputConnections(0);
    _connections->setMaxOutputConnections(0);
}


std::string Dispose::show() {
    return SinkModelComponent::show() +
	    ",collectStatistics=" + std::to_string(this->_collectStatistics);
}

void Dispose::_execute(Entity* entity) {
    _numberOut->incCountValue();
    if (_collectStatistics) {
	double timeInSystem = _parentModel->simulation()->simulatedTime() - entity->attributeValue("Entity.ArrivalTime");
	entity->entityType()->statisticsCollector(entity->entityType()->name() + "." + "Total_Time")->getStatistics()->getCollector()->addValue(timeInSystem);
    }

    _parentModel->removeEntity(entity, this->isCollectStatistics());
}

bool Dispose::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelComponent::_loadInstance(fields);
}

void Dispose::_initBetweenReplications() {
    SinkModelComponent::_initBetweenReplications();
}

std::map<std::string, std::string>* Dispose::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    return fields;

}

bool Dispose::_check(std::string* errorMessage) {
    //
    return true;
}

void Dispose::_createInternalElements() {
    // include StatisticsCollector needed for each EntityType
    std::list<ModelElement*>* enttypes = _parentModel->elements()->elementList(Util::TypeOf<EntityType>())->list();
    for (std::list<ModelElement*>::iterator it = enttypes->begin(); it != enttypes->end(); it++) {
	static_cast<EntityType*> ((*it))->statisticsCollector((*it)->name() + "." + "Total_Time"); // force create this CStat before model checking
    }
}

PluginInformation* Dispose::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Dispose>(), &Dispose::LoadInstance);
    info->setSink(true);
    return info;
}

ModelComponent* Dispose::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Dispose* newComponent = new Dispose(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;

}
