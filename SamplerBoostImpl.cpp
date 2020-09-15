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

//using namespace boost::random;

SamplerBoostImpl::SamplerBoostImpl() {
}

double SamplerBoostImpl::random() {
	//uniform_int_distribution<> dist(0.0, 1.0);
	return 0.0; // dist(_gen);
}

double SamplerBoostImpl::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleDiscrete(double acumProb, double value, ...) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleErlang(double mean, int M) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleExponential(double mean) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleGamma(double mean, double alpha) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleLogNormal(double mean, double stddev) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleNormal(double mean, double stddev) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleTriangular(double min, double mode, double max) {
    return 0.0; //dummy
}

double SamplerBoostImpl::sampleUniform(double min, double max) {
	//uniform_int_distribution<> dist(min, max);
	return 0.0; //dist(_gen);
}

double SamplerBoostImpl::sampleWeibull(double alpha, double scale) {
    return 0.0; //dummy
}

void SamplerBoostImpl::setRNGparameters(Sampler_if::RNG_Parameters* param) {

}

Sampler_if::RNG_Parameters* SamplerBoostImpl::getRNGparameters() const {
	// TODO: toimplement
}
