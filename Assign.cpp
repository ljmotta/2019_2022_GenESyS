/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.cpp
 * Author: cancian
 * 
 * Created on 31 de Agosto de 2018, 10:10
 */

#include <string>
#include "Model.h"
#include "Assign.h"
#include "Variable.h"
#include "Attribute.h"
#include "Resource.h"

Assign::Assign(Model* model) : ModelComponent(model) {
	_name = "Assign " + std::to_string(Util::GenerateNewIdOfType<Assign>());
        _model = model;
}

Assign::Assign(const Assign& orig) : ModelComponent(orig) {
}

Assign::~Assign() {
}

std::string Assign::show() {
	return ModelComponent::show() +
			"";
}

List<Assign::Assignment*>* Assign::getAssignments() const {
	return _assignments;
}

void Assign::_execute(Entity* entity) {
	/* TODO +: implement */
	Assignment* let;
	std::list<Assignment*>* lets = this->_assignments->getList();
	for (std::list<Assignment*>::iterator it = lets->begin(); it != lets->end(); it++) {
		let = (*it);
		double value = _model->parseExpression(let->getExpression());
		_model->trace(Util::TraceLevel::TL_blockInternal, "Let \"" + let->getDestination() + "\" = " + std::to_string(value));
		/* TODO: this is NOT the best way to do it (enum comparision) */
		if (let->getDestinationType() == DestinationType::Variable) {
			::Variable* myvar = (::Variable*) this->_model->getInfrastructure(Util::TypeOf<::Variable>(), let->getDestination());
			myvar->setValue(value);
		} else if (let->getDestinationType() == DestinationType::Attribute) {
			entity->setAttributeValue(let->getDestination(), value);
		}
	}

	this->_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Assign::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Assign::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Assign::_verifySymbols(std::string* errorMessage) {
    
    bool result = true;

    for (Assignment* it = this->getAssignments()->first(); it!=this->getAssignments()->last(); it++) {
        bool temp = true;
        this->_model->parseExpression(it->getExpression(), &temp, errorMessage);
        result &= temp;

        /*Checking Destination*/
        if(it->getDestinationType() == DestinationType::Attribute){
            if ((::Attribute*) this->_model->getInfrastructure(Util::TypeOf<::Attribute>(), it->getDestination()) == nullptr) { // there is no Attribute with the  name
                ::Attribute* newAttribute = new  ::Attribute();
                newAttribute->setName(it->getDestination());
                _model->getInfrastructures(Util::TypeOf<::Attribute>())->insert(newAttribute);
            }

        }else{ //(it->getDestinationType() == DestinationType.Variable)
            if ((::Variable*) this->_model->getInfrastructure(Util::TypeOf<::Variable>(), it->getDestination()) == nullptr) { // there is no Variable with the  name
                ::Variable* newVariable = new  ::Variable();
                newVariable->setName(it->getDestination());
                _model->getInfrastructures(Util::TypeOf<::Variable>())->insert(newVariable);
            }
        }

    }

    return result;
}