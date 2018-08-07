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

class Util {
public:
	typedef unsigned long identitifcation;
	typedef unsigned int rank;

	enum TimeUnit {
		TU_picosecond = 1,
		TU_microsecond = 2,
		TU_milisecond = 3,
		TU_second = 4,
		TU_minute = 5,
		TU_hour = 6,
		TU_day = 7
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
	static Util::identitifcation generateNewId();
//	static Util::TraceLevel _S_tracelevel;
//	static void setTraceLevel(Util::TraceLevel tracelevel);
//	static void Trace(Util::TraceLevel tracelevel, std::string text);
	
private:
	Util();
	Util(const Util& orig);
	virtual ~Util();
};

#endif /* UTIL_H */

