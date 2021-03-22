/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCollector.h
 * Author: rafael.luiz.cancian
 *
 * Created on 30 de Agosto de 2018, 17:24
 */

#ifndef STATISTICSCOLLECTOR_H
#define STATISTICSCOLLECTOR_H

#include "ModelElement.h"
#include "Statistics_if.h"
#include "ElementManager.h"
#include "Plugin.h"

//namespace GenesysKernel {

	/*!
	 The StatisticsCollector is the ModelElement responsible for collecting data from the model (using the Collector) and simultaneouly keeping statistics updated (using the Statistics)
	 */
	class StatisticsCollector : public ModelElement {//, public Statistics_if {
	public:
		StatisticsCollector(Model* model, std::string name = "", ModelElement* parent = nullptr, bool insertIntoModel = true);
		virtual ~StatisticsCollector() = default;
	public:
		virtual std::string show();
	public:
		static PluginInformation* GetPluginInformation();
		static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
	public:
		ModelElement* getParent() const;
		Statistics_if* getStatistics() const;

	protected:
		virtual bool _loadInstance(std::map<std::string, std::string>* fields);
		virtual std::map<std::string, std::string>* _saveInstance();
		virtual bool _check(std::string* errorMessage);
	protected:
		void _addSimulationResponses();
	private:
		void _initStaticsAndCollector();
	private:
		ModelElement* _parent;
		Statistics_if* _statistics; //= new Traits<ModelComponent>::StatisticsCollector_StatisticsImplementation();
	};
//namespace\\}
#endif /* STATISTICSCOLLECTOR_H */

