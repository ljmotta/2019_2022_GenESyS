/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Batch.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:14
 */

#ifndef BATCH_H
#define BATCH_H

#include "ModelComponent.h"

/*!
Batch module
DESCRIPTION
This module is intended as the grouping mechanism within the simulation model.
Batches can be permanently or temporarily grouped. Temporary batches must later be
split using the Separate module.
Batches may be made with any specified number of entering entities or may be
matched together based on an attribute. Entities arriving at the Batch module are
placed in a queue until the required number of entities has accumulated. Once
accumulated, a new representative entity is created.
TYPICAL USES
 Collect a number of parts before starting processing
 Reassemble previously separated copies of a form
 Bring together a patient and his record before commencing an appointment
PROMPTS
Prompt Description
Name Unique module identifier displayed on the module shape.
Type Method of batching entities together.
Batch Size Number of entities to be batched.
Save Criterion Method for assigning representative entity’s user-defined
attribute values.
Rule Determines how incoming entities will be batched. Any Entity
will take the first “Batch Size” number of entities and put them
together. By Attribute signifies that the values of the specified
attribute must match for entities to be grouped. For example, if
Attribute Name is Color, all entities must have the same Color
value to be grouped; otherwise, they will wait at the module for
additional incoming entities.
Attribute Name Name of the attribute whose value must match the value of the
other incoming entities in order for a group to be made. Applies
only when Rule is By Attribute.
Representative Entity The entity type for the representative entity. 

 */
class Batch : public ModelComponent {
public: // constructors
    Batch(Model* model, std::string name="");
    virtual ~Batch() = default;
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


#endif /* BATCH_H */

