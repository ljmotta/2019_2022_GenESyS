/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PluginConnectorDynamicImpl.cpp
 * Author: ljmotta
 *
 * Created on 5 de Maio de 2021, 23:18
 */

#ifndef PLUGINCONNECTORDYNAMICIMPL_H
#define PLUGINCONNECTORDYNAMICIMPL_H

#include "PluginConnector_if.h"
//namespace GenesysKernel {

	class PluginConnectorDynamicImpl : public PluginConnector_if {
	public:
		PluginConnectorDynamicImpl();
		virtual ~PluginConnectorDynamicImpl() = default;
	public:
		virtual Plugin* check(const std::string dynamicLibraryFilename);
		virtual Plugin* connect(const std::string dynamicLibraryFilename);
		virtual bool disconnect(const std::string dynamicLibraryFilename);
		virtual bool disconnect(Plugin* plugin);
	private:

	};
//namespace\\}
#endif /* PLUGINCONNECTORDYNAMICIMPL_H */

