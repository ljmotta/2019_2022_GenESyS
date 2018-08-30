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
#include "Collector_if.h"

class EntityType: public ModelInfrastructure {
public:
	EntityType();
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
    Collector_if* getCstatTimeInSystem() const;
    Collector_if* getCstatNVATime() const;
    Collector_if* getCstatVATime() const;
    Collector_if* getCstatOtherTime() const;
    Collector_if* getCstatTransferTime() const;
    Collector_if* getCstatWaitingTime() const;
private:
	std::string _initialPicture = "report";
	double _initialVACost = 0.0;
	double _initialNVACost = 0.0;
	double _initialOtherCost = 0.0;
	double _initialWaitingCost = 0.0;
private:
	Collector_if* _cstatWaitingTime;
	Collector_if* _cstatTransferTime;
	Collector_if* _cstatOtherTime;
	Collector_if* _cstatVATime;
	Collector_if* _cstatNVATime;
	Collector_if* _cstatTimeInSystem;
};

#endif /* ENTITYTYPE_H */

