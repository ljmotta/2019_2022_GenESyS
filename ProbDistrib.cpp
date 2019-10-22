/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProbDistrib.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 23 de Agosto de 2018, 17:25
 */

#include "ProbDistrib.h"
#include <assert.h>
#include <cmath>
#include <complex>
#include <random>

#include <boost/math/distributions.hpp>

using namespace boost::math;

double ProbDistrib::uniform(double x, double min, double max) {
    if (x >= min && x <= max)
	return 1.0 / (max - min);
    else
	return 0.0;
}

double ProbDistrib::exponential(double x, double mean) {
    assert(x >= 0);
    return mean * exp(-mean * x);
}

double ProbDistrib::erlang(double x, double shape, double scale) { //
    return ProbDistrib::gamma(x, shape, scale); // TODO: NOT EXACTLLY THIS... REDO 
}

double ProbDistrib::normal(double x, double mean, double stddev) {
    double p1 = 1 / (stddev * std::sqrt(2 * M_PI));
    double rdf = (x - mean) / stddev;
    double p2 = std::exp(-0.5 * rdf * rdf);
    return p1*p2;
}

double ProbDistrib::gamma(double x, double shape, double scale) {
    gamma_distribution<> my_gamma(shape, scale);
    return pdf(my_gamma, x);
}

double ProbDistrib::beta(double x, double alpha, double beta) {
    beta_distribution<> my_beta(alpha, beta);
    return pdf(my_beta, x);
}

double ProbDistrib::weibull(double x, double shape, double scale) {
    weibull_distribution<> my_weibull(shape, scale);
    return pdf(my_weibull, x);
}

double ProbDistrib::logNormal(double x, double mean, double stddev) {
    lognormal_distribution<> my_lognormal(mean, stddev);
    return pdf(my_lognormal, x);
}

double ProbDistrib::triangular(double x, double min, double mode, double max) {
    triangular_distribution<> my_triangular(min, mode, max);
    return pdf(my_triangular, x);
}

double ProbDistrib::tStudent(double x, double mean, double stddev, unsigned int degreeFreedom) {
    students_t_distribution<> my_students_t(degreeFreedom);
    return pdf(my_students_t, x)*mean + stddev; //t-student SEEMS to be based on NORM(0,1)
}

double ProbDistrib::fFisher(double x, double k, double m) {
    fisher_f_distribution<> my_fisher_f(k, m);
    return pdf(my_fisher_f, x);
}

double ProbDistrib::chi2(double x, double m) {
    chi_squared_distribution<> my_chi_squared(m);
    return pdf(my_chi_squared, x);
}

double ProbDistrib::poisson(double x, double mean) {
    poisson_distribution<> my_poisson(mean);
    return pdf(my_poisson, x);
}

double ProbDistrib::inverseNormal(double cumulativeProbability, double mean, double stddev) {
    normal_distribution<> my_normal(mean, stddev);
    return quantile(my_normal, cumulativeProbability);
}

double ProbDistrib::inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
    students_t_distribution<> my_students_t(degreeFreedom);
    return quantile(my_students_t, cumulativeProbability);
}

double ProbDistrib::inverseFFisher(double cumulativeProbability, double k, double m) {
    fisher_f_distribution<> my_fisher_f(k, m);
    return quantile(my_fisher_f, cumulativeProbability);
}

double ProbDistrib::inverseChi2(double cumulativeProbability, double m) {
    chi_squared_distribution<> my_chi_squared(m);
    return quantile(my_chi_squared, cumulativeProbability);
}