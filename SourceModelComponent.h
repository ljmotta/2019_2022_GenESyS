/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SourceModelCOmponent.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 19:50
 */

#ifndef SOURCEMODELCOMPONENT_H
#define SOURCEMODELCOMPONENT_H

#include "ModelComponent.h"
#include <string>


class SourceModelComponent:public ModelComponent {
public:
	SourceModelComponent();
	SourceModelComponent(const SourceModelComponent& orig);
	virtual ~SourceModelComponent();
public: // get & set
    void setFirstCreation(double _firstCreation);
    double getFirstCreation() const;
    void setCollectStatistics(bool _collectStatistics);
    bool isCollectStatistics() const;
    void setEntityType(std::string _entityType);
    std::string getEntityType() const;
    void setTimeUnit(Util::TimeUnit _timeUnit);
    Util::TimeUnit getTimeUnit() const;
    void setTimeBetweenCreationsExpression(std::string _timeBetweenCreations);
    std::string getTimeBetweenCreationsExpression() const;
    void setMaxCreations(unsigned int _maxCreations);
    unsigned int getMaxCreations() const;
private:
	double _firstCreation=0.0;
    unsigned int _maxCreations=0;
    std::string _timeBetweenCreationsExpression="1";
	Util::TimeUnit _timeUnit=Util::TimeUnit::TU_second;
    std::string _entityType = "Entity Type 1";
    bool _collectStatistics = true;
};

#endif /* SOURCEMODELCOMPONENT_H */

