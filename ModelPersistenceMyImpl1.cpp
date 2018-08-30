/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistence.cpp
 * Author: cancian
 * 
 * Created on 24 de Agosto de 2018, 19:22
 */

#include <iostream>

#include "ModelPersistenceMyImpl1.h"
#include "ModelComponent.h"

ModelPersistenceMyImpl1::ModelPersistenceMyImpl1(Model* model) {
	_model = model;
}

ModelPersistenceMyImpl1::ModelPersistenceMyImpl1(const ModelPersistenceMyImpl1& orig) {
}

ModelPersistenceMyImpl1::~ModelPersistenceMyImpl1() {
}

bool ModelPersistenceMyImpl1::saveAsTXT(std::string filename) {
}

bool ModelPersistenceMyImpl1::loadAsTXT(std::string filename) {
	bool res = true;
	std::list<std::string>* words;
	List<ModelComponent*>* components = this->_model->getComponents();
	for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
		words = (*it)->WriteComponent((*it));
		_saveLine(words);
	}
}

bool ModelPersistenceMyImpl1::saveAsXML(std::string filename) {
}

bool ModelPersistenceMyImpl1::loadAsXML(std::string filename) {
}

void ModelPersistenceMyImpl1::_saveLine(std::list<std::string>* words) {
	std::string line = "";
	for (std::list<std::string>::iterator it = words->begin(); it != words->end(); it++) {
		line += (*it) + " ; ";
	}
	_model->trace(Util::TL_mostDetailed, line);
}

bool ModelPersistenceMyImpl1::save(std::string filename) {
	return this->saveAsTXT(filename);
}

bool ModelPersistenceMyImpl1::load(std::string filename) {
	return this->loadAsTXT(filename);
}