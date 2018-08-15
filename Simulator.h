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
public: // only get
    std::string getVersion() const;
    std::string getLicense() const;
    std::string getName() const;
public: // event handlers
private: // attributes 1:n
	List<Plugin*>* _plugins;
	List<Model*>* _models;
private: // attributes 1:1
	std::string _name = "GenESyS - Generic and Expansible System Simulator [REBORN]";
	std::string _license = "Academic Mode. In academic mode this software has full functionality and executing training-size simulation models. This software may be duplicated and used for educational purposes only; any commercial application is a violation of the license agreement.";
	std::string _version = "2018.08.00.5";
};

#endif /* GENESYS_H */

