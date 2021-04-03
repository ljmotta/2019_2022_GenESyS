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
    _assignPlugin = new PluginLoader::AssignPlugin(this);
    _writePlugin = new PluginLoader::WritePlugin(this);
    _setPlugin = new PluginLoader::SetPlugin(this);
    _disposePlugin = new PluginLoader::DisposePlugin(this);
    _delayPlugin = new PluginLoader::DelayPlugin(this);
    _createPlugin = new PluginLoader::CreatePlugin(this);
    _resourcePlugin = new PluginLoader::ResourcePlugin(this);
    _decidePlugin = new PluginLoader::DecidePlugin(this);
    _queuePlugin = new PluginLoader::QueuePlugin(this);
    _seizePlugin = new PluginLoader::SeizePlugin(this);
    _releasePlugin = new PluginLoader::ReleasePlugin(this);
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

// GETTERS

PluginLoader::AssignPlugin* PluginLoader::getAssign() {
    return _assignPlugin;
}

PluginLoader::AssignPlugin::AssignmentPlugin* PluginLoader::AssignPlugin::getAssignment() {
    return _assignmentPlugin;
}

PluginLoader::WritePlugin* PluginLoader::getWrite() {
    return _writePlugin;
}

PluginLoader::WritePlugin::WriteElementPlugin* PluginLoader::WritePlugin::getWriteElement() {
    return _writeElementPlugin;
}

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

PluginLoader::SeizePlugin* PluginLoader::getSeize() {
    return _seizePlugin;
}

PluginLoader::ReleasePlugin* PluginLoader::getRelease() {
    return _releasePlugin;
}

PluginLoader::VariablePlugin* PluginLoader::getVariable() {
    return _variablePlugin;
}

// ASSIGN

PluginLoader::AssignPlugin::AssignPlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Assign>(pluginLoader) {
    PluginLoader::AssignPlugin::_pluginLoader = pluginLoader;
    PluginLoader::AssignPlugin::_handle = pluginLoader->open("libassign.so");
    _assignmentPlugin = new AssignPlugin::AssignmentPlugin(pluginLoader, _handle);
};

// ASSIGMENT

PluginLoader::AssignPlugin::AssignmentPlugin::AssignmentPlugin(PluginLoader* pluginLoader, void* handle) : PluginLoader::Plugin<Assign>(pluginLoader) {
    _pluginLoader = pluginLoader;
    _handle = handle;
};

Assign::Assignment* PluginLoader::AssignPlugin::AssignmentPlugin::create(std::string arg1, std::string arg2) {
    create_assignment_t* createAssign = (create_assignment_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Assign>::_handle, "createAssignment");
    return createAssign(arg1, arg2);
}

void PluginLoader::AssignPlugin::AssignmentPlugin::destroy(Assign::Assignment* assigment) {
    plugin_t<Assign>::destroy_plugin_t* destroyAssign = (plugin_t<Assign>::destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Assign>::_handle, "destroyAssignment");
    destroyAssign(assigment);
}

// WRITE

PluginLoader::WritePlugin::WritePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Write>(pluginLoader) {
    PluginLoader::WritePlugin::_pluginLoader = pluginLoader;
    PluginLoader::WritePlugin::_handle = pluginLoader->open("libwrite.so");
    _writeElementPlugin = new WritePlugin::WriteElementPlugin(pluginLoader, _handle);
}

// WRITE ELEMENT

PluginLoader::WritePlugin::WriteElementPlugin::WriteElementPlugin(PluginLoader* pluginLoader, void* handle) : PluginLoader::Plugin<Write>(pluginLoader) {
    _pluginLoader = pluginLoader;
    _handle = handle;
};

WriteElement* PluginLoader::WritePlugin::WriteElementPlugin::create(std::string text, bool isExpression, bool newline) {
    create_write_element_t* createWriteElement = (create_write_element_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Write>::_handle, "createWriteElement");
    return createWriteElement(text, isExpression, newline);
}

void PluginLoader::WritePlugin::WriteElementPlugin::destroy(WriteElement* writeElement) {
    plugin_t<Write>::destroy_plugin_t* destroyWriteElement = (plugin_t<Write>::destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Write>::_handle, "destroyWriteElement");
    destroyWriteElement(writeElement);
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

// SEIZE

PluginLoader::SeizePlugin::SeizePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Seize>(pluginLoader) {
    PluginLoader::SeizePlugin::_pluginLoader = pluginLoader;
    PluginLoader::SeizePlugin::_handle = pluginLoader->open("libseize.so");
}

// RELEASE

PluginLoader::ReleasePlugin::ReleasePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Release>(pluginLoader) {
    PluginLoader::ReleasePlugin::_pluginLoader = pluginLoader;
    PluginLoader::ReleasePlugin::_handle = pluginLoader->open("librelease.so");
}

// VARIABLE

PluginLoader::VariablePlugin::VariablePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Variable>(pluginLoader) {
    PluginLoader::VariablePlugin::_pluginLoader = pluginLoader;
    PluginLoader::VariablePlugin::_handle = pluginLoader->open("libvariable.so");
}
