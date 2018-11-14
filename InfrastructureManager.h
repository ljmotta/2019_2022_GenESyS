/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfrastructureManager.h
 * Author: cancian
 *
 * Created on 7 de Novembro de 2018, 12:48
 */

#ifndef INFRASTRUCTUREMANAGER_H
#define INFRASTRUCTUREMANAGER_H

#include <list>
#include <map>
#include "List.h"
#include "ModelInfrastructure.h"

class Model;

class InfrastructureManager {
public:
	InfrastructureManager(Model* model);
	InfrastructureManager(const InfrastructureManager& orig);
	virtual ~InfrastructureManager();
public:
	bool insertInfrastructure(std::string infraTypename, ModelInfrastructure* infra);
	bool removeInfrastructure(std::string infraTypename, ModelInfrastructure* infra);
	//private:
public: // MUST BE PRIVATE
	List<ModelInfrastructure*>* getInfrastructures(std::string infraTypename) const;
	ModelInfrastructure* getInfrastructure(std::string infraTypename, Util::identitifcation id);
	ModelInfrastructure* getInfrastructure(std::string infraTypename, std::string name);
	std::list<std::string>* getInfrastructureTypenames() const;
public:
	void show();
private:
	std::map<std::string, List<ModelInfrastructure*>*>* _infrastructures;
	Model* _model;
};

#endif /* INFRASTRUCTUREMANAGER_H */

