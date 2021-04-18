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

#include "../ModelElement.h"
#include "../StatisticsCollector.h"
#include "../ElementManager.h"
#include "../Counter.h"
#include "../Plugin.h"
#include "../Counter.h"
#include "../Model.h"

class Resource;

class ResourceItemRequest {
public:

	ResourceItemRequest(Resource* resource, std::string quantityExpression = "1") {
		_resource = resource;
		_quantityExpression = quantityExpression;
	}

	std::string quantityExpression() const {
		return _quantityExpression;
	}

	Resource* resource() const {
		return _resource;
	}

    void setQuantityExpression(std::string _quantityExpression) {
    	this->_quantityExpression = _quantityExpression;
    }

    void setResource(Resource* _resource) {
    	this->_resource = _resource;
    }
private:
	Resource* _resource;
	std::string _quantityExpression;
};

/*!
Resource module
DESCRIPTION
This data module defines the resources in the simulation system, including costing
information and resource availability. Resources may have a fixed capacity that does
not vary over the simulation run or may operate based on a schedule. Resource
failures and states can also be specified in this module.
TYPICAL USES
 Equipment (machinery, cash register, phone line)
 People (clerical, order processing, sales clerks, operators)
PROMPTS
Prompt Description
Name The name of the resource whose characteristics are being
defined. This name must be unique.
Type Method for determining the capacity for a resource. Fixed
Capacity will not change during the simulation run. Based on
Schedule signifies that a Schedule module is used to specify the
capacity and duration information for the resource.
Capacity Number of resource units of a given name that are available to
the system for processing. Applies only when Type is Fixed
Capacity.
Schedule Name Identifies the name of the schedule to be used by the resource.
The schedule defines the capacity of a resource for a given
period of time. Applies only when type is Schedule.
Schedule Rule Dictates when the actual capacity change is to occur when a
decrease in capacity is required for a busy resource unit. Applies
only when Type is Schedule.
Busy/Hour Cost per hour of a resource that is processing an entity. The
resource becomes busy when it is originally allocated to an entity
and becomes idle when it is released. During the time when it is
busy, cost will accumulate based on the busy/hour cost. The busy
cost per hour is automatically converted to the appropriate base
time unit specified within the Replication Parameters page of the
Run > Setup menu item.
Idle/Hour Cost per hour of a resource that is idle. The resource is idle while
it is not processing an entity. During the time when it is idle, cost
will accumulate based on the idle/hour cost. The idle cost per
hour is automatically converted to the appropriate base time unit
specified within the Replication Parameters page of the Run >
Setup menu item.
Per Use Cost of a resource on a usage basis, regardless of the time for
which it is used. Each time the resource is allocated to an entity,
it will incur a per-use cost.
StateSet Name Name of states that the resource may be assigned during the
simulation run.
Initial State Initial state of a resource. If specified, the name must be defined
within the repeat group of state names. This field is shown only
when a StateSet Name is defined.
Failures Lists all failures that will be associated with the resource.
 Failure Name–Name of the failure associated with the
resource.
 Failure Rule–Behavior that should occur when a failure is to
occur for a busy resource unit.
Report Statistics Specifies whether or not statistics will be collected automatically
and stored in the report database for this resource.
 */
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
	//Resource(Model* model);
	Resource(Model* model, std::string name = "") : ModelElement(model, Util::TypeOf<Resource>(), name) {
		GetterMember getter = DefineGetterMember<Resource>(this, &Resource::getCapacity);
		SetterMember setter = DefineSetterMember<Resource>(this, &Resource::setCapacity);
		model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), _name + ".Capacity", getter, setter));

		GetterMember getter2 = DefineGetterMember<Resource>(this, &Resource::getCostPerUse);
		SetterMember setter2 = DefineSetterMember<Resource>(this, &Resource::setCostPerUse);
		model->getControls()->insert(new SimulationControl(Util::TypeOf<Resource>(), _name + ".CostPerUse", getter2, setter2));
		// ...

	}
	virtual ~Resource() = default;
public:
	virtual std::string show() {
		return ModelElement::show() +
				",capacity=" + std::to_string(_capacity) +
				",costBusyByour=" + std::to_string(_costBusyHour) +
				",costIdleByour=" + std::to_string(_costIdleHour) +
				",costPerUse=" + std::to_string(_costPerUse) +
				",state=" + std::to_string(static_cast<int> (_resourceState));
	}

public:
	static PluginInformation* GetPluginInformation() {
		PluginInformation* info = new PluginInformation(Util::TypeOf<Resource>(), &Resource::LoadInstance, &Resource::CreateInstance);
		return info;
	}
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
		Resource* newElement = new Resource(model);
		try {
			newElement->_loadInstance(fields);
		} catch (const std::exception& e) {

		}
		return newElement;
	}
	static ModelElement* CreateInstance(Model* model, std::string name) {
		return new Resource(model, name);;
	}

