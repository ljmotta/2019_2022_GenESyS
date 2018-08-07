/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfrastructure.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 19:40
 */

#ifndef MODELINFRASTRUCTURE_H
#define MODELINFRASTRUCTURE_H

#include <string>
#include "Util.h"

class ModelInfrastructure {
public:
	ModelInfrastructure();
	ModelInfrastructure(const ModelInfrastructure& orig);
	virtual ~ModelInfrastructure();
public:
	virtual std::string show();
public: // get & set
    Util::identitifcation getId() const;
    void setName(std::string _name);
    std::string getName() const;
private:
	Util::identitifcation _id;
	std::string _name;
};

#endif /* MODELINFRASTRUCTURE_H */

