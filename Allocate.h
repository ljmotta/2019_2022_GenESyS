/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alocate.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:16
 */

#ifndef ALLOCATE_H
#define ALLOCATE_H

#include "ModelComponent.h"

/*!
 Allocate module
DESCRIPTION
The Allocate module assigns a transporter to an entity without moving it to the
entity’s station location. The entity then has control of the transporter to either move
it to a particular location or to halt it for a breakdown or failure. A particular
transporter unit may be allocated to the entity or a selection rule may be used to
determine which of the transporters will be assigned to the entity.
TYPICAL USES
 A mechanic allocates a forklift for scheduled maintenance
 Allocate a taxi to pick up waiting passengers
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Transporter Name Name of the transporter to allocate.
Selection Rule Rule for determining which of the transporters to allocate to the
entity. The selection rule has the following options: Cyclical,
Random, Preferred Order, Specific Member, Largest
Distance, and Smallest Distance.
Save Attribute The attribute name that will store the unit number of the selected
transporter.
Unit Number Determines the specific transporter in the transporter set to
allocate to the entity. It is only visible if selection rule is Specific
Member.
Priority Priority value of the entity waiting at this module for the
transporter specified if one or more entities are waiting for the
same transporter anywhere in the model.
Entity Location This field is used to determine the transporter closest to or
farthest from the requesting entity when using the Largest
Distance or Smallest Distance transporter selection rules. For
free-path transporters, the entity location must be specified as a
station. For guided transporters, the entity location may be
specified as a station, intersection, or network link.
Queue Type Type of queue used to hold the entities while waiting to allocate
the transporter, either an individual Queue, a queue Set, an
Internal queue, or an Attribute or Expression that evaluate to
the queue name.
Queue Name Name of the individual queue.
Queue Set Name Name of the queue set that contains the queue being referenced.
Set Index The index into the queue set. Note that this is the index into the
set and not the name of the queue in the set. For example, the
only valid entries for a queue set containing three members is an
expression that evaluates to 1, 2, or 3.
Attribute Name The attribute name that will be evaluated to the queue name.
Expression The expression that will be evaluated to the queue name
 */
class Allocate : public ModelComponent {
public: // constructors
    Allocate(Model* model, std::string name="");
    virtual ~Allocate() = default;
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


#endif /* ALLOCATE_H */

