/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formula.h
 * Author: rlcancian
 *
 * Created on 20 de Junho de 2019, 00:56
 */

#ifndef FORMULA_H
#define FORMULA_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"
#include "Parser_if.h"

class Formula : public ModelElement {
public:
    Formula(Model* model);
    virtual ~Formula() = default;
public:
    List<std::string>* getFormulaExpressions() const;
    double getValue(unsigned int index = 0) const;
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected: // must be overriden by derived classes
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    //    ElementManager* _elements;
    //Model* _model;
    Parser_if* _myPrivateParser;
private:
    List<std::string>* _formulaExpressions = new List<std::string>();
};

#endif /* FORMULA_H */

