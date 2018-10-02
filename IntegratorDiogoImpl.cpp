/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorDiogoImpl.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 17:28
 */

#include "IntegratorDiogoImpl.h"

IntegratorDiogoImpl::IntegratorDiogoImpl() {
}

IntegratorDiogoImpl::IntegratorDiogoImpl(const IntegratorDiogoImpl& orig) {
}

IntegratorDiogoImpl::~IntegratorDiogoImpl() {
}

void IntegratorDiogoImpl::setPrecision(double e) {
	_precision = e;
}

double IntegratorDiogoImpl::getPrecision() {
	return _precision;
}

double IntegratorDiogoImpl::integrate(double min, double max, double (*f)(double, double), double p2) {
	double fa = f(min, p2);
    double m = (min+max)/2;
    double fm = f(m, p2);
    double fb = f(max, p2);
    double result = (max-min)*(fa+4*fm+fb)/6;
    return result;
}

double IntegratorDiogoImpl::integrate(double min, double max, double (*f)(double, double, double), double p2, double p3) {
	double fa = f(min, p2, p3);
    double m = (min+max)/2;
    double fm = f(m, p2, p3);
    double fb = f(max, p2, p3);
    double result = (max-min)*(fa+4*fm+fb)/6;
    return result;
}

double IntegratorDiogoImpl::integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4) {
	double fa = f(min, p2, p3, p4);
    double m = (min+max)/2;
    double fm = f(m, p2, p3, p4);
    double fb = f(max, p2, p3, p4);
    double result = (max-min)*(fa+4*fm+fb)/6;
    return result;
}

double IntegratorDiogoImpl::integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5) {
	double fa = f(min, p2, p3, p4, p5);
    double m = (min+max)/2;
    double fm = f(m, p2, p3, p4, p5);
    double fb = f(max, p2, p3, p4, p5);
    double result = (max-min)*(fa+4*fm+fb)/6;
    return result;
}