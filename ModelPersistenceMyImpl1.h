/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistence.h
 * Author: cancian
 *
 * Created on 24 de Agosto de 2018, 19:22
 */

#ifndef MODELPERSISTENCEMYIMPL1_H
#define MODELPERSISTENCEMYIMPL1_H

#include "ModelPersistence_if.h"
#include "Model.h"

class ModelPersistenceMyImpl1: public ModelPersistence_if {
public:
	ModelPersistenceMyImpl1(Model* model);
	ModelPersistenceMyImpl1(const ModelPersistenceMyImpl1& orig);
	~ModelPersistenceMyImpl1();
public:
	bool saveAsTXT(std::string filename);
	bool loadAsTXT(std::string filename);
	bool saveAsXML(std::string filename);
	bool loadAsXML(std::string filename);
	bool save(std::string filename);
	bool load(std::string filename);		
private:
	void _saveLine(std::list<std::string>* words);
private:
	Model* _model = nullptr;
};

#endif /* MODELPERSISTENCEMYIMPL1_H */

