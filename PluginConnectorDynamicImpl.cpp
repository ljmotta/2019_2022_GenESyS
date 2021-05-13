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

#include "PluginConnectorDynamicImpl.h"

// Model Components
#include "Record.h"
#include "Dummy.h"
//#include "Leave.h"
// #include "LSODE.h"
// #include "MarkovChain.h"

//?
// #include "DropOff.h"
// #include "Hold.h"
// #include "Schedule.h"
// #include "Batch.h"
//#include "Separate.h"
#include "Submodel.h"
// #include "Match.h"
// #include "PickUp.h"
// #include "Remove.h"
// #include "Search.h"
// #include "Signal.h"
// #include "Store.h"
// #include "PickStation.h"
#include "Sequence.h"
// #include "Start.h"
// #include "Stop.h"
// #include "Unstore.h"
// #include "Failure.h"
// #include "File.h"
// #include "Storage.h"
// #include "Access.h"
// #include "Exit.h"

// Model elements
#include "EntityType.h"
#include "Attribute.h"
#include "ProbDistribDefaultImpl1.h"
#include "EntityGroup.h"
#include "Counter.h"
#// include "OLD_ODEelement.h"

#include "Util.h"
#include <dlfcn.h>
#include <iostream>
#include "PluginLoader.h"

//namespace GenesysKernel {

	PluginConnectorDynamicImpl::PluginConnectorDynamicImpl() {
	}

	Plugin* PluginConnectorDynamicImpl::check(const std::string dynamicLibraryFilename) {
		return nullptr; /**@ \todo:To implement */
	}

	Plugin* PluginConnectorDynamicImpl::connect(const std::string dynamicLibraryFilename) {
		PluginLoader* pluginLoader = new PluginLoader("./plugin/build/");

		std::string fn = getFileName(dynamicLibraryFilename);
		StaticGetPluginInformation GetInfo = nullptr;
		Plugin* pluginResult = nullptr;
	// model elements
	if (fn == "attribute.so")
		GetInfo = &Attribute::GetPluginInformation;
	else if (fn == "counter.so")
		GetInfo = &Counter::GetPluginInformation;
	else if (fn == "entitygroup.so")
		GetInfo = &EntityGroup::GetPluginInformation;
	else if (fn == "entitytype.so")
		GetInfo = &EntityType::GetPluginInformation;
	else if (fn == "statisticscollector.so")
		GetInfo = &StatisticsCollector::GetPluginInformation;
	else if (fn == "dummy.so")
		GetInfo = &Dummy::GetPluginInformation;
	else if (fn == "record.so")
		GetInfo = &Record::GetPluginInformation;
	else if (fn == "submodel.so")
		GetInfo = &Submodel::GetPluginInformation;
	else if (fn == "sequence.so")
		GetInfo = &Sequence::GetPluginInformation;

	else
		GetInfo = pluginLoader->GetPluginInfo(("lib"+fn).c_str());

		if (GetInfo != nullptr) {
			pluginResult = new Plugin(GetInfo);
		}
		return pluginResult;
	}

	bool PluginConnectorDynamicImpl::disconnect(const std::string dynamicLibraryFilename) {
		return true;
	}

	bool PluginConnectorDynamicImpl::disconnect(Plugin* plugin) {
		return true;
}

//namespace\\}
