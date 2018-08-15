/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Create.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 20:12
 */

#include "Create.h"
#include "Model.h"

Create::Create(Model* model):SourceModelComponent(model) {
	_name = "Create "+Util::_S_generateNewIdOfType("Create");
}

Create::Create(const Create& orig):SourceModelComponent(orig) {
}

Create::~Create() {
}

std::string Create::show() {
	return SourceModelComponent::show();
}

void Create::_execute(Entity* entity) {
	/* 
	std::map<std::string, AttributeValue*>::iterator it = entity->getAttributeValues()->find('Entity.ArrivalTime');
	if (it != entity->getAttributeValues()::end()) {
		(*it)->second->setValue(this->_model->getSimulationTime());
	}
	*/
	double tnow = _model->getSimulationTime();
	entity->getAttributeValues()->find("Entity.ArrivalTime")->second->setValue(tnow);
	double timeBetweenCreations, timeScale, newArrivalTime;
	for (unsigned int i=0; i<this->_entitiesPerCreation; i++) {
		this->_entitiesCreatedSoFar++;
		Entity* newEntity = new Entity();
		_model->getEntities()->insert(newEntity);
		timeBetweenCreations = _model->parseExpression(this->_timeBetweenCreationsExpression);
		timeScale = Util::_S_timeUnitConvert(this->_timeBetweenCreationsTimeUnit, _model->getReplicationLengthTimeUnit());
		newArrivalTime = tnow + timeBetweenCreations*timeScale;
		Event* newEvent = new Event(newArrivalTime, newEntity, this);
		_model->getEvents()->insert(newEvent);
		_model->traceSimulation(Util::TraceLevel::TL_blockInternal, tnow, entity, this, "Arrival of entity "+std::to_string(entity->getId()) + " schedule for time " +std::to_string(newArrivalTime));
		//_model->trace(Util::TraceLevel::TL_blockInternal, "Arrival of entity "+std::to_string(entity->getId()) + " schedule for time " +std::to_string(newArrivalTime));
	}
	_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}
