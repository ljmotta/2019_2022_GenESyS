/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistenceDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 20 de Maio de 2019, 20:41
 */

#include "ModelPersistenceDefaultImpl1.h"
#include <fstream>
#include <ctime>
#include <regex>
#include "ModelComponent.h"
#include "Simulator.h"

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(Model* model) {
    _model = model;
}

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(const ModelPersistenceDefaultImpl1& orig) {
}

ModelPersistenceDefaultImpl1::~ModelPersistenceDefaultImpl1() {
}

std::map<std::string, std::string>* ModelPersistenceDefaultImpl1::_getSimulatorInfoFieldsToSave() {
    std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
    fields->emplace("typename", "SimulatorInfo");
    fields->emplace("name", _model->getParent()->getName());
    fields->emplace("version", _model->getParent()->getVersion());
    return fields;
}

std::map<std::string, std::string>* ModelPersistenceDefaultImpl1::_getModelInfosFieldsToSave() {
    std::map<std::string, std::string>* fields = new std::map<std::string, std::string>();
    fields->emplace("typename", "ModelInfo");
    fields->emplace("analystName", _model->getInfos()->getAnalystName());
    fields->emplace("description", _model->getInfos()->getDescription());
    fields->emplace("name", _model->getInfos()->getName());
    fields->emplace("numberOfReplications", std::to_string(_model->getInfos()->getNumberOfReplications()));
    fields->emplace("projectTitle", _model->getInfos()->getProjectTitle());
    fields->emplace("replicationLength", std::to_string(_model->getInfos()->getReplicationLength()));
    fields->emplace("replicationLengthTimeUnit", std::to_string(static_cast<int> (_model->getInfos()->getReplicationLengthTimeUnit())));
    fields->emplace("terminatingCondition", _model->getInfos()->getTerminatingCondition());
    fields->emplace("version", _model->getInfos()->getVersion());
    fields->emplace("warmUpTime", std::to_string(_model->getInfos()->getWarmUpPeriod()));
    fields->emplace("warmUpTimeTimeUnit", std::to_string(static_cast<int> (_model->getInfos()->getWarmUpPeriodTimeUnit())));
    return fields;
}

bool ModelPersistenceDefaultImpl1::save(std::string filename) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Saving file \"" + filename + "\"");
    Util::IncIndent();
    std::list<std::string> *simulInfosToSave, *modelInfosToSave, *modelElementsToSave, *modelComponentsToSave;
    {
	bool res = true;
	std::map<std::string, std::string>* fields;
	fields = _getSimulatorInfoFieldsToSave();
	simulInfosToSave = _adjustFieldsToSave(fields);
	// save model own infos
	fields = _getModelInfosFieldsToSave();
	modelInfosToSave = _adjustFieldsToSave(fields);
	// save infras
	modelElementsToSave = new std::list<std::string>();
	std::list<std::string>* infraTypenames = _model->getElementManager()->getElementTypenames();
	for (std::list<std::string>::iterator itTypenames = infraTypenames->begin(); itTypenames != infraTypenames->end(); itTypenames++) {
	    if ((*itTypenames) != Util::TypeOf<StatisticsCollector>()) { //CStats do NOT need to be saved
		List<ModelElement*>* infras = _model->getElementManager()->getElements((*itTypenames));
		_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing elements of type \"" + (*itTypenames) + "\":");
		Util::IncIndent();
		{
		    for (std::list<ModelElement*>::iterator it = infras->getList()->begin(); it != infras->getList()->end(); it++) {
			_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing " + (*itTypenames) + " \"" + (*it)->getName() + "\"");
			fields = (*it)->SaveInstance((*it));
			Util::IncIndent();
			modelElementsToSave->merge(*_adjustFieldsToSave(fields));
			Util::DecIndent();
		    }
		}
		Util::DecIndent();
	    }
	}
	// save components
	_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing components\":");
	//List<ModelComponent*>* components = this->_model->getComponents();
	modelComponentsToSave = new std::list<std::string>();
	Util::IncIndent();
	{
	    for (std::list<ModelComponent*>::iterator it = _model->getComponentManager()->begin(); it != _model->getComponentManager()->end(); it++) {
		fields = (*it)->SaveInstance((*it));
		Util::IncIndent();
		modelComponentsToSave->merge(*_adjustFieldsToSave(fields));
		Util::DecIndent();
	    }
	}
	Util::DecIndent();
	// SAVE FILE
	_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Saving file");
	Util::IncIndent();
	{
	    // open file
	    std::ofstream savefile;
	    savefile.open(filename, std::ofstream::out);
	    savefile << "# Genesys simulation model " << std::endl;
	    time_t now = time(0);
	    char* dt = ctime(&now);
	    savefile << "# Last saved on " << dt;
	    savefile << std::endl << "# simulator infos" << std::endl;
	    _saveContent(simulInfosToSave, &savefile);
	    savefile << std::endl << "# model infos" << std::endl;
	    _saveContent(modelInfosToSave, &savefile);
	    savefile << std::endl << "# model elements" << std::endl;
	    _saveContent(modelElementsToSave, &savefile);
	    savefile << std::endl << "# model components" << std::endl;
	    _saveContent(modelComponentsToSave, &savefile);
	    savefile.close();
	}
	Util::DecIndent();
    }
    Util::DecIndent();
}

