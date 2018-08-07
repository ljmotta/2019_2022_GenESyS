/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observable.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 14:36
 */

#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <list>

class OldObserver;

class OldObservable {
public:
	OldObservable();
	OldObservable(const OldObservable& orig);
	virtual ~OldObservable();
public:
	void addObserver(OldObserver* observer);
	void notify();
private:
	std::list<OldObserver*>* _observers;
};

#endif /* OBSERVABLE_H */

