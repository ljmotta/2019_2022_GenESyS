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

StatisticsCollector::StatisticsCollector(const StatisticsCollector& orig) : ModelInfrastructure(orig) {
}

StatisticsCollector::~StatisticsCollector() {
}

std::string StatisticsCollector::show() {
	return ModelInfrastructure::show();
}
