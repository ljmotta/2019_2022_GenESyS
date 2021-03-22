/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ODE.h
 * Author: rlcancian
 *
 * Created on 13 de Junho de 2019, 19:12
 */

#ifndef OLD_ODEELEMENT_H
#define OLD_ODEELEMENT_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"

class ODEfunction {
public:

	ODEfunction(std::string expression, double initialPoint, double initialValue) {
		this->expression = expression;
		this->initialPoint = initialPoint;
		this->initialValue = initialValue;
	}
	std::string expression;
	double initialPoint;
	double initialValue;
};

class OLD_ODEelement : public ModelElement {
public:
	OLD_ODEelement(Model* model, std::string name = "");
	virtual ~OLD_ODEelement() = default;
public:
	virtual std::string show();
public:
	static PluginInformation* GetPluginInformation();
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
	double solve();
	void setStepH(double _h);
	double getStepH() const;
	void setEndTime(double _endTime);
	double getEndTime() const;
	List<ODEfunction*>* getODEfunctions() const;
protected: // must be overriden by derived classes
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private:

private:
	List<ODEfunction*>* _ODEfunctions = new List<ODEfunction*>();
	double _stepH = 0.1;
	double _endTime;
};

#endif /* OLD_ODEELEMENT_H */

