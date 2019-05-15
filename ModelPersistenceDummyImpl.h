/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistence.h
 * Author: rafael.luiz.cancian
 *
 * Created on 24 de Agosto de 2018, 19:22
 */

#ifndef MODELPERSISTENCEDUMMYIMPL_H
#define MODELPERSISTENCEDUMMYIMPL_H

#include "ModelPersistence_if.h"
#include "Model.h"

class ModelPersistenceDummyImpl : public ModelPersistence_if {
public:
    ModelPersistenceDummyImpl(Model* model);
    ModelPersistenceDummyImpl(const ModelPersistenceDummyImpl& orig);
    ~ModelPersistenceDummyImpl();
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

#endif /* MODELPERSISTENCEDUMMYIMPL_H */

