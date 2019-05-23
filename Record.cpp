/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Record.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 9 de Agosto de 2018, 13:52
 */

#include "Record.h"
#include "Model.h"
#include <fstream>
#include <cstdio>
#include <iostream>

Record::Record(Model* model) : ModelComponent(model, Util::TypeOf<Record>()) {
    _cstatExpression = new StatisticsCollector(_expressionName, this);
    _model->getElementManager()->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatExpression);
}

Record::Record(const Record& orig) : ModelComponent(orig) {
}

Record::~Record() {
    _model->getElementManager()->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatExpression);
}

std::string Record::show() {
    return ModelComponent::show() +
            ",expressionName=\"" + this->_expressionName + "\"" +
            ",expression=\"" + _expression + "\"" +
            "filename=\"" + _filename + "\"";
}

void Record::setExpressionName(std::string expressionName) {
    this->_expressionName = expressionName;
    this->_cstatExpression->setName(expressionName);
}

std::string Record::getExpressionName() const {
    return _expressionName;
}

StatisticsCollector* Record::getCstatExpression() const {
    return _cstatExpression;
}

void Record::setFilename(std::string filename) {
    this->_filename = filename;
}

std::string Record::getFilename() const {
    return _filename;
}

void Record::setExpression(std::string expression) {
    this->_expression = expression;
}

std::string Record::getExpression() const {
    return _expression;
}

void Record::_execute(Entity* entity) {
    double value = _model->parseExpression(_expression);
    _cstatExpression->getStatistics()->getCollector()->addValue(value);
    std::ofstream file;
    file.open(_filename, std::ofstream::out | std::ofstream::app);
    file << value << std::endl;
    file.close(); // TODO: open and close for every data is not a good idea. Should open when replication starts and close when it finishes.    
    _model->getTracer()->traceSimulation(Util::TraceLevel::blockInternal, _model->getSimulation()->getSimulatedTime(), entity, this, "Recording value " + std::to_string(value));
    _model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);

}

std::list<std::string>* Record::_saveInstance() {

}

void Record::_loadInstance(std::list<std::string> words) {

}

bool Record::_check(std::string* errorMessage) {
    // when cheking the model (before simulating it), remove the file if exists
    std::remove(_filename.c_str()); 
    return _model->checkExpression(_expression, "expression", errorMessage);
}