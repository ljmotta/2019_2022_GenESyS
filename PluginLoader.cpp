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
    void* createAddress = (void*) dlsym(handle, symbol);

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cout << "Error loading address" << symbol << std::endl;
        std::cout << dlsym_error << std::endl;
        EXIT_FAILURE;
    }

    return createAddress;
}
