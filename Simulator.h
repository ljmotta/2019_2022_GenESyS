/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Genesys.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 12:48
 */

#ifndef GENESYS_H
#define GENESYS_H

#include <string>
#include <iostream>
//#include "Traits.h"
#include "Model.h"
#include "Plugin.h"
#include "List.h"
#include "Fitter_if.h"
#include "Sampler_if.h"
#include "LicenceManager.h"

/*!
 * The main class of the ReGenesys KERNEL simulation. It gives access to simulation models and tools.
 */
class Simulator {
    typedef void (*eventHandler)();
public:
    Simulator();
    Simulator(const Simulator& orig);
    virtual ~Simulator();
public: // get & set
    /*!
     */
    List<Model*>* getModels() const; ///< Returns the list of open models in the simulator.
    List<Plugin*>* getPlugins() const;
public: // only get
    std::string getVersion() const;
    std::string getName() const;
    Sampler_if* getSampler() const; ///< Returns the Sampler, used to generate samples accordingly to a probability distribution
    Fitter_if* getFitter() const;

    LicenceManager* getLicenceManager() const {
	return _licenceManager;
    } ///< Returns the fitter, responsible for carrying out tests of adherence of theoretical distributions of probability with sampled data.
public: // event handlers
private: // attributes 1:n
    List<Plugin*>* _plugins;
    List<Model*>* _models;
private: // attributes 1:1 objects
    LicenceManager* _licenceManager;
    Fitter_if* _fitter; // = new Traits<Fitter_if>::Implementation();
    Sampler_if* _sampler; // = new Traits<Sampler_if>::Implementation();
private: // attributes 1:1 native
    const std::string _name = "ReGenESyS - Reborn Generic and Expansible System Simulator";
    const std::string _version = "2018.10.1";
};

#endif /* GENESYS_H */

