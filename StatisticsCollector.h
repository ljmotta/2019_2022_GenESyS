/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCollector.h
 * Author: cancian
 *
 * Created on 30 de Agosto de 2018, 17:24
 */

#ifndef STATISTICSCOLLECTOR_H
#define STATISTICSCOLLECTOR_H

#include "StatisticsMyImpl1.h"
#include "CollectorMyImpl1.h"
#include "ModelInfrastructure.h"

class StatisticsCollector: public ModelInfrastructure, public StatisticsMyImpl1 {
public:
	StatisticsCollector();
	StatisticsCollector(std::string name);
	StatisticsCollector(const StatisticsCollector& orig);
	virtual ~StatisticsCollector();
public:
	virtual std::string show();
	
protected: 
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);

private:

};

#endif /* STATISTICSCOLLECTOR_H */

