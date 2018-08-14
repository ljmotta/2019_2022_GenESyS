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
}

Create::Create(const Create& orig):SourceModelComponent(orig) {
}

Create::~Create() {
}

void Create::_execute(Entity* entity) {
	//this->_model->
}
