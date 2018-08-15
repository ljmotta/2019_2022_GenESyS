/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectorImpl1.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 19:43
 */

#ifndef COLLECTORIMPL1_H
#define COLLECTORIMPL1_H

#include <string>
#include "Collector_if.h"

class CollectorImpl1 : public Collector_if {
public:
	CollectorImpl1();
	CollectorImpl1(const CollectorImpl1& orig);
	virtual ~CollectorImpl1();
public: // interface implementation
	void clear() {
	};
	void addValue(double value) {
	};
	double value(unsigned int num) {
		return 0.0;
	};
	unsigned int numElements() {
		return 0;
	};
	std::string getFilename() {
		return "";
	};
	void setFilename(std::string filename) {
	};
	
	std::string getName() {
		return _name;
	};
	
	void setName(std::string name) {
		_name = name;
	};


private:
	std::string _name;


};

#endif /* COLLECTORIMPL1_H */

