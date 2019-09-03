/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CounterDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 29 de Maio de 2019, 11:24
 */

#include "Counter.h"

Counter::Counter() : ModelElement(Util::TypeOf<Counter>()) {
    _generateReportInformation = true;
}

Counter::Counter(std::string name) : ModelElement(Util::TypeOf<Counter>()) {
    _name = name;
}

Counter::Counter(std::string name, ModelElement* parent) : ModelElement(Util::TypeOf<Counter>()) {
    _name = name;
    _parent = parent;
}

Counter::Counter(const Counter& orig) : ModelElement(orig) {
}

Counter::~Counter() {
}

std::string Counter::show() {
    return ModelElement::show() +
	    ", count=" + std::to_string(this->_count);
}

void
Counter::clear() {
    _count = 0;
}

void Counter::incCountValue(int value) {
    _count += value;
}

unsigned long Counter::getCountValue() {
    return _count;
}

ModelElement* Counter::getParent() const {
    return _parent;
}

PluginInformation* Counter::GetPluginInformation() {
    PluginInformation* pluginfo = new PluginInformation(Util::TypeOf<Counter>(), &Counter::LoadInstance);
    pluginfo->generateReport = true;
    return pluginfo;
}

ModelElement* Counter::LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields) {
    Counter* newElement = new Counter();
    try {
	newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool Counter::_loadInstance(std::map<std::string, std::string>* fields) {
    return ModelElement::_loadInstance(fields);
}

std::map<std::string, std::string>* Counter::_saveInstance() {
    return ModelElement::_saveInstance();
}
//std::list<std::map<std::string,std::string>*>* _saveInstance(std::string type){}

bool Counter::_check(std::string* errorMessage) {
    return true;
}