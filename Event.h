/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 19:41
 */

#ifndef EVENT_H
#define EVENT_H

#include "ModelInfrastructure.h"
#include "Entity.h"
#include "ModelComponent.h"
#include <string>

class Event {//: public ModelInfrastructure {
public:
	Event(double time, Entity* entity, ModelComponent* component);
	Event(const Event& orig);
	virtual ~Event();
public:
    double getTime() const;
    ModelComponent* getComponent() const;
    Entity* getEntity() const;
	std::string show();
private:
	double _time;
	Entity* _entity;
	ModelComponent* _component;
};

#endif /* EVENT_H */

