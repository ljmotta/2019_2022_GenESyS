/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Route.cpp
 * Author: rlcancian
 * 
 * Created on 03 de Junho de 2019, 15:15
 */

#include "Route.h"
#include "Model.h"

Route::Route(Model* model) : ModelComponent(model, Util::TypeOf<Route>()) {
}

Route::Route(const Route& orig) : ModelComponent(orig) {
}

Route::~Route() {
}

std::string Route::show() {
    return ModelComponent::show() + "";
}

ModelComponent* Route::LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
    Route* newComponent = new Route(model);
    try {
	newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void Route::setStation(Station* _station) {
    this->_station = _station;
}

Station* Route::getStation() const {
    return _station;
}

void Route::setRouteTimeExpression(std::string _routeTimeExpression) {
    this->_routeTimeExpression = _routeTimeExpression;
}

std::string Route::getRouteTimeExpression() const {
    return _routeTimeExpression;
}

void Route::setRouteTimeTimeUnit(Util::TimeUnit _routeTimeTimeUnit) {
    this->_routeTimeTimeUnit = _routeTimeTimeUnit;
}

Util::TimeUnit Route::getRouteTimeTimeUnit() const {
    return _routeTimeTimeUnit;
}

void Route::_execute(Entity* entity) {
    _model->sendEntityToComponent(entity, this->getNextComponents()->frontConnection(), 0.0);
}

bool Route::_loadInstance(std::map<std::string, std::string>* fields) {
    bool res = ModelComponent::_loadInstance(fields);
    if (res) {
    }
    return res;
}

void Route::_initBetweenReplications() {
}

std::map<std::string, std::string>* Route::_saveInstance() {
    std::map<std::string, std::string>* fields = ModelComponent::_saveInstance();
    return fields;
}

bool Route::_check(std::string* errorMessage) {
    return true;
}

PluginInformation* Route::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<Route>(), &Route::LoadInstance);
    info->setSendTransfer(true);
    return info;
}


