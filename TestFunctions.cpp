/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestODE.cpp
 * Author: rlcancian
 * 
 * Created on 26 de Setembro de 2019, 13:00
 */

#include "TestFunctions.h"
#include "ProbDistrib.h"

#include <iostream>
#include <vector>

#include <boost/numeric/odeint.hpp>
#include <boost/math/distributions.hpp>

typedef std::vector< double > state_type;
const double gam = 0.15;

void harmonic_oscillator(const state_type &x, state_type &dxdt, const double t) {
    dxdt[0] = x[1];
    dxdt[1] = x[0] + exp(t);
}

TestODE::TestODE() {
}

int TestODE::main(int argc, char** argv) {
    using namespace std;
    using namespace boost::numeric::odeint;
    using namespace boost::math;

    //beta_distribution<>* betadist = new beta_distribution<>(2.0, 2.0);
    //betadist->alpha();
    for (double x = -2.0; x <= 2.0; x += 0.1) {
	std::cout << x << ": " << ProbDistrib::gamma(x, 2.0, 2.0) << std::endl;
    }
    //normdist->mean();
    //beta<double,double>* b = new beta<double,double>(2.0, 2.0);
    //b->

    state_type x(2);

    /*
    x[0] = 1.0; // start at x=1.0, p=0.0
    x[1] = 0.0;
    runge_kutta4< state_type > stepper;
    integrate_const(stepper, harmonic_oscillator, x, 0.0, 0.2, 0.01);
    std::cout << x[0] << " ; " << x[1] << std::endl;
     */

    /*
    x[0] = 1.0; // start at x=1.0, p=0.0
    x[1] = 0.0;
    const double dt = 0.01;
    double t;
    for (t = 0.0; t < 0.2; t += dt) {
	std::cout << t << ": " << x[0] << " ; " << x[1] << std::endl;
	stepper.do_step(harmonic_oscillator, x, t, dt);
    }
    std::cout << t << ": " << x[0] << " ; " << x[1] << std::endl;
     */

    /*
    x[0] = 1.0; // start at x=1.0, p=0.0
    x[1] = 0.0;
    typedef runge_kutta_cash_karp54< state_type > error_stepper_type;
    typedef controlled_runge_kutta< error_stepper_type > controlled_stepper_type;
    controlled_stepper_type controlled_stepper;
    //integrate_adaptive(controlled_stepper, harmonic_oscillator, x, 0.0, 0.2, 0.01);
    integrate_adaptive(make_controlled< error_stepper_type >(1.0e-20, 1.0e-16), harmonic_oscillator, x, 0.0, 0.2, 0.01);
    std::cout << x[0] << " ; " << x[1] << std::endl;
     */

    return 0;
}