/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 17:12
 */

#include "Queue.h"
#include "Model.h"

Queue::Queue(Model* model) : ModelInfrastructure(Util::TypeOf<Queue>()) {
	_model = model;
	_cstatNumberInQueue = new StatisticsCollector("Number In Queue", this); /* TODO: ++ WHY THIS INSERT "DISPOSE" AND "10ENTITYTYPE" STATCOLL ?? */
	_cstatTimeInQueue = new StatisticsCollector("Time In Queue", this);
	_model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatNumberInQueue);
	_model->getInfraManager()->insertInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatTimeInQueue);
}

Queue::Queue(const Queue& orig) : ModelInfrastructure(orig) {
}

Queue::~Queue() {
	_model->getInfraManager()->removeInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatNumberInQueue);
	_model->getInfraManager()->removeInfrastructure(Util::TypeOf<StatisticsCollector>(), _cstatTimeInQueue);
	//_cstatNumberInQueue->~StatisticsCollector();
	//_cstatTimeInQueue->~StatisticsCollector();
}

std::string Queue::show() {
	return ModelInfrastructure::show() +
			",waiting=" + this->_list->show();
}

void Queue::insertElement(Waiting* element) {
	_list->insert(element);
	this->_cstatNumberInQueue->getCollector()->addValue(_list->size());
}

void Queue::removeElement(Waiting* element, double tnow) {
	_list->remove(element);
	this->_cstatNumberInQueue->getCollector()->addValue(_list->size());
	double timeInQueue = tnow - element->getTimeStartedWaiting();
	this->_cstatTimeInQueue->getCollector()->addValue(timeInQueue);
}

unsigned int Queue::size() {
	return _list->size();
}

Waiting* Queue::first() {
	return _list->first();
}



//List<Waiting*>* Queue::getList() const {
//	return _list;
//}

void Queue::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Queue::_saveInstance() {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance(Util::TypeOf<Queue>());
	return words;
}

bool Queue::_verifySymbols(std::string* errorMessage) {
	return true;
}