/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sampler.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:10
 */

#ifndef SAMPLER_H
#define SAMPLER_H

class Sampler {
public:
	Sampler();
	Sampler(const Sampler& orig);
	virtual ~Sampler();
public:
	double sampleUniform(double min, double max);	
	double sampleTriangular(double min, double mo,double max);
	double sampleNormal(double avg, double stddev);
	double sampleExpo(double period);
	double sampleErlang(double a, double b);
	double sampleBeta(double a, double b);
	double sampleWeibull(double a, double b);
	double sampleEmpiric(double *pairs);
	double random();
	void   seed(unsigned long value);	
private:

};

#endif /* SAMPLER_H */

