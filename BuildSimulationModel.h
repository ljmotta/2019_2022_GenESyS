/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buildSimpleModel1.h
 * Author: cancian
 *
 * Created on 2 de Outubro de 2018, 19:18
 */

#ifndef BUILDSIMPLEMODEL1_H
#define BUILDSIMPLEMODEL1_H

#include "GenesysApplication_if.h"

class BuildSimulationModel : public GenesysApplication_if {
public:
	BuildSimulationModel();
protected:
public:
	int main(int argc, char** argv);
};

#endif /* BUILDSIMPLEMODEL1_H */

