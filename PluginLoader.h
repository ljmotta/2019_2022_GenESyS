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
    virtual StaticGetPluginInformation GetPluginInfo2(const char* libname);

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
            virtual T* create(Model* model, std::string name = "");
            virtual void* getHandle();
            virtual void destroy(T* instance);
            virtual StaticGetPluginInformation GetPluginInfo();
    };

    class SetPlugin : public Plugin<Set> {
        public:
            SetPlugin(PluginLoader* pluginLoader);
            virtual ~SetPlugin() = default;
    };

    class ResourcePlugin : public Plugin<Resource>{
        public:
            ResourcePlugin(PluginLoader* pluginLoader);
            virtual ~ResourcePlugin() = default;
    };
    class DecidePlugin : public Plugin<Decide>{
        public:
            DecidePlugin(PluginLoader* pluginLoader);
            virtual ~DecidePlugin() = default;
    };
    class QueuePlugin : public Plugin<Queue>{
        public:
            QueuePlugin(PluginLoader* pluginLoader);
            virtual ~QueuePlugin() = default;
    };
    class SeizePlugin : public Plugin<Seize>{
        public:
            SeizePlugin(PluginLoader* pluginLoader);
            virtual ~SeizePlugin() = default;
    };
    class VariablePlugin : public Plugin<Variable>{
        public:
            VariablePlugin(PluginLoader* pluginLoader);
            virtual ~VariablePlugin() = default;
    };
    class DisposePlugin : public Plugin<Dispose> {
        public:
            DisposePlugin(PluginLoader* pluginLoader);
            virtual ~DisposePlugin() = default;
    };

    class DelayPlugin : public Plugin<Delay> {
        public:
            DelayPlugin(PluginLoader* pluginLoader);
            virtual ~DelayPlugin() = default;
    };

    class CreatePlugin : public Plugin<Create> {
        public:
            CreatePlugin(PluginLoader* pluginLoader);
            virtual ~CreatePlugin() = default;
    };
public:
    PluginLoader::SetPlugin* _setPlugin;
    PluginLoader::DisposePlugin* _disposePlugin;
    PluginLoader::DelayPlugin* _delayPlugin;
    PluginLoader::CreatePlugin* _createPlugin;
    PluginLoader::ResourcePlugin* _resourcePlugin;
    PluginLoader::DecidePlugin* _decidePlugin;
    PluginLoader::QueuePlugin* _queuePlugin;
    PluginLoader::SeizePlugin* _seizePlugin;
    PluginLoader::VariablePlugin* _variablePlugin;

public:
    PluginLoader::SetPlugin* getSet();
    PluginLoader::DisposePlugin* getDispose();
    PluginLoader::DelayPlugin* getDelay();
    PluginLoader::CreatePlugin* getCreate();
    PluginLoader::ResourcePlugin* getResource();
    PluginLoader::DecidePlugin* getDecide();
    PluginLoader::QueuePlugin* getQueue();
    PluginLoader::SeizePlugin* getSeize();
    PluginLoader::VariablePlugin* getVariable();

public:
    const char*_handleRootPath = "";
};

template<typename T>
struct plugin_t {
    typedef T* create_plugin_t(Model* model, std::string name);
    typedef void destroy_plugin_t(void* instance);
    typedef StaticGetPluginInformation get_plugin_information_t();
};

typedef StaticGetPluginInformation get_plugin_information_t();

#endif /* PLUGINLOADER_H */
