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
#include "Traits.h"

Simulator::Simulator() {
	// 1:1
	_fitter = new Traits<Fitter_if>::Implementation();
	_sampler = new Traits<Sampler_if>::Implementation();

	// instanciate 1:n attributes 
	_plugins = new List<Plugin*>();
	_models = new List<Model*>();
	std::cout << _name << std::endl << _license << std::endl << std::endl; // The ONLY cout allowed "inside" the simulator (including model and other classes, pls
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

std::string Simulator::getVersion() const {
	return _version;
}

std::string Simulator::getLicense() const {
	return _license;
}

std::string Simulator::getName() const {
	return _name;
}

Sampler_if* Simulator::getSampler() const {
	return _sampler;
}

Fitter_if* Simulator::getFitter() const {
	return _fitter;
}

