/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LSODE.h
 * Author: rlcancian
 *
 * Created on 22 de Outubro de 2019, 22:28
 */

#ifndef LSODE_H
#define LSODE_H

#include "ModelComponent.h"
#include "Formula.h"

/*!
 This component ...
 */
class LSODE : public ModelComponent {
public: // constructors
    LSODE(Model* model);
    virtual ~LSODE() = default;
public: // virtual
    virtual std::string show();
public: // static
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public: // g&s
    void setFormula(Formula* formula);
    Formula* getFormula() const;
protected: // virtual
    virtual void _execute(Entity* entity);
    virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
    //virtual void _createInternalElements();
private: // methods
private: // attributes 1:1
    Formula* _formula;
private: // attributes 1:n
};

#endif /* LSODE_H */

