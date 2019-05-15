/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelCheckerDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 8 de Maio de 2019, 18:44
 */

#include "ModelCheckerDefaultImpl1.h"

ModelCheckerDefaultImpl1::ModelCheckerDefaultImpl1(Model* model) {
    _model = model;
}

ModelCheckerDefaultImpl1::ModelCheckerDefaultImpl1(const ModelCheckerDefaultImpl1& orig) {
}

ModelCheckerDefaultImpl1::~ModelCheckerDefaultImpl1() {
}

bool ModelCheckerDefaultImpl1::checkAll() {
    bool res = true;
    res &= checkConnected();
    //res &= checkPathway();
    res &= checkSymbols();
    //res &= checkAndAddInternalLiterals();
    //res &= checkActivationCode();
    return res;
}

bool ModelCheckerDefaultImpl1::checkAndAddInternalLiterals() {
    /* TODO +-: not implemented yet */
    return true;
}

bool ModelCheckerDefaultImpl1::checkConnected() {
    /* TODO +-: not implemented yet */
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Checking connected");
    Util::IncIndent();
    {
    }
    Util::DecIndent();
    return true;
}

bool ModelCheckerDefaultImpl1::checkSymbols() {
    bool res = true;
    std::string* errorMessage; // replaced by errorMessages in model??
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Checking symbols");
    Util::IncIndent();
    {
        // check components
        _model->getTracer()->trace(Util::TraceLevel::blockInternal, "Components:");
        Util::IncIndent();
        {
            List<ModelComponent*>* components = _model->getComponents();
            for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
                res &= (*it)->VerifySymbols((*it), errorMessage);
            }
        }
        Util::DecIndent();
    }
    Util::DecIndent();

    // check elements
    _model->getTracer()->trace(Util::TraceLevel::blockInternal, "Elements:");
    Util::IncIndent();
    {
        std::string elementType;
        bool result;
        ModelElement* element;
        std::list<std::string>* elementTypes = _model->getElementManager()->getElementTypenames();
        for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
            elementType = (*typeIt);
            List<ModelElement*>* elements = _model->getElementManager()->getElements(elementType);
            for (std::list<ModelElement*>::iterator it = elements->getList()->begin(); it != elements->getList()->end(); it++) {
                element = (*it);
                _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verifying symbols of " + elementType + " " + element->getName()); //std::to_string(component->_id));
                result = element->VerifySymbols((*it), errorMessage);
                res &= result;
                if (!result) {
                    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verification of symbols of component \"" + element->getName() + "\" has failed with message " + *errorMessage);
                }
            }
        }
    }
    Util::DecIndent();
    return res;
}

bool ModelCheckerDefaultImpl1::checkPathway() {
    /* TODO +-: not implemented yet */
    return true;

}

bool ModelCheckerDefaultImpl1::checkActivationCode() {
    /* TODO +-: not implemented yet */
    return true;
}

bool ModelCheckerDefaultImpl1::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
    bool res = true;
    if (mandatory && expression == "") {
        _model->getTracer()->getErrorMessages()->insert("Error verifying symbol \"" + expressionName + "\" of component \"" + componentName + "\n: Mandatory symbol is empty");
        res = false;
    }
    /* TODO: Not implemented yet */
    return res;
}
