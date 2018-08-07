/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observer.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 14:35
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include "OldObservable.h"
#include "OldEventObserv.h"

class OldObserver {
public:
	OldObserver();
	OldObserver(const OldObserver& orig);
	virtual ~OldObserver();
public:
	virtual void onNotify(OldObservable * entity, OldEventObserv event) = 0;
private:

};

#endif /* OBSERVER_H */

