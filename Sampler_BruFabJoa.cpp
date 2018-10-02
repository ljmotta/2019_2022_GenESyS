/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MMC_if.h
 * Author: Bruno Bonotto, Fabíola Maria Kretzer and João Vicente Souto
 *
 * Created on 14 de Agosto de 2018, 13:20
 */

#include "Sampler_BruFabJoa.h"

double Sampler_BruFabJoa::random()
{
    return ((double) rand() / (RAND_MAX));
}

/* 
 * To obtain a uniformly distributed random
 * variable using the inverse transformation technique.
*/
double Sampler_BruFabJoa::sampleUniform(double min, double max)
{
    if (min < 0 || max < 0 || max < min)
        return 0;

    return min + (max - min) * random();
}

/* 
 * To obtain a exponential distributed random
 * variable using the inverse transformation technique.
*/
double Sampler_BruFabJoa::sampleExponential(double mean)
{
    if (mean < 0)
        return 0;

    return mean * (-log(random()));
}

/*
 * When the shape parameter of the gamma density 
 * is a positive integer, the range is known as
* distribution of Erlang
*/
double Sampler_BruFabJoa::sampleErlang(double mean, int M)
{
    if (mean < 0 || M <= 0)
        return 0;

    double p = 1;
    for (int i = 0; i < M; ++i)
        p = p * random();

    return (mean / M) * -log(p);
}

double Sampler_BruFabJoa::sampleNormal(double mean, double stddev)
{
    double W;
    double U1, U2;

    if (mean <= 0 || stddev <= 0)
        return 0;

    if (_normal)
    {
        _normal = false;

        do {
            U1 = 2 * random() - 1;
            U2 = 2 * random() - 1;
            W = U1 * U1 + U2 * U2;
        } while (W >= 1);

        _normal_value = mean + U2 * sqrt((-2 * log(W)) / W) * stddev;
        
        return mean + U1 * sqrt((-2 * log(W)) / W) * stddev;
    }
    else
    {
        _normal = true;
        return _normal_value;
    }

}
            
#include <assert.h>

double Sampler_BruFabJoa::sampleGammaJonk(double alpha)
{
    double x, v1 = (exp(1) + alpha) / exp(1), v2, u1, u2;

    while (true)
    {
        u1 = random();
        u2 = random();
        v2 = v1 * u1;

        if (v2 <= 1)
        {
            x = pow(v2, 1/alpha);

            if (u2 <= exp(-x))
                return x;
        }
        else
        {
            x = -log((v1 - v2) / alpha);

            if (u2 <= pow(x, alpha - 1))
                return x;
        }
    }
}

//! Reference: http://pdg.lbl.gov/2011/reviews/rpp2011-rev-monte-carlo-techniques.pdf
double Sampler_BruFabJoa::sampleGamma(double mean, double alpha)
{
    if (mean <= 0 || alpha <= 0)
        return 0;

    if (alpha < 1)
        return (mean / alpha) * sampleGammaJonk(alpha);

    if (alpha == 1)
        return mean * (-log(random()));

    //! alpha > 1
    double c = 3 * alpha - 0.75, u1, v1, v2, x, u2, v3;

    while (true)
    {
        u1 = random();
        v1 = u1 * (1 - u1);
        v2 = (u1 - 0.5) * sqrt(c / v1);
        x = alpha + v2 - 1;

        if (x <= 0)
            continue;

        u2 = random();
        v3 = 64 * pow(v1, 3) * pow(u2, 2);

        if (v3 <= (1-(2*pow(v2, 2)/x)) || log(v3) <= 2 * ((alpha-1)*log(x/(alpha-1))-v2))
            return (mean / alpha) * x;
    }
}

double Sampler_BruFabJoa::sampleBeta(double alpha, double beta, double infLimit, double supLimit)
{
    if (alpha <= 0 || beta <= 0 || infLimit > supLimit || infLimit < 0 || supLimit < 0)
        return 0;

    double y1, y2, x;
    
    do
    {
        y1 = sampleGamma(alpha, alpha);
        y2 = sampleGamma(beta, beta);
        x = y1 / (y1 + y2);
    } while (x < 0 || x > 1);

    return infLimit + (supLimit - infLimit) * x;
}

/* 
 * It has a great variety of forms, its function of failure 
 * is monotonous, that is, it is strictly increasing, 
 * strictly decreasing or constant.
*/
double Sampler_BruFabJoa::sampleWeibull(double alpha, double scale)
{
    if (alpha <= 0 || scale <= 0)
        return 0;

    return exp(log(scale * (-log(random()))) / alpha);
}

/*
 * Is a continuous probability distribution of a random 
 * variable whose logarithm is normally distributed. 
 * Thus, if the random variable X is log-normally distributed.
*/
double Sampler_BruFabJoa::sampleLogNormal(double mean, double stddev)
{
    if (mean <= 0 || stddev <= 0)
        return 0;

    double dispNorm = log(pow(stddev,2) / pow(mean,2) + 1);
    double meanNorm = log(pow(mean,2) / sqrt(pow(mean,2) + pow(stddev,2)));

    return exp(sampleNormal(meanNorm, sqrt(dispNorm)));
}

/*
 * Is a distribution of features that has a minimum of value, a 
 * maximum value is a fashion c, a density density mode is zero 
 * for the extremes (a and b), and akin between each extreme and
 * fashion, so that the graph of it is a triangle.
*/
double Sampler_BruFabJoa::sampleTriangular(double min, double mode, double max)
{
    if (min > mode || max < mode || min > max || min < 0 || max < 0 || mode < 0)
        return 0;

    double part1 = mode - min;
    double part2 = max - mode;
    double full = max - min;
    double ran = random();

    if (ran <= part1 / full)
        return min + sqrt(part1 * full * ran);
    else
        return max - sqrt(part2 * full * (1 - ran));
}

double Sampler_BruFabJoa::sampleDiscrete(double value, double acumProb, ...)
{
    va_list args;
    va_start(args, acumProb);

    double lower_limits = 0;
    double current_value = value;
    double current_prob = acumProb;
    double ran = random();

    while (lower_limits <= 1)
    {
        if (ran >= lower_limits && ran < (lower_limits + current_prob))
        {
            va_end(args);
            return current_value;
        }

        current_value = va_arg(args, double);
        lower_limits += current_prob;
        current_prob = va_arg(args, double);
    }

    va_end(args);
    return 0;
}

void Sampler_BruFabJoa::setRNGparameters(Sampler_BruFabJoa::RNG_Parameters* param)
{
	this->_parameters = param;
}

Sampler_BruFabJoa::RNG_Parameters* Sampler_BruFabJoa::getRNGparameters() const
{
	return this->_parameters;
}
