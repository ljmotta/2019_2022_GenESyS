/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hold.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:20
 */

#ifndef HOLD_H
#define HOLD_H

#include "ModelComponent.h"

/*!
Hold module
DESCRIPTION
This module will hold an entity in a queue to wait for a signal, wait for a specified
condition to become true (scan), or be held infinitely (to be removed later with the
Remove module).
If the entity is holding for a signal, the Signal module is used elsewhere in the model
to allow the entity to move on to the next module. If the entity is holding for a given
condition to be true, the entity will remain at the module (either in a defined or
internal queue) until the condition(s) becomes true. When the entity is in an infinite 
hold, the Remove module is used elsewhere in the model to allow the entity to
continue processing.
TYPICAL USES
 Waiting for a traffic light to turn green
 Holding a part for authorization
 Checking the status of a machine or operator to continue a process
PROMPTS
Prompt Description
Name Unique module identifier displayed on the module shape.
Type Indicates the reasoning for holding the entity within a specified
or internal queue. Wait for Signal will hold the entity until a
signal of the same value is received. Scan for Condition will hold
the entity until the specified condition becomes true. Infinite
Hold will hold the entity until it is removed from the queue by a
Remove module.
Wait for Value Signal code for the waiting entity. Applies only when Type is
Wait for Signal.
Limit Maximum number of waiting entities that will be released upon
receipt of a signal. Applies only when Type is Wait for Signal.
Condition Specifies the condition that will be evaluated to hold the entity at
the module. If the condition is evaluated to true, the entity leaves
the module immediately. If the condition is false, the entity will
wait in the associated queue until the condition becomes true.
Applies only when Type is Scan for Condition.
Queue Type Determines the type of queue used to hold the entities. If Queue
is selected, the queue name is specified. If Set is selected, the
queue set and member in the set are specified. If Internal is
selected, an internal queue is used to hold all waiting entities.
Attribute and Expression are additional methods for defining the
queue to be used.
Queue Name This field is visible only if Queue Type is Queue, and it defines
the symbol name of the queue.
Set Name This field is visible only if Queue Type is Set, and it defines the
queue set that contains the queue being referenced.
Set Index This field is visible only if Queue Type is Set, and it defines the
index into the queue set. Note that this is the index into the set
and not the name of the queue in the set. For example, the only
valid entry for a queue set containing three members is an
expression that evaluates to 1, 2, or 3.
Attribute This field is visible only if Queue Type is Attribute. The attribute
entered in this field will be evaluated to indicate which queue is
to be used.
Expression This field is visible only if Queue Type is Expression. The
expression entered in this field will be evaluated to indicate
which queue is to be used.
 */
class Hold : public ModelComponent {
public: // constructors
    Hold(Model* model, std::string name="");
    virtual ~Hold() = default;
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


#endif /* HOLD_H */

