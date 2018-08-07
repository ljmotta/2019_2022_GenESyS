/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Genesys.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 12:48
 */

#ifndef GENESYS_H
#define GENESYS_H

#include <string>
#include <iostream>
#include "Model.h"
#include "Plugin.h"
#include "List.h"

class Simulator {
	typedef void (*eventHandler)();
public:
	Simulator();
	Simulator(const Simulator& orig);
	virtual ~Simulator();
public: // get & set
	List<Model*>* getModels() const;
	List<Plugin*>* getPlugins() const;
public: // event handlers
private: // attributes
	List<Plugin*>* _plugins;
	List<Model*>* _models;
private:
	std::string _name;
};

#endif /* GENESYS_H */

