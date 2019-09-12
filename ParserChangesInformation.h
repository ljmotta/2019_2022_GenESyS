/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParserChangesInformation.h
 * Author: rlcancian
 *
 * Created on 11 de Setembro de 2019, 20:42
 */

#ifndef PARSERCHANGESINFORMATION_H
#define PARSERCHANGESINFORMATION_H

#include <string>
#include <list>


class ParserChangesInformation {
public:
    typedef std::string token;
    typedef std::string typeobj;
    typedef std::string lexinclude;
    typedef std::pair<std::string,std::string> production;
    typedef std::pair<std::string,std::string> lexicalelement;
public:
    ParserChangesInformation();
    ParserChangesInformation(const ParserChangesInformation& orig);
    virtual ~ParserChangesInformation();

public: // gets and sets
    void setLexicalElementToRemove(std::list<ParserChangesInformation::lexicalelement*>* _lexicalElementToRemove);
    std::list<ParserChangesInformation::lexicalelement*>* getLexicalElementToRemove() const;
    void setLexicalElementToAdd(std::list<ParserChangesInformation::lexicalelement*>* _lexicalElementToAdd);
    std::list<ParserChangesInformation::lexicalelement*>* getLexicalElementToAdd() const;
    void setLexIncludeToRemove(std::list<ParserChangesInformation::lexinclude*>* _lexIncludeToRemove);
    std::list<ParserChangesInformation::lexinclude*>* getLexIncludeToRemove() const;
    void setLexIncludeToAdd(std::list<ParserChangesInformation::lexinclude*>* _lexIncludeToAdd);
    std::list<ParserChangesInformation::lexinclude*>* getLexIncludeToAdd() const;
    void setProductionToRemove(std::list<ParserChangesInformation::production*>* _productionToRemove);
    std::list<ParserChangesInformation::production*>* getProductionToRemove() const;
    void setProductionToAdd(std::list<ParserChangesInformation::production*>* _productionToAdd);
    std::list<ParserChangesInformation::production*>* getProductionToAdd() const;
    void setTypeobjToRemove(std::list<ParserChangesInformation::typeobj*>* _typeobjToRemove);
    std::list<ParserChangesInformation::typeobj*>* getTypeobjToRemove() const;
    void setTypeobjToAdd(std::list<ParserChangesInformation::typeobj*>* _typeobjToAdd);
    std::list<ParserChangesInformation::typeobj*>* getTypeobjToAdd() const;
    void setTokensToRemove(std::list<ParserChangesInformation::token*>* _tokensToRemove);
    std::list<ParserChangesInformation::token*>* getTokensToRemove() const;
    void setTokensToAdd(std::list<ParserChangesInformation::token*>* _tokensToAdd);
    std::list<ParserChangesInformation::token*>* getTokensToAdd() const;
private:
    std::list<token*>* _tokensToAdd;
    std::list<token*>* _tokensToRemove;
    std::list<typeobj*>* _typeobjToAdd;
    std::list<typeobj*>* _typeobjToRemove;
    std::list<production*>* _productionToAdd;
    std::list<production*>* _productionToRemove;
    std::list<lexinclude*>* _lexIncludeToAdd;
    std::list<lexinclude*>* _lexIncludeToRemove;
    std::list<lexicalelement*>* _lexicalElementToAdd;
    std::list<lexicalelement*>* _lexicalElementToRemove;
    
};

#endif /* PARSERCHANGESINFORMATION_H */

