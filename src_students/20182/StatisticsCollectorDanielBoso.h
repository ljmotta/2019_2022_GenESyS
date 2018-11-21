/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticsCollectorDanielBoso.h
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 23:07
 */

#ifndef STATISTICSCOLLECTORDANIELBOSO_H
#define STATISTICSCOLLECTORDANIELBOSO_H

#include "StatisticsDanielBoso.h"
#include "CollectorDanielBoso.h"
#include "../../ModelInfrastructure.h"

class StatisticsCollectorDanielBoso: public ModelInfrastructure, public StatisticsDanielBoso {
public:
    StatisticsCollectorDanielBoso();
    StatisticsCollectorDanielBoso(std::string name);
    StatisticsCollectorDanielBoso(const StatisticsCollectorDanielBoso& orig);
    virtual ~StatisticsCollectorDanielBoso();
public:
    virtual std::string show();
	
protected: 
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _verifySymbols(std::string* errorMessage);

};

#endif /* STATISTICSCOLLECTORDANIELBOSO_H */

