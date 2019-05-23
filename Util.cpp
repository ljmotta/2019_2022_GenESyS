/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 13:02
 */

#include <typeinfo>
#include <map>

#include "Util.h"

Util::identitifcation Util::_S_lastId = 0;
unsigned int Util::_S_indentation;
std::map<std::string, Util::identitifcation> Util::_S_lastIdOfType = std::map<std::string, Util::identitifcation>();

void Util::IncIndent() {
    Util::_S_indentation++;
}

void Util::SetIndent(unsigned short indent) {
    Util::_S_indentation=indent;
}

void Util::DecIndent() {
    Util::_S_indentation--;
}


std::string Util::Indent() {
    std::string spaces = "";
    for (unsigned int i = 0; i < Util::_S_indentation; i++) {
        spaces += "|  ";
    }
    return spaces;
}

std::string Util::SetW(std::string text, unsigned short width) {
    std::string spaces(width,' ');
    std::string result = text + spaces;
    return result.substr(0, width);
}

Util::identitifcation Util::GenerateNewId() {
    Util::_S_lastId++;
    return Util::_S_lastId;
}

Util::identitifcation Util::GenerateNewIdOfType(std::string objtype) {
    std::map<std::string, Util::identitifcation>::iterator it = Util::_S_lastIdOfType.find(objtype);
    if (it == Util::_S_lastIdOfType.end()) {
        // a new one. create the pair
        Util::_S_lastIdOfType.insert(std::pair<std::string, Util::identitifcation>(objtype, 0));
        it = Util::_S_lastIdOfType.find(objtype);
    }
    Util::identitifcation next = (*it).second;
    next++;
    (*it).second = next;
    return (*it).second;
}

double Util::TimeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2) {
    double scaleValues[] = {1.0, 1000.0, 1000.0, 1000.0, 1000.0, 60.0, 60.0, 24.0, 7.0};
    // TU_picosecond = 1, TU_microsecond = 3, TU_milisecond = 4, TU_second = 5, TU_minute = 6, TU_hour = 7, TU_day = 8, TU_week = 9
    double res = 1.0;
    int intTimeUnit1, intTimeUnit2;
    intTimeUnit1 = static_cast<int> (timeUnit1);
    intTimeUnit2 = static_cast<int> (timeUnit2);
    if (intTimeUnit1 <= intTimeUnit2) {
        for (unsigned int i = intTimeUnit1 + 1; i <= intTimeUnit2; i++) {
            res /= scaleValues[i];
        }
    } else {
        for (unsigned int i = intTimeUnit2 + 1; i <= intTimeUnit1; i++) {
            res *= scaleValues[i];
        }
    }
    return res;
}