/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Set.h
 * Author: rlcancian
 *
 * Created on 03 de Junho de 2019, 15:11
 */

#ifndef SET_H
#define SET_H

#include "../ModelElement.h"
#include "../ElementManager.h"
#include "../ParserChangesInformation.h"
#include "../PluginInformation.h"
#include "../Model.h"

/*!
 Set module
DESCRIPTION
This data module defines various types of sets, including resource, counter, tally,
entity type, and entity picture. Resource sets can be used in the Process modules (and
Seize, Release, Enter, and Leave of the Advanced Process and Advanced Transfer
panels). Counter and Tally sets can be used in the Record module. Queue sets can be
used with the Seize, Hold, Access, Request, Leave, and Allocate modules of the
Advanced Process and Advanced Transfer panels.
TYPICAL USES
 Machines that can perform the same operations in a manufacturing facility
 Supervisors, check-out clerks in a store
 Shipping clerks, receptionists in an office
 Set of pictures corresponding to a set of entity types
PROMPTS
Prompt Description
Name The unique name of the set being defined.
Type Type of set being defined.
Members Repeat group that specifies the resource members with the set.
The order of listing the members within the repeat group is
important when using selection rules such as Preferred Order and
Cyclical.
Resource Name Name of the resource to include in the resource set. Applies only
when Type is Resource.
Tally Name Name of the tally within the tally set. Applies only when Type is
Tally.
Counter Name Name of the counter within the counter set. Applies only when
Type is Counter.
Entity Type Name of the entity type within the entity type set. Applies only
when Type is Entity.
Picture Name Name of the picture within the picture set. Applies only when
Type is Entity Picture.
 */
class Set : public ModelElement {
public:
	Set(Model* model, std::string name = "") : ModelElement(model, Util::TypeOf<Set>(), name) {};
	virtual ~Set() = default;
public: // static
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
		Set* newElement = new Set(model);
		try {
			newElement->_loadInstance(fields);
		} catch (const std::exception& e) {

		}
		return newElement;
	}
	static ModelElement* CreateInstance(Model* model, std::string name) {
		return new Set(model, name);;
	}
	static PluginInformation* GetPluginInformation() {
		PluginInformation* info = new PluginInformation(Util::TypeOf<Set>(), &Set::LoadInstance, &Set::CreateInstance);
		return info;
	}
public:
	virtual std::string show() {
		return ModelElement::show() +
				"";
	}
public:
	virtual void setSetOfType(std::string _setOfType) {
		this->_setOfType = _setOfType;
	}
	virtual std::string getSetOfType() const {
		return _setOfType;
	}
	virtual List<ModelElement*>* getElementSet() const {
		return _elementSet;
	}

protected: // must be overriden by derived classes
	bool _loadInstance(std::map<std::string, std::string>* fields) {
		bool res = ModelElement::_loadInstance(fields);
		if (res) {
			try {
				_setOfType = LoadField(fields, "type", DEFAULT.setOfType);
				unsigned int memberSize = LoadField(fields, "memberSize", DEFAULT.membersSize);
				for (unsigned int i = 0; i < memberSize; i++) {
					std::string memberName = LoadField(fields, "member" + std::to_string(i));
					ModelElement* member = _parentModel->getElements()->getElement(_setOfType, memberName);
					if (member == nullptr) { // not found. That's a problem. Resource not loaded yet (or mismatch name
						_parentModel->getTracer()->trace("ERROR: Could not found " + _setOfType + " set member named \"" + memberName + "\"", Util::TraceLevel::L1_errorFatal);
					} else {//found
						_elementSet->insert(member);
					}
				}
			} catch (...) {
			}
		}
		return res;
	}

	std::map<std::string, std::string>* _saveInstance() {
		std::map<std::string, std::string>* fields = ModelElement::_saveInstance(); //Util::TypeOf<Set>());
		SaveField(fields, "type", _setOfType, DEFAULT.setOfType);
		SaveField(fields, "membersSize", _elementSet->size(), DEFAULT.membersSize);
		unsigned int i = 0;
		for (ModelElement* element : *_elementSet->list()) {
			SaveField(fields, "member" + std::to_string(i), element->getName());
			i++;
		}
		return fields;
	}
protected: // could be overriden by derived classes
	bool _check(std::string* errorMessage) {
		bool resultAll = true;
		// resultAll |= ...
		return resultAll;
	}
	ParserChangesInformation* _getParserChangesInformation() {
		ParserChangesInformation* changes = new ParserChangesInformation();
		//changes->getProductionToAdd()->insert(...);
		//changes->getTokensToAdd()->insert(...);
		return changes;
	}

private:
	//ElementManager* _elems;
	const struct DEFAULT_VALUES {
		unsigned int membersSize = 0;
		std::string setOfType = Util::TypeOf<EntityType>();
	} DEFAULT;
	List<ModelElement*>* _elementSet = new List<ModelElement*>();
	std::string _setOfType;
};

#endif /* SET_H */

