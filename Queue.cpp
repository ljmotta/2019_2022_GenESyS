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

Queue::Queue() : ModelInfrastructure(Util::TypeOf<Queue>()) {
}

Queue::Queue(const Queue& orig) : ModelInfrastructure(orig) {
}

Queue::~Queue() {
}

std::string Queue::show() {
	return ModelInfrastructure::show()+
			",waiting="+this->_list->show();
}

//void Queue::insertElement(Waiting* element) {
//	_list->insert(element);
//}

//unsigned int Queue::size() {
//	return _list->size();
//}

List<Waiting*>* Queue::getList() const {
	return _list;
}


