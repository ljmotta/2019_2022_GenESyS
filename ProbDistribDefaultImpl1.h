/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProbDistrib_if.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Agosto de 2018, 00:32
 */

#ifndef PROBDISTRIBDEFAULTIMPL1_H
#define PROBDISTRIBDEFAULTIMPL1_H

#include "Prob_Distrib_if.h"

class ProbDistribDefaultImpl1 : public ProbDistrib_if {
public:
	double beta(double x, double alpha, double beta);
	double chi2(double x, double m);
	double erlang(double x, double shape, double scale); // int M
	double exponential(double x, double mean);
	double fFisher(double x, double k, double m);
	double gamma(double x, double shape, double scale);
	double logNormal(double x, double mean, double stddev);
	double normal(double x, double mean, double stddev);
	double poisson(double x, double mean);
	double triangular(double x, double min, double mode, double max);
	double tStudent(double x, double mean, double stddev, unsigned int degreeFreedom);
	double uniform(double x, double min, double max);
	double weibull(double x, double shape, double scale);
	// inverse
	double inverseChi2(double cumulativeProbability, double m);
	double inverseFFisher(double cumulativeProbability, double k, double m);
	double inverseNormal(double cumulativeProbability, double mean, double stddev);
	double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);
	// ... 
};

#endif /* PROBDISTRIBDEFAULTIMPL1_H */

