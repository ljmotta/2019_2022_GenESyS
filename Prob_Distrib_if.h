/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob_Distrib_if.h
 * Author: rlcancian
 *
 * Created on 15 de setembro de 2020, 17:58
 */

#ifndef PROB_DISTRIB_IF_H
#define PROB_DISTRIB_IF_H

class ProbDistrib_if {
public:
    virtual double beta(double x, double alpha, double beta) = 0;
    virtual double chi2(double x, double m) = 0;
    virtual double erlang(double x, double shape, double scale) = 0; // int M
    virtual double exponential(double x, double mean) = 0;
    virtual double fFisher(double x, double k, double m) = 0;
    virtual double gamma(double x, double shape, double scale) = 0;
    virtual double logNormal(double x, double mean, double stddev) = 0;
    virtual double normal(double x, double mean, double stddev) = 0;
    virtual double poisson(double x, double mean) = 0;
    virtual double triangular(double x, double min, double mode, double max) = 0;
    virtual double tStudent(double x, double mean, double stddev, unsigned int degreeFreedom) = 0;
    virtual double uniform(double x, double min, double max) = 0;
    virtual double weibull(double x, double shape, double scale) = 0;
    // inverse
    virtual double inverseChi2(double cumulativeProbability, double m) = 0;
    virtual double inverseFFisher(double cumulativeProbability, double k, double m) = 0;
    virtual double inverseNormal(double cumulativeProbability, double mean, double stddev) = 0;
    virtual double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) = 0;
	// ... other inverses ... 
};

#endif /* PROB_DISTRIB_IF_H */

