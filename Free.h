/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Free.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:16
 */

#ifndef FREE_H
#define FREE_H

#include "ModelComponent.h"

/*!
Free module
DESCRIPTION
The Free module releases the entity’s most recently allocated transporter unit. If
another entity is waiting in a queue to request or allocate the transporter, the
transporter will be given to that entity. If there are no waiting entities at the time the
transporter unit is freed, the transporter will wait idle at the freeing entity’s station
location, unless otherwise specified in the Transporter module.
TYPICAL USES
 A part awaiting a shipping truck frees its forklift
 An airport transfer cart completes its trip
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Transporter Name Name of the transporter to free. A blank value assumes the most
recently allocated or requested transporter.
Unit Number Determines which of the transporter units in the transporter set to
free.
 */
class Free : public ModelComponent {
public: // constructors
	Free(Model* model, std::string name = "");
	virtual ~Free() = default;
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


#endif /* FREE_H */

