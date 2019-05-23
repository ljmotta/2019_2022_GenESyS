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

double ProbDistrib::uniform(double x, double min, double max) {
    if (x >= min && x <= max)
        return 1.0 / (max - min);
    else
        return 0.0;
}

double ProbDistrib::exponential(double x, double mean) {
    assert(x >= 0);
    return 0;
}

double ProbDistrib::erlang(double x, double mean, double M) { //
}

double ProbDistrib::normal(double x, double mean, double stddev) {
    double p1 = 1 / (stddev * std::sqrt(2 * M_PI));
    double rdf = (x - mean) / stddev;
    double p2 = std::exp(-0.5 * rdf * rdf);
    return p1*p2;
}

double ProbDistrib::_gammaFunction(unsigned int x) {
    if (x > 1)
        return (x - 1) * _gammaFunction(x - 1);
    else
        return 1.0;
}

double ProbDistrib::_gammaFunction(double z) {
    // TODO: IT DOES NOT WORK
    double term, product;
    double gammaConst = 0.577215664901532860606512090082402431042; //Euler-Mascheroni Constant
    unsigned int n, maxIter = 1e3;
    n = 1;
    product = 1.0;
    do {
        term = (1.0 + z / n) * std::exp(-z / n);
        product *= term;
        n++;
    } while (n < maxIter);
    double value = 1 / (z * std::exp(gammaConst * z) * product);
    return value;
}

double ProbDistrib::gamma(double x, unsigned int alpha, double beta) {
    double num = std::pow(beta, alpha) * std::pow(x, alpha - 1) * std::exp(-beta * x);
    double denum = _gammaFunction(alpha);
    return num / denum;
}

/*
double ProbDistrib::gamma(double x, double k, double theta) {
    double num = std::pow(x, k - 1) * std::exp(-x/theta);
    double denum = std::exp(theta, k)*_gammaFunction(k);
    return num/denum;
}
 */

double ProbDistrib::beta(double x, double alpha, double beta) {
    double term1 = std::pow(x, alpha - 1) * std::pow(1 - x, beta - 1);
    double term2 = _gammaFunction(alpha + beta) / (_gammaFunction(alpha) * _gammaFunction(beta));
    return term1 * term2;
}

double ProbDistrib::weibull(double x, double alpha, double scale) {
}

double ProbDistrib::logNormal(double x, double mean, double stddev) {
    
}

double ProbDistrib::triangular(double x, double min, double mode, double max) {
}

double ProbDistrib::tStudent(double x, double mean, double stddev, unsigned int degreeFreedom) {
    double num = _gammaFunction((degreeFreedom + 1) / 2.0);
    double denum = std::sqrt(degreeFreedom * M_PI) * _gammaFunction(degreeFreedom / 2.0);
    double term = std::pow(1 + (x * x) / degreeFreedom, -((degreeFreedom + 1) / 2.0));
    return (num / denum)* term;
}

double ProbDistrib::fSnedecor(double x, double u, double v) {
}

double ProbDistrib::chi2(double x, double m) {
}

double ProbDistrib::inverseNormal(double cumulativeProbability, double mean, double stddev) {
}

double ProbDistrib::inverseTStudent(double cumulativeProbability, double mean, double stddev, double degreeFreedom) {
}

double ProbDistrib::inverseFSnedecor(double cumulativeProbability, double u, double v) {
}

double ProbDistrib::inverseChi2(double cumulativeProbability, double m) {
}