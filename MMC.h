/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MMC.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 18:22
 */

#ifndef MMC_H
#define MMC_H

#include "MMC_if.h"

class MMC : public MMC_if {
public:
	MMC(MMC_if* mmc_impl) {
		_mmc_impl = mmc_impl;
	};
	MMC(const MMC& orig);
	virtual ~MMC();
public: // probability distributions
	double random() {
		return _mmc_impl->random();
	};
	double uniform(double min, double max) {
		return _mmc_impl->uniform(min, max);
	}
	double exponential(double mean) {
		return _mmc_impl->exponential(mean);
	};
	double erlang(double mean, int M) {
		return _mmc_impl->erlang(mean, M);
	};
	double normal(double mean, double stddev){
		return _mmc_impl->normal(mean, stddev);
	};
	double gamma(double mean, double alpha){
		return _mmc_impl->gamma(mean, alpha);
	};
	double beta(double alpha, double beta, double infLimit, double supLimit){
		return _mmc_impl->beta(alpha, beta, infLimit, supLimit);
	};
	double weibull(double alpha, double scale){
		return _mmc_impl->weibull(alpha, scale);
	};
	double logNormal(double mean, double stddev){
		return _mmc_impl->logNormal(mean,stddev);
	};
	double triangular(double min, double mode, double max){
		return _mmc_impl->triangular(min, mode, max);
	};
	double discrete(double value, double acumProb, ...){
		//return _mmc_impl->;
	};
public:
	void setRNGparameters(RNG_Parameters param) {
		_mmc_impl->setRNGparameters(param);
	};
	RNG_Parameters getRNGparameters() const {
		return _mmc_impl->getRNGparameters();
	};	
private:
	MMC_if* _mmc_impl;
};

#endif /* MMC_H */

