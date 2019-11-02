/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assign.h
 * Author: rafael.luiz.cancian
 *
 * Created on 31 de Agosto de 2018, 10:10
 */

#ifndef ASSIGN_H
#define ASSIGN_H

#include "ModelComponent.h"
#include "Model.h"
#include "Plugin.h"


class Assign : public ModelComponent {
public:
    /*!
     * While the assign class allows you to perform multiple assignments, the assignment class defines an assignment itself.
     */
    class Assignment {
    public:
	Assignment(std::string destination, std::string expression) {
	    this->_destination = destination;
	    this->_expression = expression;
	    // an assignment is always in the form:
	    // (destinationType) destination = expression
	};
	void setDestination(std::string _destination) {
	    this->_destination = _destination;
	}

	std::string getDestination() const {
	    return _destination;
	}

	void setExpression(std::string _expression) {
	    this->_expression = _expression;
	}

	std::string getExpression() const {
	    return _expression;
	}
    private:
	std::string _destination = "";
	std::string _expression = "";

    };
public:
    Assign(Model* model);
    virtual ~Assign() = default;
public:
    virtual std::string show();
public:
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public:
    List<Assignment*>* assignments() const;
protected:
    virtual void _execute(Entity* entity);
    virtual bool _loadInstance(std::map<std::string, std::string>* fields);
    virtual void _initBetweenReplications();
    virtual std::map<std::string, std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);
private:
private:
    List<Assignment*>* _assignments = new List<Assignment*>();
};

#endif /* ASSIGN_H */

