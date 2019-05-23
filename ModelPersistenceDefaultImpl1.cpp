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
#include "ModelComponent.h"

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(Model* model) {
    _model = model;
}

ModelPersistenceDefaultImpl1::ModelPersistenceDefaultImpl1(const ModelPersistenceDefaultImpl1& orig) {
}

ModelPersistenceDefaultImpl1::~ModelPersistenceDefaultImpl1() {
}

bool ModelPersistenceDefaultImpl1::saveAsTXT(std::string filename) {
    bool res = true;
    std::list<std::string>* words;

    // open file

    // save model own infos
    // ...

    // save components
    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing components\":");
    List<ModelComponent*>* components = this->_model->getComponents();
    Util::IncIndent();
    {
        for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
            words = (*it)->SaveInstance((*it));
            _saveLine(words, filename);
        }
    }
    Util::DecIndent();

    // save infras
    std::list<std::string>* infraTypenames = _model->getElementManager()->getElementTypenames();
    for (std::list<std::string>::iterator itTypenames = infraTypenames->begin(); itTypenames != infraTypenames->end(); itTypenames++) {
        List<ModelElement*>* infras = _model->getElementManager()->getElements((*itTypenames));
        _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing elements of type \"" + (*itTypenames) + "\":");
        Util::IncIndent();
        {
            for (std::list<ModelElement*>::iterator it = infras->getList()->begin(); it != infras->getList()->end(); it++) {
                _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Writing " + (*itTypenames) + " \"" + (*it)->getName() + "\"");
                words = (*it)->SaveInstance((*it));
                _saveLine(words, filename);
            }
        }
        Util::DecIndent();
    }

    // close file
}

bool ModelPersistenceDefaultImpl1::loadAsTXT(std::string filename) {

}

bool ModelPersistenceDefaultImpl1::saveAsXML(std::string filename) {
}

bool ModelPersistenceDefaultImpl1::loadAsXML(std::string filename) {
}

void ModelPersistenceDefaultImpl1::_saveLine(std::list<std::string>* words, std::string filename) {
    std::string line = "";
    for (std::list<std::string>::iterator it = words->begin(); it != words->end(); it++) {
        line += (*it) + " ; ";
    }
    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, line);
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
