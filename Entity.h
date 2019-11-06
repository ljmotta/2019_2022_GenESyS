/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 16:30
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <map>

#include "Util.h"
#include "List.h"
#include "ModelElement.h"
#include "EntityType.h"

class Entity : public ModelElement {
public:
    Entity(Model* model);
    //Entity(const Entity &orig);
    virtual ~Entity() = default;
public:
    virtual std::string show();

public: // g & s
    void setEntityTypeName(std::string entityTypeName) throw(); // indirect access to EntityType
    std::string entityTypeName() const;
    void setEntityType(EntityType* entityType); // direct access to EntityType
    EntityType* entityType() const;
public:
    double attributeValue(std::string attributeName);
    double attributeValue(std::string index, std::string attributeName);
    double attributeValue(Util::identification attributeID);
    double attributeValue(std::string index, Util::identification attributeID);
    void setAttributeValue(std::string attributeName, double value);
    void setAttributeValue(std::string index, std::string attributeName, double value);
    void setAttributeValue(Util::identification attributeID, double value);
    void setAttributeValue(std::string index, Util::identification attributeID, double value);
    Util::identification entityNumber() const;
protected:
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private: 
    Util::identification _entityNumber;
    EntityType* _entityType = nullptr;
    List< std::map<std::string,double>* >* _attributeValues = new List<std::map<std::string,double>*>();
};

#endif /* ENTITY_H */

