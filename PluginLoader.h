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
#include "Write.h"
#include "Resource.h"
#include "Model.h"
#include "Set.h"
#include "Dispose.h"
#include "Delay.h"
#include "Create.h"
#include "Decide.h"
#include "Queue.h"
#include "Seize.h"
#include "Release.h"
#include "Variable.h"

class PluginLoader {
public:
    PluginLoader(const char* handleRootPath);
    virtual ~PluginLoader() = default;
public:
    void* open(const char* handleName);
    void* getAddress(void* handle, const char* symbol);
    virtual StaticGetPluginInformation GetPluginInfo(const char* libname);

public:
    class Plugin {
        public:
            Plugin(PluginLoader* pluginLoader);
            virtual ~Plugin() = default;
        public:
            void* _handle;
            PluginLoader* _pluginLoader;
    };

public:
    const char*_handleRootPath = "";
};

typedef StaticGetPluginInformation get_plugin_information_t();

#endif /* PLUGINLOADER_H */
