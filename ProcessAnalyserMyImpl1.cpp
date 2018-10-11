/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProcessAnalyserMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 10 de Outubro de 2018, 18:27
 */

#include "ProcessAnalyserMyImpl1.h"

ProcessAnalyserMyImpl1::ProcessAnalyserMyImpl1() {
}

ProcessAnalyserMyImpl1::ProcessAnalyserMyImpl1(const ProcessAnalyserMyImpl1& orig) {
}

ProcessAnalyserMyImpl1::~ProcessAnalyserMyImpl1() {
}

List<SimulationScenario*>* ProcessAnalyserMyImpl1::getScenarios() const {
}

List<SimulationControl*>* ProcessAnalyserMyImpl1::getControls() const {
}

List<SimulationResponse*>* ProcessAnalyserMyImpl1::getResponses() const {
}

List<SimulationControl*>* ProcessAnalyserMyImpl1::extractControlsFromModel(std::string modelFilename) const {
}

List<SimulationResponse*>* ProcessAnalyserMyImpl1::extractResponsesFromModel(std::string modelFilename) const {
}

void ProcessAnalyserMyImpl1::startSimulationOfScenario(SimulationScenario* scenario) {
}

void ProcessAnalyserMyImpl1::startSimulation() {
}

void ProcessAnalyserMyImpl1::stopSimulation() {
}

void ProcessAnalyserMyImpl1::addTraceSimulationListener(traceSimulationProcessListener traceSimulationProcessListener) {
}