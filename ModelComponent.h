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
/*
	class ModelComponentDescription {
		std::string COMPONENT_KIND = "";
		std::string COMPONENT_AUTHOR = "";
		std::string COMPONENT_VERSION = "";
		std::string COMPONENT_DESCRIPTION = "";
		std::string COMPONENT_IS_VISUAL = "";
		std::string COMPONENT_IS_SOURCE = "";
		std::string COMPONENT_IS_SINK = "";
		std::string COMPONENT_DEPENDENCES = "";
	}
*/
public:
	ModelComponent(Model* model);
	ModelComponent(const ModelComponent& orig);
	virtual ~ModelComponent();
public:
	virtual std::string show();
	List<ModelComponent*>* getNextComponents() const;
        bool getCheckedConnection() ;
        void setCheckedConnection(bool _checkedConnection);
public:
	static void Execute(Entity* entity, ModelComponent* component);
	static bool VerifySymbols(ModelComponent* component, std::string* errorMessage);
	static std::list<std::string>* SaveInstance(ModelComponent* component);
private:
	List<ModelComponent*>* _nextComponents;
        bool _checkedConnection;
protected:
	virtual void _execute(Entity* entity) = 0;

protected:
	Model* _model;
};

#endif /* MODELCOMPONENT_H */

