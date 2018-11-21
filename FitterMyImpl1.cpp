/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FitterMyImpl1.cpp
 * Author: cancian
 * 
 * Created on 23 de Agosto de 2018, 15:36
 */

#include "FitterMyImpl1.h"

FitterMyImpl1::FitterMyImpl1() {
}

FitterMyImpl1::FitterMyImpl1(const FitterMyImpl1& orig) {
}

FitterMyImpl1::~FitterMyImpl1() {
}

bool FitterMyImpl1::isNormalDistributed(double confidencelevel) {
	
}

void FitterMyImpl1::fitUniform(double *sqrerror, double *min, double *max) {

}

void FitterMyImpl1::fitTriangular(double *sqrerror, double *min, double *mo, double *max) {

}

void FitterMyImpl1::fitNormal(double *sqrerror, double *avg, double *stddev) {

}

void FitterMyImpl1::fitExpo(double *sqrerror, double *avg1) {
}

void FitterMyImpl1::fitErlang (double *sqrerror, double *avg, double *m) {

}

void FitterMyImpl1::fitBeta (double *sqrerror, double *alpha, double *beta, double *infLimit,double *supLimit) {

}

void FitterMyImpl1::fitWeibull (double *sqrerror, double *alpha, double *scale)  {

}

void FitterMyImpl1::fitAll(double *sqrerror, std::string *name) {

}

void FitterMyImpl1::setDataFilename(std::string dataFilename) {

}

std::string FitterMyImpl1::getDataFilename() {

}
