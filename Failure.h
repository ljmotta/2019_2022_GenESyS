/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Failure.h
 * Author: rlcancian
 *
 * Created on 20 de Failureembro de 2019, 20:07
 */

#ifndef FAILURE_H
#define FAILURE_H


#include "ModelElement.h"
#include "ElementManager.h"
#include "ParserChangesInformation.h"
#include "PluginInformation.h"

class Failure: public ModelElement {
public:
    Failure(Model* model);
    Failure(Model* model, std::string name);
    virtual ~Failure() = default;
public: // static
    static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields); 
    static PluginInformation* GetPluginInformation();
public:
    virtual std::string show();

protected: // must be overriden by derived classes
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
protected: // could be overriden by derived classes
    virtual bool _check(std::string* errorMessage);
    virtual ParserChangesInformation* _getParserChangesInformation();
//private:
//    ElementManager* _elems;
};

#endif /* FAILURE_H */

