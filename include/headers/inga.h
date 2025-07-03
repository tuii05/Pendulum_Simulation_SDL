#include <cstdio>
#include <iostream>
#include "Coords.h"
#include <stdexcept>

#ifndef INGA_H_INCLUDED
#define INGA_H_INCLUDED

//struct xypt{double x, y, phi, phidot, t;};

//typedef std::vector<xypt> Coords;

class inga {
private:
    double phi0, L, m, k; //m, k, L negat�v, akkor hiba
    const double g = 9.81;
public:
    const double pi = 3.14;
    // Inicializ�l�s
    inga (double phi0 = 0.2, double L = 1, double m = 2, double k = 0.4) {
        if (L < 0) {throw std::domain_error("Az inga hossza (L) csak nemnegativ lehet!");}
        if (m <= 0) {throw std::domain_error("Az inga t�mege (m) csak pozitiv lehet!");}
        if (k < 0) {throw std::domain_error("Az inga kozegellenallasi tenyezoje (k) csak nemnegativ lehet!");}
        this->phi0 = phi0*pi/180; this->L = L; this->m = m; this->k =k; // phi0 > 180, akkor hiba <- -sz�get adjon emg
    }
    // Ctor
    inga (inga &other) {
        phi0 = other.phi0; L = other.L; m = other.m; k = other.k;
    }
    const inga & operator=(const inga &inga) {
        phi0 = inga.phi0; L = inga.L; m = inga.m; k = inga.k;
        return *this;
    }
    //Getterek
    double getPhi0() {return phi0;}
    double getL() {return L;}
    double getM() {return m;}
    double getK() {return k;}
    //Setterek
    //Tagf�ggv�nyek
    double iteracio(xypt &c0, double dt); // er�t�rv�ny iter�ci�ja
    void refine_dt(const xypt c0, double &dt); // dt finom�t�sa, megfelel� id�pont keres�se
    xypt ujcoords(xypt c); //
    void adatok() {std::cout<< "phi: " << phi0 << " (rad), " << "L: " << L << " (m), " << "m: " << m << " (kg), " << "k: " << k << " (N*s/m) \n";}
    void graph(const Coords c);
};

#endif // INGA_H_INCLUDED
