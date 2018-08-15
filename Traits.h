/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Traits.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:36
 */

#ifndef TRAITS_H
#define TRAITS_H

#include "Model.h"
#include "Collector_if.h"
#include "CollectorImpl1.h"

template <typename T>
struct Traits {
    static const bool debugged = true;	
};

template <> struct Traits<Model> {
	
};

template <> struct Traits<Collector_if> {
	typedef CollectorImpl1 Collector_Impl;
};

#endif /* TRAITS_H */

