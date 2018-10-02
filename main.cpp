/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 12:47
 */

#include <cstdlib>
#include <iostream>

#include "Traits.h"

/*
 * 
 */
int main(int argc, char** argv) {
	// do not change it. Set you own application in Traits file => Traits<GenesysApplication_if>::Application
	GenesysApplication_if *app = new Traits<GenesysApplication_if>::Application();
	int res = app->main(argc, argv);
	return res;
}

