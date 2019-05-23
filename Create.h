/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Create.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 20:12
 */

#ifndef CREATE_H
#define CREATE_H

#include <string>
#include <limits>
#include "SourceModelComponent.h"
#include "EntityType.h"

/*!
 * Create is the most basic component to include the first entities into the model, and therefore is a source component (derived from SourceModelComponent)
 */
class Create : public SourceModelComponent {
public:
    Create(Model* model);
    Create(const Create& orig);
    virtual ~Create();
public:
    virtual std::string show();
protected:
    virtual void _execute(Entity* entity);
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    EntityType* _entityType;
};

#endif /* CREATE_H */
