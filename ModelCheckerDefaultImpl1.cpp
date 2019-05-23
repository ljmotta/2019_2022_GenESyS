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

//bool ModelCheckerDefaultImpl1::checkAndAddInternalLiterals() {
//    /* TODO +-: not implemented yet */
//    return true;
//}

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
    _model->getTracer()->trace(Util::TraceLevel::blockArrival, "Checking symbols");
    Util::IncIndent();
    {
        // check components
        _model->getTracer()->trace(Util::TraceLevel::blockInternal, "Components:");
        Util::IncIndent();
        {
            List<ModelComponent*>* components = _model->getComponents();
            for (std::list<ModelComponent*>::iterator it = components->getList()->begin(); it != components->getList()->end(); it++) {
                res &= (*it)->Check((*it));
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
        std::string* errorMessage = new std::string();
        std::list<std::string>* elementTypes = _model->getElementManager()->getElementTypenames();
        for (std::list<std::string>::iterator typeIt = elementTypes->begin(); typeIt != elementTypes->end(); typeIt++) {
            elementType = (*typeIt);
            List<ModelElement*>* elements = _model->getElementManager()->getElements(elementType);
            for (std::list<ModelElement*>::iterator it = elements->getList()->begin(); it != elements->getList()->end(); it++) {
                element = (*it);
                // copyed from modelCOmponent. It is not inside the ModelElement::Check because ModelElement has no access to Model to call Tracer
                _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Checking " + element->getTypename() + ": " + element->getName()); //std::to_string(component->_id));
                Util::IncIndent();
                {
                    try {
                        result = element->Check((*it), errorMessage);
                        res &=result;
                        if (!res) {
                            _model->getTracer()->trace(Util::TraceLevel::errors, "Error: Checking has failed with message '" + *errorMessage + "'");
                        }
                    } catch (const std::exception& e) {
                        _model->getTracer()->traceError(e, "Error verifying component " + element->show());
                    }
                }
                Util::DecIndent();
                
                /*
                _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verifying symbols of " + elementType + " " + element->getName()); //std::to_string(component->_id));
                result = element->Check((*it), errorMessage);
                res &= result;
                if (!result) {
                    _model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Verification of symbols of component \"" + element->getName() + "\" has failed with message " + *errorMessage);
                }
                */
            }
        }
    }
    Util::DecIndent();
    return res;
}

bool ModelCheckerDefaultImpl1::checkActivationCode() {
    /* TODO +-: not implemented yet */
    return true;
}

/*
bool ModelCheckerDefaultImpl1::verifySymbol(std::string componentName, std::string expressionName, std::string expression, std::string expressionResult, bool mandatory) {
    bool res = true;
    if (mandatory && expression == "") {
        _model->getTracer()->getErrorMessages()->insert("Error verifying symbol \"" + expressionName + "\" of component \"" + componentName + "\n: Mandatory symbol is empty");
        res = false;
    }
    // TODO: Not implemented yet 
    return res;
}
*/