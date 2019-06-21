/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ODE.h
 * Author: rlcancian
 *
 * Created on 13 de Junho de 2019, 19:12
 */

#ifndef ODE_H
#define ODE_H

#include "ModelElement.h"

class ODE : public ModelElement {
public:
    ODE();
    ODE(const ODE& orig);
    virtual ~ODE();
public:
    virtual std::string show();
public:
    void setExpression(std::string expression);
    std::string getExpression() const;
protected: // must be overriden by derived classes
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:

private:
    std::string expression;
};

#endif /* ODE_H */

