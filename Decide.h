/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decide.h
 * Author: rafael.luiz.cancian
 *
 * Created on 9 de Maio de 2019, 20:39
 */

#ifndef DECIDE_H
#define DECIDE_H

#include "ModelComponent.h"

class Decide : public ModelComponent {
public:
    Decide(Model* model);
    Decide(const Decide& orig);
    virtual ~Decide();
public:
    List<std::string>* getConditions() const;

public:
    virtual std::string show();
protected:
    virtual void _execute(Entity* entity);
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _verifySymbols(std::string* errorMessage);
private:
    List<std::string>* _conditions = new List<std::string>();
private:

};

#endif /* DECIDE_H */

