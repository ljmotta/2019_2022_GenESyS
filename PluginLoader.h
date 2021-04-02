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
#include "Model.h"

class PluginLoader {
public:
    PluginLoader(const char* handleRootPath);
    virtual ~PluginLoader() = default;
public:
    void* open(const char* handleName);
    void* getAddress(void* handle, const char* symbol);
public:
    class AssignPlugin {
        public:
            AssignPlugin(PluginLoader* pluginLoader);
        public:
            void* _handle;
            PluginLoader* _pluginLoader;
        public:
            void* getHandle();
            Assign* create(Model* model);
            void destroy(Assign* assign);
            StaticGetPluginInformation GetPluginInfo();
            Assign::Assignment* createAssignment(std::string arg1, std::string arg2);
            void destroyAssigmnent(Assign::Assignment* assigment);
    };
    class WritePlugin {
        public:
            WritePlugin(PluginLoader* pluginLoader);
        public:
            void* _handle;
            PluginLoader* _pluginLoader;
        public:
            void* getHandle();
            Write* create(Model* model, std::string name = "");
            void destroy(Write* write);
            StaticGetPluginInformation GetPluginInfo();
            WriteElement* createWriteElement(std::string text, bool isExpression = false, bool newline = false);
            void destroyWriteElement(WriteElement* writeElement);
    };
public:
    // plugins
    PluginLoader::AssignPlugin* _assignPlugin;
    PluginLoader::WritePlugin* _writePlugin;
public:
    PluginLoader::AssignPlugin* getAssign();
    PluginLoader::WritePlugin* getWrite();
public:
    const char*_handleRootPath = "";
    // static constexpr PluginAddresses pluginAddresses = { "create", "destroy","getPluginInformation" };
};

typedef StaticGetPluginInformation get_plugin_information_t();

#endif /* PLUGINLOADER_H */
