/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Station.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:12
 */

#ifndef STATION_H
#define STATION_H

#include "../ModelElement.h"
#include "../ElementManager.h"
#include "../Plugin.h"
#include "../Entity.h"
#include "../Model.h"
#include "../Attribute.h"

/*
 Station module
DESCRIPTION
The Station module defines a station (or a set of stations) corresponding to a physical
or logical location where processing occurs. If the Station module defines a station
set, it is effectively defining multiple processing locations.
The station (or each station within the defined set) has a matching Activity Area that
is used to report all times and costs accrued by the entities in this station. This
Activity Area’s name is the same as the station. If a parent Activity Area is defined,
then it also accrues any times and costs by the entities in this station.
TYPICAL USES
 Defining a lathe area
 Defining a set of toll booths
 Defining a food preparation area
PROMPTS
Prompt Description
Name Unique name of the module that will be displayed in the
flowchart.
Station Type Type of station being defined, either as an individual Station or a
station Set.
Station Name Name of the individual station.
Set Name Name of the station set.
Parent Activity Area Name of the Activity Area’s parent.
Associated Intersection Name of the intersection associated with this station in a guided
transporter network.
Report Statistics Specifies whether or not statistics will automatically be collected
and stored in the report database for this station and its
corresponding activity area.
Save Attribute Attribute name used to store the index number into the station set
of the member that is selected.
Station Set Members Names of the stations that are members of this station set.
Station Name A given station can only exist once within a model. Therefore, an
individual station can only be the member of one station set, and
that individual station may not be the name of a station in
another module.
Parent Activity Area Name of the Activity Area’s parent for the station set member.
Associated Intersection Name of the intersection associated with this station set in a
guided transporter network.
Report Statistics Specifies whether or not statistics will automatically be collected
and stored in the report database for this station set member and
its corresponding activity area. 
 */
class Station : public ModelElement {
public:
	Station(Model* model, std::string name) : ModelElement(model, Util::TypeOf<Station>(), name) {}
	virtual ~Station() {
		//_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), _cstatNumberInStation);
		//_parentModel->elements()->remove(Util::TypeOf<StatisticsCollector>(), _cstatTimeInStation);
	}
public:
	virtual std::string show() {
		std::string msg = ModelElement::show() + ",enterIntoStationComponent=";
		if (_enterIntoStationComponent == nullptr)
			msg += "NULL";
		else
			msg += _enterIntoStationComponent->getName();
		return msg;
	}
public: // static 
	static PluginInformation* GetPluginInformation() {
		PluginInformation* info = new PluginInformation(Util::TypeOf<Station>(), &Station::LoadInstance, &Station::CreateInstance);
		return info;
	}
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
		Station* newElement = new Station(model, "");
		try {
			newElement->_loadInstance(fields);
		} catch (const std::exception& e) {

		}
		return newElement;
	}

	static ModelElement* CreateInstance(Model* model, std::string name) {
		return new Station(model, name);
	}
public:
	virtual void initBetweenReplications() {
		_cstatNumberInStation->getStatistics()->getCollector()->clear();
		_cstatTimeInStation->getStatistics()->getCollector()->clear();

	}
	virtual void enter(Entity* entity) {
		std::string attributeName = "Entity.ArrivalAt" + this->getName();
		trimwithin(attributeName);
		entity->setAttributeValue(attributeName, _parentModel->getSimulation()->getSimulatedTime());
		entity->setAttributeValue("Entity.Station", _id);
		_numberInStation++;
		if (_reportStatistics)
			this->_cstatNumberInStation->getStatistics()->getCollector()->addValue(_numberInStation);
	}
	virtual void leave(Entity* entity) {
		std::string attributeName = "Entity.ArrivalAt" + this->getName();
		trimwithin(attributeName);
		double arrivalTime = entity->getAttributeValue(attributeName);
		double timeInStation = _parentModel->getSimulation()->getSimulatedTime() - arrivalTime;
		entity->setAttributeValue("Entity.Station", 0.0);
		_numberInStation--;
		if (_reportStatistics) {
			_cstatNumberInStation->getStatistics()->getCollector()->addValue(_numberInStation);
			_cstatTimeInStation->getStatistics()->getCollector()->addValue(timeInStation);
			if (entity->getEntityType()->isReportStatistics())
				entity->getEntityType()->addGetStatisticsCollector(entity->getEntityTypeName() + ".TimeInStations")->getStatistics()->getCollector()->addValue(timeInStation); // \todo: should check if entitytype reports (?)
		}
	}
	virtual void setEnterIntoStationComponent(ModelComponent* _enterIntoStationComponent) {
		this->_enterIntoStationComponent = _enterIntoStationComponent;
	}
	virtual ModelComponent* getEnterIntoStationComponent() const {
		return _enterIntoStationComponent;
	}
protected:
	virtual bool _loadInstance(std::map<std::string, std::string>* fields) {
		bool res = ModelElement::_loadInstance(fields);
		if (res) {
			try {
			} catch (...) {
			}
		}
		return res;
	}
	virtual std::map<std::string, std::string>* _saveInstance() {
		std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Station>());
		return fields;
	}
	virtual bool _check(std::string* errorMessage) {
		/* include attributes needed */
		std::vector<std::string> neededNames = {"Entity.Station"};
		neededNames.insert(neededNames.begin(), "Entity.ArrivalAt" + this->getName());
		std::string neededName;
		for (unsigned int i = 0; i < neededNames.size(); i++) {
			neededName = neededNames[i];
			if (_parentModel->getElements()->getElement(Util::TypeOf<Attribute>(), neededName) == nullptr) {
				new Attribute(_parentModel, neededName);
			}
		}
		//
		return true;
	}
	virtual void _createInternalElements() {
		if (_reportStatistics) {
			if (_cstatNumberInStation == nullptr) {
				_cstatNumberInStation = new StatisticsCollector(_parentModel, getName() + "." + "NumberInStation", this);
				_cstatTimeInStation = new StatisticsCollector(_parentModel, getName() + "." + "TimeInStation", this);
				_childrenElements->insert({"NumberInStation", _cstatNumberInStation});
				_childrenElements->insert({"TimeInStation", _cstatTimeInStation});
				//
				// include StatisticsCollector needed in EntityType
				std::list<ModelElement*>* enttypes = _parentModel->getElements()->getElementList(Util::TypeOf<EntityType>())->list();
				for (std::list<ModelElement*>::iterator it = enttypes->begin(); it != enttypes->end(); it++) {
					if ((*it)->isReportStatistics())
						static_cast<EntityType*> ((*it))->addGetStatisticsCollector((*it)->getName() + ".TimeInStations"); // force create this CStat before simulation starts
				}

			}
		} else
			if (_cstatNumberInStation != nullptr) {
			_removeChildrenElements();
		}
	}
private:
	unsigned int _numberInStation = 0;
	ModelComponent* _enterIntoStationComponent;
private: // inner elements
	StatisticsCollector* _cstatNumberInStation = nullptr;
	StatisticsCollector* _cstatTimeInStation;
};

#endif /* STATION_H */

