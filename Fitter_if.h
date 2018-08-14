/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fitter_if.h
 * Author: cancian
 *
 * Created on 14 de Agosto de 2018, 14:05
 */

#ifndef FITTER_IF_H
#define FITTER_IF_H

#include <string>

class Fitter_if {
public:
	virtual void fitUniform (double *sqrerror, double *min, double *max) = 0;
	virtual void fitTriangular (double *sqrerror, double *min, double *mo, double *max) = 0;
	virtual void fitNormal (double *sqrerror, double *avg, double *stddev) = 0;
	virtual void fitExpo (double *sqrerror, double *avg1) = 0;
	virtual void fitErlang (double *sqrerror, double *a, double *b, double *offset,double *mult) = 0;
	virtual void fitBeta (double *sqrerror, double *a, double *b, double *offset,double *mult) = 0;
	virtual void fitWeibull (double *sqrerror, double *a, double *b, double *offset, double *mult) = 0;
	virtual void fitAll (double *sqrerror, std::string *name) = 0;
};

#endif /* FITTER_IF_H */

