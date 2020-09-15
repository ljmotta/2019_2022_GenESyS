/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Access.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:14
 */

#ifndef ACCESS_H
#define ACCESS_H

#include "ModelComponent.h"

/*!
Access module
DESCRIPTION
The Access module allocates one or more cells of a conveyor to an entity for
movement from one station to another. Once the entity has control of the cells on the
conveyor, it may then be conveyed to the next station.
When an entity arrives at an Access module, it will wait until the appropriate number
of contiguous cells on the conveyor are empty and aligned with the entity’s station
location.
TYPICAL USES
 Parts accessing a conveyor to be sent to a paint booth
 Glass accessing a conveyor to be transferred to a cutting station
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Conveyor Name Name of the conveyor that the entity desires.
# of Cells Number of contiguous conveyor cells the entity requires for
movement on the conveyor.
Queue Type Determines the type of queue used to hold the entities, either an
individual Queue, a queue Set, and Internal queue or an
Attribute or Expression that evaluate to the queue name.
Queue Name Name of the queue that will hold the entity until it accesses the
conveyor.
Set Name Name of the set of queues. 
Set Index Defines the index into the queue set. Note that this is the index
into the set and not the name of the queue in the set. For
example, the only valid entries for a queue set containing three
members is an expression that evaluates to 1, 2, or 3.
Attribute Name Defines the name of the attribute that stores the queue name to
which entities will reside.
Expression Defines the name of the expression that stores the queue name to
which entities will reside.
 */
class Access : public ModelComponent {
public: // constructors
	Access(Model* model, std::string name = "");
	virtual ~Access() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected: // virtual
	virtual void _execute(Entity* entity);
	virtual void _initBetweenReplications();
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private: // methods
private: // attributes 1:1
private: // attributes 1:n
};


#endif /* ACCESS_H */

