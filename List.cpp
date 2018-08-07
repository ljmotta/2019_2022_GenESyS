/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListManager.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 12:55
 */

#include "List.h"
#include <string>

template <typename T>
List<T>::List() {
	//_map = new std::map<Util::identitifcation, T>();
	_list = new std::list<T>();
	_it = _list->begin();
}

template <typename T>
std::list<T>* List<T>::getList() const {
	return _list;
}

template <typename T>
unsigned int List<T>::size() {
	return _list->size();
}

template <typename T>
List<T>::List(const List& orig) {
}

template <typename T>
List<T>::~List() {
}

template <typename T>
std::string List<T>::show() {
	int i = 0;
	std::string text = "{";
	for (typename std::list<T>::iterator it = _list->begin(); it != _list->end(); it++, i++) {
		text += "[" + std::to_string(i) + "]=(" + (*it)->show() + "),";
	}
	text += "};";
	return text;
}

template <typename T>
void List<T>::insert(T element) {
	_it = _list->insert(_list->end(), element);
}

template <typename T>
void List<T>::pop_front() {
	typename std::list<T>::iterator itTemp = _list->begin();
	_list->pop_front();
	if (_it == itTemp) { /* TODO +: check this */
		_it = _list->begin(); // if it points to the removed element, then changes to begin
	}
}

template <typename T>
void List<T>::remove(T element) {
	_list->remove(element);
	if ((*_it) == element) { /* TODO +: check this */
		_it = _list->begin(); // if it points to the removed element, then changes to begin
	}
}

template <typename T>
T List<T>::create() {
	return new T();
}

template <typename T>
void List<T>::clear() {
	_list->clear();
}

template <typename T>
T List<T>::next() {
	_it++;
	return (*_it);

}

template <typename T>
T List<T>::current() {
	return (*_it);

}

template <typename T>
typename std::list<T>::iterator List<T>::find(T element) {
	for (typename std::list<T>::iterator it = _list->begin(); it != _list->end(); it++) {
		if ((*it) == element) {
			return it;
		}
	}
	return _list->end(); /* TODO+-: check nullptr or invalid iterator when not found */
	//return nullptr;
}

template <typename T>
void List<T>::setCurrent(T element) {
	return;
	
	/* TODO: + Seg fault? why that?? */
	
	
//	for (typename std::list<T>::iterator it=_list->begin(); it!=_list->end(); it++) {
	for (_it=_list->begin(); _it!=_list->end(); _it++) {
		if ((*_it)==element) {
			return;
		}
	}
	// ops. element was not found
	//this->_it = this->_list->iterator->end();  /* TODO +-: check this method */
	
//	typename std::list<T>::iterator it = find(element);
//	if (it != _list->end()) { /* TODO +-: attached to "find" return is nullptrt or end()? */
//		this->_it= it;
//	}
}

template <typename T>
T List<T>::first() {
	_it = _list->begin();
	return (*_it);
}

template <typename T>
T List<T>::last() {
	_it = _list->end();
	return (*_it);
}

template <typename T>
T List<T>::previous() {
	_it--;
	return (*_it);
}

template <typename T>
template<typename U>
T List<T>::create(U arg) {
	return T(arg);
}

template <typename T>
template<class Compare>
void List<T>::sort(Compare comp) {
	_list->sort(comp);
}