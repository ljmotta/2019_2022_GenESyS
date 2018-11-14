/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "StatisticsCancianImpl.h"
#include "ProbDistrib.h"

#include "FitterFabiola.h"
#include "Traits.h"

FitterFabiola::FitterFabiola() {  
    _collector = new Traits<Collector_if>::Implementation();
    
    _statistics = new Traits<Statistics_if>::Implementation();
    _statistics->setCollector(_collector);
}

bool FitterFabiola::isNormalDistributed(double confidencelevel) {
    double sqrerror, avg, stddev;
    
    fitNormal(&sqrerror, &avg, &stddev);

    Traits<HypothesisTester_if>::Implementation tester;
    tester.setDataFilename(_collector->getDataFilename());
    
    return tester.testAverage(confidencelevel, avg, HypothesisTester_if::EQUAL) // DEVERIA SER TESTE DO CHI2
        && tester.testVariance(confidencelevel, stddev, HypothesisTester_if::EQUAL);
}

void FitterFabiola::fitUniform (double *sqrerror, double *min, double *max){
    *min = _statistics->min();
    *max = _statistics->max();
    double sizeClass = (*max - *min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = *min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::uniform, *min, *max);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}
    
void FitterFabiola::fitTriangular (double *sqrerror, double *min, double *mo, double *max) {
    *min = _statistics->min();
    *mo = _statistics->mode();
    *max = _statistics->max();
    double sizeClass = (*max - *min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = *min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::triangular, *min, *mo, *max);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}

void FitterFabiola::fitNormal (double *sqrerror, double *avg, double *stddev) {
    *avg = _statistics->average();
    *stddev = _statistics->stddeviation();
    
    double min = _statistics->min();
    double max = _statistics->max();
    double sizeClass = (max - min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::normal, *avg, *stddev);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}

void FitterFabiola::fitExpo (double *sqrerror, double *avg1) {
    *avg1 = _statistics->average();
    
    double min = _statistics->min();
    double max = _statistics->max();
    double sizeClass = (max - min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::exponential, *avg1);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}

void FitterFabiola::fitErlang (double *sqrerror, double *avg, double *m) {
    *avg = _statistics->average();
    *m = *avg * std::pow(*avg / _statistics->stddeviation(), 2);
    
    double min = _statistics->min();
    double max = _statistics->max();
    double sizeClass = (max - min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::erlang, *avg, *m);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}

void FitterFabiola::fitBeta (double *sqrerror, double *alpha, double *beta, double *infLimit, double *supLimit) {
    *infLimit = _statistics->min();
    *supLimit = _statistics->max();
    
    double avg = _statistics->average();
    double dev = _statistics->stddeviation();
    
    *alpha = ((1 - avg) / std::pow(dev, 2) - 1 / avg) * std::pow(avg, 2);
    *beta = *alpha * (1 / avg - 1);
    
    double sizeClass = (*supLimit - *infLimit) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = *infLimit;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::beta, *alpha, *beta);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}
void FitterFabiola::fitWeibull (double *sqrerror, double *alpha, double *scale) {
    double avg = _statistics->average();
    double dev = _statistics->stddeviation();
    
    *alpha = std::pow(dev / avg, -1.086);
    *scale = avg / std::tgamma(1 + 1 / *alpha);
    
    double min = _statistics->min();
    double max = _statistics->max();
    double sizeClass = (max - min) / _statistics->histogramNumClasses();
    double elements = _statistics->numElements();
    
    double integral = 0;
    double frequency = 0;
    Traits<Integrator_if>::Implementation integrate;
    
    double a = min;
    double b = a + sizeClass;
    
    for (int i = 0; i < _statistics->histogramNumClasses(); i++) {
        integral = integrate.integrate(a, b, ProbDistrib::weibull, *alpha, *scale);
        frequency = integral * elements;
        *sqrerror = *sqrerror + (pow(_statistics->histogramClassFrequency(i) - frequency, 2) / frequency);
        a = b;
        b = b + sizeClass;
    }
}

void FitterFabiola::fitAll (double *sqrerror, std::string *name) {
    
    double error, x, p1, p2, p3, p4;
    
    fitUniform(&error, &p1, &p2);
    *name = "Uniform";
    
    fitTriangular(&x, &p1, &p2, &p3);
    
    if(x < error) {
        error = x;
        *name = "Triangular";
    }
    
    fitNormal(&x, &p1, &p2);
    
    if(x < error) {
        error = x;
        *name = "Normal";
    }
    
    fitExpo(&x, &p1);
    
    if(x < error) {
        error = x;
        *name = "Exponential";
    }
    
    fitErlang(&x, &p1, &p2);
    
    if(x < error) {
        error = x;
        *name = "Erlang";
    }
    
    fitBeta(&x, &p1, &p2, &p3, &p4);
    
    if(x < error) {
        error = x;
        *name = "Beta";
    }
    
    fitWeibull(&x, &p1, &p2);
    
    if(x < error) {
        error = x;
        *name = "Weibull";
    }
    
    *sqrerror = error; 
}

void FitterFabiola::setDataFilename(std::string dataFilename) {
    _collector->setDataFilename(dataFilename);
}

std::string FitterFabiola::getDataFilename() {
    return _collector->getDataFilename();
}