/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinkModelComponent.h
 * Author: rafael.luiz.cancian
 *
 * Created on 14 de Agosto de 2018, 14:29
 */

#ifndef SINKMODELCOMPONENT_H
#define SINKMODELCOMPONENT_H

#include "ModelComponent.h"

/*!
 * This class is the basis for any component representing the end of a process flow, such as a Dispose. 
 * It can remove entities from the system and collect statistics.
 */
class SinkModelComponent : public ModelComponent {
public:
    SinkModelComponent(Model* model, std::string componentTypename);
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

