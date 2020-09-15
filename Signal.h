/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Signal.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:20
 */

#ifndef SIGNAL_H
#define SIGNAL_H

#include "ModelComponent.h"

/*!
Signal module
DESCRIPTION
The Signal module sends a signal value to each Hold module in the model set to Wait
for Signal and releases the maximum specified number of entities.
When an entity arrives at a Signal module, the signal is evaluated and the signal code
is sent. At this time, entities at Hold modules that are waiting for the same signal are
removed from their queues. The entity sending the signal continues processing until it
encounters a delay, enters a queue, or is disposed.
TYPICAL USES
 Analyzing traffic patterns at an intersection (signal when the light turns green)
 Signaling an operator to complete an order that was waiting for a component part
PROMPTS
Prompt Description
Name Unique module identifier displayed on the module shape.
Signal Value Value of the signal to be sent to entities in Hold modules.
Limit Maximum number of entities that are to be released from any
Hold modules when the signal is received.
 */
class Signal : public ModelComponent {
public: // constructors
	Signal(Model* model, std::string name = "");
	virtual ~Signal() = default;
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


#endif /* SIGNAL_H */

