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

StatisticsCollector::StatisticsCollector() : ModelInfrastructure(Util::TypeOf<StatisticsCollector>()) {
}

StatisticsCollector::StatisticsCollector(std::string name) : ModelInfrastructure(Util::TypeOf<StatisticsCollector>()) {
	_name = name;
}

StatisticsCollector::StatisticsCollector(std::string name, ModelInfrastructure* parent) : ModelInfrastructure(Util::TypeOf<StatisticsCollector>()) {
	_name = name;
	_parent = parent;
}

StatisticsCollector::StatisticsCollector(const StatisticsCollector& orig) : ModelInfrastructure(orig) {
}

StatisticsCollector::~StatisticsCollector() {
}

std::string StatisticsCollector::show() {
	std::string parentStr = "";
	if (_parent != nullptr) {
		try {
			parentStr = " (" + _parent->getName() + ")";
		} catch (...) { // if parent changed or deleted, can cause seg fault
			parentStr = "<<INCONSISTENT>>"; /*TODO ++*/
			//std::cout << "WHAT TO DO?\n";
		}
	}
	return ModelInfrastructure::show()+ parentStr;
}

ModelInfrastructure* StatisticsCollector::getParent() const {
	return _parent;
}

void StatisticsCollector::_loadInstance(std::list<std::string> words) {

}

std::list<std::string>* StatisticsCollector::_saveInstance() {
	std::list<std::string>* words = ModelInfrastructure::_saveInstance(Util::TypeOf<StatisticsCollector>());
	return words;
}

bool StatisticsCollector::_verifySymbols(std::string* errorMessage) {
	return true;
}