/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Integrator.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:09
 */

#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Integrator_if.h"

class Integrator : public Integrator_if {
public:
	Integrator(Integrator_if* integrator_impl) {
		_integrator_impl = integrator_impl;
	};
	Integrator(const Integrator& orig);
	virtual ~Integrator();
public:
	double integrate(double min, double max, double (*f)(double), double p1) {
		return _integrator_impl->integrate(min, max, f, p1);
	};
	double integrate(double min, double max, double (*f)(double, double), double p1, double p2) {
		return _integrator_impl->integrate(min, max, f, p1, p2);
	};
	double integrate(double min, double max, double (*f)(double, double, double), double p1, double p2, double p3) {
		return _integrator_impl->integrate(min, max, f, p1, p2, p3);
	};
public:
	static double uniform(double min, double max);
	static double exponential(double mean);
	static double erlang(double mean, int M);
	static double normal(double mean, double stddev);
	static double gamma(double mean, double alpha);
	static double beta(double alpha, double beta);
	static double weibull(double alpha, double scale);
	static double logNormal(double mean, double stddev);
	static double triangular(double min, double mode, double max);
private:
	Integrator_if* _integrator_impl;
};

#endif /* INTEGRATOR_H */

