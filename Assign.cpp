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

#include "Assign.h"
#include "Attribute.h" // to avoid compile error: invalid use of incomplete type ‘class Model’
#include <iostream>

Assign::Assign(Model* model) : ModelComponent(model) {
	_name = "Assign " + std::to_string(Util::GenerateNewIdOfType<Assign>());
        _model = model;
}

Assign::Assign(const Assign& orig) : ModelComponent(orig) {
}

Assign::~Assign() {
}

std::string Assign::show() {
	return ModelComponent::show()+
			"";
}

List<Assign::Assignment*>* Assign::getAssignments() const {
	return _assignments;
}


void Assign::_execute(Entity* entity) {
	/* TODO +: implement */
	this->_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
}

void Assign::_loadInstance(std::list<std::string> words) {
}

std::list<std::string>* Assign::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool Assign::_verifySymbols(std::string* errorMessage) {
    try
    {
        for (Assignment* it = this->getAssignments()->first(); it!=this->getAssignments()->last(); it++) {
            this->_model->parseExpression(it->getExpression());
            /*NOT ABLE TO DO: 
             * bool temp;
            * this->_model->parseExpression(it->getExpression(), &temp, errorMessage);  */
            
            
            /*Checking Destination*/
            if(it->getDestinationType() == DestinationType::Attribute){
                
                //Attribute* attributeBeenChecked = new Attribute();
                //attributeBeenChecked = (Attribute*) _model->getInfrastructure(Util::TypeOf<Attribute>(), it->getDestination());
                /*if ((Attribute*) _model->getInfrastructure(Util::TypeOf<Attribute>(), it->getDestination()) == nullptr) { // there is no Attribute with the  name
                    Attribute* newAttribute = new Attribute();
                    newAttribute->setName(it->getDestination());
                    _model->getInfrastructures(Util::TypeOf<Attribute>())->insert(newAttribute);
                }*/
                
            }else{ //(it->getDestinationType() == DestinationType.Variable)
                /*if (_model->getInfrastructure(Util::TypeOf<Variable>(), it->getDestination()) == nullptr) { // there is no Variable with the  name
                    Variable* newVariable = new Variable();
                    newVariable->setName(it->getDestination());
                    _model->getInfrastructures(Util::TypeOf<Variable>())->insert(newVariable);
                }*/
            }
            
        }
        
        return true;
    }
    catch (int e)
    {
        *errorMessage = e;
        return false;
    }
}