/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ModelCheckerDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 *
 * Created on 8 de Agosto de 2018, 18:44
 */

#include "ModelCheckerDefaultImpl1.h"
#include "SourceModelComponent.h"
#include "SinkModelComponent.h"
#include "ComponentManager.h"
#include "Simulator.h"

#include <assert.h>

//using namespace GenesysKernel;

ModelCheckerDefaultImpl1::ModelCheckerDefaultImpl1(Model* model) {
	_model = model;
}

bool ModelCheckerDefaultImpl1::checkAll() {
	bool res = true;
	res &= checkSymbols();
	//res &= checkAndAddInternalLiterals();
	//res &= checkActivationCode();
	res &= checkLimits();
	res &= checkConnected();
	return res;
}

//bool ModelCheckerDefaultImpl1::checkAndAddInternalLiterals() {
//    /*  \todo: +-: not implemented yet */
//    return true;
//}

void ModelCheckerDefaultImpl1::_recursiveConnectedTo(PluginManager* pluginManager, ModelComponent* comp, List<ModelComponent*>* visited, List<ModelComponent*>* unconnected, bool* drenoFound) {
	visited->insert(comp);
	_model->tracer()->trace(Util::TraceLevel::toolDetailed, "Connected to component \"" + comp->name() + "\"");
	Plugin* plugin = pluginManager->find(comp->classname());
	assert(plugin != nullptr);
	if (plugin->pluginInfo()->isSink() || (plugin->pluginInfo()->isSendTransfer() && comp->nextComponents()->size() == 0)) {//(dynamic_cast<SinkModelComponent*> (comp) != nullptr) {
		// it is a sink OR it can send entities throught a transfer and has no nextConnections
		*drenoFound = true;
	} else { // it is not a sink
		if (comp->nextComponents()->size() == 0) {
			unconnected->insert(comp);
			_model->tracer()->trace(Util::TraceLevel::errorFatal, "Component \"" + comp->name() + "\" is unconnected (not a sink with no next componentes connected to)");
			*drenoFound = false;
		} else {
			ModelComponent* nextComp;
			for (std::list<Connection*>::iterator it = comp->nextComponents()->list()->begin(); it != comp->nextComponents()->list()->end(); it++) {
				nextComp = (*it)->first;
				if (visited->find(nextComp) == visited->list()->end()) { // not visited yet
					*drenoFound = false;
					Util::IncIndent();
					this->_recursiveConnectedTo(pluginManager, nextComp, visited, unconnected, drenoFound);
					Util::DecIndent();
				} else {
					Util::IncIndent();
					_model->tracer()->trace(Util::TraceLevel::toolDetailed, "Connected to " + nextComp->name());
					Util::DecIndent();
					*drenoFound = true;
				}
			}
		}
	}
}

bool ModelCheckerDefaultImpl1::checkConnected() {
	/*  \todo: +-: not implemented yet */
	_model->tracer()->trace(Util::TraceLevel::toolInternal, "Checking connected");
	bool resultAll = true;
	PluginManager* pluginManager = this->_model->parentSimulator()->plugins();
	Plugin* plugin;
	Util::IncIndent();
	{
		List<ModelComponent*>* visited = new List<ModelComponent*>();
		List<ModelComponent*>* unconnected = new List<ModelComponent*>();
		ModelComponent* comp;
		for (std::list<ModelComponent*>::iterator it = _model->components()->begin(); it != _model->components()->end(); it++) {
			comp = (*it);
			plugin = pluginManager->find(comp->classname());
			assert(plugin != nullptr);
			if (plugin->pluginInfo()->isSource() || plugin->pluginInfo()->isReceiveTransfer()) { //(dynamic_cast<SourceModelComponent*> (comp) != nullptr) {
				// it is a source component OR it can receive enetities from transfer
				bool drenoFound = false;
				_recursiveConnectedTo(pluginManager, comp, visited, unconnected, &drenoFound);
			}
		}
		// check if any component remais unconnected
		for (std::list<ModelComponent*>::iterator it = _model->components()->begin(); it != _model->components()->end(); it++) {
			comp = (*it);
			if (visited->find(comp) == visited->list()->end()) { //not found
				resultAll = false;
				_model->tracer()->trace(Util::TraceLevel::errorFatal, "Component \"" + comp->name() + "\" is unconnected.");
			}
		}

	}
	Util::DecIndent();
	return resultAll;
}

