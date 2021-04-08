/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Write.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 13:06
 */

#include "../Write.h"
#include "../Model.h"

#include <fstream>

extern "C" StaticGetPluginInformation getPluginInformation() {
	return &Write::GetPluginInformation;
}

Write::Write(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<Write>(), name) {
}

std::string Write::show() {
	return ModelComponent::show() + "";
}

ModelComponent* Write::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
	Write* newComponent = new Write(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

ModelComponent* Write::CreateInstance(Model* model, std::string name) {
	Write* newComponent = new Write(model, name);
	return newComponent;
}

List<WriteElement*>* Write::writeElements() const {
	return _writeElements;
}

void Write::setFilename(std::string _filename) {
	this->_filename = _filename;
}

std::string Write::filename() const {
	return _filename;
}

void Write::setWriteToType(WriteToType _writeToType) {
	this->_writeToType = _writeToType;
}

Write::WriteToType Write::writeToType() const {
	return _writeToType;
}

void Write::_execute(Entity* entity) {
	WriteElement* msgElem;
	std::list<WriteElement*>* msgs = this->_writeElements->list();
	std::string message = "";
	for (std::list<WriteElement*>::iterator it = msgs->begin(); it != msgs->end(); it++) {
		msgElem = (*it);
		if (msgElem->isExpression) {
			message += std::to_string(_parentModel->parseExpression(msgElem->text));
		} else {
			message += msgElem->text;
		}
		if (msgElem->newline) {
			if (this->_writeToType == Write::WriteToType::SCREEN) { //\todo: Write To FILE not implemented
				_parentModel->getTracer()->trace(Util::TraceLevel::report, message);
			} else if (this->_writeToType == Write::WriteToType::FILE) {
				// open file
				std::ofstream savefile;
				savefile.open(_filename, std::ofstream::app);
				savefile << message << std::endl;
				savefile.close();
			}
			message = "";
		}
	}

	this->_parentModel->sendEntityToComponent(entity, this->getNextComponents()->getFrontConnection(), 0.0);
}

void Write::_initBetweenReplications() {
	try {
		std::ofstream savefile;
		savefile.open(_filename, std::ofstream::app);
		savefile << "# Replication number " << _parentModel->getSimulation()->getCurrentReplicationNumber() << "/" << _parentModel->getInfos()->getNumberOfReplications() << std::endl;
		savefile.close();
	} catch (...) {

	}
}

bool Write::_loadInstance(std::map<std::string, std::string>* fields) {
	bool res = ModelComponent::_loadInstance(fields);
	if (res) {
		this->_writeToType = static_cast<WriteToType> (std::stoi((*fields->find("writeToType")).second));
		unsigned short writesSize = std::stoi((*fields->find("writesSize")).second);
		for (unsigned short i = 0; i < writesSize; i++) {
			std::string text = (*fields->find(text)).second;
			bool isExpression = static_cast<bool> (std::stoi((*fields->find("isExpression")).second));
			bool newline = static_cast<bool> (std::stoi((*fields->find("newline")).second));
			this->_writeElements->insert(new WriteElement(text, isExpression, newline));
		}
	}
	return res;
}

std::map<std::string, std::string>* Write::_saveInstance() {
	std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
	fields->emplace("writeToType", std::to_string(static_cast<int> (_writeToType)));
	fields->emplace("writesSize", std::to_string(_writeElements->size()));
	unsigned short i = 0;
	WriteElement* writeElem;
	for (std::list<WriteElement*>::iterator it = _writeElements->list()->begin(); it != _writeElements->list()->end(); it++) {

		writeElem = (*it);
		fields->emplace("isExpression" + std::to_string(i), std::to_string(writeElem->isExpression));
		fields->emplace("newline" + std::to_string(i), std::to_string(writeElem->newline));
		fields->emplace("text" + std::to_string(i), writeElem->text);
		i++;
	}
	//this->_writeElements
	return fields;
}

bool Write::_check(std::string* errorMessage) {
	bool resultAll = true;
	WriteElement* msgElem;
	unsigned short i = 0;
	std::list<WriteElement*>* msgs = this->_writeElements->list();
	for (std::list<WriteElement*>::iterator it = msgs->begin(); it != msgs->end(); it++) {
		msgElem = (*it);
		i++;
		if (msgElem->isExpression) {
			resultAll &= _parentModel->checkExpression(msgElem->text, "writeExpression" + std::to_string(i), errorMessage);
		}
	}
	// when cheking the model (before simulating it), remove the file if exists
	std::remove(_filename.c_str());

	return resultAll;
}

PluginInformation* Write::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<Write>(), &Write::LoadInstance, &Write::CreateInstance);
	// ...
	return info;
}


