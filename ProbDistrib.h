/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProbDistrib.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 17:25
 */

#ifndef PROBDISTRIB_H
#define PROBDISTRIB_H

class ProbDistrib {
public:
	static double uniform(double x, double min, double max);
	static double exponential(double x, double mean);
	static double erlang(double x, double mean, double M); // int M
	static double normal(double x, double mean, double stddev);
	static double gamma(double x, double mean, double alpha);
	static double beta(double x, double alpha, double beta);
	static double weibull(double x, double alpha, double scale);
	static double logNormal(double x, double mean, double stddev);
	static double triangular(double x, double min, double mode, double max);
private:

};

#endif /* PROBDISTRIB_H */

