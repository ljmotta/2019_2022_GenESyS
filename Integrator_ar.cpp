/*
 * Integratorar.cpp
 *
 *  Created on: 29 de ago de 2018
 *      Author: ribeiro
 */

#include "Integrator_ar.h"

namespace std {

Integrator_ar::Integrator_ar() {
	// TODO Auto-generated constructor stub

}

Integrator_ar::~Integrator_ar() {
	// TODO Auto-generated destructor stub
}

double Integrator_ar::integrate(double min, double max,
		double (*f)(double, double), double p2) {

	double sum = 0;
	double x[10];
	double y[10];
	int m = 1;
	double integral = -1;
	double integral_prev = -999;

	while ((integral - integral_prev) > _precision and m < 10) {

		integral_prev = integral;

		for (int i = 0; i < m; i++) {
			x[i] = (0.5 * (max - min) * t[m][i]) + (0.5 * (max + min));
			y[i] = f(x[i], p2);
			sum += c[m][i] * y[i];
		}

		double integral = 0.5 * (max - min) * sum;
		m++;
	}
	return integral;
}

double Integrator_ar::integrate(double min, double max,
		double (*f)(double, double, double), double p2, double p3) {

	double sum = 0;
	double x[10];
	double y[10];
	int m = 1;
	double integral = -1;
	double integral_prev;

	while ((integral - integral_prev) > _precision && m < 10) {

		integral_prev = integral;

		for (int i = 0; i < m; i++) {
			x[i] = (0.5 * (max - min) * t[m][i]) + (0.5 * (max + min));
			y[i] = f(x[i], p2, p3);
			sum += c[m][i] * y[i];
		}

		double integral = 0.5 * (max - min) * sum;
		m++;
	}
	return integral;
}

double Integrator_ar::integrate(double min, double max,
		double (*f)(double, double, double, double), double p2, double p3,
		double p4) {

	double sum = 0;
	double x[10];
	double y[10];
	int m = 1;
	double integral = -1;
	double integral_prev;

	while ((integral - integral_prev) > _precision && m < 10) {

		integral_prev = integral;

		for (int i = 0; i < m; i++) {
			x[i] = (0.5 * (max - min) * t[m][i]) + (0.5 * (max + min));
			y[i] = f(x[i], p2,p3,p4);
			sum += c[m][i] * y[i];
		}

		double integral = 0.5 * (max - min) * sum;
		m++;
	}
	return integral;
}
double Integrator_ar::integrate(double min, double max,
		double (*f)(double, double, double, double, double), double p2,
		double p3, double p4, double p5) {
	double sum = 0;
	double x[10];
	double y[10];
	int m = 1;
	double integral = -1;
	double integral_prev;

	while ((integral - integral_prev) > _precision && m < 10) {

		integral_prev = integral;

		for (int i = 0; i < m; i++) {
			x[i] = (0.5 * (max - min) * t[m][i]) + (0.5 * (max + min));
			y[i] = f(x[i], p2,p3,p4,p5);
			sum += c[m][i] * y[i];
		}

		double integral = 0.5 * (max - min) * sum;
		m++;
	}
	return integral;
}

} /* namespace std */

