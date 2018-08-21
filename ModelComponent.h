/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Element.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 15:56
 */

#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

#include <string>
#include <list>

#include "Plugin.h"
#include "List.h"
#include "Entity.h"
#include "ModelInfrastructure.h"

class Model;

class ModelComponent : public ModelInfrastructure {
public:
	ModelComponent(Model* model, std::string thistypename);
	ModelComponent(const ModelComponent& orig);
	virtual ~ModelComponent();
public:
	virtual std::string show();
	List<ModelComponent*>* getNextComponents() const;
private:
	List<ModelComponent*>* _nextComponents;
public: // ...static...
	void execute(Entity* entity, ModelComponent* component);
	void readComponent(std::list<std::string> words); // return ModelComponent* ?
	std::list<std::string> writeComponent(ModelComponent* component);
	bool verifySymbols(ModelComponent* component, std::string* errorMessage);
protected:
	virtual void _execute(Entity* entity) = 0;
	//virtual void _read(std::string text) = 0;
protected:
	Model* _model;
};

#endif /* MODELCOMPONENT_H */

