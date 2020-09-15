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

#include "ProbDistribDefaultImpl1.h"
#include <assert.h>
#include <cmath>

double ProbDistribDefaultImpl1::uniform(double x, double min, double max) {
	if (x >= min && x <= max)
		return 1.0 / (max - min);
	else
		return 0.0;
}

double ProbDistribDefaultImpl1::exponential(double x, double mean) {
	assert(x >= 0);
	return 0.0; //mean * exp(-mean * x);
}

double ProbDistribDefaultImpl1::erlang(double x, double shape, double scale) { //
	return ProbDistribDefaultImpl1::gamma(x, shape, scale); // \todo: NOT EXACTLLY THIS... REDO
}

double ProbDistribDefaultImpl1::normal(double x, double mean, double stddev) {
	double p1 = 1 / (stddev * std::sqrt(2 * M_PI));
	double rdf = (x - mean) / stddev;
	double p2 = std::exp(-0.5 * rdf * rdf);
	return p1*p2;
}

double ProbDistribDefaultImpl1::gamma(double x, double shape, double scale) {
	// gamma_distribution<> my_gamma(shape, scale);
	return 0.0; // pdf(my_gamma, x);
}

double ProbDistribDefaultImpl1::beta(double x, double alpha, double beta) {
	// beta_distribution<> my_beta(alpha, beta);
	return 0.0; // pdf(my_beta, x);
}

double ProbDistribDefaultImpl1::weibull(double x, double shape, double scale) {
	// weibull_distribution<> my_weibull(shape, scale);
	return 0.0; // pdf(my_weibull, x);
}

double ProbDistribDefaultImpl1::logNormal(double x, double mean, double stddev) {
	//lognormal_distribution<> my_lognormal(mean, stddev);
	return 0.0; // pdf(my_lognormal, x);
}

double ProbDistribDefaultImpl1::triangular(double x, double min, double mode, double max) {
	//triangular_distribution<> my_triangular(min, mode, max);
	return 0.0; // pdf(my_triangular, x);
}

double ProbDistribDefaultImpl1::tStudent(double x, double mean, double stddev, unsigned int degreeFreedom) {
	//students_t_distribution<> my_students_t(degreeFreedom);
	return 0.0; // pdf(my_students_t, x)*mean + stddev; //t-student SEEMS to be based on NORM(0,1)
}

double ProbDistribDefaultImpl1::fFisher(double x, double k, double m) {
	//fisher_f_distribution<> my_fisher_f(k, m);
	return 0.0; // pdf(my_fisher_f, x);
}

double ProbDistribDefaultImpl1::chi2(double x, double m) {
	//chi_squared_distribution<> my_chi_squared(m);
	return 0.0; // pdf(my_chi_squared, x);
}

double ProbDistribDefaultImpl1::poisson(double x, double mean) {
	//poisson_distribution<> my_poisson(mean);
	return 0.0; // pdf(my_poisson, x);
}

double ProbDistribDefaultImpl1::inverseNormal(double cumulativeProbability, double mean, double stddev) {
	//normal_distribution<> my_normal(mean, stddev);
	return 0.0; //quantile(my_normal, cumulativeProbability);
}

double ProbDistribDefaultImpl1::inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
	//students_t_distribution<> my_students_t(degreeFreedom);
	return 0.0; // quantile(my_students_t, cumulativeProbability);
}

double ProbDistribDefaultImpl1::inverseFFisher(double cumulativeProbability, double k, double m) {
	//fisher_f_distribution<> my_fisher_f(k, m);
	return 0.0; // quantile(my_fisher_f, cumulativeProbability);
}

double ProbDistribDefaultImpl1::inverseChi2(double cumulativeProbability, double m) {
	//chi_squared_distribution<> my_chi_squared(m);
	return 0.0; // quantile(my_chi_squared, cumulativeProbability);
}