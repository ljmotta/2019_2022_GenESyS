/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 19:49
 */

#ifndef DELAY_H
#define DELAY_H

#include <string>
#include "ModelComponent.h"

class Delay : public ModelComponent {
public:
    Delay(Model* model);
    Delay(const Delay& orig);
    virtual ~Delay();
    public:
    void setDelayExpression(std::string _delayExpression);
    std::string getDelayExpression() const;
    void setDelayTimeUnit(Util::TimeUnit _delayTimeUnit);
    Util::TimeUnit getDelayTimeUnit() const;
public:
    virtual std::string show();
protected:
    virtual void _execute(Entity* entity);
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    std::string _delayExpression = "1.0";
    Util::TimeUnit _delayTimeUnit = Util::TimeUnit::second;
};

#endif /* DELAY_H */

