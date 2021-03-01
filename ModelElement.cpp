/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelElement.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:40
 */

//#include <typeinfo>
#include <iostream>   
#include "ModelElement.h"
#include "Model.h"

//using namespace GenesysKernel;

ModelElement::ModelElement(Model* model, std::string thistypename, std::string name, bool insertIntoModel) {
	_id = Util::GenerateNewId(); //GenerateNewIdOfType(thistypename);
	_typename = thistypename;
	_parentModel = model;
	if (name == "")
		_name = thistypename + "_" + std::to_string(Util::GenerateNewIdOfType(thistypename));
	else
		_name = name;
	if (insertIntoModel)
		model->insert(this);
}

//ModelElement::ModelElement(const ModelElement &orig) {
//this->_parentModel = orig->_parentModel;
//this->_name = "copy_of_" + orig->_name;
//this->_typename = orig->_typename;
//}

ModelElement::~ModelElement() {
	_parentModel->tracer()->trace(Util::TraceLevel::everythingMostDetailed, "Removing Element \"" + this->_name + "\" from the model");
	Util::IncIndent();
	{
		for (std::map<std::string, ModelElement*>::iterator it = _childrenElements->begin(); it != _childrenElements->end(); it++) {
			(*it).second->~ModelElement();
		}
	}
	Util::DecIndent();
	_parentModel->elements()->remove(this);
}

bool ModelElement::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = true;
	std::map<std::string, std::string>::iterator it;
	it = fields->find("id");
	it != fields->end() ? this->_id = std::stoi((*it).second) : res = false;
	it = fields->find("name");
	if (it != fields->end()) {
		this->_name = (*it).second;
	} else
		res = false;
	//it != fields->end() ? this->_name = (*it).second : res = false;
	return res;
}

std::map<std::string, std::string>* ModelElement::_saveInstance() {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	fields->emplace("typename", this->_typename);
	fields->emplace("id", std::to_string(this->_id));
	fields->emplace("name", this->_name);
	return fields;
}

bool ModelElement::_check(std::string* errorMessage) {
	return true; // if there is no ovveride, return true
}

ParserChangesInformation* ModelElement::_getParserChangesInformation() {
	return new ParserChangesInformation(); // if there is no override, return no changes
}

void ModelElement::_initBetweenReplications() {

}

/*
std::list<std::map<std::string,std::string>*>* ModelElement::_saveInstance(std::string type) {
	std::list<std::map<std::string,std::string>*>* fields = ModelElement::_saveInstance();
	fields->push_back(type);
	return fields;
}
 */

std::string ModelElement::show() {
	return "id=" + std::to_string(_id) + ",name=\"" + _name + "\"";
}

std::list<std::string>* ModelElement::childrenElementKeys() const {
	std::list<std::string>* result = new std::list<std::string>();
	return result;
}

Util::identification ModelElement::id() const {
	return _id;
}

void ModelElement::setName(std::string _name) {
	this->_name = _name;
}

std::string ModelElement::name() const {
	return _name;
}

std::string ModelElement::classname() const {
	return _typename;
}

//std::list<std::map<std::string,std::string>*>* ModelElement::_saveInstance() { /* \todo: REMOVE - IS PURE VIRTUAL  TEMP */
//	std::list<std::map<std::string,std::string>*>* fiels = new std::map<std::string,std::string>();
//	return fields;
//}

void ModelElement::InitBetweenReplications(ModelElement* element) {
	//component->_model->getTraceManager()->trace(Util::TraceLevel::blockArrival, "Writing component \"" + component->_name + "\""); //std::to_string(component->_id));
	try {
		element->_initBetweenReplications();
	} catch (const std::exception& e) {
		element->_parentModel->tracer()->traceError(e, "Error initing component " + element->show());
	};
}

ModelElement* ModelElement::LoadInstance(Model* model, std::map<std::string, std::string>* fields, bool insertIntoModel) {
	std::string name = "";
	if (insertIntoModel) {
		// extracts the name from the fields even before "_laodInstance" and even before construct a new ModelElement in such way when constructing the ModelElement, it's done with the correct name and that correct name is show in trace
		std::map<std::string, std::string>::iterator it = fields->find("name");
		if (it != fields->end())
			name = (*it).second;
	}
	ModelElement* newElement = new ModelElement(model, "ModelElement", name, insertIntoModel);
	try {
		newElement->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newElement;
}

std::map<std::string, std::string>* ModelElement::SaveInstance(ModelElement* element) {
	std::map<std::string, std::string>* fields; // = new std::list<std::string>();
	try {
		fields = element->_saveInstance();
	} catch (const std::exception& e) {
		//element->_model->getTrace()->traceError(e, "Error saving anElement " + element->show());
	}
	return fields;
}

bool ModelElement::Check(ModelElement* element, std::string* errorMessage) {
	//    element->_model->getTraceManager()->trace(Util::TraceLevel::mostDetailed, "Checking " + element->_typename + ": " + element->_name); //std::to_string(element->_id));
	bool res = false;
	Util::IncIndent();
	{
		try {
			res = element->_check(errorMessage);
			if (!res) {
				//                element->_model->getTraceManager()->trace(Util::TraceLevel::errors, "Error: Checking has failed with message '" + *errorMessage + "'");
			}
		} catch (const std::exception& e) {
			//            element->_model->getTraceManager()->traceError(e, "Error verifying element " + element->show());
		}
	}
	Util::DecIndent();
	return res;
}

void ModelElement::CreateInternalElements(ModelElement* element) {
	try {
		element->_createInternalElements();
	} catch (const std::exception& e) {
		//element->...->_model->getTraceManager()->traceError(e, "Error creating elements of element " + element->show());
	};
}

void ModelElement::_createInternalElements() {

}