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

#include <iostream>
#include "../ModelElement.h"
#include "../ElementManager.h"
#include "../Plugin.h"
#include "../Parser_if.h"
#include "../Model.h"
#include "../Traits.h"

class Formula : public ModelElement {
public:
	Formula(Model* model, std::string name = "") : ModelElement(model, "Formula", name) {
		//_myPrivateParser = new Traits<Parser_if>::Implementation(_parentModel);
	}
	virtual ~Formula() = default;
public: // virtual
	virtual std::string show() {
		std::string expressions = "";
		//unsigned int i = 0;
		// for (std::list<std::string>::iterator it = _formulaExpressions->list()->begin(); it != _formulaExpressions->list()->end(); it++) {
		//expressions += "expression[" + std::to_string(i++) + "]=\"" + (*it) + "\"; ";
		//}
		return ModelElement::show() + expressions;
	}
public:
	virtual unsigned int size() {
		return _formulaExpressions->size();
	}
	virtual void setExpression(std::string index, std::string formulaExpression) {
		std::map<std::string, std::string>::iterator mapIt = _formulaExpressions->find(index);
		if (mapIt != _formulaExpressions->end()) {//found
			(*mapIt).second = formulaExpression;
		} else {//not found
			_formulaExpressions->insert({index, formulaExpression});
		}
	}
	virtual void setExpression(std::string formulaExpression) {
		setExpression("", formulaExpression);
	}
	virtual std::string expression(std::string index) {
		std::map<std::string, std::string>::iterator it = _formulaExpressions->find(index);
		if (it == _formulaExpressions->end()) {
			return ""; // index does not exist. No formula expressions returned. \todo: Should it be traced?.
		} else {
			return it->second;
		}
	}

	virtual std::string expression() {
		return expression("");
	}
	virtual double value() {
		return value("");
	}
	virtual double value(std::string index) {
		std::string strexpression = this->expression(index);
		double value = 0.0;
		try {
			value = _parentModel->parseExpression(strexpression);
		} catch (const std::exception& e) {
			_parentModel->getTracer()->traceError(e, "Error parsing formula \"" + strexpression + "\"");
		}
		return value;
	}
public: // statics
	static PluginInformation* GetPluginInformation() {
		PluginInformation* info = new PluginInformation("Formula", &Formula::LoadInstance, &Formula::CreateInstance);
		return info;
	}
	static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields) {
		Formula* newElement = new Formula(model);
		try {
			newElement->_loadInstance(fields);
		} catch (const std::exception& e) {

		}
		return newElement;
	}
	static ModelElement* CreateInstance(Model* model, std::string name) {
		return new Formula(model, name);
	}
protected: // must be overriden by derived classes
	bool _loadInstance(std::map<std::string, std::string>* fields) {
		return ModelElement::_loadInstance(fields);
	}
	std::map<std::string, std::string>* _saveInstance() {
		std::map<std::string, std::string>* fields = ModelElement::_saveInstance();
		//fields->emplace("...", std::to_string(this->_...));
		return fields;
	}
	bool _check(std::string* errorMessage) {
		std::string errorMsg = "";
		bool res, resAll = true;
		//unsigned int i = 0;
		for (std::map<std::string, std::string>::iterator it = _formulaExpressions->begin(); it != _formulaExpressions->end(); it++) {
			res = _parentModel->checkExpression((*it).second, "formula expression[" + (*it).first + "]", &errorMsg);
			if (!res) {
				_parentModel->getTracer()->trace(Util::TraceLevel::errorFatal, "Error parsing expression \"" + (*it).second + "\"");
			}
			resAll &= res;
		}
		return resAll;
	}

private:
	std::map<std::string, std::string>* _formulaExpressions = new std::map<std::string, std::string>(); // map<index,formula>
};

#endif /* FORMULA_H */

