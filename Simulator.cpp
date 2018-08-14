/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Genesys.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 12:48
 */

#include "Simulator.h"
#include "List.cpp"  // tell the compiler where is the implementation of the template class and avoid link error 

Simulator::Simulator() {
	// instanciate 1:n attributes 
	_plugins = new List<Plugin*>();
	_models = new List<Model*>();
	std::cout << _name << "\t" << std::endl << _license << std::endl << std::endl;
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

List<Model*>* Simulator::getModels() const {
	return _models;
}

List<Plugin*>* Simulator::getPlugins() const {
	return _plugins;
}

