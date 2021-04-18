/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Agosto de 2018, 17:12
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../Attribute.h"
#include "../ElementManager.h"
#include "../Entity.h"
#include "../List.h"
#include "../Model.h"
#include "../ModelComponent.h"
#include "../ModelElement.h"
#include "../Plugin.h"
#include "../StatisticsCollector.h"


class Waiting {
public:

	Waiting(Entity* entity, ModelComponent* component, double timeStartedWaiting) {
		_entity = entity;
		_component = component;
		_timeStartedWaiting = timeStartedWaiting;
	}

	virtual ~Waiting() = default;
public:

	virtual std::string show() {
		return //ModelElement::show()+
		",entity=" + std::to_string(_entity->getId()) +
				",component=\"" + _component->getName() + "\"" +
				",timeStatedWaiting=" + std::to_string(_timeStartedWaiting);
	}
public:

	double getTimeStartedWaiting() const {
		return _timeStartedWaiting;
	}

	ModelComponent* getComponent() const {
		return _component;
	}

	Entity* getEntity() const {
		return _entity;
	}
private:
	Entity* _entity;
	ModelComponent* _component;
	double _timeStartedWaiting;
};

/*!
 Queue module
DESCRIPTION
This data module may be utilized to change the ranking rule for a specified queue.
The default ranking rule for all queues is First In, First Out unless otherwise specified
in this module. There is an additional field that allows the queue to be defined as
shared.
TYPICAL USES
 Stack of work waiting for a resource at a Process module
 Holding area for documents waiting to be collated at a Batch module
Prompt Description
Name The name of the queue whose characteristics are being defined.
This name must be unique.
Type Ranking rule for the queue, which can be based on an attribute.
Types include First In, First Out; Last In, First Out; Lowest
Attribute Value (first); and Highest Attribute Value (first). A
low attribute value would be 0 or 1, while a high value may be
200 or 300.
Attribute Name Attribute that will be evaluated for the Lowest Attribute Value or
Highest Attribute Value types. Entities with lowest or highest
values of the attribute will be ranked first in the queue, with ties
being broken using the First In, First Out rule.
Shared Check box that determines whether a specific queue is used in
multiple places within the simulation model. Shared queues can
only be used for seizing resources (for example, with the Seize
module from the Advanced Process panel).
Report Statistics Specifies whether or not statistics will be collected automatically
and stored in the report database for this queue.
 */


class Queue : public ModelElement {
public:
	enum class OrderRule : int {
		FIFO = 1, LIFO = 2, HIGHESTVALUE = 3, SMALLESTVALUE = 4
	};

public:
	Queue(Model* model, std::string name = "") : ModelElement(model, Util::TypeOf<Queue>(), name) {}
	virtual ~Queue() = default;
public:
	virtual std::string show() {
		return ModelElement::show() +
				",waiting=" + this->_list->show();
	}
public:
	static PluginInformation* GetPluginInformation() {
		PluginInformation* info = new PluginInformation(Util::TypeOf<Queue>(), &Queue::LoadInstance, &Queue::CreateInstance);
		return info;
	}
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
		Queue* newElement = new Queue(model);
		try {
			newElement->_loadInstance(fields);
		} catch (const std::exception& e) {

		}
		return newElement;
	}
	static ModelElement* CreateInstance(Model* model, std::string name) {
		return new Queue(model, name);;
	}
