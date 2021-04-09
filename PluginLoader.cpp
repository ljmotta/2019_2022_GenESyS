/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   PluginLoader.cpp
 * Author: luiz
 *
 * Created on 1 de Abril de 2021, 22:42
 */

#include "PluginLoader.h"
#include <dlfcn.h>
#include <iostream>

PluginLoader::PluginLoader(const char* handleRootPath) {
	_handleRootPath = handleRootPath;
    _setPlugin = new PluginLoader::SetPlugin(this);
    _disposePlugin = new PluginLoader::DisposePlugin(this);
    _delayPlugin = new PluginLoader::DelayPlugin(this);
    _createPlugin = new PluginLoader::CreatePlugin(this);
    _resourcePlugin = new PluginLoader::ResourcePlugin(this);
    _decidePlugin = new PluginLoader::DecidePlugin(this);
    _queuePlugin = new PluginLoader::QueuePlugin(this);
    _variablePlugin = new PluginLoader::VariablePlugin(this);

}

void* PluginLoader::open(const char* handleName) {
    std::string handleFullPath = std::string() + this->_handleRootPath + handleName;
    void* handle = dlopen(handleFullPath.c_str(), RTLD_LAZY);

    if (!handle) {
		std::cout << "Error loading handle" << handleFullPath << std::endl;
		std::cout << dlerror() << std::endl;
        EXIT_FAILURE;
	}

    return handle;
}

void* PluginLoader::getAddress(void* handle, const char* symbol) {
    void* address = (void*) dlsym(handle, symbol);

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cout << "Error loading address" << symbol << std::endl;
        std::cout << dlsym_error << std::endl;
        EXIT_FAILURE;
    }

    return address;
}

template <typename T>
PluginLoader::Plugin<T>::Plugin(PluginLoader* pluginLoader) {
    PluginLoader::Plugin<T>::_pluginLoader = pluginLoader;
}

template <typename T>
void* PluginLoader::Plugin<T>::getHandle() {
    return _handle;
}

template <typename T>
T* PluginLoader::Plugin<T>::create(Model* model, std::string name = "") {
    typename plugin_t<T>::create_plugin_t* createInstance = (typename plugin_t<T>::create_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<T>::_handle, "create");
    return createInstance(model, name);
}

template <typename T>
void PluginLoader::Plugin<T>::destroy(T* instance) {
    typename plugin_t<T>::destroy_plugin_t* destroyInstance = (typename plugin_t<T>::destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<T>::_handle, "destroy");
    destroyInstance(instance);
}

template <typename T>
StaticGetPluginInformation PluginLoader::Plugin<T>::GetPluginInfo() {
    typename plugin_t<T>::get_plugin_information_t* getPluginInformation = (typename plugin_t<T>::get_plugin_information_t*) _pluginLoader->getAddress(_handle, "getPluginInformation");
    return getPluginInformation();
};

StaticGetPluginInformation PluginLoader::GetPluginInfo2(const char* libname) {
    void* handle = this->open(libname);
    get_plugin_information_t* getPluginInformation = (get_plugin_information_t*) this->getAddress(handle, "getPluginInformation");
    return getPluginInformation();
};

// GETTERS

PluginLoader::SetPlugin* PluginLoader::getSet() {
    return _setPlugin;
}

PluginLoader::DisposePlugin* PluginLoader::getDispose() {
    return _disposePlugin;
}

PluginLoader::DelayPlugin* PluginLoader::getDelay() {
    return _delayPlugin;
}

PluginLoader::CreatePlugin* PluginLoader::getCreate() {
    return _createPlugin;
}

PluginLoader::ResourcePlugin* PluginLoader::getResource() {
    return _resourcePlugin;
}

PluginLoader::DecidePlugin* PluginLoader::getDecide() {
    return _decidePlugin;
}

PluginLoader::QueuePlugin* PluginLoader::getQueue() {
    return _queuePlugin;
}

PluginLoader::VariablePlugin* PluginLoader::getVariable() {
    return _variablePlugin;
}

// SET

PluginLoader::SetPlugin::SetPlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Set>(pluginLoader) {
    PluginLoader::SetPlugin::_pluginLoader = pluginLoader;
    PluginLoader::SetPlugin::_handle = pluginLoader->open("libset.so");
}

// Dipose

PluginLoader::DisposePlugin::DisposePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Dispose>(pluginLoader) {
    PluginLoader::DisposePlugin::_pluginLoader = pluginLoader;
    PluginLoader::DisposePlugin::_handle = pluginLoader->open("libdispose.so");
}

// Delay

PluginLoader::DelayPlugin::DelayPlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Delay>(pluginLoader) {
    PluginLoader::DelayPlugin::_pluginLoader = pluginLoader;
    PluginLoader::DelayPlugin::_handle = pluginLoader->open("libdelay.so");
}

// CREATE

PluginLoader::CreatePlugin::CreatePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Create>(pluginLoader) {
    PluginLoader::CreatePlugin::_pluginLoader = pluginLoader;
    PluginLoader::CreatePlugin::_handle = pluginLoader->open("libcreate.so");
}

// RESOURCE PLUGIN

PluginLoader::ResourcePlugin::ResourcePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Resource>(pluginLoader) {
    PluginLoader::ResourcePlugin::_pluginLoader = pluginLoader;
    PluginLoader::ResourcePlugin::_handle = pluginLoader->open("libresource.so");
}

// DECIDE

PluginLoader::DecidePlugin::DecidePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Decide>(pluginLoader) {
    PluginLoader::DecidePlugin::_pluginLoader = pluginLoader;
    PluginLoader::DecidePlugin::_handle = pluginLoader->open("libdecide.so");
}

// QUEUE

PluginLoader::QueuePlugin::QueuePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Queue>(pluginLoader) {
    PluginLoader::QueuePlugin::_pluginLoader = pluginLoader;
    PluginLoader::QueuePlugin::_handle = pluginLoader->open("libqueue.so");
}

// VARIABLE

PluginLoader::VariablePlugin::VariablePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Variable>(pluginLoader) {
    PluginLoader::VariablePlugin::_pluginLoader = pluginLoader;
    PluginLoader::VariablePlugin::_handle = pluginLoader->open("libvariable.so");
}
