/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerDummyImpl.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 23 de Agosto de 2018, 13:08
 */

#include "SamplerDummyImpl.h"
#include <iostream> //remove
#include <cmath>

SamplerDummyImpl::SamplerDummyImpl() {
}

SamplerDummyImpl::SamplerDummyImpl(const SamplerDummyImpl& orig) {
}

SamplerDummyImpl::~SamplerDummyImpl() {
}

double SamplerDummyImpl::random() {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleUniform(double min, double max) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleExponential(double mean) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleErlang(double mean, int M) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleNormal(double mean, double stddev) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleGamma(double mean, double alpha) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleWeibull(double alpha, double scale) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleLogNormal(double mean, double stddev) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleTriangular(double min, double mode, double max) {
    return 0.0; // dummy
}

double SamplerDummyImpl::sampleDiscrete(double value, double acumProb, ...) {
    return 0.0; // dummy
}

void SamplerDummyImpl::setRNGparameters(Sampler_if::RNG_Parameters* param) {
    _param = dynamic_cast<MyRNG_Parameters*> (param);
}

Sampler_if::RNG_Parameters* SamplerDummyImpl::getRNGparameters() const {
    return _param;
}
