/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitterMyImpl1.h
 * Author: cancian
 *
 * Created on 23 de Agosto de 2018, 15:36
 */

#ifndef FITTERMYIMPL1_H
#define FITTERMYIMPL1_H

#include "Fitter_if.h"

class FitterMyImpl1: public Fitter_if {
public:
	FitterMyImpl1();
	FitterMyImpl1(const FitterMyImpl1& orig);
	~FitterMyImpl1();
public:
	void fitUniform (double *sqrerror, double *min, double *max);
	void fitTriangular (double *sqrerror, double *min, double *mo, double *max);
	void fitNormal (double *sqrerror, double *avg, double *stddev);
	void fitExpo (double *sqrerror, double *avg1);
	void fitErlang (double *sqrerror, double *a, double *b, double *offset,double *mult);
	void fitBeta (double *sqrerror, double *a, double *b, double *offset,double *mult);
	void fitWeibull (double *sqrerror, double *a, double *b, double *offset, double *mult);
	void fitAll (double *sqrerror, std::string *name);
public:
	void setDataFilename(std::string dataFilename);
	std::string getDataFilename();
private:
	std::string _dataFilename = "";
};

#endif /* FITTERMYIMPL1_H */

