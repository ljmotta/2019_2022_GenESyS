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
#include <typeinfo>

Create::Create(Model* model) : SourceModelComponent(model) {
	_name = "Create " + std::to_string(Util::GenerateNewIdOfType<Create>()); 
}

Create::Create(const Create& orig) : SourceModelComponent(orig) {
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
	double tnow = _model->getSimulatedTime();
	entity->getAttributeValues()->find("Entity.ArrivalTime")->second->setValue(tnow);
	double timeBetweenCreations, timeScale, newArrivalTime;
	for (unsigned int i = 0; i<this->_entitiesPerCreation; i++) {
		this->_entitiesCreatedSoFar++;
		Entity* newEntity = new Entity();
		_model->getEntities()->insert(newEntity);
		timeBetweenCreations = _model->parseExpression(this->_timeBetweenCreationsExpression);
		timeScale = Util::TimeUnitConvert(this->_timeBetweenCreationsTimeUnit, _model->getReplicationLengthTimeUnit());
		newArrivalTime = tnow + timeBetweenCreations*timeScale;
		Event* newEvent = new Event(newArrivalTime, newEntity, this);
		_model->getEvents()->insert(newEvent);
		_model->traceSimulation(Util::TraceLevel::TL_blockInternal, tnow, entity, this, "Arrival of entity " + std::to_string(newEntity->getId()) + " schedule for time " + std::to_string(newArrivalTime));
		//_model->trace(Util::TraceLevel::TL_blockInternal, "Arrival of entity "+std::to_string(entity->getId()) + " schedule for time " +std::to_string(newArrivalTime));
	}
	_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Create::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* Create::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	words->insert(words->end(), Util::TypeOf<Create>());
	words->insert(words->end(), std::to_string(this->_collectStatistics));
	words->insert(words->end(), std::to_string(this->_entitiesPerCreation));
	words->insert(words->end(), (this->_entityType));
	words->insert(words->end(), std::to_string(this->_firstCreation));
	words->insert(words->end(), std::to_string(this->_maxCreations));
	words->insert(words->end(), (this->_timeBetweenCreationsExpression));
	words->insert(words->end(), std::to_string(this->_timeBetweenCreationsTimeUnit));
	return words;
}

bool Create::_verifySymbols(std::string* errorMessage) {
	//Genesys.AuxFunctions.VerifySymbol(thismodule.Name, 'Time Between Creations', thisModule.aTimeBetweenCreations, cEXPRESSION, true);
	bool res = _model->verifySymbol(this->_name, "Time Between Creations", this->_timeBetweenCreationsExpression, "EXPRESSION", true); // Todo: typeid(Expression)
	return res;
}
