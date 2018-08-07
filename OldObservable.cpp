/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observable.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 14:36
 */

#include <list>

#include "OldObservable.h"
#include "OldObserver.h"

OldObservable::OldObservable() {
	_observers = new std::list<OldObserver*>();
}

OldObservable::OldObservable(const OldObservable& orig) {
}

OldObservable::~OldObservable() {
}

void OldObservable::addObserver(OldObserver* observer) {
	_observers->insert(_observers->end(), observer);
}

void OldObservable::notify() {
	OldEventObserv event = OldEventObserv();
	for (std::list<OldObserver*>::iterator it=_observers->begin(); it != _observers->end(); it++) {
		(*it)->onNotify(this, event);
	}
}