public:
	virtual void insertElement(Waiting* element) {
		_list->insert(element);
		if (_reportStatistics)
			this->_cstatNumberInQueue->getStatistics()->getCollector()->addValue(_list->size());
	}
	virtual void removeElement(Waiting* element) {
		double tnow = _parentModel->getSimulation()->getSimulatedTime();
		_list->remove(element);
		if (_reportStatistics) {
			this->_cstatNumberInQueue->getStatistics()->getCollector()->addValue(_list->size());
			double timeInQueue = tnow - element->getTimeStartedWaiting();
			this->_cstatTimeInQueue->getStatistics()->getCollector()->addValue(timeInQueue);
		}
	}
	virtual unsigned int size() {
		return _list->size();
	}
	virtual Waiting* first() {
		return _list->front();
	}
	virtual Waiting* getAtRank(unsigned int rank) {
		return _list->getAtRank(rank);
	}
	virtual void setAttributeName(std::string _attributeName) {
		this->_attributeName = _attributeName;
	}
	virtual std::string getAttributeName() const {
		return _attributeName;
	}
	virtual void setOrderRule(OrderRule _orderRule) {
		this->_orderRule = _orderRule;
	}
	virtual Queue::OrderRule getOrderRule() const {
		return _orderRule;
	}
public: // to implement SIMAN functions
	virtual double sumAttributesFromWaiting(Util::identification attributeID) {
		double sum = 0.0;
		for (std::list<Waiting*>::iterator it = _list->list()->begin(); it != _list->list()->end(); it++) {
			sum += (*it)->getEntity()->attributeValue(attributeID);
		}
		return sum;
	} // use to implement SIMAN SAQUE function
	virtual double getAttributeFromWaitingRank(unsigned int rank, Util::identification attributeID) {
		Waiting* wait = _list->getAtRank(rank);
		if (wait != nullptr) {
			return wait->getEntity()->attributeValue(attributeID);
		}
		return 0.0;
	}
public:
	virtual void initBetweenReplications() {
		this->_list->clear();
	}
protected:
	bool _loadInstance(std::map<std::string, std::string>* fields) {
		bool res = ModelElement::_loadInstance(fields);
		if (res) {
			try {
				this->_attributeName = (*fields->find("attributeName")).second;
				this->_orderRule = static_cast<OrderRule> (std::stoi((*fields->find("orderRule")).second));
			} catch (...) {
			}
		}
		return res;
	}
	std::map<std::string, std::string>* _saveInstance() {
		std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Queue>());
		fields->emplace("orderRule", std::to_string(static_cast<int> (this->_orderRule)));
		fields->emplace("attributeName", this->_attributeName);
		return fields;
	}
	bool _check(std::string* errorMessage) {
		return _parentModel->getElements()->check(Util::TypeOf<Attribute>(), _attributeName, "AttributeName", false, errorMessage);
	}
	void _createInternalElements() {
		if (_reportStatistics) {
			if (_cstatNumberInQueue == nullptr) {
				_cstatNumberInQueue = new StatisticsCollector(_parentModel, _name + "." + "NumberInQueue", this); /* \todo: ++ WHY THIS INSERT "DISPOSE" AND "10ENTITYTYPE" STATCOLL ?? */
				_cstatTimeInQueue = new StatisticsCollector(_parentModel, _name + "." + "TimeInQueue", this);
				_childrenElements->insert({"NumberInQueue", _cstatNumberInQueue});
				_childrenElements->insert({"TimeInQueue", _cstatTimeInQueue});
			}
		} else if (_cstatNumberInQueue != nullptr) {
			// \todo: remove
			_removeChildrenElements();
			//_childrenElements->remove(_cstatNumberInQueue);
			//_childrenElements->remove(_cstatTimeInQueue);
			//_cstatNumberInQueue->~StatisticsCollector();
			//_cstatTimeInQueue->~StatisticsCollector();
		}
	}
	ParserChangesInformation* _getParserChangesInformation() {
		ParserChangesInformation* changes = new ParserChangesInformation();
		//changes->getProductionToAdd()->insert(...);
		//changes->getTokensToAdd()->insert(...);
		return changes;
	}

private:
	void _initCStats();
private: //1::n
	List<Waiting*>* _list = new List<Waiting*>();
private: //1::1
	OrderRule _orderRule = OrderRule::FIFO;
	std::string _attributeName = "";
private: // inner children elements
	StatisticsCollector* _cstatNumberInQueue = nullptr;
	StatisticsCollector* _cstatTimeInQueue;
};

#endif /* QUEUE_H */

