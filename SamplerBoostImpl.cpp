/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SamplerBoostImpl.cpp
 * Author: rlcancian
 * 
 * Created on 21 de Outubro de 2019, 17:24
 */

#include "SamplerBoostImpl.h"

using namespace boost::random;

SamplerBoostImpl::SamplerBoostImpl() {
}
// default destructor

double SamplerBoostImpl::random() {
    uniform_int_distribution<> dist(0.0, 1.0);
    return dist(_gen);
}

double SamplerBoostImpl::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
}

double SamplerBoostImpl::sampleDiscrete(double acumProb, double value, ...) {
}

double SamplerBoostImpl::sampleErlang(double mean, int M) {
}

double SamplerBoostImpl::sampleExponential(double mean) {
}

double SamplerBoostImpl::sampleGamma(double mean, double alpha) {
}

double SamplerBoostImpl::sampleLogNormal(double mean, double stddev) {
}

double SamplerBoostImpl::sampleNormal(double mean, double stddev) {
}

double SamplerBoostImpl::sampleTriangular(double min, double mode, double max) {
}

double SamplerBoostImpl::sampleUniform(double min, double max) {
    uniform_int_distribution<> dist(min, max);
    return dist(_gen);
}

double SamplerBoostImpl::sampleWeibull(double alpha, double scale) {
}

void SamplerBoostImpl::setRNGparameters(Sampler_if::RNG_Parameters* param) {

}

Sampler_if::RNG_Parameters* SamplerBoostImpl::getRNGparameters() const {

}
