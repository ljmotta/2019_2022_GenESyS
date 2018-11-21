   /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SamplerDanielBoso.cpp
 * Author: Daniel Boso
 *
 * Created on October 18, 2018 at 09:23
 */

#include <stdio.h>

#include "SamplerDanielBoso.h"

SamplerDanielBoso::SamplerDanielBoso() { }

SamplerDanielBoso::SamplerDanielBoso(const SamplerDanielBoso& orig) { }

SamplerDanielBoso::~SamplerDanielBoso() { }

double SamplerDanielBoso::random() {
    return ((double) rand() / (RAND_MAX));
}

double SamplerDanielBoso::sampleUniform(double min, double max) {
    return (min + ((max - min) * random()));
}

double SamplerDanielBoso::sampleExponential(double mean) {
    return (mean * (log(random())));
}

double SamplerDanielBoso::sampleErlang(double mean, int M) {
    int i;
    double p = 1;

    for(i = 0; i < M; i++) {
        p *= random();
    }

    return ((mean/M) * (-log(p)));
}

double SamplerDanielBoso::sampleNormal(double mean, double stddev) {
    double u1, u2, w, y;

    if(mean <= 0 || stddev <= 0) {
        return 0;
    }
        
    if(_normalFlag) {
            
        do {
            u1 = 2 * SamplerDanielBoso::random() - 1.0;
            u2 = (2 * random()) - 1.0;
            w  = u1 * u1 + u2 * u2;
        } while(w >= 1.0);

        y = sqrt((-2 * log(w)) / w);

        _normalResult = mean + u2 * y * stddev;
        _normalFlag = false;

        return mean + u1 * y * stddev;
        
    } else {
        _normalFlag = true;
        return _normalResult;
    }

}

double SamplerDanielBoso::gammaJonk(double alpha) {
    double r, r1, r2, x, y;

    do {
        do {
            r1 = random();
            r2 = random();
        } while((r1 > 1e-30) && (r2 > 1e-30));

        if (log10(r2) / alpha < -1e3) {
            x = 0;
        } else {
            x = exp(log(r2) / alpha);
        } 
    
    if (log(r1) / (1 - alpha) < -1e3) {
        y = 0;
    } else {
        y = exp(log(r1) / (1 - alpha));
    }
        
    } while(x + y <= 1);

    do {
        r = random();
    } while(r > 1e-20);
    
    return ((-log(r) * x) / (y + x));
}

double SamplerDanielBoso::sampleGamma(double mean, double alpha) {
    int 	i;
    double 	p;
    int		intAlpha;
    double 	ostAlpha;

    if(alpha < 1.0) {
        return ((mean / alpha) * gammaJonk(alpha));
    } else {
        if(alpha = 1.0) {
            return (mean * log(random()));
        } else {
            intAlpha = round(int(alpha));
            ostAlpha = alpha - intAlpha;

            do {
                p = 1;

                for(i = 0; i < intAlpha; i++) {
                        p *= random();
                }

            } while(p > 0);

            if(ostAlpha > 0) {
                return (mean / alpha) * ((-log(p)) + gammaJonk(ostAlpha));
            } else {
                return (mean / alpha) * (-log(p));
            }
        }
    }
}

double SamplerDanielBoso::sampleBeta(double alpha, double beta, double infLimit, double supLimit) {
    double x, y1, y2;

    if((alpha <= 0.0) or (beta <= 0.0) or (infLimit > supLimit) 
                      or (infLimit < 0) or (supLimit < 0)) {
        return 0;
    }
    
    do {
        y1 = sampleGamma(alpha, alpha);
        y2 = sampleGamma(beta, beta);
        x  = y1 / (y1 + y2);
    } while(!(x >= 0) && (x <= 1.0));

    return infLimit + (supLimit - infLimit ) * x;
}

double SamplerDanielBoso::sampleWeibull(double alpha, double scale) {
    return (exp(log(scale * (-log(random()))) / alpha));
}

double SamplerDanielBoso::sampleLogNormal(double mean, double stddev) {
    double meanNormal, dispNormal;
    dispNormal  = log((stddev * stddev) / (mean * mean) + 1.0);
    meanNormal = log(mean) - 0.5 * dispNormal;
    
    return (exp(sampleNormal(meanNormal, sqrt(dispNormal))));
}

double SamplerDanielBoso::sampleTriangular(double min, double mode, double max) {
    double part1, part2, full, r;
    part1 = mode-min;
    part2 = max-mode;
    full = max-min;
    r = random();
    
    if(r <= part1/full) {
        return(min + sqrt(part1 * full * r));
    } else {
        return(max - sqrt(part2 * full * (1.0-r)));
    }
}

// Inspired by resolution of Bruno Bonotto, Fabíola Maria Kretzer and João Vicente Souto
double SamplerDanielBoso::sampleDiscrete(double value, double acumProb, ...) {
    va_list args;
    va_start(args, acumProb);

    double lower_limit = 0;
    double index_value = value;
    double acumulated_probability = acumProb;

    double random_value = random();

    while(acumulated_probability < 1) {

        if(lower_limit <= random_value && acumulated_probability >= random_value) {
            va_end(args);
            return index_value;
        }

        index_value = va_arg(args, double);
        lower_limit = acumulated_probability;
        acumulated_probability = va_arg(args, double);
    }
    va_end(args);
    return 0;
} 

void SamplerDanielBoso::setRNGparameters(SamplerDanielBoso::RNG_Parameters* param){
	this->_param = param;
}

SamplerDanielBoso::RNG_Parameters* SamplerDanielBoso::getRNGparameters() const {
	return this->_param; 
}
