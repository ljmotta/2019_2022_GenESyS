/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedByComponent.cpp
 * Author: cancian
 * 
 * Created on 22 de Agosto de 2018, 07:35
 */

#include "LinkedByComponent.h"

LinkedByComponent::LinkedByComponent() {
}

LinkedByComponent::LinkedByComponent(const LinkedByComponent& orig) {
}

LinkedByComponent::~LinkedByComponent() {
}

void LinkedByComponent::addLink() {
	this->_linkedBy++;
}
	
void LinkedByComponent::removeLink() {
	this->_linkedBy--;
}

bool LinkedByComponent::isLinked() {
	return this->_linkedBy > 0;
}