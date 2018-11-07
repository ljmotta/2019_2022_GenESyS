/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OnEventManager.h
 * Author: cancian
 *
 * Created on 7 de Novembro de 2018, 12:28
 */

#ifndef ONEVENTMANAGER_H
#define ONEVENTMANAGER_H

#include <list>

/* TODO: To implement as item (1) for DS3
 * used to get and set values no matter the class (for process analyser)
 * should be a wait to invoke a getter or setter no matter the class (a pointer to a member function without specifying the class 
 */
typedef double (*memberFunctionGetDoubleVarHandler)(); //template<> ... typedef double (T::*getDoubleVarHandler)() or something like that
typedef void (*memberFunctionSetDoubleVarHandler)(double); 


class ReplicationEvent {
public:
unsigned int getReplicationNumber() const {
	return _replicationNumber;
	}
private:
	unsigned int _replicationNumber;
};

typedef void (*replicationEventListener)(ReplicationEvent*);


class OnEventManager {
public:
	OnEventManager();
	OnEventManager(const OnEventManager& orig);
	virtual ~OnEventManager();
public: // event listeners (handlers)
	void addOnReplicationStartListener(replicationEventListener eventListener);
	void addOnReplicationEndListener(replicationEventListener eventListener);
private: // events listener
	std::list<replicationEventListener>* _onReplicationStartListeners = new std::list<replicationEventListener>();
	std::list<replicationEventListener>* _onReplicationEndListeners = new std::list<replicationEventListener>();	
private:
};

#endif /* ONEVENTMANAGER_H */

