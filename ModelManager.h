/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelManager.h
 * Author: rlcancian
 *
 * Created on 31 de Maio de 2019, 08:37
 */

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "Model.h"

class ModelManager {
public:
    ModelManager(Simulator* simulator);
    ModelManager(const ModelManager& orig);
    virtual ~ModelManager();
public:
    void insert(Model* model);
    void remove(Model* model);
    void setCurrent(Model* model);
public:
    Model* front();
    Model* current();
    Model* next();
    Model* end();
private:
    List<Model*>* _models;
    Model* _currentModel;
private:
    Simulator* _simulator;
};

#endif /* MODELMANAGER_H */

