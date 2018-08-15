/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Integrator_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 13:54
 */

#ifndef INTEGRATOR_IF_H
#define INTEGRATOR_IF_H

class Integrator_if {
public:
	virtual double integrate(double min, double max, double (*f)(double), double p1) = 0;
	virtual double integrate(double min, double max, double (*f)(double, double), double p1, double p2) = 0;
	virtual double integrate(double min, double max, double (*f)(double, double,double), double p1, double p2, double p3) = 0;
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
};

#endif /* INTEGRATOR_IF_H */

