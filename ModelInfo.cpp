/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfo.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 7 de Novembro de 2018, 18:13
 */

#include "ModelInfo.h"
#include "Model.h"
#include "Assign.h"

ModelInfo::ModelInfo() {
	_name = "Model " + std::to_string(Util::GenerateNewIdOfType<Model>());
}

std::string ModelInfo::show() {
	return "analystName=\"" + this->_analystName + "\"" +
			",description=\"" + this->_description + "\"" +
			",name=\"" + this->_name + "\"" +
			",numberOfReplications=" + std::to_string(this->_numberOfReplications) +
			",replicationLength=" + std::to_string(this->_replicationLength) + " " + Util::StrTimeUnit(this->_replicationLengthTimeUnit) +
			",terminatingCondition=\"" + this->_terminatingCondition + "\"" +
			",version=" + this->_version +
			",warmupTime=" + std::to_string(this->_warmUpPeriod) + " " + Util::StrTimeUnit(this->_warmUpPeriodTimeUnit);
}

void ModelInfo::setName(std::string _name) {
	this->_name = _name;
	_hasChanged = true;
}

std::string ModelInfo::name() const {
	return _name;
}

void ModelInfo::setAnalystName(std::string _analystName) {
	this->_analystName = _analystName;
	_hasChanged = true;
}

std::string ModelInfo::analystName() const {
	return _analystName;
}

void ModelInfo::setDescription(std::string _description) {
	this->_description = _description;
	_hasChanged = true;
}

std::string ModelInfo::description() const {
	return _description;
}

void ModelInfo::setProjectTitle(std::string _projectTitle) {
	this->_projectTitle = _projectTitle;
	_hasChanged = true;
}

std::string ModelInfo::projectTitle() const {
	return _projectTitle;
}

void ModelInfo::setVersion(std::string _version) {
	this->_version = _version;
	_hasChanged = true;
}

std::string ModelInfo::version() const {
	return _version;
}

void ModelInfo::setNumberOfReplications(unsigned int _numberOfReplications) {
	this->_numberOfReplications = _numberOfReplications;
	_hasChanged = true;
}

unsigned int ModelInfo::numberOfReplications() const {
	return _numberOfReplications;
}

void ModelInfo::setReplicationLength(double _replicationLength) {
	this->_replicationLength = _replicationLength;
	_hasChanged = true;
}

double ModelInfo::replicationLength() const {
	return _replicationLength;
}

void ModelInfo::setReplicationLengthTimeUnit(Util::TimeUnit _replicationLengthTimeUnit) {
	this->_replicationLengthTimeUnit = _replicationLengthTimeUnit;
	_hasChanged = true;
}

Util::TimeUnit ModelInfo::replicationLengthTimeUnit() const {
	return _replicationLengthTimeUnit;
}

void ModelInfo::setWarmUpPeriod(double _warmUpPeriod) {
	this->_warmUpPeriod = _warmUpPeriod;
	_hasChanged = true;
}

double ModelInfo::warmUpPeriod() const {
	return _warmUpPeriod;
}

void ModelInfo::setWarmUpPeriodTimeUnit(Util::TimeUnit _warmUpPeriodTimeUnit) {
	this->_warmUpPeriodTimeUnit = _warmUpPeriodTimeUnit;
	_hasChanged = true;
}

Util::TimeUnit ModelInfo::warmUpPeriodTimeUnit() const {
	return _warmUpPeriodTimeUnit;
}

void ModelInfo::setTerminatingCondition(std::string _terminatingCondition) {
	this->_terminatingCondition = _terminatingCondition;
	_hasChanged = true;
}

std::string ModelInfo::terminatingCondition() const {
	return _terminatingCondition;
}

void ModelInfo::loadInstance(std::map<std::string, std::string>* fields) {
	this->_analystName = (*fields->find("analystName")).second;
	this->_description = (*fields->find("description")).second;
	this->_name = (*fields->find("name")).second;
	this->_numberOfReplications = std::stoi((*fields->find("numberOfReplications")).second);
	this->_projectTitle = (*fields->find("projectTitle")).second;
	this->_replicationLength = std::stod((*fields->find("replicationLength")).second);
	this->_replicationLengthTimeUnit = static_cast<Util::TimeUnit> (std::stoi((*fields->find("replicationLengthTimeUnit")).second));
	this->_terminatingCondition = (*fields->find("terminatingCondition")).second;
	this->_version = (*fields->find("version")).second;
	this->_warmUpPeriod = std::stod((*fields->find("warmUpTime")).second);
	this->_warmUpPeriodTimeUnit = static_cast<Util::TimeUnit> (std::stoi((*(fields->find("warmUpTimeTimeUnit"))).second));
	_hasChanged = false;
}

// \todo:!: implement check method (to check things like terminating condition)

std::map<std::string, std::string>* ModelInfo::saveInstance() {
	std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
	fields->emplace("typename", "ModelInfo");
	fields->emplace("analystName", "\"" + analystName() + "\"");
	fields->emplace("description", "\"" + description() + "\"");
	fields->emplace("name", "\"" + name() + "\"");
	fields->emplace("numberOfReplications", std::to_string(numberOfReplications()));
	fields->emplace("projectTitle", "\"" + projectTitle() + "\"");
	fields->emplace("replicationLength", std::to_string(replicationLength()));
	fields->emplace("replicationLengthTimeUnit", std::to_string(static_cast<int> (replicationLengthTimeUnit())));
	fields->emplace("terminatingCondition", "\"" + terminatingCondition() + "\"");
	fields->emplace("version", "\"" + version() + "\"");
	fields->emplace("warmUpTime", std::to_string(warmUpPeriod()));
	fields->emplace("warmUpTimeTimeUnit", std::to_string(static_cast<int> (warmUpPeriodTimeUnit())));
	_hasChanged = false;
	return fields;
}

bool ModelInfo::hasChanged() const {
	return _hasChanged;
}
