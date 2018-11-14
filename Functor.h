/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Functor.h
 * Author: joaovicentesouto
 *
 * Created on November 3, 2018, 11:04 AM
 */

#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <functional>
#include "Util.h"

typedef std::function<double()> GetFunctor;
typedef std::function<void(double)> SetFunctor;

template<typename Class>
GetFunctor make_get_functor(Class * object, double (Class::*function)()) {
	return std::bind(function, object);
}

template<typename Class>
GetFunctor make_get_functor(Class * object, double (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetFunctor make_set_functor(Class * object, void (Class::*function)(double)) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename Class>
GetFunctor make_get_functor(Class * object, unsigned int (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetFunctor make_set_functor(Class * object, void (Class::*function)(unsigned int)) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename Class>
GetFunctor make_get_functor(Class * object, bool (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetFunctor make_set_functor(Class * object, void (Class::*function)(bool)) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename Class>
GetFunctor make_get_functor(Class * object, std::string (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetFunctor make_set_functor(Class * object, void (Class::*function)(std::string)) {
	return std::bind(function, object, std::placeholders::_1);
}

template<typename Class>
GetFunctor make_get_functor(Class * object, Util::TimeUnit (Class::*function)() const) {
	return std::bind(function, object);
}

template<typename Class>
SetFunctor make_set_functor(Class * object, void (Class::*function)(Util::TimeUnit)) {
	return std::bind(function, object, std::placeholders::_1);
}
#endif /* FUNCTOR_H */
