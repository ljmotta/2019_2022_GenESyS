/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorDiogoImpl.h
 * Author: Diogo
 *
 * Created on 29 de Agosto de 2018
 */

#ifndef INTEGRATORDIOGOIMPL1_H
#define INTEGRATORDIOGOIMPL1_H

#include "Integrator_if.h"

/*
 * Utilizes Composite Simpson's method to integrate a function
 * between two points
 */
class IntegratorDiogoImpl : public Integrator_if {
public:
	IntegratorDiogoImpl();
	IntegratorDiogoImpl(const IntegratorDiogoImpl& orig);
	~IntegratorDiogoImpl();
public:
	void setPrecision(double e);
	double getPrecision();
	double integrate(double min, double max, double (*f)(double, double), double p2);
	double integrate(double min, double max, double (*f)(double, double, double), double p2, double p3);
	double integrate(double min, double max, double (*f)(double, double, double, double),  double p2, double p3, double p4);
	double integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5);
private:
	double _precision = 1e-9;
	double _n = 1000;
};

#endif /* INTEGRATORDIOGOIMPL1_H */

