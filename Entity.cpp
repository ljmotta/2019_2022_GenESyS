/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 16:30
 */

#include "Entity.h"

Entity::Entity() {
	_attributeValues = new std::map<std::string, AttributeValue*>();
}

Entity::Entity(const Entity& orig) {
}

Entity::~Entity() {
}

