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

#ifndef PROBDISTRIB_IF_H
#define PROBDISTRIB_IF_H

#include <boost/math/distributions.hpp>
#include <boost/math/distributions/normal.hpp>

class ProbDistrib {
public:
    static double beta(double x, double alpha, double beta);
    static double chi2(double x, double m);
    static double erlang(double x, double shape, double scale); // int M
    static double exponential(double x, double mean);
    static double fFisher(double x, double k, double m);
    static double gamma(double x, double shape, double scale);
    static double logNormal(double x, double mean, double stddev);
    static double normal(double x, double mean, double stddev);
    static double poisson(double x, double mean);
    static double triangular(double x, double min, double mode, double max);
    static double tStudent(double x, double mean, double stddev, unsigned int degreeFreedom);
    static double uniform(double x, double min, double max);
    static double weibull(double x, double shape, double scale);
    // inverse
    static double inverseChi2(double cumulativeProbability, double m);
    static double inverseFFisher(double cumulativeProbability, double k, double m);
    static double inverseNormal(double cumulativeProbability, double mean, double stddev);
    static double inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom);

};

#endif /* PROBDISTRIB_IF_H */

