/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserChangesInformation.cpp
 * Author: rlcancian
 * 
 * Created on 11 de Setembro de 2019, 20:42
 */

#include "ParserChangesInformation.h"

ParserChangesInformation::ParserChangesInformation() {
}

ParserChangesInformation::ParserChangesInformation(const ParserChangesInformation& orig) {
}

ParserChangesInformation::~ParserChangesInformation() {
}

void ParserChangesInformation::setLexicalElementToRemove(std::list<ParserChangesInformation::lexicalelement*>* _lexicalElementToRemove) {
    this->_lexicalElementToRemove = _lexicalElementToRemove;
}

std::list<ParserChangesInformation::ParserChangesInformation::lexicalelement*>* ParserChangesInformation::getLexicalElementToRemove() const {
    return _lexicalElementToRemove;
}

void ParserChangesInformation::setLexicalElementToAdd(std::list<ParserChangesInformation::ParserChangesInformation::lexicalelement*>* _lexicalElementToAdd) {
    this->_lexicalElementToAdd = _lexicalElementToAdd;
}

std::list<ParserChangesInformation::lexicalelement*>* ParserChangesInformation::getLexicalElementToAdd() const {
    return _lexicalElementToAdd;
}

void ParserChangesInformation::setLexIncludeToRemove(std::list<ParserChangesInformation::lexinclude*>* _lexIncludeToRemove) {
    this->_lexIncludeToRemove = _lexIncludeToRemove;
}

std::list<ParserChangesInformation::lexinclude*>* ParserChangesInformation::getLexIncludeToRemove() const {
    return _lexIncludeToRemove;
}

void ParserChangesInformation::setLexIncludeToAdd(std::list<ParserChangesInformation::lexinclude*>* _lexIncludeToAdd) {
    this->_lexIncludeToAdd = _lexIncludeToAdd;
}

std::list<ParserChangesInformation::lexinclude*>* ParserChangesInformation::getLexIncludeToAdd() const {
    return _lexIncludeToAdd;
}

void ParserChangesInformation::setProductionToRemove(std::list<ParserChangesInformation::production*>* _productionToRemove) {
    this->_productionToRemove = _productionToRemove;
}

std::list<ParserChangesInformation::production*>* ParserChangesInformation::getProductionToRemove() const {
    return _productionToRemove;
}

void ParserChangesInformation::setProductionToAdd(std::list<ParserChangesInformation::production*>* _productionToAdd) {
    this->_productionToAdd = _productionToAdd;
}

std::list<ParserChangesInformation::production*>* ParserChangesInformation::getProductionToAdd() const {
    return _productionToAdd;
}

void ParserChangesInformation::setTypeobjToRemove(std::list<ParserChangesInformation::typeobj*>* _typeobjToRemove) {
    this->_typeobjToRemove = _typeobjToRemove;
}

std::list<ParserChangesInformation::typeobj*>* ParserChangesInformation::getTypeobjToRemove() const {
    return _typeobjToRemove;
}

void ParserChangesInformation::setTypeobjToAdd(std::list<ParserChangesInformation::typeobj*>* _typeobjToAdd) {
    this->_typeobjToAdd = _typeobjToAdd;
}

std::list<ParserChangesInformation::typeobj*>* ParserChangesInformation::getTypeobjToAdd() const {
    return _typeobjToAdd;
}

void ParserChangesInformation::setTokensToRemove(std::list<ParserChangesInformation::token*>* _tokensToRemove) {
    this->_tokensToRemove = _tokensToRemove;
}

std::list<ParserChangesInformation::token*>* ParserChangesInformation::getTokensToRemove() const {
    return _tokensToRemove;
}

void ParserChangesInformation::setTokensToAdd(std::list<ParserChangesInformation::token*>* _tokensToAdd) {
    this->_tokensToAdd = _tokensToAdd;
}

std::list<ParserChangesInformation::token*>* ParserChangesInformation::getTokensToAdd() const {
    return _tokensToAdd;
}

