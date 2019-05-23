/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimulationReporterDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 8 de Agosto de 2018, 10:59
 */

#include "SimulationReporterDefaultImpl1.h"
#include <assert.h>
#include <iomanip>

SimulationReporterDefaultImpl1::SimulationReporterDefaultImpl1(ModelSimulation* simulation, Model* model) {
    _simulation = simulation;
    _model = model;
}

SimulationReporterDefaultImpl1::SimulationReporterDefaultImpl1(const SimulationReporterDefaultImpl1& orig) {
}

SimulationReporterDefaultImpl1::~SimulationReporterDefaultImpl1() {
}

void SimulationReporterDefaultImpl1::showReplicationStatistics() {
    _model->getTracer()->traceReport(Util::TraceLevel::report, "");
    _model->getTracer()->traceReport(Util::TraceLevel::report, "Begin of Report for replication " + std::to_string(_simulation->getCurrentReplicationNumber()) + " of " + std::to_string(_model->getInfos()->getNumberOfReplications()));

    // runs over all elements and list the statistics for each one, and then the statistics with no parent
    Util::IncIndent();
    // organizes statistics into a map of maps
    std::list<ModelElement*>* statistics = _model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>())->getList();
    std::map< std::string, std::map<std::string, std::list<StatisticsCollector*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>();

    for (std::list<ModelElement*>::iterator it = statistics->begin(); it != statistics->end(); it++) {
        StatisticsCollector* stat = static_cast<StatisticsCollector*> ((*it));
        std::string parentName = stat->getParent()->getName();
        std::string parentTypename = stat->getParent()->getTypename();

        // look for key=parentTypename 
        std::map<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
        if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
            std::pair< std::string, std::map<std::string, std::list<StatisticsCollector*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>(parentTypename, new std::map<std::string, std::list<StatisticsCollector*>*>());
            mapMapTypeStat->insert(*newPair);
            mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will. 
        }
        //assert(mapMapIt != mapMapTypeStat->end());
        std::map<std::string, std::list<StatisticsCollector*>*>* mapTypeStat = (*mapMapIt).second;
        //assert(mapTypeStat != nullptr);
        // look for key=parentName
        std::map<std::string, std::list<StatisticsCollector*>*>::iterator mapIt = mapTypeStat->find(parentName);
        if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
            std::pair< std::string, std::list<StatisticsCollector*>* >* newPair = new std::pair<std::string, std::list<StatisticsCollector*>*>(parentName, new std::list<StatisticsCollector*>());
            mapTypeStat->insert(*newPair);
            mapIt = mapTypeStat->find(parentName); // find again. Now it will. 
        }
        // get the list and insert the stat in that list
        std::list<StatisticsCollector*>* listStat = (*mapIt).second;
        listStat->insert(listStat->end(), stat);
        //_model->getTracer()->traceReport(Util::TraceLevel::report, parentTypename + " -> " + parentName + " -> " + stat->show());
    }
    // now runs over that map of maps showing the statistics
    for (auto const mapmapItem : *mapMapTypeStat) {
        _model->getTracer()->traceReport(Util::TraceLevel::report, "Statistis for " + mapmapItem.first + ":");
        Util::IncIndent();
        {
            for (auto const mapItem : *(mapmapItem.second)) {
                _model->getTracer()->traceReport(Util::TraceLevel::report, mapItem.first + ":");
                Util::IncIndent();
                {
                    int w = 12;
                    _model->getTracer()->traceReport(Util::TraceLevel::report, Util::SetW("name", 30) +
                            Util::SetW("elems", w) + Util::SetW("min", w) + Util::SetW("max", w) + Util::SetW("average", w) + Util::SetW("variance", w) + Util::SetW("stddev", w) + Util::SetW("varCoef", w) + Util::SetW("confInterv", w) + Util::SetW("confLevel", w));
                    for (auto const item : *(mapItem.second)) {
                        Statistics_if* stat = item->getStatistics();
                        _model->getTracer()->traceReport(Util::TraceLevel::report,
                                Util::SetW(item->getName(), 30) +
                                Util::SetW(std::to_string(stat->numElements()), w) +
                                Util::SetW(std::to_string(stat->min()), w) +
                                Util::SetW(std::to_string(stat->max()), w) +
                                Util::SetW(std::to_string(stat->average()), w) +
                                Util::SetW(std::to_string(stat->variance()), w) +
                                Util::SetW(std::to_string(stat->stddeviation()), w) +
                                Util::SetW(std::to_string(stat->variationCoef()), w) +
                                Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), w) +
                                Util::SetW(std::to_string(stat->getConfidenceLevel()), w)
                                );
                    }
                }
                Util::DecIndent();
            }
        }
        Util::DecIndent();
    }

    Util::DecIndent();
    _model->getTracer()->traceReport(Util::TraceLevel::report, "End of Report for replication " + std::to_string(_simulation->getCurrentReplicationNumber()) + " of " + std::to_string(_model->getInfos()->getNumberOfReplications()));
    _model->getTracer()->traceReport(Util::TraceLevel::report, "------------------------------");
}

