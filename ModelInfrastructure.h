/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelInfrastructure.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 19:40
 */

#ifndef MODELINFRASTRUCTURE_H
#define MODELINFRASTRUCTURE_H

#include <string>
#include <list>
#include "Util.h"


class ModelInfrastructure {
public:
	ModelInfrastructure(std::string infrastructureTypename);
	ModelInfrastructure(const ModelInfrastructure& orig);
	virtual ~ModelInfrastructure();
public:
	virtual std::string show();
public: // static
	static void LoadInstance(std::list<std::string> words); // TODO: return ModelComponent* ?
	static std::list<std::string>* SaveInstance(ModelInfrastructure* infrastructure);
	static bool VerifySymbols(ModelInfrastructure* infrastructure, std::string* errorMessage);

public: // get & set
	Util::identitifcation getId() const;
	void setName(std::string _name);
	std::string getName() const;

protected: // must be overriden by derived classes
	virtual void _loadInstance(std::list<std::string> words)=0;
	virtual std::list<std::string>* _saveInstance();
	virtual std::list<std::string>* _saveInstance(std::string type);
	virtual bool _verifySymbols(std::string* errorMessage) = 0;

protected:
	Util::identitifcation _id;
	std::string _name;
};

#endif /* MODELINFRASTRUCTURE_H */

