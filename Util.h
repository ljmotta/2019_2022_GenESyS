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
	static std::map<std::string, Util::identitifcation> _S_lastIdOfType;
	static Util::identitifcation GenerateNewId();

	static double TimeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2);
	//private:
	static Util::identitifcation _GenerateNewIdOfType(std::string objtyp);

public: // template implementations
	template<class T> static std::string TypeOf() {
		std::string name = typeid (T).name();
		/* TODO -: corret (remove) first chars (numbers) of the name */
		return name;
	}
	template<class T> static Util::identitifcation GenerateNewIdOfType() {
		std::string objtype = Util::TypeOf<T>();
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

private:
	Util();
	Util(const Util& orig);
	virtual ~Util();
};

#endif /* UTIL_H */