bool ModelCheckerDefaultImpl1::checkSymbols() {
	bool res = true;
	_model->tracer()->trace(Util::TraceLevel::toolInternal, "Checking symbols");
	Util::IncIndent();
	{
		// check components
		_model->tracer()->trace(Util::TraceLevel::toolDetailed, "Components:");
		Util::IncIndent();
		{
			//List<ModelComponent*>* components = _model->getComponents();
			for (std::list<ModelComponent*>::iterator it = _model->components()->begin(); it != _model->components()->end(); it++) {
				res &= (*it)->Check((*it));
			}
		}
		Util::DecIndent();

		// check elements
		_model->tracer()->trace(Util::TraceLevel::toolDetailed, "Elements:");
		Util::IncIndent();
		{
			std::string elementType;
			bool result;
			ModelElement* element;
			std::string* errorMessage = new std::string();
			std::list<std::string>* elementTypes = _model->elements()->elementClassnames();
			for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
				elementType = (*typeIt);
				List<ModelElement*>* elements = _model->elements()->elementList(elementType);
				for (std::list<ModelElement*>::iterator it = elements->list()->begin(); it != elements->list()->end(); it++) {
					element = (*it);
					// copyed from modelCOmponent. It is not inside the ModelElement::Check because ModelElement has no access to Model to call Tracer
					_model->tracer()->trace(Util::TraceLevel::toolDetailed, "Checking " + element->classname() + ": \"" + element->name() + "\" (id " + std::to_string(element->id()) + ")"); //std::to_string(component->_id));
					Util::IncIndent();
					{
						try {
							result = element->Check((*it), errorMessage);
							res &= result;
							if (!result) {
								_model->tracer()->trace(Util::TraceLevel::errorFatal, "Error: Checking has failed with message '" + *errorMessage + "'");
							}
						} catch (const std::exception& e) {
							_model->tracer()->traceError(e, "Error verifying component " + element->show());
						}
					}
					Util::DecIndent();
				}
			}
		}
		Util::DecIndent();
	}
	Util::DecIndent();

	return res;
}

bool ModelCheckerDefaultImpl1::checkActivationCode() {
	/*  \todo: +-: not implemented yet */
	_model->tracer()->trace(Util::TraceLevel::toolInternal, "Checking activation code");
	Util::IncIndent();
	{

	}
	Util::DecIndent();
	return true;
}

bool ModelCheckerDefaultImpl1::checkLimits() {
	bool res = true;
	std::string text;
	unsigned int value, limit;
	LicenceManager *licence = _model->parentSimulator()->licenceManager();
	_model->tracer()->trace(Util::TraceLevel::toolInternal, "Checking model limits");
	Util::IncIndent();
	{
		value = _model->components()->numberOfComponents();
		limit = licence->modelComponentsLimit();
		res &= value <= limit;
		_model->tracer()->trace("Model has " + std::to_string(value) + "/" + std::to_string(limit) + " components");
		if (!res) {
			text = "Model has " + std::to_string(_model->components()->numberOfComponents()) + " components, exceding the limit of " + std::to_string(licence->modelComponentsLimit()) + " components imposed by the current activation code";
			//_model->getTraceManager()->trace(Util::TraceLevel::errors, text);
		} else {
			value = _model->elements()->numberOfElements();
			limit = licence->modelElementsLimit();
			res &= value <= limit;
			_model->tracer()->trace("Model has " + std::to_string(value) + "/" + std::to_string(limit) + " elements");
			if (!res) {
				text = "Model has " + std::to_string(_model->elements()->numberOfElements()) + " elements, exceding the limit of " + std::to_string(licence->modelElementsLimit()) + " elements imposed by the current activation code";
				//_model->getTraceManager()->trace(Util::TraceLevel::errors, text);
			}
		}
		if (!res) {
			_model->tracer()->trace(Util::TraceLevel::errorFatal, "Error: Checking has failed with message '" + text + "'");
		}
	}
	Util::DecIndent();
	return res;
}
