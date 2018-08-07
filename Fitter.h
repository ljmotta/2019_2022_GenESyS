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

class Fitter {
public:
	Fitter();
	Fitter(const Fitter& orig);
	virtual ~Fitter();
public:
	void fitUniform (double *sqrerror, double *min, double *max);
	void fitTriangular (double *sqrerror, double *min, double *mo, double *max);
	void fitNormal (double *sqrerror, double *avg, double *stddev);
	void fitExpo (double *sqrerror, double *avg1);
	void fitErlang (double *sqrerror, double *a, double *b, double *offset,double *mult);
	void fitBeta (double *sqrerror, double *a, double *b, double *offset,double *mult);
	void fitWeibull (double *sqrerror, double *a, double *b, double *offset, double *mult);
	void fitAll (double *sqrerror, char *name);
	
private:

};

#endif /* FITTER_H */

