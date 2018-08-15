/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 13:02
 */

#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <typeinfo>
#include <string>

class Util {
public:
	typedef unsigned long identitifcation;
	typedef unsigned int rank;

	enum TimeUnit {
		TU_picosecond = 1,
		TU_nanosecond = 2,
		TU_microsecond = 3,
		TU_milisecond = 4,
		TU_second = 5,
		TU_minute = 6,
		TU_hour = 7,
		TU_day = 8,
		TU_week = 9
	};

	enum TraceLevel {
		TL_noTraces = 0,
		TL_errors = 10,
		TL_simulation = 20,
		TL_transferOnly = 30,
		TL_blockArrival = 40,
		TL_blockInternal = 50,
		TL_mostDetailed = 60
	};
public:
	static Util::identitifcation _S_lastId;
	static std::map<std::string,Util::identitifcation> _S_lastIdOfType;
	static Util::identitifcation _S_generateNewId();
	static Util::identitifcation _S_generateNewIdOfType(std::string objtyp);
	static double _S_timeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2);
//	static Util::TraceLevel _S_tracelevel;
//	static void setTraceLevel(Util::TraceLevel tracelevel);
//	static void Trace(Util::TraceLevel tracelevel, std::string text);
	
private:
	Util();
	Util(const Util& orig);
	virtual ~Util();
};

#endif /* UTIL_H */