void ModelPersistenceDefaultImpl1::_saveContent(std::list<std::string>* content, std::ofstream* file) {
    for (std::list<std::string>::iterator it = content->begin(); it != content->end(); it++) {
	*file << (*it) << std::endl;
    }
}

void ModelPersistenceDefaultImpl1::_loadFields(std::string line) {
    //std::regex regex{R"([=]+)"}; // split on space R"([\s]+)"
    std::regex regex{R"([;\s]+)"}; // split on "; ".TODO: How change it by the attribute _linefieldseparator ??
    std::sregex_token_iterator it{line.begin(), line.end(), regex, -1};
    std::vector<std::string> vecfields{it,{}};
    std::list<std::string> lstfields{it,{}};
    // separate the first field (typename)
    regex = {R"([=]+)"}; // split on "; ".TODO: How change it by the attribute _linefieldseparator ??
    it = {vecfields[0].begin(), vecfields[0].end(), regex, -1};
    std::vector<std::string> firstField{it,{}};
    if (firstField[0] == "typename") {
	lstfields.pop_front();
	if (firstField[1] == "SimulatorInfo") {
	    //this->_loadSimulatorInfoFields(lstfields);
	} else if (firstField[1] == "ModelInfo") {
	    //this->_lodModelInfosFields(lstfields);
	} else {
	    // invoke the right class to handle it
	}
    } else {
	_model->getTracer()->trace(Util::TraceLevel::errors, "Unknow format on line: " + line);
    }
}

void ModelPersistenceDefaultImpl1::_lodModelInfosFields(std::map<std::string, std::string>* fields) {
    //fields->front();
}

void ModelPersistenceDefaultImpl1::_loadSimulatorInfoFields(std::map<std::string, std::string>* fields) {
}

bool ModelPersistenceDefaultImpl1::load(std::string filename) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Loading file \"" + filename + "\"");
    Util::IncIndent();
    {
	std::ifstream modelFile;
	std::string inputLine;
	try {
	    modelFile.open(filename);
	    while (getline(modelFile, inputLine)) {
		if (inputLine.substr(0, 1) != "#" && !inputLine.empty()) {
		    _loadFields(inputLine);
		}
	    }
	    modelFile.close();
	} catch (...) {
	    _model->getTracer()->trace(Util::TraceLevel::errors, "Error loading file \"" + filename + "\"");
	}

    }
    Util::DecIndent();
}

std::list<std::string>* ModelPersistenceDefaultImpl1::_adjustFieldsToSave(std::map<std::string, std::string>* fields) {
    std::list<std::string>* newList = new std::list<std::string>();
    for (std::map<std::string, std::string>::iterator it = fields->begin(); it != fields->end(); it++) {
	std::string newStr = (*it).first + "=" + (*it).second;
	newList->push_back(newStr);
    }
    return newList;
}

bool ModelPersistenceDefaultImpl1::isSaved() {
    return _isSaved;
}
