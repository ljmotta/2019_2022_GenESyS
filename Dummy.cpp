/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dummy.cpp
 * Author: rlcancian
 * 
 * Created on 22 de Maio de 2019, 18:41
 */

#include "Dummy.h"
#include "Model.h"

Dummy::Dummy(Model* model) : ModelComponent(model, Util::TypeOf<Dummy>()) {
}

Dummy::Dummy(const Dummy& orig): ModelComponent(orig) {
}

Dummy::~Dummy() {
}

std::string Dummy::show() {
    return ModelComponent::show() + "";
}

void Dummy::_execute(Entity* entity) {
    _model->getTracer()->trace(Util::TraceLevel::blockInternal, "I'm dummy and I'm only sending the entity forward");
    _model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Dummy::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Dummy::_saveInstance() {
}

bool Dummy::_check(std::string* errorMessage) {
    return true;
}

