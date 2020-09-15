/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formula.h
 * Author: rlcancian
 *
 * Created on 20 de Junho de 2019, 00:56
 */

#ifndef FORMULA_H
#define FORMULA_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"
#include "Parser_if.h"

class Formula : public ModelElement {
public:
	Formula(Model* model, std::string name = "");
	virtual ~Formula() = default;
public: // virtual
	virtual std::string show();
public:
	unsigned int size();
	void setExpression(std::string index, std::string formulaExpression);
	void setExpression(std::string formulaExpression);
	std::string expression(std::string index);
	std::string expression();
	double value();
	double value(std::string index);
public: // statics
	static PluginInformation* GetPluginInformation();
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
protected: // must be overriden by derived classes
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private:
private:
	std::map<std::string, std::string>* _formulaExpressions = new std::map<std::string, std::string>(); // map<index,formula>
};

#endif /* FORMULA_H */

