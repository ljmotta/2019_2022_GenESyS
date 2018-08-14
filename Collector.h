/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collector.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:06
 */

#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "Collector_if.h"

class Collector : public Collector_if {
public:
	Collector(Collector_if* collector_impl) {
		_collector_impl = collector_impl;
	};
	Collector(const Collector& orig);
	virtual ~Collector();
public:
	void clear() {
		_collector_impl->clear();
	};
	void addValue(double value){
		_collector_impl->addValue(value);
	};
	double value(unsigned int num) {
		return _collector_impl->value(num);
	};
	unsigned int numElements() {
		return _collector_impl->numElements();
	};
	std::string getFilename() {
		return _collector_impl->getFilename();
	};
	void setFilename(std::string filename) {
		_collector_impl->setFilename(filename);
	};
private:
	Collector_if* _collector_impl;
};

#endif /* COLLECTOR_H */

