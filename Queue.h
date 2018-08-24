/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: cancian
 *
 * Created on 21 de Agosto de 2018, 17:12
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "ModelInfrastructure.h"
#include "LinkedBy.h"

#include "List.h"
#include "Entity.h"

class Queue: public ModelInfrastructure, public LinkedBy {
public:
	Queue();
	Queue(const Queue& orig);
	virtual ~Queue();
public:
	virtual std::string show();
public: //g&s
private:
	List<Entity*>* _list = new List<Entity*>();
};

#endif /* QUEUE_H */

