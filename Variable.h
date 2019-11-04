/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.h
 * Author: rafael.luiz.cancian
 *
 * Created on 4 de Setembro de 2018, 18:28
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"


class Variable : public ModelElement {
public:
    Variable(Model* model, std::string name="");
    virtual ~Variable() = default;
public:
    virtual std::string show();
public: //static
    static PluginInformation* GetPluginInformation();
    static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
    double value();
    void setValue(double value);
    double value(std::string index);
    void setValue(std::string index, double value);
    double initialValue();
    void setInitialValue(double value);
    double initialValue(std::string index);
    void setInitialValue(std::string index, double value);
    List<unsigned int>* dimensionSizes() const;

protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
    virtual void _initBetweenReplications();

private:
    List<unsigned int>* _dimensionSizes = new List<unsigned int>();
    std::map<std::string, double>* _values = new std::map<std::string, double>();
    std::map<std::string, double>* _initialValues = new std::map<std::string, double>();
};

#endif /* VARIABLE_H */

