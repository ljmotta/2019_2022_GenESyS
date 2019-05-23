/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 16:52
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ModelElement.h"
#include "StatisticsCollector.h"
#include "ElementManager.h"

class Resource : public ModelElement { 
public:
    typedef std::function<void(Resource*) > ResourceEventHandler;

    template<typename Class>
    static ResourceEventHandler SetResourceEventHandler(void (Class::*function)(Resource*), Class * object) {
        return std::bind(function, object, std::placeholders::_1);
    }

    enum class ResourceType : int {
        SET = 1, RESOURCE = 2
    };

    enum class ResourceRule : int {
        RANDOM = 1, CICLICAL = 2, ESPECIFIC = 3, SMALLESTBUSY = 4, LARGESTREMAININGCAPACITY = 5
    };

    enum class ResourceState : int {
        IDLE = 1, BUSY = 2, FAILED = 3, INACTIVE = 4, OTHER = 5
    };

public:
    Resource(ElementManager* elems);
    Resource(ElementManager* elems, std::string name);
    Resource(const Resource& orig);
    virtual ~Resource();
public:
    virtual std::string show();
public:
    void seize(unsigned int quantity, double tnow);
    void release(unsigned int quantity, double tnow);
public: // g&s
    void setResourceState(ResourceState _resourceState);
    Resource::ResourceState getResourceState() const;
    void setCapacity(unsigned int _capacity);
    unsigned int getCapacity() const;
    void setCostBusyHour(double _costBusyHour);
    double getCostBusyHour() const;
    void setCostIdleHour(double _costIdleHour);
    double getCostIdleHour() const;
    void setCostPerUse(double _costPerUse);
    double getCostPerUse() const;
public: // gets
    unsigned int getNumberBusy() const;
    unsigned int getNumberOut() const;
public:
    void addResourceEventHandler(ResourceEventHandler eventHandler);
protected:
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

private:
    void _initCStats();
    void _notifyEventHandlers();
private:
    ElementManager* _elems;
private:
    unsigned int _capacity = 1;
    double _costBusyHour = 1.0;
    double _costIdleHour = 1.0;
    double _costPerUse = 1.0;
    ResourceState _resourceState = ResourceState::IDLE;
    //Queue* _queue;
private: // only gets
    unsigned int _numberBusy = 0;
    unsigned int _numberOut = 0;
private: // not gets nor sets
    unsigned int _seizes = 0;
    double _lastTimeSeized = 0.0; // to check
    double _whenSeized; // same as last? check
private: //1:1
    StatisticsCollector* _cstatTimeSeized; // = new StatisticsCollector("Time Seized");
private: //1::n
    List<ResourceEventHandler>* _resourceEventHandlers = new List<ResourceEventHandler>();
    //aFailures:	TStringList;
    //std::list<Failure*>* _failures;
};

#endif /* RESOURCE_H */

