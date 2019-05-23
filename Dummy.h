/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dummy.h
 * Author: rlcancian
 *
 * Created on 22 de Maio de 2019, 18:41
 */

#ifndef DUMMY_H
#define DUMMY_H

#include "ModelComponent.h"

class Dummy : public ModelComponent {
public:
    Dummy(Model* model);
    Dummy(const Dummy& orig);
    virtual ~Dummy();
public:
    virtual std::string show();
protected:
    virtual void _execute(Entity* entity);
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:

};

#endif /* DUMMY_H */

