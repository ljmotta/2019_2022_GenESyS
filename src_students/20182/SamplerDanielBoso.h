/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDanielBoso.h
 * Author: Daniel Boso
 * 
 * Created on October 18, 2018 at 09:22
 */

#ifndef SAMPLERDANIELBOSO_H
#define SAMPLERDANIELBOSO_H

#include <cmath>
#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <random>

#include "../../Sampler_if.h"

class SamplerDanielBoso : public Sampler_if {
public:

    class MyRNG_Parameters : public RNG_Parameters {
    public:
            unsigned int seed = 1000000000;
            unsigned int module = 2147483647;
            unsigned int multiplier = 950706376;
    };

public:
    SamplerDanielBoso();
    SamplerDanielBoso(const SamplerDanielBoso& orig);
    ~SamplerDanielBoso();
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
    double gammaJonk(double alpha);

private:
    RNG_Parameters* _param = new MyRNG_Parameters();
    bool	    _normalFlag = true;
    double          _normalResult = 0;
};

#endif /* SAMPLERDANIELBOSO_H */
