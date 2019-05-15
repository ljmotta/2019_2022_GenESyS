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

double ProbDistrib::gamma(double x, double mean, double alpha) {
}

double ProbDistrib::beta(double x, double alpha, double beta) {
}

double ProbDistrib::weibull(double x, double alpha, double scale) {
}

double ProbDistrib::logNormal(double x, double mean, double stddev) {
}

double ProbDistrib::triangular(double x, double min, double mode, double max) {
}

double ProbDistrib::tStudent(double x, double mean, double stddev) {
}

static double ProbDistrib::fSnedecor(double x, double u, double v) {
}

static double ProbDistrib::chi2(double x, double m) {
}