void SimulationReporterDefaultImpl1::showSimulationStatistics(List<StatisticsCollector*>* cstatsSimulation) {
    _model->getTracer()->traceReport(Util::TraceLevel::report, "");
    _model->getTracer()->traceReport(Util::TraceLevel::report, "Begin of Report for Simulation (based on " + std::to_string(_model->getInfos()->getNumberOfReplications()) + " replications)");
    // runs over all elements and list the statistics for each one, and then the statistics with no parent
    Util::IncIndent();
    // organizes statistics into a map of maps
    std::list<StatisticsCollector*>* statistics = cstatsSimulation->getList(); //_model->getElementManager()->getElements(Util::TypeOf<StatisticsCollector>())->getList();
    std::map< std::string, std::map<std::string, std::list<StatisticsCollector*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>();

    for (std::list<StatisticsCollector*>::iterator it = statistics->begin(); it != statistics->end(); it++) {
        StatisticsCollector* stat = ((*it)); //static_cast<StatisticsCollector*> ((*it));
        std::string parentName = stat->getParent()->getName();
        std::string parentTypename = stat->getParent()->getTypename();

        // look for key=parentTypename 
        std::map<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
        if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
            std::pair< std::string, std::map<std::string, std::list<StatisticsCollector*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<StatisticsCollector*>*>*>(parentTypename, new std::map<std::string, std::list<StatisticsCollector*>*>());
            mapMapTypeStat->insert(*newPair);
            mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will. 
        }
        //assert(mapMapIt != mapMapTypeStat->end());
        std::map<std::string, std::list<StatisticsCollector*>*>* mapTypeStat = (*mapMapIt).second;
        //assert(mapTypeStat != nullptr);
        // look for key=parentName
        std::map<std::string, std::list<StatisticsCollector*>*>::iterator mapIt = mapTypeStat->find(parentName);
        if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
            std::pair< std::string, std::list<StatisticsCollector*>* >* newPair = new std::pair<std::string, std::list<StatisticsCollector*>*>(parentName, new std::list<StatisticsCollector*>());
            mapTypeStat->insert(*newPair);
            mapIt = mapTypeStat->find(parentName); // find again. Now it will. 
        }
        // get the list and insert the stat in that list
        std::list<StatisticsCollector*>* listStat = (*mapIt).second;
        listStat->insert(listStat->end(), stat);
        //_model->getTracer()->traceReport(Util::TraceLevel::report, parentTypename + " -> " + parentName + " -> " + stat->show());
    }
    // now runs over that map of maps showing the statistics
    for (auto const mapmapItem : *mapMapTypeStat) {
        _model->getTracer()->traceReport(Util::TraceLevel::report, "Statistis for " + mapmapItem.first + ":");
        Util::IncIndent();
        {
            for (auto const mapItem : *(mapmapItem.second)) {
                _model->getTracer()->traceReport(Util::TraceLevel::report, mapItem.first + ":");
                Util::IncIndent();
                {
                    int w = 12;
                    _model->getTracer()->traceReport(Util::TraceLevel::report, Util::SetW("name", 30) +
                            Util::SetW("elems", w) + Util::SetW("min", w) + Util::SetW("max", w) + Util::SetW("average", w) + Util::SetW("variance", w) + Util::SetW("stddev", w) + Util::SetW("varCoef", w) + Util::SetW("confInterv", w) + Util::SetW("confLevel", w));
                    for (auto const item : *(mapItem.second)) {
                        Statistics_if* stat = item->getStatistics();
                        _model->getTracer()->traceReport(Util::TraceLevel::report,
                                Util::SetW(item->getName(), 30) +
                                Util::SetW(std::to_string(stat->numElements()), w) +
                                Util::SetW(std::to_string(stat->min()), w) +
                                Util::SetW(std::to_string(stat->max()), w) +
                                Util::SetW(std::to_string(stat->average()), w) +
                                Util::SetW(std::to_string(stat->variance()), w) +
                                Util::SetW(std::to_string(stat->stddeviation()), w) +
                                Util::SetW(std::to_string(stat->variationCoef()), w) +
                                Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), w) +
                                Util::SetW(std::to_string(stat->getConfidenceLevel()), w)
                                );
                    }
                }
                Util::DecIndent();
            }
        }
        Util::DecIndent();
    }

    Util::DecIndent();
    _model->getTracer()->traceReport(Util::TraceLevel::report, "End of Report for Simulation");
}
