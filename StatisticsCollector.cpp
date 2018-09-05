/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCollector.cpp
 * Author: cancian
 * 
 * Created on 30 de Agosto de 2018, 17:24
 */

#include "StatisticsCollector.h"

StatisticsCollector::StatisticsCollector() : ModelInfrastructure(typeid (this).name()) {
}

StatisticsCollector::StatisticsCollector(std::string name) : ModelInfrastructure(typeid (this).name()) {
	_name = name;
}

StatisticsCollector::StatisticsCollector(const StatisticsCollector& orig) : ModelInfrastructure(orig) {
}

StatisticsCollector::~StatisticsCollector() {
}

std::string StatisticsCollector::show() {
	return ModelInfrastructure::show();
}

void StatisticsCollector::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* StatisticsCollector::_saveInstance() {
	std::list<std::string>* words = new std::list<std::string>();
	return words;
}

bool StatisticsCollector::_verifySymbols(std::string* errorMessage) {

}