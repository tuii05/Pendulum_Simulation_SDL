#include <cstdio>
#include <iostream>
#include "inga.h"
#include <math.h>
#include "Coords.h"


void inga::refine_dt(const xypt c0, double &dt) { // megfelelõ dt megtalálása
    double eps = 0.005;
    double phidot_1, phidot_2;
    double theta = m*L*L;
    phidot_1 = (1-k*L*L/theta*dt)*phi0-m*g*L/theta*sin(phi0);
    dt = dt/2;
    phidot_2 = (1-k*L*L/theta*dt)*phi0-m*g*L/theta*sin(phi0);
    while (fabs(phidot_1 - phidot_2) > eps) {
        phidot_1 = phidot_2;
        dt = dt/2;
        phidot_2 = (1-k*L*L/theta*dt)*phi0-m*g*L/theta*sin(phi0);
    }
    //std::cout << '\n' << "dt:" << dt << '\n';
}

double inga::iteracio(xypt &c0, double dt) { // mozgás iterációja
    double phi, phidot;
    double phi0 = c0.phi;
    double phidot0 = c0.phidot;
    double theta = m*L*L;
    double beta;
    //std::cout << "\nTest2: dt:" << dt << '\n';
    phidot = (1-k*L*L/theta*dt)*phidot0-m*g*L/theta*sin(phi0)*dt; // szögsebesség dt idõ múlva
    phi = phidot0*dt + phi0; //szögelfordulás dt idõ múlva
    beta = (phidot-phidot0)/dt;
    c0.t += dt;
    c0.x = L*sin(phi);
    c0.y = L*cos(phi);
    c0.phi = phi;
    c0.phidot = phidot;
    return beta;
}


xypt inga::ujcoords(xypt c) { //koordináták kiszámolása
    double dt = 0.1;
    double theta = m*L*L;
    double hiba = 0.01;
    //refine_dt(c, dt);
    double beta = iteracio(c, 0.02);
    return c;
}
