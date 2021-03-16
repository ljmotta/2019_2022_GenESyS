/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CounterDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 29 de Maio de 2019, 11:24
 */

#ifndef COUNTERDEFAULTIMPL1_H
#define COUNTERDEFAULTIMPL1_H

#include "ModelElement.h"
#include "ElementManager.h"
#include "Plugin.h"
//namespace GenesysKernel {

	/*!
	 The Counter element is used to count events, and its internal count value is added by a configurable amount, usually incremented by one.
	 */
	class Counter : public ModelElement {
	public:
		Counter(Model* model, std::string name = "", ModelElement* parent = nullptr);
		virtual ~Counter() = default;
	public:
		virtual std::string show();
	public:
		static PluginInformation* GetPluginInformation();
		static ModelElement* LoadInstance(Model* model, std::map<std::string, std::string>* fields);
	public:
		void clear();
		void incCountValue(int value = 1);
		unsigned long getCountValue() const;
		ModelElement* getParent() const;
	protected: // from ModelElement
		virtual bool _loadInstance(std::map<std::string, std::string>* fields);
		virtual std::map<std::string, std::string>* _saveInstance();
		virtual bool _check(std::string* errorMessage);
	private:
		ModelElement* _parent;
		unsigned long _count = 0;
	};
//namespace\\}
#endif /* COUNTERDEFAULTIMPL1_H */

