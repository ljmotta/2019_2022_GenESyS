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
	bool res = true;
	std::list<std::string>* words;
	// save model own infos
	// ...
	
	// save components
	List<ModelComponent*>* components = this->_model->getComponents();
	for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
		words = (*it)->SaveInstance((*it));
		_saveLine(words);
	}
	
	// save infras
	std::list<std::string>* infraTypenames = _model->getInfraManager()->getInfrastructureTypenames();
	for (std::list<std::string>::iterator itTypenames=infraTypenames->begin(); itTypenames!=infraTypenames->end(); itTypenames++) {
		List<ModelInfrastructure*>* infras = _model->getInfraManager()->getInfrastructures((*itTypenames));
		_model->getTracer()->trace(Util::TraceLevel::blockArrival, "Writing infrastructures of type \"" + (*itTypenames) + "\":"); 
		for (std::list<ModelInfrastructure*>::iterator it=infras->getList()->begin(); it!=infras->getList()->end(); it++) {
			_model->getTracer()->trace(Util::TraceLevel::blockArrival, "    Writing infrastructure \"" + (*it)->getName() + "\""); 
			words = (*it)->SaveInstance((*it));
			_saveLine(words);
		}
	}
}

bool ModelPersistenceMyImpl1::loadAsTXT(std::string filename) {

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
	_model->getTracer()->trace(Util::TraceLevel::mostDetailed, line);
}

bool ModelPersistenceMyImpl1::save(std::string filename) {
	return this->saveAsTXT(filename);
}

bool ModelPersistenceMyImpl1::load(std::string filename) {
	return this->loadAsTXT(filename);
}
