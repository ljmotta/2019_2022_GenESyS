/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerMyImpl1.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 13:08
 */

#ifndef SAMPLERMYIMPL1_H
#define SAMPLERMYIMPL1_H

#include "Sampler_if.h"

class SamplerMyImpl1 : public Sampler_if {
public:

	struct MyRNG_Parameters : public RNG_Parameters {
		unsigned int seed;
		unsigned int module;
		unsigned int multiplier;
	};
public:
	SamplerMyImpl1();
	SamplerMyImpl1(const SamplerMyImpl1& orig);
	~SamplerMyImpl1();
public: // probability distributions
	double random();
	double sampleUniform(double min, double max);
	double sampleExponential(double mean);
	double sampleErlang(double mean, int M);
	double sampleNormal(double mean, double stddev);
	double sampleGamma(double mean, double alpha);
	double sampleBeta(double alpha, double beta, double infLimit, double supLimit);
	double sampleWeibull(double alpha, double scale);
	double sampleLogNormal(double mean, double stddev);
	double sampleTriangular(double min, double mode, double max);
	double sampleDiscrete(double value, double acumProb, ...);
public:
	void setRNGparameters(RNG_Parameters param);
	RNG_Parameters getRNGparameters() const;
private:
	unsigned int seed;
	unsigned int module;
	unsigned int multiplier;

};

#endif /* SAMPLERMYIMPL1_H */

