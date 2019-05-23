/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decide.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 9 de Agosto de 2018, 20:39
 */

#include "Decide.h"
#include "Model.h"

Decide::Decide(Model* model):ModelComponent(model, Util::TypeOf<Decide>()) {
}

List<std::string>* Decide::getConditions() const {
    return _conditions;
}

Decide::Decide(const Decide& orig):ModelComponent(orig) {
}

Decide::~Decide() {
}

std::string Decide::show() {

}

void Decide::_execute(Entity* entity) {
    double value;
    unsigned short i = 0;
    for (std::list<std::string>::iterator it = _conditions->getList()->begin(); it != _conditions->getList()->end(); it++) {
        value = _model->parseExpression((*it));
        _model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, std::to_string(i+1)+"th condition evaluated to " + std::to_string(value));
        if (value) {
            _model->sendEntityToComponent(entity, this->getNextComponents()->getAtRank(i), 0.0);
            return;
        }
        i++;
    }
    _model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "No condition has been evaluated true");
    _model->sendEntityToComponent(entity, this->getNextComponents()->getAtRank(i), 0.0);
}

void Decide::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Decide::_saveInstance() {
}

bool Decide::_check(std::string* errorMessage) {
    bool allResult=true, result = true;
    std::string condition;
    for (std::list<std::string>::iterator it = _conditions->getList()->begin(); it != _conditions->getList()->end(); it++) {
        condition = (*it);
        allResult &= _model->checkExpression(condition, "Condition", errorMessage);
    }
    return allResult;    
}