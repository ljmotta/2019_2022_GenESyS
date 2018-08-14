/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fitter.h
 * Author: cancian
 *
 * Created on 7 de Agosto de 2018, 19:08
 */

#ifndef FITTER_H
#define FITTER_H

#include "Fitter_if.h"

class Fitter : public Fitter_if {
public:
	Fitter(Fitter_if* fitter_impl) {
		_fitter_impl = fitter_impl;
	};
	Fitter(const Fitter& orig);
	virtual ~Fitter();
public:
	void fitUniform(double *sqrerror, double *min, double *max) {
		_fitter_impl->fitUniform(sqrerror, min, max);
	};
	void fitTriangular(double *sqrerror, double *min, double *mo, double *max) {
		_fitter_impl->fitTriangular(sqrerror, min, mo, max);
	};
	void fitNormal(double *sqrerror, double *avg, double *stddev) {
		_fitter_impl->fitNormal(sqrerror, avg, stddev);
	};
	void fitExpo(double *sqrerror, double *avg1) {
		_fitter_impl->fitExpo(sqrerror, avg1);
	};
	void fitErlang(double *sqrerror, double *a, double *b, double *offset, double *mult) {
		_fitter_impl->fitErlang(sqrerror, a, b, offset, mult);
	};
	void fitBeta(double *sqrerror, double *a, double *b, double *offset, double *mult) {
		_fitter_impl->fitBeta(sqrerror, a, b, offset, mult);
	};
	void fitWeibull(double *sqrerror, double *a, double *b, double *offset, double *mult){
		_fitter_impl->fitWeibull(sqrerror, a, b, offset, mult);
	};
	void fitAll(double *sqrerror, char *name) {
		_fitter_impl->fitAll(sqrerror, name);
	};

private:
	Fitter_if* _fitter_impl;
};

#endif /* FITTER_H */

