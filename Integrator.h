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

class Integrator {
public:
	Integrator();
	Integrator(const Integrator& orig);
	virtual ~Integrator();
public:
	double integrate(double min, double max, double (*f)(double, double), double p1, double p2);
	double integrate(double min, double max, double (*f)(double, double,double), double p1, double p2, double p3);
	static double normal (double avg, double std);
	static double uniform (double min, double max);
	static double triangular (double min, double mode, double max);
	//...
	//continuar para as outras distribuições de probabilidade encontradas nas demais classes		
private:

};

#endif /* INTEGRATOR_H */

