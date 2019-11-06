/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelManager.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 31 de Maio de 2019, 08:37
 */

#include "ModelManager.h"
#include "List.h"

ModelManager::ModelManager(Simulator* simulator) {
    _simulator = simulator;
    _currentModel = nullptr;
}


void ModelManager::insert(Model* model) {
    _models->insert(model);
    this->_currentModel = model;
}

void ModelManager::remove(Model* model) {
    _models->remove(model);
    if (_currentModel == model) {
	_currentModel = nullptr;
    }
    model->~Model();
}

unsigned int ModelManager::size(){
    return _models->size();
}

bool ModelManager::saveModel(std::string filename) {
    if (_currentModel != nullptr)
	return _currentModel->save(filename);
    return false;
}

bool ModelManager::loadModel(std::string filename) {
    Model* model = new Model(_simulator);
    bool res = model->load(filename);
    if (res) 
	this->insert(model);
    else
	model->~Model();
    return res;
}

void ModelManager::setCurrent(Model* model) {
    this->_currentModel = model;
}

Model* ModelManager::current() {
    return _currentModel;
}

Model* ModelManager::front() {
    return _models->front();
}

Model* ModelManager::next() {
    return _models->next();
}

Model* ModelManager::end() {
    return _models->last();
}
