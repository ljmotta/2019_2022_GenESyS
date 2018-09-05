/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Release.h
 * Author: cancian
 *
 * Created on 21 de Agosto de 2018, 16:17
 */

#ifndef RELEASE_H
#define RELEASE_H

#include <string>

#include "ModelComponent.h"
#include "Resource.h"
#include "Queue.h"

class Release: public ModelComponent {
public:
	Release(Model* model);
	Release(const Release& orig);
	virtual ~Release();
public:
	virtual std::string show();
public: // get & set
    void setPriority(unsigned short _priority);
    unsigned short getPriority() const;
    void setResourceType(Resource::ResourceType _resourceType);
    Resource::ResourceType getResourceType() const;
    void setQuantity(std::string _quantity);
    std::string getQuantity() const;
    void setRule(Resource::ResourceRule _rule);
    Resource::ResourceRule getRule() const;
    void setSaveAttribute(std::string _saveAttribute);
    std::string getSaveAttribute() const;
	// indirect access to Queue* and Resource*
    void setResourceName(std::string _resourceName);
    std::string getResourceName() const;
    void setQueueName(std::string _queueName);
    std::string getQueueName() const;
	
protected:
	virtual void _execute(Entity* entity);
	virtual void _loadInstance(std::list<std::string> words);
	virtual std::list<std::string>* _saveInstance();
	virtual bool _verifySymbols(std::string* errorMessage);
private:
//	unsigned int _allocationType = 0; // uint ? enum?
	unsigned short _priority = 0;
	Resource::ResourceType _resourceType = Resource::ResourceType::rtRESOURCE;
	std::string _quantity = "1";
	Resource::ResourceRule _rule = Resource::ResourceRule::rrSMALLESTBUSY;
	std::string _saveAttribute = "";
	
private: // no g&s
	Resource* _resource;
	Queue* _queue;
};

#endif /* RELEASE_H */

