/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Element.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 15:56
 */

#include "ModelComponent.h"
#include "Model.h"

ModelComponent::ModelComponent(Model* model, std::string componentTypename) : ModelElement(componentTypename) {
    _model = model;
    _nextComponents = new List<ModelComponent*>();
}

ModelComponent::ModelComponent(const ModelComponent& orig) : ModelElement(orig) {
}

ModelComponent::~ModelComponent() {
}

void ModelComponent::Execute(Entity* entity, ModelComponent* component) {
    component->_model->getTracer()->trace(Util::TraceLevel::blockArrival, "Entity " + std::to_string(entity->getId()) + " has arrived at component \"" + component->_name + "\""); //std::to_string(component->_id));
    Util::IncIndent();
    try {
        component->_execute(entity);
    } catch (const std::exception& e) {
        component->_model->getTracer()->traceError(e, "Error executing component " + component->show());
    }
    Util::DecIndent();
}

std::list<std::string>* ModelComponent::SaveInstance(ModelComponent* component) {
    component->_model->getTracer()->trace(Util::TraceLevel::blockArrival, "Writing component \"" + component->_name + "\""); //std::to_string(component->_id));
    std::list<std::string>* fields = new std::list<std::string>();
    try {
        fields = component->_saveInstance();
    } catch (const std::exception& e) {
        component->_model->getTracer()->traceError(e, "Error executing component " + component->show());
    }
    return fields;
}

bool ModelComponent::Check(ModelComponent* component) {
    component->_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Checking " + component->_typename + ": " + component->_name); //std::to_string(component->_id));
    bool res = false;
    std::string* errorMessage = new std::string();
    Util::IncIndent();
    {
        try {
            res = component->_check(errorMessage);
            if (!res) {
                component->_model->getTracer()->trace(Util::TraceLevel::errors, "Error: Checking has failed with message '" + *errorMessage + "'");
            }
        } catch (const std::exception& e) {
            component->_model->getTracer()->traceError(e, "Error verifying component " + component->show());
        }
    }
    Util::DecIndent();
    return res;
}

List<ModelComponent*>* ModelComponent::getNextComponents() const {
    return _nextComponents;
}

std::string ModelComponent::show() {
    return ModelElement::show(); // "{id=" + std::to_string(this->_id) + ",name=\""+this->_name + "\"}"; // , nextComponents[]=(" + _nextComponents->show() + ")}";
}

std::list<std::string>* ModelComponent::_saveInstance() {
    std::list<std::string>* fields = ModelElement::_saveInstance();
    fields->push_back("nextSize="+std::to_string(this->_nextComponents->size()));
    //unsigned short i=0;
    for (std::list<ModelComponent*>::iterator it=_nextComponents->getList()->begin(); it!=_nextComponents->getList()->end(); it++){
        fields->push_back("next="+(*it)->_name);
    }
    return fields;
}

/*
std::list<std::string>* ModelComponent::_saveInstance(std::string type) {
    std::list<std::string>* fields = ModelComponent::_saveInstance();
    fields->push_back(std::to_string(this->_nextComponents->size()));
    for (std::list<ModelComponent*>::iterator it=_nextgetComponentManager()->begin(); it!=_nextgetComponentManager()->end(); it++){
        fields->push_back((*it)->_name);
    }
    return fields;
}
*/