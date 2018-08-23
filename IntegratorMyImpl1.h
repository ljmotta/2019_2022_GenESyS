/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorMyImpl1.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 17:28
 */

#ifndef INTEGRATORMYIMPL1_H
#define INTEGRATORMYIMPL1_H

#include "Integrator_if.h"

class IntegratorMyImpl1 : public Integrator_if {
public:
	IntegratorMyImpl1();
	IntegratorMyImpl1(const IntegratorMyImpl1& orig);
	~IntegratorMyImpl1();
public:
	void setPrecision(double e);
	double getPrecision();
	double integrate(double min, double max, double (*f)(double, double), double p2);
	double integrate(double min, double max, double (*f)(double, double, double), double p2, double p3);
	double integrate(double min, double max, double (*f)(double, double, double, double),  double p2, double p3, double p4);
	double integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5);
private:
	double _precision = 1e-9;
};

#endif /* INTEGRATORMYIMPL1_H */

