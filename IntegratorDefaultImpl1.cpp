/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegratorDefaultImpl1.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 2 de Agosto de 2018, 00:44
 */

#include "IntegratorDefaultImpl1.h"
#include "Traits.h"

///https://codereview.stackexchange.com/questions/200289/implementing-numerical-integration

IntegratorDefaultImpl1::IntegratorDefaultImpl1() {
	this->_precision = Traits<Integrator_if>::Precision;
}

void IntegratorDefaultImpl1::setPrecision(double e) {
	_precision = e;
}

double IntegratorDefaultImpl1::getPrecision() {
	return _precision;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double), double p2) {
	//Rosetta::GaussLegendreQuadrature<5>();
	unsigned int c, i, m = Traits<Integrator_if>::MaxIterations;
	double x, y, h = (max - min) / m;
	double I1 = 0.0;
	for (unsigned int j = 1; j <= m + 1; j++) {
		i = j - 1;
		if (i == 0 || i == m)
			c = 1;
		else
			c = 2;
		x = min + i*h;
		y = f(x, p2);
		I1 += c*y;
	}
	return (h / 2)*I1;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double), double p2, double p3) {
	unsigned int c, i, m = Traits<Integrator_if>::MaxIterations;
	double x, y, h = (max - min) / m;
	double I1 = 0.0;
	for (unsigned int j = 1; j <= m + 1; j++) {
		i = j - 1;
		if (i == 0 || i == m)
			c = 1;
		else
			c = 2;
		x = min + i*h;
		y = f(x, p2, p3);
		I1 += c*y;
	}
	return (h / 2)*I1;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double, double), double p2, double p3, double p4) {
	unsigned int c, i, m = Traits<Integrator_if>::MaxIterations;
	double x, y, h = (max - min) / m;
	double I1 = 0.0;
	for (unsigned int j = 1; j <= m + 1; j++) {
		i = j - 1;
		if (i == 0 || i == m)
			c = 1;
		else
			c = 2;
		x = min + i*h;
		y = f(x, p2, p3, p4);
		I1 += c*y;
	}
	return (h / 2)*I1;
}

double IntegratorDefaultImpl1::integrate(double min, double max, double (*f)(double, double, double, double, double), double p2, double p3, double p4, double p5) {
	unsigned int c, i, m = Traits<Integrator_if>::MaxIterations;
	double x, y, h = (max - min) / m;
	double I1 = 0.0;
	for (unsigned int j = 1; j <= m + 1; j++) {
		i = j - 1;
		if (i == 0 || i == m)
			c = 1;
		else
			c = 2;
		x = min + i*h;
		y = f(x, p2, p3, p4, p5);
		I1 += c*y;
	}
	return (h / 2)*I1;
}

/*
double simpsonIntegral(double a, double b, int n, const std::function<double (double)> &f) {
	const double width = (b-a)/n;

	double simpson_integral = 0;
	for(int step = 0; step < n; step++) {
		const double x1 = a + step*width;
		const double x2 = a + (step+1)*width;

		simpson_integral += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
	}

	return simpson_integral;
}
 */