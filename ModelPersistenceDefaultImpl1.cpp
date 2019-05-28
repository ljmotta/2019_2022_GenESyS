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
#include "ModelComponent.h"
#include "Simulator.h"

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(Model* model) {
    _model = model;
}

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(const ModelPersistenceDefaultImpl1& orig) {
}

ModelPersistenceDefaultImpl1::~ModelPersistenceDefaultImpl1() {
}

std::list<std::string>* ModelPersistenceDefaultImpl1::_getSimulatorInfoFieldsToSave() {
    std::list<std::string>* fields = new std::list<std::string>();
    fields->push_back("typename=SimulatorInfo");
    fields->push_back("name=" + _model->getParent()->getName());
    fields->push_back("version=" + _model->getParent()->getVersion());
    return fields;
}

std::list<std::string>* ModelPersistenceDefaultImpl1::_getModelInfosFieldsToSave() {
    std::list<std::string>* fields = new std::list<std::string>();
    fields->push_back("typename=ModelInfo");
    fields->push_back("analystName=" + _model->getInfos()->getAnalystName());
    fields->push_back("description=" + _model->getInfos()->getDescription());
    fields->push_back("name=" + _model->getInfos()->getName());
    fields->push_back("numberOfReplications=" + std::to_string(_model->getInfos()->getNumberOfReplications()));
    fields->push_back("projectTitle=" + _model->getInfos()->getProjectTitle());
    fields->push_back("replicationLength=" + std::to_string(_model->getInfos()->getReplicationLength()));
    fields->push_back("replicationLengthTimeUnit=" + std::to_string(static_cast<int> (_model->getInfos()->getReplicationLengthTimeUnit())));
    fields->push_back("terminatingCondition=" + _model->getInfos()->getTerminatingCondition());
    fields->push_back("version=" + _model->getInfos()->getVersion());
    fields->push_back("warmUpTime=" + std::to_string(_model->getInfos()->getWarmUpPeriod()));
    fields->push_back("warmUpTimeTimeUnit=" + std::to_string(static_cast<int> (_model->getInfos()->getWarmUpPeriodTimeUnit())));
    return fields;
}

bool ModelPersistenceDefaultImpl1::save(std::string filename) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Saving file \"" + filename + "\"");
    Util::IncIndent();
    std::list<std::string> *simulInfosToSave, *modelInfosToSave, *modelElementsToSave, *modelComponentsToSave;
    {
        bool res = true;
        std::list<std::string>* fields;
        fields = _getSimulatorInfoFieldsToSave();
        simulInfosToSave = _adjustFieldsToSaveAsTXT(fields);
        // save model own infos
        fields = _getModelInfosFieldsToSave();
        modelInfosToSave = _adjustFieldsToSaveAsTXT(fields);
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
                        modelElementsToSave->merge(*_adjustFieldsToSaveAsTXT(fields));
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
                modelComponentsToSave->merge(*_adjustFieldsToSaveAsTXT(fields));
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

bool ModelPersistenceDefaultImpl1::load(std::string filename) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "loading file \"" + filename + "\"");
    Util::IncIndent();
    {
        std::ifstream modelFile;
        std::string inputLine;
        try {
            modelFile.open(filename);
            while (getline(modelFile, inputLine)) {
                if (inputLine.substr(0, 1) != "#" && !inputLine.empty()) {
                    std::cout << inputLine << std::endl;
                }
            }
            modelFile.close();
        } catch (...) {
        }

    }
    Util::DecIndent();
}

std::list<std::string>* ModelPersistenceDefaultImpl1::_adjustFieldsToSaveAsTXT(std::list<std::string>* fields) {
    std::string line = "";
    std::string field;
    for (std::list<std::string>::iterator it = fields->begin(); it != fields->end(); it++) {
        field = (*it);
        // todo: check pointers when spliting string
        //std::string *key= new std::string();
        //std::string *value= new std::string();
        //Util::SepKeyVal(field, key, value);
        line += field + _linefieldseparator;
    }
    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, line);
    std::list<std::string>* newList = new std::list<std::string>();
    newList->insert(newList->end(), line);
    return newList;
}

bool ModelPersistenceDefaultImpl1::isSaved() {
    return _isSaved;
}
