/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HypothesisTester.cpp
 * Author: cancian
 * 
 * Created on 7 de Agosto de 2018, 19:03
 */

#include "HypothesisTesterMyImpl1.h"

HypothesisTesterMyImpl1::HypothesisTesterMyImpl1() {
}

HypothesisTesterMyImpl1::HypothesisTesterMyImpl1(const HypothesisTesterMyImpl1& orig) {
}

HypothesisTesterMyImpl1::~HypothesisTesterMyImpl1() {
}

bool HypothesisTesterMyImpl1::testAverage(double confidencelevel, double avg, H1Comparition comp) {
}

bool HypothesisTesterMyImpl1::testProportion(double confidencelevel, double prop, H1Comparition comp) {
}

bool HypothesisTesterMyImpl1::testVariance(double confidencelevel, double var, H1Comparition comp) {
}

bool HypothesisTesterMyImpl1::testAverage(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

bool HypothesisTesterMyImpl1::testProportion(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

bool HypothesisTesterMyImpl1::testVariance(double confidencelevel, std::string secondPopulationDataFilename, H1Comparition comp) {
}

void HypothesisTesterMyImpl1::setDataFilename(std::string dataFilename) {
}

std::string HypothesisTesterMyImpl1::getDataFilename() {
}