/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginInformation.cpp
 * Author: rlcancian
 * 
 * Created on 9 de Setembro de 2019, 20:02
 */

#include "PluginInformation.h"

//using namespace GenesysKernel;

PluginInformation::PluginInformation(std::string pluginTypename, StaticLoaderComponentInstance componentloader, StaticComponentInstance componentInstance) {
	this->_componentloader = componentloader; //// \todo:
	this->_elementloader = nullptr; /// \todo:
	this->_isComponent = true; //// \todo:
	this->_pluginTypename = pluginTypename;
	this->_componentInstance = componentInstance;
}

PluginInformation::PluginInformation(std::string pluginTypename, StaticLoaderComponentInstance componentloader) {
	this->_componentloader = componentloader; //// \todo:
	this->_elementloader = nullptr; /// \todo:
	this->_isComponent = true; //// \todo:
	this->_pluginTypename = pluginTypename;
}


PluginInformation::PluginInformation(std::string pluginTypename, StaticLoaderElementInstance elementloader) {
	this->_componentloader = nullptr;
	this->_elementloader = elementloader;
	this->_isComponent = false;
	this->_pluginTypename = pluginTypename;
}

StaticLoaderElementInstance PluginInformation::getElementLoader() const {
	return _elementloader;
}

StaticLoaderComponentInstance PluginInformation::GetComponentLoader() const {
	return _componentloader;
}

StaticComponentInstance PluginInformation::GetComponentInstance() const {
	return _componentInstance;
}

bool PluginInformation::isGenerateReport() const {
	return _generateReport;
}

bool PluginInformation::isComponent() const {
	return _isComponent;
}

bool PluginInformation::isSendTransfer() const {
	return _sendTransfer;
}

bool PluginInformation::isReceiveTransfer() const {
	return _receiveTransfer;
}

bool PluginInformation::isSink() const {
	return _isSink;
}

bool PluginInformation::isSource() const {
	return _isSource;
}

std::string PluginInformation::getObservation() const {
	return _observation;
}

std::string PluginInformation::getVersion() const {
	return _version;
}

std::string PluginInformation::getDate() const {
	return _date;
}

std::string PluginInformation::getAuthor() const {
	return _author;
}

std::string PluginInformation::getPluginTypename() const {
	return _pluginTypename;
}

void PluginInformation::insertDynamicLibFileDependence(std::string filename) {
	_dynamicLibFilenameDependencies->insert(_dynamicLibFilenameDependencies->end(), filename);
}

void PluginInformation::setDynamicLibFilenameDependencies(std::list<std::string>* dynamicLibFilenameDependencies) {
	this->_dynamicLibFilenameDependencies = dynamicLibFilenameDependencies;
}

std::list<std::string>* PluginInformation::getDynamicLibFilenameDependencies() const {
	return _dynamicLibFilenameDependencies;
}

void PluginInformation::setGenerateReport(bool generateReport) {
	this->_generateReport = generateReport;
}

void PluginInformation::setSendTransfer(bool sendTransfer) {
	this->_sendTransfer = sendTransfer;
}

void PluginInformation::setReceiveTransfer(bool receiveTransfer) {
	this->_receiveTransfer = receiveTransfer;
}

void PluginInformation::setSink(bool Sink) {
	_isSink = Sink;
}

void PluginInformation::setSource(bool Source) {
	_isSource = Source;
}

void PluginInformation::setObservation(std::string observation) {
	this->_observation = observation;
}

void PluginInformation::setVersion(std::string version) {
	this->_version = version;
}

void PluginInformation::setDate(std::string date) {
	this->_date = date;
}

void PluginInformation::setAuthor(std::string author) {
	this->_author = author;
}

void PluginInformation::setMaximumOutputs(unsigned short _maximumOutputs) {
	this->_maximumOutputs = _maximumOutputs;
}

unsigned short PluginInformation::getMaximumOutputs() const {
	return _maximumOutputs;
}

void PluginInformation::setMinimumOutputs(unsigned short _minimumOutputs) {
	this->_minimumOutputs = _minimumOutputs;
}

unsigned short PluginInformation::getMinimumOutputs() const {
	return _minimumOutputs;
}

void PluginInformation::setMaximumInputs(unsigned short _maximumInputs) {
	this->_maximumInputs = _maximumInputs;
}

unsigned short PluginInformation::getMaximumInputs() const {
	return _maximumInputs;
}

void PluginInformation::setMinimumInputs(unsigned short _minimumInputs) {
	this->_minimumInputs = _minimumInputs;
}

unsigned short PluginInformation::getMinimumInputs() const {
	return _minimumInputs;
}


