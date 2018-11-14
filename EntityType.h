/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntityType.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:24
 */

#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <string>
#include "ModelInfrastructure.h"
#include "StatisticsCollector.h"
#include "Model.h"

class EntityType: public ModelInfrastructure {
public:
	EntityType(Model* model);
	EntityType(const EntityType& orig);
	virtual ~EntityType();
public:
	virtual std::string show();
public: //get & set
    void setInitialWaitingCost(double _initialWaitingCost);
    double getInitialWaitingCost() const;
    void setInitialOtherCost(double _initialOtherCost);
    double getInitialOtherCost() const;
    void setInitialNVACost(double _initialNVACost);
    double getInitialNVACost() const;
    void setInitialVACost(double _initialVACost);
    double getInitialVACost() const;
    void setInitialPicture(std::string _initialPicture);
    std::string getInitialPicture() const;
public: //get
    StatisticsCollector* getCstatTimeInSystem() const;
    StatisticsCollector* getCstatNVATime() const;
    StatisticsCollector* getCstatVATime() const;
    StatisticsCollector* getCstatOtherTime() const;
    StatisticsCollector* getCstatTransferTime() const;
    StatisticsCollector* getCstatWaitingTime() const;

protected: // must be overriden by derived classes
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);
	
private:
	std::string _initialPicture = "report";
	double _initialVACost = 0.0;
	double _initialNVACost = 0.0;
	double _initialOtherCost = 0.0;
	double _initialWaitingCost = 0.0;
private:
	StatisticsCollector* _cstatWaitingTime; // = new StatisticsCollector("Waiting Time");
	StatisticsCollector* _cstatTransferTime; // = new StatisticsCollector("Transfer Time");
	StatisticsCollector* _cstatOtherTime; // = new StatisticsCollector("Other Time");
	StatisticsCollector* _cstatVATime; // = new StatisticsCollector("Value Added Time");
	StatisticsCollector* _cstatNVATime; // = new StatisticsCollector("Non Value Added Time");
	StatisticsCollector* _cstatTimeInSystem; // = new StatisticsCollector("Time In System");
};

#endif /* ENTITYTYPE_H */