public:
	virtual void seize(unsigned int quantity, double tnow) {
		_numberBusy += quantity;
		if (_reportStatistics)
			_numSeizes->incCountValue(quantity);
		_lastTimeSeized = tnow;
		_resourceState = Resource::ResourceState::BUSY;
		// \todo implement costs
	}
	virtual void release(unsigned int quantity, double tnow) {
		if (_numberBusy >= quantity) {
			_numberBusy -= quantity;
		} else {
			_numberBusy = 0;
		}
		if (_numberBusy == 0) {
			_resourceState = Resource::ResourceState::IDLE;
		}
		double timeSeized = tnow - _lastTimeSeized;
		if (_reportStatistics) {
			_numReleases->incCountValue(quantity);
			_cstatTimeSeized->getStatistics()->getCollector()->addValue(timeSeized);
		}
		//
		_lastTimeSeized = timeSeized;
		_notifyReleaseEventHandlers();
	}
	virtual void initBetweenReplications() {
		this->_lastTimeSeized = 0.0;
		this->_numberBusy = 0;
		if (_reportStatistics) {
			this->_numSeizes->clear();
			this->_numReleases->clear();
		}
	}
public: // g&s
	virtual void setResourceState(ResourceState _resourceState) {
		this->_resourceState = _resourceState;
	}
	virtual Resource::ResourceState getResourceState() const {
		return _resourceState;
	}
	virtual void setCapacity(unsigned int _capacity) {
		this->_capacity = _capacity;
	}
	virtual unsigned int getCapacity() const {
		return _capacity;
	}
	virtual void setCostBusyHour(double _costBusyHour) {
		this->_costBusyHour = _costBusyHour;
	}
	virtual double getCostBusyHour() const {
		return _costBusyHour;
	}
	virtual void setCostIdleHour(double _costIdleHour) {
		this->_costIdleHour = _costIdleHour;
	}
	virtual double getCostIdleHour() const {
		return _costIdleHour;
	}
	virtual void setCostPerUse(double _costPerUse) {
		this->_costPerUse = _costPerUse;
	}
	virtual double getCostPerUse() const {
		return _costPerUse;
	}

public: // gets
	virtual unsigned int getNumberBusy() const {
		return _numberBusy;
	}
public:
	virtual void addReleaseResourceEventHandler(ResourceEventHandler eventHandler)  {
		this->_resourceEventHandlers->insert(eventHandler); // \todo: priority should be registered as well, so handlers are invoqued ordered by priority
	}
	virtual double getLastTimeSeized() const {
		return _lastTimeSeized;
	}

protected:
	bool _loadInstance(std::map<std::string, std::string>* fields) {
		bool res = ModelElement::_loadInstance(fields);
		if (res) {
			this->_capacity = std::stoi((*(fields->find("capacity"))).second);
			this->_costBusyHour = std::stod((*(fields->find("costBusyHour"))).second);
			this->_costIdleHour = std::stod((*(fields->find("costIdleHour"))).second);
			this->_costPerUse = std::stod((*(fields->find("costPerUse"))).second);
		}
		return res;
	}
	std::map<std::string, std::string>* _saveInstance() {
		std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Resource>());
		fields->emplace("capacity", std::to_string(this->_capacity));
		fields->emplace("costBusyHour", std::to_string(this->_costBusyHour));
		fields->emplace("costIdleHour", std::to_string(this->_costIdleHour));
		fields->emplace("costPerUse", std::to_string(this->_costPerUse));
		return fields;
	}
	bool _check(std::string* errorMessage) {
		return true;
	}
	void _createInternalElements() {
		if (_reportStatistics && _cstatTimeSeized == nullptr) {
			_cstatTimeSeized = new StatisticsCollector(_parentModel, _name + "." + "TimeSeized", this);
			_numSeizes = new Counter(_parentModel, _name + "." + "Seizes", this);
			_numReleases = new Counter(_parentModel, _name + "." + "Releases", this);
			_childrenElements->insert({"TimeSeized", _cstatTimeSeized});
			_childrenElements->insert({"Seizes", _numSeizes});
			_childrenElements->insert({"Releases", _numReleases});
		} else if (!_reportStatistics && _cstatTimeSeized != nullptr) {
			_removeChildrenElements();
		}
	}

private:
	void _notifyReleaseEventHandlers() {
		for (std::list<ResourceEventHandler>::iterator it = this->_resourceEventHandlers->list()->begin(); it != _resourceEventHandlers->list()->end(); it++) {
			(*it)(this);
		}
	} ///< Notify observer classes that some of the resource capacity has been released. It is useful for allocation components (such as Seize) to know when an entity waiting into a queue can try to seize the resource again
	//private:
	//    ElementManager* _elems;
private:
	unsigned int _capacity = 1;
	double _costBusyHour = 1.0;
	double _costIdleHour = 1.0;
	double _costPerUse = 1.0;
	ResourceState _resourceState = ResourceState::IDLE;
private: // only gets
	unsigned int _numberBusy = 0;
	//unsigned int _numberOut = 0;
	double _lastTimeSeized = 0.0; // \todo: It won't work for resources with capacity>1, when not all capacity is seized and them some more are seized. Seized time of first units will be lost. I don't have a solution so far
private: // not gets nor sets
	//unsigned int _seizes = 0;
	//double _whenSeized; // same as last? check
private: //1::n
	List<ResourceEventHandler>* _resourceEventHandlers = new List<ResourceEventHandler>();
	//aFailures:	TStringList;
	//std::list<Failure*>* _failures;
private: // inner children elements
	StatisticsCollector* _cstatTimeSeized = nullptr;
	Counter* _numSeizes;
	Counter* _numReleases;
};

#endif /* RESOURCE_H */

