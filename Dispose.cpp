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

Dispose::Dispose(Model* model) : SinkModelComponent(model, Util::TypeOf<Dispose>()) {
    model->getResponses()->insert(new SimulationResponse(Util::TypeOf<Dispose>(), "Number Out",
            DefineGetterMember<Dispose>(this, &Dispose::getNumberOut))
            );
}

Dispose::Dispose(const Dispose& orig) : SinkModelComponent(orig) {
}

Dispose::~Dispose() {
}

std::string Dispose::show() {
    return SinkModelComponent::show() +
            ",collectStatistics=" + std::to_string(this->_collectStatistics);
}

unsigned int Dispose::getNumberOut() const {
    return _numberOut;
}

void Dispose::setCollectStatistics(bool _collectStatistics) {
    this->_collectStatistics = _collectStatistics;
}

bool Dispose::isCollectStatistics() const {
    return _collectStatistics;
}

void Dispose::_execute(Entity* entity) {
    _model->removeEntity(entity, this->isCollectStatistics());
}

void Dispose::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Dispose::_saveInstance() {
    std::list<std::string>* words = ModelComponent::_saveInstance(Util::TypeOf<Dispose>());
    return words;

}

bool Dispose::_verifySymbols(std::string* errorMessage) {
    return true;
}