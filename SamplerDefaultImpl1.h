/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDefaultImpl1.h
 * Author: rafael.luiz.cancian
 *
 * Created on 2 de Maio de 2019, 01:10
 */

#ifndef SAMPLERDEFAULTIMPL1_H
#define SAMPLERDEFAULTIMPL1_H

#include "Sampler_if.h"

class SamplerDefaultImpl1 : public Sampler_if {
public:

    class DefaultImpl1RNG_Parameters : public RNG_Parameters {
    public:
        unsigned int seed = 666;
        unsigned int module = 2147483647;
        unsigned int multiplier = 950706376;
    };
public:
    SamplerDefaultImpl1();
    SamplerDefaultImpl1(const SamplerDefaultImpl1& orig);
    virtual ~SamplerDefaultImpl1();
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
    void reset(); ///< reinitialize seed and other parameters so (pseudo) random number sequence will be generated again.
public:
    void setRNGparameters(RNG_Parameters* param);
    RNG_Parameters* getRNGparameters() const;
private:
    DefaultImpl1RNG_Parameters* _param = new DefaultImpl1RNG_Parameters();
    unsigned int _seed;
    //bool _normalflag;
};

#endif /* SAMPLERDEFAULTIMPL1_H */

