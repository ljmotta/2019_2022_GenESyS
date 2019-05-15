/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 13:02
 */

#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <typeinfo>
#include <string>
#include <cctype>

class Util {
public:
    typedef unsigned long identitifcation;
    typedef unsigned int rank;

    enum class TimeUnit : int {
        picosecond = 1,
        nanosecond = 2,
        microsecond = 3,
        milisecond = 4,
        second = 5,
        minute = 6,
        hour = 7,
        day = 8,
        week = 9
    };

    enum class TraceLevel : int {
        noTraces = 0,
        errors = 10,
        report = 20,
        simulation = 30,
        transferOnly = 40,
        blockArrival = 50,
        blockInternal = 60,
        mostDetailed = 70
    };
private:
    static Util::identitifcation _S_lastId;
    static std::map<std::string, Util::identitifcation> _S_lastIdOfType;
    static unsigned int _S_indentation;

public: // indentation ans string
    static void SetIndent(unsigned short indent);
    static void IncIndent();
    static void DecIndent();
    static std::string Indent();
    static std::string SetW(std::string text, unsigned short width); 
    
public: // identitification
    static Util::identitifcation GenerateNewId();
    static Util::identitifcation GenerateNewIdOfType(std::string objtyp);

public: // simulation support
    static double TimeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2);

public: // template implementations

    /*!
     * Return the name of the class used as T.
     */
    template<class T> static std::string TypeOf() {
        std::string name = typeid (T).name();
        /* TODO -: corret (remove) first chars (numbers) of the name */
        while (std::isdigit(name[0])) {
            name.erase(0, 1);
        }
        return name;
    }

    /*!
     * Every component or element has a unique ID for its class, but not unique for other classes. IDs are generated sequentially for each class.
     */
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

