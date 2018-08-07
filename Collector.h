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

class Collector {
public:
	Collector();
	Collector(const Collector& orig);
	virtual ~Collector();
public:
	void clear();
	void addValue(double value);
	double value(unsigned int num);
	unsigned int numElements();
private:

};

#endif /* COLLECTOR_H */

