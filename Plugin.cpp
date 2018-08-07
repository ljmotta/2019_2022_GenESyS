/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plugin.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 12:58
 */

#include "Plugin.h"

Plugin::Plugin(std::string name, bool source, bool drain) {
	//_fullfilename = fullfilename;
	_source = source;
	_drain = drain;
}

Plugin::Plugin(const Plugin& orig) {
}

Plugin::~Plugin() {
}

bool Plugin::isDrain() const {
	return _drain;
}

bool Plugin::isSource() const {
	return _source;
}


