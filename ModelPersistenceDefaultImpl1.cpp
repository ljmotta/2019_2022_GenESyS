/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelPersistenceDefaultImpl1.cpp
 * Author: rlcancian
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

std::list<std::string>* ModelPersistenceDefaultImpl1::_saveSimulatorInfo() {
    std::list<std::string>* words = new std::list<std::string>();
    words->insert(words->end(), "SimulatorInfo");
    words->insert(words->end(), _model->getParent()->getName());
    words->insert(words->end(), _model->getParent()->getVersion());
    return words;
}

std::list<std::string>* ModelPersistenceDefaultImpl1::_saveModelInfo() {
    std::list<std::string>* words = new std::list<std::string>();
    words->insert(words->end(), "ModelInfo");
    words->insert(words->end(), _model->getInfos()->getAnalystName());
    words->insert(words->end(), _model->getInfos()->getDescription());
    words->insert(words->end(), _model->getInfos()->getName());
    words->insert(words->end(), std::to_string(_model->getInfos()->getNumberOfReplications()));
    words->insert(words->end(), _model->getInfos()->getProjectTitle());
    words->insert(words->end(), std::to_string(_model->getInfos()->getReplicationLength()));
    words->insert(words->end(), std::to_string(static_cast<int> (_model->getInfos()->getReplicationLengthTimeUnit())));
    words->insert(words->end(), _model->getInfos()->getTerminatingCondition());
    words->insert(words->end(), _model->getInfos()->getVersion());
    words->insert(words->end(), std::to_string(_model->getInfos()->getWarmUpPeriod()));
    words->insert(words->end(), std::to_string(static_cast<int> (_model->getInfos()->getWarmUpPeriodTimeUnit())));
    return words;
}

bool ModelPersistenceDefaultImpl1::saveAsTXT(std::string filename) {
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Saving file \"" + filename + "\"");
    Util::IncIndent();
    {
        bool res = true;
        std::list<std::string>* words;
        // open file
        std::ofstream savefile;
        savefile.open(filename, std::ofstream::out);
        // save basic infos about simulator, data, etc
        savefile << "#" << std::endl;
        savefile << "# Genesys simulation model " << std::endl;
        time_t now = time(0);
        char* dt = ctime(&now);
        savefile << "# " << dt << std::endl;
        savefile << "# simulator infos" << std::endl;
        words = _saveSimulatorInfo();
        _saveLine(words, &savefile);
        // save model own infos
        savefile << "# model infos" << std::endl;
        words = _saveModelInfo();
        _saveLine(words, &savefile);
        // save infras
        savefile << "# model elements" << std::endl;
        std::list<std::string>* infraTypenames = _model->getElementManager()->getElementTypenames();
        for (std::list<std::string>::iterator itTypenames = infraTypenames->begin(); itTypenames != infraTypenames->end(); itTypenames++) {
            List<ModelElement*>* infras = _model->getElementManager()->getElements((*itTypenames));
            _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing elements of type \"" + (*itTypenames) + "\":");
            Util::IncIndent();
            {
                for (std::list<ModelElement*>::iterator it = infras->getList()->begin(); it != infras->getList()->end(); it++) {
                    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing " + (*itTypenames) + " \"" + (*it)->getName() + "\"");
                    words = (*it)->SaveInstance((*it));
                    Util::IncIndent();
                    _saveLine(words, &savefile);
                    Util::DecIndent();
                }
            }
            Util::DecIndent();
        }
        // save components
        savefile << "# model components" << std::endl;
        _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing components\":");
        List<ModelComponent*>* components = this->_model->getComponents();
        Util::IncIndent();
        {
            for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
                words = (*it)->SaveInstance((*it));
                Util::IncIndent();
                _saveLine(words, &savefile);
                Util::DecIndent();
            }
        }
        Util::DecIndent();
        // close file
        savefile.close();
    }
    Util::DecIndent();
}

bool ModelPersistenceDefaultImpl1::loadAsTXT(std::string filename) {

}

bool ModelPersistenceDefaultImpl1::saveAsXML(std::string filename) {
}

bool ModelPersistenceDefaultImpl1::loadAsXML(std::string filename) {
}

void ModelPersistenceDefaultImpl1::_saveLine(std::list<std::string>* words, std::ofstream* savefile) {
    std::string line = "";
    for (std::list<std::string>::iterator it = words->begin(); it != words->end(); it++) {
        line += (*it) + _linefieldseparator;
    }
    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, line);
    *savefile << line << std::endl;
}

bool ModelPersistenceDefaultImpl1::save(std::string filename) {
    return this->saveAsTXT(filename);
}

bool ModelPersistenceDefaultImpl1::load(std::string filename) {
    return this->loadAsTXT(filename);
}

bool ModelPersistenceDefaultImpl1::isSaved() {
    return _isSaved;
}
