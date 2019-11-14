/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Halt.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:17
 */

#ifndef HALT_H
#define HALT_H

#include "ModelComponent.h"

/*!
Halt module
DESCRIPTION
The Halt module changes the status of a transporter unit to inactive. If the transporter
is busy at the time when an entity enters the Halt module, the status is considered
busy and inactive until the entity that controls the transporter frees the unit. If the
transporter is idle at the time when an entity halts the transporter, it is set to inactive
immediately. Once a transporter unit has been halted, no entities will get control of
the transporter until it is activated.
TYPICAL USES
 Stop a forklift for scheduled maintenance
 Disable a broken gurney in an emergency room
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Transporter Name Name of the transporter to halt.
Unit Number Determines which of the transporter units in the transporter set to
halt.
 */
class Halt : public ModelComponent {
public: // constructors
    Halt(Model* model, std::string name="");
    virtual ~Halt() = default;
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


#endif /* HALT_H */

