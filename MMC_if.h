/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MMC_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 13:20
 */

#ifndef MMC_IF_H
#define MMC_IF_H

class MMC_if {
public:
	struct RNG_Parameters{
		unsigned ling seed;
	};
public: // probability distributions
	virtual double random() = 0;
	virtual double uniform(double min, double max) = 0;
	virtual double exponential(double mean) = 0;
	virtual double erlang(double mean, int M) = 0;
	virtual double normal(double mean, double stddev) = 0;
	virtual double gamma(double mean, double alpha) = 0;
	virtual double beta(double alpha, double beta, double infLimit, double supLimit) = 0;
	virtual double weibull(double alpha, double scale) = 0;
	virtual double logNormal(double mean, double stddev) = 0;
	virtual double triangular(double min, double mode, double max) = 0;
	virtual double discrete(double value, double acumProb, ...) = 0;
public:
	virtual void setRNGparameters(RNG_Parameters param) = 0;
	virtual RNG_Parameters getRNGparameters() const = 0;
};

#endif /* MMC_IF_H */

