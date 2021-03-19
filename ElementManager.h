/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElementManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 12:48
 */

#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#include <list>
#include <map>
#include "List.h"
#include "ModelElement.h"

//namespace GenesysKernel {
	class Model;

	/*!
	 * The ElementManager is responsible for inserting and removing elements (ModelElement) used by components,
	 * in a consistent way.
	 * TO FIX: No direct access for insertion or deletion should be allow
	 */
	class ElementManager {
	public:
		ElementManager(Model* model);
		virtual ~ElementManager() = default;
	public:
		bool insert(ModelElement* anElement);
		void remove(ModelElement* anElement); ///< Deprected
		bool insert(std::string elementTypename, ModelElement* anElement); ///< Deprected
		void remove(std::string elementTypename, ModelElement* anElement);
		bool check(std::string elementTypename, ModelElement* anElement, std::string expressionName, std::string* errorMessage);
		bool check(std::string elementTypename, std::string elementName, std::string expressionName, bool mandatory, std::string* errorMessage);
		void clear();
	public:
		ModelElement* getElement(std::string elementTypename, Util::identification id);
		ModelElement* getElement(std::string elementTypename, std::string name);
		unsigned int getNumberOfElements(std::string elementTypename);
		unsigned int getNumberOfElements();
		int getRankOf(std::string elementTypename, std::string name); ///< returns the position (1st position=0) of the element if found, or negative value if not found
		std::list<std::string>* getElementClassnames() const;

		//private:
	public:
		// \todo: MUST BE PRIVATE
		List<ModelElement*>* getElementList(std::string elementTypename) const;
	public:
		void show();
		Model* getParentModel() const;
		bool hasChanged() const;
		void setHasChanged(bool _hasChanged);
	private:
		std::map<std::string, List<ModelElement*>*>* _elements;
		Model* _parentModel;
		bool _hasChanged = false;
	};
//namespace\\}
#endif /* ELEMENTMANAGER_H */

