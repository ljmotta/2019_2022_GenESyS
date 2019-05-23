/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysShell.h
 * Author: rlcancian
 *
 * Created on 23 de Maio de 2019, 13:02
 */

#ifndef GENESYSSHELL_H
#define GENESYSSHELL_H

#include "GenesysApplication_if.h"

class GenesysShell : public GenesysApplication_if {
public:
    GenesysShell();
    GenesysShell(const GenesysShell& orig);
    virtual ~GenesysShell();
public:
    virtual int main(int argc, char** argv);
};

#endif /* GENESYSSHELL_H */

