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
#include <limits>
//#include <numeric_limits>

class SourceModelComponent : public ModelComponent {
public:
	SourceModelComponent(Model* model);
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
    unsigned int getEntitiesCreated() const;
    void setEntitiesCreated(unsigned int _entitiesCreated);
    void setEntitiesPerCreation(unsigned int _entitiesPerCreation);
    unsigned int getEntitiesPerCreation() const;
public:
	virtual std::string show();
protected: // get & set
	std::string _entityType = "Entity Type 1";
	double _firstCreation = 0.0;
	unsigned int _entitiesPerCreation = 1;
	unsigned int _maxCreations = std::numeric_limits<unsigned int>::max();  // std::numeric_limits<unsigned int>::max();
	std::string _timeBetweenCreationsExpression = "10"; ////
	Util::TimeUnit _timeBetweenCreationsTimeUnit = Util::TimeUnit::TU_second;
	bool _collectStatistics = true;
	unsigned int _entitiesCreatedSoFar = 0;
};

#endif /* SOURCEMODELCOMPONENT_H */

