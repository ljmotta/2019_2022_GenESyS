/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitterJoaoSouto.h
 * Author: joaovicentesouto
 *
 * Created on October 13, 2018, 9:10 PM
 */

#ifndef FITTERJOAOSOUTO_H
#define FITTERJOAOSOUTO_H

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <cmath>
#include <vector>

#include "../../Fitter_if.h"
#include "../../Traits.h"
#include "../../ProbDistrib.h"

class FitterJoaoSouto: public Fitter_if
{
public:
	FitterJoaoSouto() = default;
	FitterJoaoSouto(const FitterJoaoSouto& orig) = default;
	~FitterJoaoSouto() = default;
public:
	bool isNormalDistributed(double confidencelevel);
	void fitUniform(double *sqrerror, double *min, double *max);
	void fitTriangular(double *sqrerror, double *min, double *mo, double *max);
	void fitNormal(double *sqrerror, double *avg, double *stddev);
	void fitExpo(double *sqrerror, double *avg1);
	void fitErlang(double *sqrerror, double *avg, int *m);
	void fitBeta(double *sqrerror, double *alpha, double *beta, double *infLimit, double *supLimit);
	void fitWeibull(double *sqrerror, double *alpha, double *scale);
	void fitAll(double *sqrerror, std::string *name);
public:
	void setDataFilename(std::string dataFilename);
	std::string getDataFilename();

private:
	void initStats();

	template<typename F, typename ... Args>
	double square_error(F f, Args ... args);
	
private:
	std::string _dataFilename{""};
	Traits<Statistics_if>::Implementation * _stats{nullptr};
    Traits<Collector_if>::Implementation * _collector{nullptr};
};

template<typename F, typename ... Args>
double FitterJoaoSouto::square_error(F f, Args ... args)
{
    if (!_stats)
        return std::numeric_limits<double>::max();

    double error = 0;
    double range = (_stats->max() - _stats->min()) / _stats->histogramNumClasses();
    double i = _stats->min();
    double j = i + range;
    double total_elements = _stats->numElements();

    Traits<Integrator_if>::Implementation integrator;

    for (auto c = 0; c < _stats->histogramNumClasses(); c++, i = j, j += range)
    {
        double area = integrator.integrate(i, j, f, args...);
        error += pow(_stats->histogramClassFrequency(c) / total_elements - area, 2);
    }

    return error;
}

#endif /* FITTERJOAOSOUTO_H */
