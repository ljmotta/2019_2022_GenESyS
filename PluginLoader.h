/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginLoader.h
 * Author: luiz
 *
 * Created on 1 de Abril de 2021, 22:42
 */

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H
#include "Assign.h"
#include "Model.h"

class PluginLoader {
public:
    PluginLoader(const char* handleRootPath);
    virtual ~PluginLoader() = default;
public:
    void* open(const char* handleName);
    void* getAddress(void* handle, const char* symbol);
public:
    const char*_handleRootPath = "";
    // static constexpr PluginAddresses pluginAddresses = { "create", "destroy","getPluginInformation" };
};

#endif /* PLUGINLOADER_H */
