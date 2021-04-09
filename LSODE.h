/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LSODE.h
 * Author: rlcancian
 *
 * Created on 22 de Outubro de 2019, 22:28
 */

#ifndef LSODE_H
#define LSODE_H

#include "ModelComponent.h"
#include "plugin/Formula.h"
#include "plugin/Variable.h"

/*!
 This component ...
 */
class LSODE : public ModelComponent {
public: // constructors
	LSODE(Model* model, std::string name = "");
	virtual ~LSODE() = default;
public: // virtual
	virtual std::string show();
public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
public: // g&s
	void setDiffEquations(Formula* formula);
	Formula* getDiffEquations() const;
	void setTimeVariable(Variable* _timeVariable);
	Variable* getTimeVariable() const;
	void setStep(double _step);
	double getStep() const;
	void setVariables(Variable* _variables);
	Variable* getVariables() const;
protected: // virtual
	virtual void _execute(Entity* entity);
	virtual void _initBetweenReplications();
	virtual bool _loadInstance(std::map<std::string, std::string>* fields);
	virtual std::map<std::string, std::string>* _saveInstance();
	virtual bool _check(std::string* errorMessage);
	//virtual void _createInternalElements();
private: // methods
	bool _doStep();
private: // attributes 1:1
	Formula* _diffEquations;
	Variable* _variables;
	Variable* _timeVariable;
	double _step;
private: // attributes 1:n
};

#endif /* LSODE_H */

