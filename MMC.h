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

class MMC {
public:
	MMC();
	MMC(const MMC& orig);
	virtual ~MMC();
public: // probability distributions
	double random();
	double uniform(double min, double max);
	double exponential(double mean);
	double erlang(double mean, int M);
	double normal(double mean, double stddev);
	double gamma(double mean, double alpha);
	double beta(double alpha, double beta);
	double weibull(double alpha, double scale);
	double logNormal(double mean, double stddev);
	double triangular(double min, double mode, double max);
public: // g & s
    void setModule(unsigned long _module);
    unsigned long getModule() const;
    void setMultiplier(unsigned long _multiplier);
    unsigned long getMultiplier() const;
    void setSeed(unsigned long _seed);
    unsigned long getSeed() const;
private: // attribs
	unsigned long _seed = 0;
	unsigned long _multiplier = 0;
	unsigned long _module = 0;
	bool normalFlag = true;
};

#endif /* MMC_H */

