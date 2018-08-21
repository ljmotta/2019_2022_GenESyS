/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinkModelComponent.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 14:29
 */

#ifndef SINKMODELCOMPONENT_H
#define SINKMODELCOMPONENT_H

#include "ModelComponent.h"

class SinkModelComponent : public ModelComponent {
public:
	SinkModelComponent(Model* model, std::string thistypename);
	SinkModelComponent(const SinkModelComponent& orig);
	virtual ~SinkModelComponent();
public:
	void setCollectStatistics(bool _collectStatistics);
	bool isCollectStatistics() const;
public:

private:
	bool _collectStatistics = true;
};

#endif /* SINKMODELCOMPONENT_H */

