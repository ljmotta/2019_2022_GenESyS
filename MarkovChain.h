/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MarkovChain.h
 * Author: rlcancian
 *
 * Created on 24 de Outubro de 2019, 18:26
 */

#ifndef MARKOVCHAIN_H
#define MARKOVCHAIN_H

#include "ModelComponent.h"
#include "plugin/Variable.h"
#include "Sampler_if.h"

class MarkovChain : public ModelComponent {
public: // constructors
	MarkovChain(Model* model, std::string name = "");
	virtual ~MarkovChain() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public: // get and set
	void setTransitionProbabilityMatrix(Variable* _transitionMatrix);
	Variable* getTransitionMatrix() const;
	Variable* getCurrentState() const;
	void setInitialDistribution(Variable* _initialDistribution);
	Variable* getInitialState() const;
	void setInitilized(bool _initilized);
	bool isInitilized() const;
	void setCurrentState(Variable* _currentState);
protected: // virtual
	virtual void _execute(Entity* entity);
	virtual void _initBetweenReplications();
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
private: // methods
private: // attributes 1:1
	Variable* _transitionProbMatrix;
	Variable* _initialDistribution;
	Variable* _currentState;
	bool _initilized = false;
private: // attributes 1:n
	Sampler_if* _sampler;
};

#endif /* MARKOVCHAIN_H */

