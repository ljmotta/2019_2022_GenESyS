/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PluginConnectorDynamic.cpp
 * Author: ljmotta
 *
 * Created on 5 de Maio de 2021, 23:18
 */

#ifndef PLUGINCONNECTORDYNAMIC_H
#define PLUGINCONNECTORDYNAMIC_H

#include "PluginConnector_if.h"
//namespace GenesysKernel {

	class PluginConnectorDynamic : public PluginConnector_if {
	public:
		PluginConnectorDynamic();
		virtual ~PluginConnectorDynamic() = default;
	public:
		virtual Plugin* check(const std::string dynamicLibraryFilename);
		virtual Plugin* connect(const std::string dynamicLibraryFilename);
		virtual bool disconnect(const std::string dynamicLibraryFilename);
		virtual bool disconnect(Plugin* plugin);
	private:

	};
//namespace\\}
#endif /* PLUGINCONNECTORDYNAMIC_H */

