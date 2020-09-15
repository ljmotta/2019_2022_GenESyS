/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Move.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 13:17
 */

#ifndef MOVE_H
#define MOVE_H

#include "ModelComponent.h"

/*!
Move module
DESCRIPTION
The Move module advances a transporter from one location to another without
moving the controlling entity to the destination station. The controlling entity
remains at its current module location until the transporter arrives at its destination.
At that time, the entity will be able to move to another module or task in the model.
If the transporter being moved is a free-path transporter, then the time delay to move
the transporter from one station to the next is based on the velocity of the transporter
and the distance between the stations (specified in the Distance module). If the
transporter being moved is a guided transporter, then the time delay to move the
transporter depends not only on the velocity and distance to the destination, but also
the transporter’s acceleration, deceleration, and any traffic it encounters on the way
TYPICAL USES
 Move a broken forklift to a service station
 Move a worker to a break room
 Move a waiter to the kitchen
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Transporter Name Name of the transporter to move.
Unit Number Determines which of the transporter units in the transporter set to
move.
Destination Type Determines the method for specifying the transporter destination.
The Intersection and Network Link options apply only to
guided transporters.
Station Name Name of the individual destination station.
Attribute Name Name of the attribute that stores the destination station name to
which entities will route.
Expression Expression that is evaluated to the destination station name
where entities will route.
Intersection Name Defines the name of the intersection to which the guided
transporter will move.
Network Link Name Defines the name of the network link to which the guided
transporter will move.
Zone The specific zone number of the Network Link Name.
Velocity Specifies the temporary velocity at which the transporter is
moved to the destination station.
Units Velocity time units.
 */
class Move : public ModelComponent {
public: // constructors
	Move(Model* model, std::string name = "");
	virtual ~Move() = default;
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


#endif /* MOVE_H */

