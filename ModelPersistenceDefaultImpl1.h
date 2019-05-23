/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistenceDefaultImpl1.h
 * Author: rlcancian
 *
 * Created on 20 de Maio de 2019, 20:41
 */

#ifndef MODELPERSISTENCEDEFAULTIMPL1_H
#define MODELPERSISTENCEDEFAULTIMPL1_H

#include "ModelPersistence_if.h"
#include "Model.h"

class ModelPersistenceDefaultImpl1 : public ModelPersistence_if{
public:
    ModelPersistenceDefaultImpl1(Model* model);
    ModelPersistenceDefaultImpl1(const ModelPersistenceDefaultImpl1& orig);
    virtual ~ModelPersistenceDefaultImpl1();
public:
    virtual bool saveAsTXT(std::string filename);
    virtual bool loadAsTXT(std::string filename);
    virtual bool saveAsXML(std::string filename);
    virtual bool loadAsXML(std::string filename);
    virtual bool save(std::string filename);
    virtual bool load(std::string filename);
    virtual bool isSaved();
private:
    void _saveLine(std::list<std::string>* words, std::string filename);
private:
    Model* _model = nullptr;
    bool _isSaved = false;
};

#endif /* MODELPERSISTENCEDEFAULTIMPL1_H */

