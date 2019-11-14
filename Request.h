/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Request.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:17
 */

#ifndef REQUEST_H
#define REQUEST_H

#include "ModelComponent.h"

/*!
Request module
DESCRIPTION
The Request module assigns a transporter unit to an entity and moves the unit to the
entity’s station location. A specific transporter unit may be specified or the selection
may occur based on a rule.
When the entity arrives at the Request module, it is allocated a transporter when one
is available. The entity remains at the Request module until the transporter unit has
reached the entity’s station. The entity then moves out of the Request module.
TYPICAL USES
 A sanded part requests a cart to take it to the paint shop
 Customers in a restaurant are ready to order and thus request a waiter
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Transporter Name Name of the transporter to allocate.
Selection Rule Rule for determining which of the transporters to allocate to the
entity, either Cyclical, Random, Preferred Order, Specific
Member, Largest Distance, or Smallest Distance.
Save Attribute Denotes the attribute name that will store the unit number of the
selected transporter.
Unit Number Determines the specific transporter unit in the transporter set to
request.
Priority Priority value of the entity waiting at this module for the
transporter specified if one or more entities are waiting for the
same transporter anywhere in the model.
Entity Location The location to which the transporter will move after being
allocated. For free-path transporters, the entity location must be
specified as a station. For guided transporters, the entity location
may be specified as a station, intersection, or network link.
Velocity Speed at which the transporter is moved to the entity location in
length units per unit time. The unit time is specified in the Units
field.
Units Velocity time units.
 */
class Request : public ModelComponent {
public: // constructors
    Request(Model* model, std::string name="");
    virtual ~Request() = default;
public:  // virtual
    virtual std::string show();
public:  // static
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected:  // virtual
    virtual void _execute(Entity* entity);
    virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private: // methods
private: // attributes 1:1
private: // attributes 1:n
};


#endif /* REQUEST_H */

