/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 13:02
 */

#include <typeinfo>
#include <map>

#include "Util.h"

Util::identitifcation Util::_S_lastId = 0;
std::map<std::string,Util::identitifcation> Util::_S_lastIdOfType = std::map<std::string,Util::identitifcation>();

Util::identitifcation Util::_S_generateNewId() {
	Util::_S_lastId++;
	return Util::_S_lastId;
}

Util::identitifcation Util::_S_generateNewIdOfType(std::string objtype) {
	std::map<std::string,Util::identitifcation>::iterator it =  Util::_S_lastIdOfType.find(objtype);
	if (it == Util::_S_lastIdOfType.end() ) {
		// a new one. create the pair
		Util::_S_lastIdOfType.insert(std::pair<std::string,Util::identitifcation>(objtype, 0));
		it =  Util::_S_lastIdOfType.find(objtype);
	}
	(*it).second = (*it).second + 1;
	return (*it).second; 
}

double Util::_S_timeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2) {
	double scaleValues[] = {1.0, 1000.0, 1000.0, 1000.0, 1000.0, 60.0, 60.0, 24.0, 7.0};
	// TU_picosecond = 1, TU_microsecond = 3, TU_milisecond = 4, TU_second = 5, TU_minute = 6, TU_hour = 7, TU_day = 8, TU_week = 9
	double res = 1.0;
	if (timeUnit1 <= timeUnit2) {
		for (unsigned int i=timeUnit1+1; i<=timeUnit2; i++) {
			res /= scaleValues[i];
		}
	} else {
		for (unsigned int i=timeUnit2+1; i<=timeUnit1; i++) {
			res *= scaleValues[i];
		}
	}
	return res;
}