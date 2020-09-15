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
#include <iostream>
//#include "Counter.h"
#include "Traits.h"

SimulationReporterDefaultImpl1::SimulationReporterDefaultImpl1(ModelSimulation* simulation, Model* model, List<ModelElement*>* statsCountersSimulation) {
	_simulation = simulation;
	_model = model;
	_statsCountersSimulation = statsCountersSimulation;
}

void SimulationReporterDefaultImpl1::showReplicationStatistics() {
	_model->tracer()->traceReport("");
	_model->tracer()->traceReport("Begin of Report for replication " + std::to_string(_simulation->currentReplicationNumber()) + " of " + std::to_string(_model->infos()->numberOfReplications()));
	/* \todo: StatisticsCollector and Counter should NOT be special classes. It should iterate classes looking for classes that can generate reports.
	 StatisticsCollector and Counter should ovveride an inherited attribute from ModelElement to specify they generate report information
	 look for _generateReportInformation = true;  using bool generateReportInformation() const;
	 */
	const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
	const std::string UtilTypeOfCounter = Util::TypeOf< Traits<SimulationReporter_if>::CounterImplementation >(); // = Util::TypeOf<Counter>();
	// runs over all elements and list the statistics for each one, and then the statistics with no parent
	Util::IncIndent();
	// copy the ist of statistics and counters into a single new list
	std::list<ModelElement*>* statisticsAndCounters = new std::list<ModelElement*>(*(_model->elements()->elementList(UtilTypeOfStatisticsCollector)->list()));
	std::list<ModelElement*>* counters = new std::list<ModelElement*>(*(_model->elements()->elementList(UtilTypeOfCounter)->list()));
	statisticsAndCounters->merge(*counters);
	// organizes statistics into a map of maps
	std::map< std::string, std::map<std::string, std::list<ModelElement*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<ModelElement*>*>*>();

	for (std::list<ModelElement*>::iterator it = statisticsAndCounters->begin(); it != statisticsAndCounters->end(); it++) {
		std::string parentName, parentTypename;
		ModelElement* statOrCnt = (*it);
		//std::cout << statOrCnt->getName() << ": " << statOrCnt->getTypename() << std::endl;
		if ((*it)->classname() == UtilTypeOfStatisticsCollector) {
			StatisticsCollector* stat = dynamic_cast<StatisticsCollector*> (statOrCnt);
			parentName = stat->getParent()->name();
			parentTypename = stat->getParent()->classname();
		} else {
			if ((*it)->classname() == UtilTypeOfCounter) {
				Counter* cnt = dynamic_cast<Counter*> (statOrCnt);
				parentName = cnt->getParent()->name();
				parentTypename = cnt->getParent()->classname();

			}
		}
		// look for key=parentTypename
		std::map<std::string, std::map<std::string, std::list<ModelElement*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
		if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::map<std::string, std::list<ModelElement*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<ModelElement*>*>*>(parentTypename, new std::map<std::string, std::list<ModelElement*>*>());
			mapMapTypeStat->insert(*newPair);
			mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will.
		}
		//assert(mapMapIt != mapMapTypeStat->end());
		std::map<std::string, std::list<ModelElement*>*>* mapTypeStat = (*mapMapIt).second;
		assert(mapTypeStat != nullptr);
		// look for key=parentName
		std::map<std::string, std::list<ModelElement*>*>::iterator mapIt = mapTypeStat->find(parentName);
		if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::list<ModelElement*>* >* newPair = new std::pair<std::string, std::list<ModelElement*>*>(parentName, new std::list<ModelElement*>());
			mapTypeStat->insert(*newPair);
			mapIt = mapTypeStat->find(parentName); // find again. Now it will.
		}
		// get the list and insert the stat in that list
		std::list<ModelElement*>* listStatAndCount = (*mapIt).second;
		assert(listStatAndCount != nullptr);
		listStatAndCount->insert(listStatAndCount->end(), statOrCnt);
		//_model->getTraceManager()->traceReport(parentTypename + " -> " + parentName + " -> " + stat->show());
	}
	// now runs over that map of maps showing the statistics
	for (auto const mapmapItem : *mapMapTypeStat) {
		_model->tracer()->traceReport("Statistis for " + mapmapItem.first + ":");
		Util::IncIndent();
		{
			for (auto const mapItem : *(mapmapItem.second)) {
				_model->tracer()->traceReport(mapItem.first + ":");
				Util::IncIndent();
				{
					_model->tracer()->traceReport(Util::SetW("name", _nameW) +
							Util::SetW("elems", _w) + Util::SetW("min", _w) + Util::SetW("max", _w) + Util::SetW("average", _w) + Util::SetW("variance", _w) + Util::SetW("stddev", _w) + Util::SetW("varCoef", _w) + Util::SetW("confInterv", _w) + Util::SetW("confLevel", _w));
					for (ModelElement * const item : *(mapItem.second)) {
						if (item->classname() == UtilTypeOfStatisticsCollector) {
							Statistics_if* stat = dynamic_cast<StatisticsCollector*> (item)->getStatistics();
							_model->tracer()->traceReport(Util::TraceLevel::report,
									Util::SetW(item->name() + std::string(_nameW, '.'), _nameW - 1) + " " +
									Util::SetW(std::to_string(stat->numElements()), _w) +
									Util::SetW(std::to_string(stat->min()), _w) +
									Util::SetW(std::to_string(stat->max()), _w) +
									Util::SetW(std::to_string(stat->average()), _w) +
									Util::SetW(std::to_string(stat->variance()), _w) +
									Util::SetW(std::to_string(stat->stddeviation()), _w) +
									Util::SetW(std::to_string(stat->variationCoef()), _w) +
									Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), _w) +
									Util::SetW(std::to_string(stat->getConfidenceLevel()), _w)
									);
						} else {
							if (item->classname() == UtilTypeOfCounter) {
								Counter* count = dynamic_cast<Counter*> (item);
								_model->tracer()->traceReport(Util::TraceLevel::report,
										Util::SetW(count->name() + std::string(_nameW, '.'), _nameW - 1) + " " +
										Util::SetW(std::to_string(count->getCountValue()), _w)
										);
							}
						}
					}
				}
				Util::DecIndent();
			}
		}
		Util::DecIndent();
	}

	Util::DecIndent();
	_model->tracer()->traceReport("End of Report for replication " + std::to_string(_simulation->currentReplicationNumber()) + " of " + std::to_string(_model->infos()->numberOfReplications()));
	_model->tracer()->traceReport("------------------------------");
}

