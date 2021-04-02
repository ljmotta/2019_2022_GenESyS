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

// ASSIGN PLUGIN

PluginLoader::AssignPlugin* PluginLoader::getAssign() {
    return _assignPlugin;
}

PluginLoader::AssignPlugin::AssignPlugin(PluginLoader* pluginLoader) {
    PluginLoader::AssignPlugin::_pluginLoader = pluginLoader;
    PluginLoader::AssignPlugin::_handle = pluginLoader->open("libassign.so");
}

void* PluginLoader::AssignPlugin::getHandle() {
    return _handle;
}

Assign* PluginLoader::AssignPlugin::create(Model* model) {
    create_assign_t* createAssign = (create_assign_t*) _pluginLoader->getAddress(PluginLoader::AssignPlugin::_handle, "create");
    return createAssign(model);
}

void PluginLoader::AssignPlugin::destroy(Assign* assign) {
    destroy_assign_t* destroyAssign = (destroy_assign_t*) _pluginLoader->getAddress(PluginLoader::AssignPlugin::_handle, "destroy");
    destroyAssign(assign);
}

Assign::Assignment* PluginLoader::AssignPlugin::createAssignment(std::string arg1, std::string arg2) {
    create_assignment_t* createAssign = (create_assignment_t*) _pluginLoader->getAddress(PluginLoader::AssignPlugin::_handle, "createAssignment");
    return createAssign(arg1, arg2);
}

void PluginLoader::AssignPlugin::destroyAssigmnent(Assign::Assignment* assigment) {
    destroy_assignment_t* destroyAssign = (destroy_assignment_t*) _pluginLoader->getAddress(PluginLoader::AssignPlugin::_handle, "destroyAssignment");
    destroyAssign(assigment);
}

StaticGetPluginInformation PluginLoader::AssignPlugin::GetPluginInfo() {
    get_plugin_information_t* getPluginInformation = (get_plugin_information_t* ) _pluginLoader->getAddress(_handle, "getPluginInformation");
    return getPluginInformation();
};

// WRITE PLUGIN

PluginLoader::WritePlugin* PluginLoader::getWrite() {
    return _writePlugin;
}

PluginLoader::WritePlugin::WritePlugin(PluginLoader* pluginLoader) {
    PluginLoader::WritePlugin::_pluginLoader = pluginLoader;
    PluginLoader::WritePlugin::_handle = pluginLoader->open("libwrite.so");
}

void* PluginLoader::WritePlugin::getHandle() {
    return _handle;
}

Write* PluginLoader::WritePlugin::create(Model* model, std::string name) {
    create_write_t* createWrite = (create_write_t*) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "create");
    return createWrite(model, name);
}

void PluginLoader::WritePlugin::destroy(Write* write) {
    destroy_write_t* destroyWrite = (destroy_write_t*) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "destroy");
    destroyWrite(write);
}

WriteElement* PluginLoader::WritePlugin::createWriteElement(std::string text, bool isExpression, bool newline) {
    create_write_element_t* createWriteElement = (create_write_element_t*) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "createWriteElement");
    return createWriteElement(text, isExpression, newline);
}

void PluginLoader::WritePlugin::destroyWriteElement(WriteElement* writeElement) {
    destroy_write_element_t* destroyWriteElement = (destroy_write_element_t*) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "destroyWriteElement");
    destroyWriteElement(writeElement);
}

StaticGetPluginInformation PluginLoader::WritePlugin::GetPluginInfo() {
    get_plugin_information_t* getPluginInformation = (get_plugin_information_t* ) _pluginLoader->getAddress(PluginLoader::WritePlugin::_handle, "getPluginInformation");
    return getPluginInformation();
};
