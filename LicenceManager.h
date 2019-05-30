/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LicenceManager.h
 * Author: rlcancian
 *
 * Created on 29 de Maio de 2019, 11:45
 */

#ifndef LICENCEMANAGER_H
#define LICENCEMANAGER_H

#include <string>

class Simulator;

class LicenceManager {
public:
    LicenceManager(Simulator* simulator);
    LicenceManager(const LicenceManager& orig);
    virtual ~LicenceManager();
    const std::string getLicense() const;
private:
    Simulator* _simulator;
    const std::string _license = "Academic Mode. In academic mode this software has full functionality and executing training-size simulation models. This software may be duplicated and used for educational purposes only; any commercial application is a violation of the license agreement. Designed and developed by prof. Dr. Ing Rafael Luiz Cancian";

};

#endif /* LICENCEMANAGER_H */

