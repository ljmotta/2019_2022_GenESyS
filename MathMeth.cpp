/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathMeth.cpp
 * Author: rlcancian
 * 
 * Created on 17 de Outubro de 2019, 17:46
 */

#include "MathMeth.h"

MathMeth::MathMeth() {
}

/*
void MathMeth::RK4step(int ndep, double dx, double &x, valarray<double> &Y, valarray<double> (*F)(double, valarray<double>)) {
	valarray<double> dY1(ndep), dY2(ndep), dY3(ndep), dY4(ndep);

	dY1 = F(x, Y) * dx;
	dY2 = F(x + 0.5 * dx, Y + 0.5 * dY1) * dx;
	dY3 = F(x + 0.5 * dx, Y + 0.5 * dY2) * dx;
	dY4 = F(x + dx, Y + dY3) * dx;
	Y += (dY1 + 2.0 * dY2 + 2.0 * dY3 + dY4) / 6.0;

	x += dx;
}
 */
