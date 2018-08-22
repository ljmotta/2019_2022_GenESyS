/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Release.cpp
 * Author: cancian
 * 
 * Created on 21 de Agosto de 2018, 16:17
 */

#include "Release.h"
#include "Model.h"

Release::Release(Model* model) : ModelComponent(model) {
	_name = "Release "+std::to_string(Util::_S_generateNewIdOfType(typeid(this).name()));
}

Release::Release(const Release& orig) : ModelComponent(orig) {
}

Release::~Release() {
}

std::string Release::show(){
	return ModelComponent::show()+ ",resourceName="+this->_resourceName+", quantity="+this->_quantity+",...";
}

void Release::_execute(Entity* entity) {
	/* TODO +: not implemented yet */
	_model->sendEntityToComponent(entity, this->getNextComponents()->first(), 0.0);
	
}

