/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfo.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 18:13
 */

#ifndef MODELINFO_H
#define MODELINFO_H

#include <string>
#include "Util.h"

/*!
 * ModelInfo stores basic model project information.
 */
class ModelInfo {
public:
    ModelInfo();
    virtual ~ModelInfo() = default;
public:
    std::string show();
public: // gets and sets
    void setName(std::string _name);
    std::string name() const;
    void setAnalystName(std::string _analystName);
    std::string analystName() const;
    void setDescription(std::string _description);
    std::string description() const;
    void setProjectTitle(std::string _projectTitle);
    std::string projectTitle() const;
    void setVersion(std::string _version);
    std::string version() const;
    void setNumberOfReplications(unsigned int _numberOfReplications);
    unsigned int numberOfReplications() const;
    void setReplicationLength(double _replicationLength);
    double replicationLength() const;
    void setReplicationLengthTimeUnit(Util::TimeUnit _replicationLengthTimeUnit);
    Util::TimeUnit replicationLengthTimeUnit() const;
    void setWarmUpPeriod(double _warmUpPeriod);
    double warmUpPeriod() const;
    void setWarmUpPeriodTimeUnit(Util::TimeUnit _warmUpPeriodTimeUnit);
    Util::TimeUnit warmUpPeriodTimeUnit() const;
    void setTerminatingCondition(std::string _terminatingCondition);
    std::string terminatingCondition() const;
public:
    void loadInstance(std::map<std::string, std::string>* fields);
    std::map<std::string, std::string>* saveInstance();
    bool hasChanged() const;
private: // with public access (get & set)
    // model general information
    std::string _name;
    std::string _analystName = "";
    std::string _description = "";
    std::string _projectTitle = "";
    std::string _version = "1.0";

    // replication and warmup duration
    unsigned int _numberOfReplications = 1;
    double _replicationLength = 3600.0; // by default, 3600 s = 1.0 h
    Util::TimeUnit _replicationLengthTimeUnit = Util::TimeUnit::second;
    double _warmUpPeriod = 0.0;
    Util::TimeUnit _warmUpPeriodTimeUnit = Util::TimeUnit::second;
    std::string _terminatingCondition = "";
    bool _hasChanged = false;
};

#endif /* MODELINFO_H */

