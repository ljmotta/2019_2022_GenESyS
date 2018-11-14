/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCollectorDanielBoso.cpp
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:07
 */

#include "StatisticsCollectorDanielBoso.h"
#include "fstream"

std::list<std::string>* _words;

StatisticsCollectorDanielBoso::StatisticsCollectorDanielBoso() : ModelInfrastructure(typeid (this).name()) {}

StatisticsCollectorDanielBoso::StatisticsCollectorDanielBoso(std::string name) : ModelInfrastructure(typeid (this).name()) {
	_name = name;
}

StatisticsCollectorDanielBoso::StatisticsCollectorDanielBoso(const StatisticsCollectorDanielBoso& orig) : ModelInfrastructure(orig) {}

StatisticsCollectorDanielBoso::~StatisticsCollectorDanielBoso() {}

std::string StatisticsCollectorDanielBoso::show() {
	return ModelInfrastructure::show();
}

void StatisticsCollectorDanielBoso::_loadInstance(std::list<std::string> words) {
    _words = &words;
}

std::list<std::string>* StatisticsCollectorDanielBoso::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool StatisticsCollectorDanielBoso::_verifySymbols(std::string* errorMessage) {}