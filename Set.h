/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Set.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:11
 */

#ifndef SET_H
#define SET_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "ParserChangesInformation.h"
#include "PluginInformation.h"

class Set: public ModelElement {
public:
    Set(ElementManager* elems);
    Set(ElementManager* elems, std::string name);
    Set(const Set& orig);
    virtual ~Set();
public: // static
    static ModelElement* LoadInstance(ElementManager* elems, std::map<std::string, std::string>* fields); 
    static PluginInformation* GetPluginInformation();
public:
    virtual std::string show();
public:
    void setSetOfType(std::string _setOfType);
    std::string getSetOfType() const;
    List<ModelElement*>* getElementSet() const;

protected: // must be overriden by derived classes
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
protected: // could be overriden by derived classes
    virtual bool _check(std::string* errorMessage);
    virtual ParserChangesInformation* _getParserChangesInformation();
private:
    ElementManager* _elems;
    List<ModelElement*>* _elementSet = new List<ModelElement*>();
    std::string _setOfType;
};

#endif /* SET_H */

