/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginInformation.h
 * Author: rlcancian
 *
 * Created on 9 de Setembro de 2019, 20:02
 */

#ifndef PLUGININFORMATION_H
#define PLUGININFORMATION_H

#include <map>
#include <list>
#include <string>

//namespace GenesysKernel {
	class ModelElement;
	class ModelComponent;
	class Model;
	class ElementManager;

	// \todo: the following 2 types were diffferent but now on they are the same and should be merged
	typedef ModelComponent* (*StaticLoaderComponentInstance)(Model*, std::map<std::string, std::string>*);
	typedef ModelComponent* (*StaticComponentInstance)(Model*, std::string);
	typedef ModelElement* (*StaticLoaderElementInstance)(Model*, std::map<std::string, std::string>*);
	typedef ModelElement* (*StaticElementInstance)(Model*, std::string);
	class PluginInformation;
	typedef PluginInformation* (*StaticGetPluginInformation)();

	class PluginInformation {
	public:
		PluginInformation(std::string pluginTypename, StaticLoaderComponentInstance componentloader, StaticComponentInstance componentInstance);
		PluginInformation(std::string pluginTypename, StaticLoaderComponentInstance componentloader);
		PluginInformation(std::string pluginTypename, StaticLoaderElementInstance elementloader, StaticElementInstance elementInstance);
		PluginInformation(std::string pluginTypename, StaticLoaderElementInstance elementloader);
	public:
		// gets
		StaticLoaderElementInstance getElementLoader() const;
		StaticElementInstance getElementInstance() const;
		StaticLoaderComponentInstance GetComponentLoader() const;
		StaticComponentInstance GetComponentInstance() const;
		bool isGenerateReport() const;
		bool isComponent() const;
		bool isSendTransfer() const;
		bool isReceiveTransfer() const;
		bool isSink() const;
		bool isSource() const;
		std::string getObservation() const;
		std::string getVersion() const;
		std::string getDate() const;
		std::string getAuthor() const;
		std::string getPluginTypename() const;
		// sets
		void insertDynamicLibFileDependence(std::string filename);
		void setDynamicLibFilenameDependencies(std::list<std::string>* dynamicLibFilenameDependencies);
		std::list<std::string>* getDynamicLibFilenameDependencies() const;
		void setGenerateReport(bool generateReport);
		void setSendTransfer(bool sendTransfer);
		void setReceiveTransfer(bool receiveTransfer);
		void setSink(bool Sink);
		void setSource(bool Source);
		void setObservation(std::string observation);
		void setVersion(std::string version);
		void setDate(std::string date);
		void setAuthor(std::string author);
		void setMaximumOutputs(unsigned short _maximumOutputs);
		unsigned short getMaximumOutputs() const;
		void setMinimumOutputs(unsigned short _minimumOutputs);
		unsigned short getMinimumOutputs() const;
		void setMaximumInputs(unsigned short _maximumInputs);
		unsigned short getMaximumInputs() const;
		void setMinimumInputs(unsigned short _minimumInputs);
		unsigned short getMinimumInputs() const;
	public:
	private:
		std::string _author = "prof. Dr. Ing. Rafael Luiz Cancian";
		std::string _date = "01/07/2018";
		std::string _version = "0.9.1";
		std::string _observation = "First implementation not fully completed nor tested. Use with caution.";
		bool _isSource = false;
		bool _isSink = false;
		bool _receiveTransfer = false; /*!< If true, an entity can arrive to this component without a phisical connection. In terms of model connection check, it is just like a Source component, since it does not need to have a predecessor */
		bool _sendTransfer = false; /*!< If true, an entity can be sent from this component to another one without a phisical connection. In terms of model connection check, it is just like a Sink component, since it does not need to have a sucessor */
		bool _generateReport = false;
		std::list<std::string>* _dynamicLibFilenameDependencies = new std::list<std::string>();
		// set from constructor
		std::string _pluginTypename;
		bool _isComponent = false;
		unsigned short _minimumInputs = 1;
		unsigned short _maximumInputs = 1;
		unsigned short _minimumOutputs = 1;
		unsigned short _maximumOutputs = 1;
		StaticLoaderComponentInstance _componentloader;
		StaticComponentInstance _componentInstance;
		StaticLoaderElementInstance _elementloader;
		StaticElementInstance _elementInstance;
	};
//namespace\\}

#endif /* PLUGININFORMATION_H */