void SimulationReporterDefaultImpl1::showSimulationStatistics() {//List<StatisticsCollector*>* cstatsSimulation) {
	_model->tracer()->traceReport("");
	_model->tracer()->traceReport("Begin of Report for Simulation (based on " + std::to_string(_model->infos()->numberOfReplications()) + " replications)");
	const std::string UtilTypeOfStatisticsCollector = Util::TypeOf<StatisticsCollector>();
	const std::string UtilTypeOfCounter = Util::TypeOf<Counter>();
	// runs over all elements and list the statistics for each one, and then the statistics with no parent
	Util::IncIndent();
	// COPY the list of statistics and counters into a single new list
	//std::list<ModelElement*>* statisticsAndCounters = //new std::list<ModelElement*>(*(this->_statsCountersSimulation->list()));
	// organizes statistics into a map of maps
	std::map< std::string, std::map<std::string, std::list<ModelElement*>*>* >* mapMapTypeStat = new std::map<std::string, std::map<std::string, std::list<ModelElement*>*>*>();

	for (std::list<ModelElement*>::iterator it = _statsCountersSimulation->list()->begin(); it != _statsCountersSimulation->list()->end(); it++) {
		std::string parentName, parentTypename;
		ModelElement* statOrCnt = (*it);
		//std::cout << statOrCnt->getName() << ": " << statOrCnt->getTypename() << std::endl;
		if ((*it)->classname() == UtilTypeOfStatisticsCollector) {
			StatisticsCollector* stat = dynamic_cast<StatisticsCollector*> (statOrCnt);
			parentName = stat->getParent()->name();
			parentTypename = stat->getParent()->classname();
		} else {
			if ((*it)->classname() == UtilTypeOfCounter) {
				Counter* cnt = dynamic_cast<Counter*> (statOrCnt);
				parentName = cnt->getParent()->name();
				parentTypename = cnt->getParent()->classname();

			}
		}
		// look for key=parentTypename
		std::map<std::string, std::map<std::string, std::list<ModelElement*>*>*>::iterator mapMapIt = mapMapTypeStat->find(parentTypename);
		if (mapMapIt == mapMapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::map<std::string, std::list<ModelElement*>*>* >* newPair = new std::pair<std::string, std::map<std::string, std::list<ModelElement*>*>*>(parentTypename, new std::map<std::string, std::list<ModelElement*>*>());
			mapMapTypeStat->insert(*newPair);
			mapMapIt = mapMapTypeStat->find(parentTypename); // find again. Now it will.
		}
		assert(mapMapIt != mapMapTypeStat->end());
		std::map<std::string, std::list<ModelElement*>*>* mapTypeStat = (*mapMapIt).second;
		assert(mapTypeStat != nullptr);
		// look for key=parentName
		std::map<std::string, std::list<ModelElement*>*>::iterator mapIt = mapTypeStat->find(parentName);
		if (mapIt == mapTypeStat->end()) { // parentTypename does not exists in map. Include it.
			std::pair< std::string, std::list<ModelElement*>* >* newPair = new std::pair<std::string, std::list<ModelElement*>*>(parentName, new std::list<ModelElement*>());
			mapTypeStat->insert(*newPair);
			mapIt = mapTypeStat->find(parentName); // find again. Now it will.
		}
		// get the list and insert the stat in that list
		std::list<ModelElement*>* listStat = (*mapIt).second;
		listStat->insert(listStat->end(), statOrCnt);
		//_model->getTraceManager()->traceReport(parentTypename + " -> " + parentName + " -> " + stat->show());
	}
	// now runs over that map of maps showing the statistics
	//int w = 12;
	for (auto const mapmapItem : *mapMapTypeStat) {
		_model->tracer()->traceReport("Statistis for " + mapmapItem.first + ":");
		Util::IncIndent();
		{
			for (auto const mapItem : *(mapmapItem.second)) {
				_model->tracer()->traceReport(mapItem.first + ":");
				Util::IncIndent();
				{
					_model->tracer()->traceReport(Util::SetW("name", _nameW) +
							Util::SetW("elems", _w) + Util::SetW("min", _w) + Util::SetW("max", _w) + Util::SetW("average", _w) + Util::SetW("variance", _w) + Util::SetW("stddev", _w) + Util::SetW("varCoef", _w) + Util::SetW("confInterv", _w) + Util::SetW("confLevel", _w));
					for (ModelElement * const item : *(mapItem.second)) {
						if (item->classname() == UtilTypeOfStatisticsCollector) {
							Statistics_if* stat = dynamic_cast<StatisticsCollector*> (item)->getStatistics();
							_model->tracer()->traceReport(Util::TraceLevel::report,
									Util::SetW(item->name() + std::string(_nameW, '.'), _nameW - 1) + " " +
									Util::SetW(std::to_string(stat->numElements()), _w) +
									Util::SetW(std::to_string(stat->min()), _w) +
									Util::SetW(std::to_string(stat->max()), _w) +
									Util::SetW(std::to_string(stat->average()), _w) +
									Util::SetW(std::to_string(stat->variance()), _w) +
									Util::SetW(std::to_string(stat->stddeviation()), _w) +
									Util::SetW(std::to_string(stat->variationCoef()), _w) +
									Util::SetW(std::to_string(stat->halfWidthConfidenceInterval()), _w) +
									Util::SetW(std::to_string(stat->getConfidenceLevel()), _w)
									);
						} else {
							if (item->classname() == UtilTypeOfCounter) {
								Counter* cnt = dynamic_cast<Counter*> (item);
								_model->tracer()->traceReport(Util::TraceLevel::report,
										Util::SetW(cnt->name() + std::string(_nameW, '.'), _nameW - 1) + " " +
										Util::SetW(std::to_string(cnt->getCountValue()), _w)
										);

							}
						}
					}
				}
				Util::DecIndent();
			}
		}
		Util::DecIndent();
	}

	Util::DecIndent();
	_model->tracer()->traceReport("End of Report for Simulation");
}
