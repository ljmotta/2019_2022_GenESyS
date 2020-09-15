/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestLSODE.h
 * Author: rlcancian
 *
 * Created on 23 de Outubro de 2019, 13:07
 */

#ifndef TESTLSODE_H
#define TESTLSODE_H

#include "BaseConsoleGenesysApplication.h"
#include "List.h"

class TestLSODE : public BaseConsoleGenesysApplication {
public:
	TestLSODE();
	virtual ~TestLSODE() = default;
public:
	virtual int main(int argc, char** argv);
private:
	List<std::string>* _differentialequation = new List<std::string>();
};

#endif /* TESTLSODE_H */

