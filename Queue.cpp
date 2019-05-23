/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Agosto de 2018, 17:12
 */

#include "Queue.h"
#include "Model.h"
#include "Attribute.h"

Queue::Queue(ElementManager* elems) : ModelElement(Util::TypeOf<Queue>()) {
    _elems = elems;
    _initCStats();
}

Queue::Queue(ElementManager* elems, std::string name) : ModelElement(Util::TypeOf<Queue>()) {
    _name = name;
    _elems = elems;
    _initCStats();
}

void Queue::_initCStats() {
    _cstatNumberInQueue = new StatisticsCollector("Number In Queue", this); /* TODO: ++ WHY THIS INSERT "DISPOSE" AND "10ENTITYTYPE" STATCOLL ?? */
    _cstatTimeInQueue = new StatisticsCollector("Time In Queue", this);
    _elems->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatNumberInQueue);
    _elems->insertElement(Util::TypeOf<StatisticsCollector>(), _cstatTimeInQueue);

}

Queue::Queue(const Queue& orig) : ModelElement(orig) {
}

Queue::~Queue() {
    _elems->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatNumberInQueue);
    _elems->removeElement(Util::TypeOf<StatisticsCollector>(), _cstatTimeInQueue);
}

std::string Queue::show() {
    return ModelElement::show() +
            ",waiting=" + this->_list->show();
}

void Queue::insertElement(Waiting* element) {
    _list->insert(element);
    this->_cstatNumberInQueue->getStatistics()->getCollector()->addValue(_list->size());
}

void Queue::removeElement(Waiting* element, double tnow) {
    _list->remove(element);
    this->_cstatNumberInQueue->getStatistics()->getCollector()->addValue(_list->size());
    double timeInQueue = tnow - element->getTimeStartedWaiting();
    this->_cstatTimeInQueue->getStatistics()->getCollector()->addValue(timeInQueue);
}

unsigned int Queue::size() {
    return _list->size();
}

Waiting* Queue::first() {
    return _list->first();
}

void Queue::setAttributeName(std::string _attributeName) {
    this->_attributeName = _attributeName;
}

std::string Queue::getAttributeName() const {
    return _attributeName;
}

void Queue::setOrderRule(OrderRule _orderRule) {
    this->_orderRule = _orderRule;
}

Queue::OrderRule Queue::getOrderRule() const {
    return _orderRule;
}



//List<Waiting*>* Queue::getList() const {
//	return _list;
//}

void Queue::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Queue::_saveInstance() {
    std::list<std::string>* words = ModelElement::_saveInstance(Util::TypeOf<Queue>());
    return words;
}

bool Queue::_check(std::string* errorMessage) {
    return _elems->checkElement(Util::TypeOf<Attribute>(), _attributeName, "AttributeName", false, errorMessage);
}