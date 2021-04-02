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
#include "Decide.h"
#include "Queue.h"

class PluginLoader {
public:
    PluginLoader(const char* handleRootPath);
    virtual ~PluginLoader() = default;
public:
    void* open(const char* handleName);
    void* getAddress(void* handle, const char* symbol);
public:
    template <typename T>
    class Plugin {
        public:
            Plugin(PluginLoader* pluginLoader);
            virtual ~Plugin() = default;
        public:
            void* _handle;
            PluginLoader* _pluginLoader;
        public:
            virtual void* getHandle();
            virtual void destroy(T* instance);
            virtual StaticGetPluginInformation GetPluginInfo();
    };
    
    class AssignPlugin : public Plugin<Assign> {
        public:
            AssignPlugin(PluginLoader* pluginLoader);
            virtual ~AssignPlugin() = default;
        public:
            Assign* create(Model* model);
        public:
            class AssignmentPlugin : public Plugin<Assign> {
                public:
                    AssignmentPlugin(PluginLoader* pluginLoader, void* handle);
                    Assign::Assignment* create(std::string arg1, std::string arg2);
                    void destroy(Assign::Assignment* assignment);
            };
            PluginLoader::AssignPlugin::AssignmentPlugin* _assignmentPlugin;
            PluginLoader::AssignPlugin::AssignmentPlugin* getAssignment();
    };

    class WritePlugin : public Plugin<Write> {
        public:
            WritePlugin(PluginLoader* pluginLoader);
            virtual ~WritePlugin() = default;
        public:
            Write* create(Model* model, std::string name = "");
        public:
            class WriteElementPlugin : public Plugin<Write> {
                public:
                    WriteElementPlugin(PluginLoader* pluginLoader, void* handle);
                    WriteElement* create(std::string text, bool isExpression = false, bool newline = false);
                    void destroy(WriteElement* writeElement);
            };
            PluginLoader::WritePlugin::WriteElementPlugin* _writeElementPlugin;
            PluginLoader::WritePlugin::WriteElementPlugin* getWriteElement();
    };

    class SetPlugin : public Plugin<Set> {
        public:
            SetPlugin(PluginLoader* pluginLoader);
            virtual ~SetPlugin() = default;
        public:
            Set* create(Model* model, std::string name = "");
    };

    class ResourcePlugin : public Plugin<Resource>{
        public:
            ResourcePlugin(PluginLoader* pluginLoader);
            virtual ~ResourcePlugin() = default;
        public:
            Resource* create(Model* model, std::string name = "");
    };
    class DecidePlugin : public Plugin<Decide>{
        public:
            DecidePlugin(PluginLoader* pluginLoader);
            virtual ~DecidePlugin() = default;
        public:
            Decide* create(Model* model, std::string name = "");
    };
    class QueuePlugin : public Plugin<Queue>{
        public:
            QueuePlugin(PluginLoader* pluginLoader);
            virtual ~QueuePlugin() = default;
        public:
            Queue* create(Model* model, std::string name = "");
    };
public:
    PluginLoader::AssignPlugin* _assignPlugin;
    PluginLoader::WritePlugin* _writePlugin;
    PluginLoader::SetPlugin* _setPlugin;
    PluginLoader::ResourcePlugin* _resourcePlugin;
    PluginLoader::DecidePlugin* _decidePlugin;
    PluginLoader::QueuePlugin* _queuePlugin;
public:
    PluginLoader::AssignPlugin* getAssign();
    PluginLoader::WritePlugin* getWrite();
    PluginLoader::SetPlugin* getSet();
    PluginLoader::ResourcePlugin* getResource();
    PluginLoader::DecidePlugin* getDecide();
    PluginLoader::QueuePlugin* getQueue();
public:
    const char*_handleRootPath = "";
};

typedef void destroy_plugin_t(void* instance);
typedef StaticGetPluginInformation get_plugin_information_t();

#endif /* PLUGINLOADER_H */
