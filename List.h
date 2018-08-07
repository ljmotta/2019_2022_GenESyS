/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TManager.h
 * Author: cancian
 *
 * Created on 21 de Junho de 2018, 12:55
 */

#ifndef LISTMANAGER_H
#define LISTMANAGER_H

#include <string>
#include <list>
#include <map>
#include <iterator>
#include "Util.h"

class Simulator;

template <typename T>
class List {
public:
public:
	List();
	List(const List& orig);
	virtual ~List();
public: // direct access to list
	unsigned int size();
	bool empty();
	void clear();
	void pop_front();
	template<class Compare> 
	void sort(Compare comp);
    std::list<T>* getList() const;
public: // new methods 
	T create();
	template<typename U>
	T create(U arg);
	std::string show();
	typename std::list<T>::iterator find(T element);
	void setCurrent(T element);
public:	// improved (easier) methods
	void insert(T element);
	void remove (T element);
	T next();
	T first();
	T last();
	T previous();
	T current();
private:
	//std::map<Util::identitifcation, T>* _map;
	std::list<T>* _list;
	typename std::list<T>::iterator _it;
};

#endif /* LISTMANAGER_H */

