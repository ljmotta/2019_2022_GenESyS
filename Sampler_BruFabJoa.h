/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MMC_Default.h
 * Author: Bruno Bonotto, Fabíola Kretzer e João Vicente Souto
 */

#ifndef SAMPLER_BRUFABJOA
#define SAMPLER_BRUFABJOA

#include <cstdlib>
#include <math.h>
#include <stdarg.h>

#include "Sampler_if.h"

class Sampler_BruFabJoa : public Sampler_if {
public:

	struct MyRNG_Parameters : public RNG_Parameters {
		unsigned int seed = 1234;
		unsigned int module = 2147483648;
		unsigned int multiplier = 1103515245;
	};

public:
	Sampler_BruFabJoa() = default;
	Sampler_BruFabJoa(const Sampler_BruFabJoa& orig) = delete;
	~Sampler_BruFabJoa() = default;
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
	void setRNGparameters(RNG_Parameters* param);
	RNG_Parameters* getRNGparameters() const;

private:
	double sampleGammaJonk(double alpha);

private:
	RNG_Parameters* _parameters = new MyRNG_Parameters();
	double _normal_value = 0;
	bool _normal = true;

};

#endif /* MMC_Default_H */
