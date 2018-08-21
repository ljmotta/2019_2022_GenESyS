/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinkModelComponent.cpp
 * Author: cancian
 * 
 * Created on 14 de Agosto de 2018, 14:29
 */

#include "SinkModelComponent.h"

SinkModelComponent::SinkModelComponent(Model* model, std::string thistypename) : ModelComponent(model, thistypename) {
}

SinkModelComponent::SinkModelComponent(const SinkModelComponent& orig) : ModelComponent(orig) {
}

SinkModelComponent::~SinkModelComponent() {
}

void SinkModelComponent::setCollectStatistics(bool _collectStatistics) {
	this->_collectStatistics = _collectStatistics;
}

bool SinkModelComponent::isCollectStatistics() const {
	return _collectStatistics;
}

