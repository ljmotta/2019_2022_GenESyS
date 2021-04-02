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
void PluginLoader::Plugin<T>::destroy(T* instance) {
    destroy_plugin_t* destroyInstance = (destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<T>::_handle, "destroy");
    destroyInstance(instance);
}

template <typename T>
StaticGetPluginInformation PluginLoader::Plugin<T>::GetPluginInfo() {
    get_plugin_information_t* getPluginInformation = (get_plugin_information_t* ) _pluginLoader->getAddress(_handle, "getPluginInformation");
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

// ASSIGN

PluginLoader::AssignPlugin::AssignPlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Assign>(pluginLoader) {
    PluginLoader::AssignPlugin::_pluginLoader = pluginLoader;
    PluginLoader::AssignPlugin::_handle = pluginLoader->open("libassign.so");
    _assignmentPlugin = new AssignPlugin::AssignmentPlugin(pluginLoader, _handle);
};

Assign* PluginLoader::AssignPlugin::create(Model* model) {
    create_assign_t* createAssign = (create_assign_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Assign>::_handle, "create");
    return createAssign(model);
}

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
    destroy_plugin_t* destroyAssign = (destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Assign>::_handle, "destroyAssignment");
    destroyAssign(assigment);
}

// WRITE

PluginLoader::WritePlugin::WritePlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Write>(pluginLoader) {
    PluginLoader::WritePlugin::_pluginLoader = pluginLoader;
    PluginLoader::WritePlugin::_handle = pluginLoader->open("libwrite.so");
    _writeElementPlugin = new WritePlugin::WriteElementPlugin(pluginLoader, _handle);
}

Write* PluginLoader::WritePlugin::create(Model* model, std::string name) {
    create_write_t* createWrite = (create_write_t*) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "create");
    return createWrite(model, name);
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
    destroy_plugin_t* destroyWriteElement = (destroy_plugin_t*) _pluginLoader->getAddress(PluginLoader::Plugin<Write>::_handle, "destroyWriteElement");
    destroyWriteElement(writeElement);
}

// SET

PluginLoader::SetPlugin::SetPlugin(PluginLoader* pluginLoader) : PluginLoader::Plugin<Set>(pluginLoader) {
    PluginLoader::SetPlugin::_pluginLoader = pluginLoader;
    PluginLoader::SetPlugin::_handle = pluginLoader->open("libset.so");
}

Set* PluginLoader::SetPlugin::create(Model* model, std::string name) {
    create_set_t* createSet = (create_set_t*) _pluginLoader->getAddress(PluginLoader::SetPlugin::_handle, "create");
    return createSet(model, name);
}