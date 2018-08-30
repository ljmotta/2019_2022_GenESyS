/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.h
 * Author: cancian
 *
 * Created on 21 de Agosto de 2018, 16:52
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ModelInfrastructure.h"
#include "LinkedBy.h"
#include "StatisticsCollector.h"

class Resource : public ModelInfrastructure, public LinkedBy {
public:

	enum ResourceType {
		rtSET, rtRESOURCE
	};

	enum ResourceRule {
		rrRANDOM, rrCICLICAL, rrESPECIFIC, rrSMALLESTBUSY, rrLARGESTREMAININGCAPACITY
	};

	enum ResourceState {
		rsIDLE, rsBUSY, rsFAILED, rsINACTIVE, rsOTHER
	};

public:
	Resource();
	Resource(const Resource& orig);
	virtual ~Resource();
public:
	virtual std::string show();
public:
	void seize(unsigned int quantity, double tnow);
	void release(unsigned int quantity, double tnow);
public: // g&s
	void setResourceState(ResourceState _resourceState);
	ResourceState getResourceState() const;
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
private:
	unsigned int _capacity = 1;
	double _costBusyHour = 1.0;
	double _costIdleHour = 1.0;
	double _costPerUse = 1.0;
	ResourceState _resourceState = ResourceState::rsIDLE;
	//Queue* _queue;
private: // only gets
	unsigned int _numberBusy = 0;
	unsigned int _numberOut = 0;
private: // not gets nor sets
	unsigned int _seizes = 0;
	double _lastTimeSeized = 0.0; // to check
	double _whenSeized; // same as last? check
private:
	StatisticsCollector* _cstatTimeSeized = new StatisticsCollector();
	// aCSTATTimeSeizedID:	word;
	//aFailures:	TStringList;
	//std::list<Failure*>* _failures;
};

#endif /* RESOURCE_H */

