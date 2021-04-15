/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SeizableItemRequest.h
 * Author: rlcancian
 *
 * Created on 10 de abril de 2021, 08:45
 */

#ifndef SEIZABLEITEMREQUEST_H
#define SEIZABLEITEMREQUEST_H

#include "PersistentObject_base.h"
#include "Resource.h"
#include "Set.h"

class SeizableItemRequest : PersistentObject_base {
public:

	enum class SelectionRule : int {
		CYCLICAL = 1, RANDOM = 2, SPECIFICMEMBER = 3, LARGESTREMAININGCAPACITY = 4, SMALLESTNUMBERBUSY = 5
	};

	enum class ResourceType : int {
		RESOURCE = 1, SET = 2
	};

public:


public:
	SeizableItemRequest(ModelElement* resourceOrSet, std::string quantityExpression = "1", SeizableItemRequest::ResourceType resourceType = SeizableItemRequest::ResourceType::RESOURCE, SeizableItemRequest::SelectionRule selectionRule = SeizableItemRequest::SelectionRule::LARGESTREMAININGCAPACITY, std::string saveAttribute = "", unsigned int index = 0);

public:
	virtual bool _loadInstance(std::map<std::string, std::string>* fields, unsigned int parentIndex);
	virtual std::map<std::string, std::string>* _saveInstance(unsigned int parentIndex);
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	std::string show();
	void setIndex(unsigned int index);
	unsigned int getIndex() const;
	void setSaveAttribute(std::string saveAttribute);
	std::string getSaveAttribute() const;
	void setSelectionRule(SelectionRule selectionRule);
	SelectionRule getSelectionRule() const;
	void setQuantityExpression(std::string quantityExpression);
	std::string getQuantityExpression() const;
	std::string getResourceName() const;
	void setResource(Resource* resource);
	Resource* getResource() const;
	void setSet(Set* set);
	Set* getSet() const;
	void setResourceType(ResourceType resourceType);
	ResourceType getResourceType() const;
	void setLastMemberSeized(unsigned int lastMemberSeized);
	unsigned int getLastMemberSeized() const;

private:
	const struct DEFAULT_VALUES {
		const std::string quantityExpression = "1";
		const SeizableItemRequest::ResourceType resourceType = SeizableItemRequest::ResourceType::RESOURCE;
		const SeizableItemRequest::SelectionRule selectionRule = SeizableItemRequest::SelectionRule::LARGESTREMAININGCAPACITY;
		const std::string saveAttribute = "";
		const unsigned int index = 0;
	} DEFAULT;

	ResourceType _resourceType;
	ModelElement* _resourceOrSet;
	std::string _resourceName;
	std::string _quantityExpression;
	SelectionRule _selectionRule;
	std::string _saveAttribute;
	unsigned int _index;
	unsigned int _lastMemberSeized = 0;
};

#endif /* SEIZABLEITEMREQUEST_H */

