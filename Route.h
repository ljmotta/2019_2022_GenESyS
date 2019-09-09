/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Route.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:15
 */

#ifndef ROUTE_H
#define ROUTE_H

#include "ModelComponent.h"
#include "Station.h"

class Route : public ModelComponent {
public:
    Route(Model* model);
    Route(const Route& orig);
    virtual ~Route();
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
    void setStation(Station* _station);
    Station* getStation() const;
    void setRouteTimeExpression(std::string _routeTimeExpression);
    std::string getRouteTimeExpression() const;
    void setRouteTimeTimeUnit(Util::TimeUnit _routeTimeTimeUnit);
    Util::TimeUnit getRouteTimeTimeUnit() const;
public:
protected:
    virtual void _execute(Entity* entity);
    virtual void _initBetweenReplications();
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
    Station* _station;
    std::string _routeTimeExpression = "0.0";
    Util::TimeUnit _routeTimeTimeUnit = Util::TimeUnit::second;
};

#endif /* ROUTE_H */

