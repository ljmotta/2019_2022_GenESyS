/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PluginConnectorDummyImpl1.cpp
 * Author: rlcancian
 * 
 * Created on 9 de Setembro de 2019, 19:24
 */

#include "PluginConnectorDummyImpl1.h"

PluginConnectorDummyImpl1::PluginConnectorDummyImpl1() {
}

PluginConnectorDummyImpl1::PluginConnectorDummyImpl1(const PluginConnectorDummyImpl1& orig) {
}

PluginConnectorDummyImpl1::~PluginConnectorDummyImpl1() {
}

bool PluginConnectorDummyImpl1::check(const std::string dynamicLibraryFilename, Plugin* plugin) {
    return true;
}

bool PluginConnectorDummyImpl1::connect(const std::string dynamicLibraryFilename, Plugin* plugin) {
}

bool PluginConnectorDummyImpl1::disconnect(const std::string dynamicLibraryFilename) {
    return true;
}

bool PluginConnectorDummyImpl1::disconnect(Plugin* plugin) {
    return true;
}
