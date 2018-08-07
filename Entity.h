/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 16:30
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "Util.h"
#include "ModelInfrastructure.h"
#include <string>
#include <map>
#include "AttributeValue.h"

class Entity: public ModelInfrastructure {
public:
	Entity();
	Entity(const Entity& orig);
	virtual ~Entity();
private:
	std::map<std::string, AttributeValue*>* _attributeValues;
};

#endif /* ENTITY_H */

