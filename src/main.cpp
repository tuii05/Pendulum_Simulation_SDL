#include <iostream>
#include <cstdio>
#include "inga.h"
#include "Coords.h"
#include "Screen.h"


int main(int argc, char *argv[]) {
    try{
        inga proba1(100,2,10,0.3);
        xypt cx = {proba1.getL()*sin(proba1.getPhi0()),proba1.getL()*cos(proba1.getPhi0()),proba1.getPhi0(),0,0};
        double dt;
        int R = 10;
        proba1.refine_dt(cx, dt);
        Screen kep1(480, 480, dt);
        kep1.abrazol(proba1, R);
    }
    catch(std::exception &e) {
        fprintf(stderr, e.what());
        return -1;
    }
    catch(...) {
        fprintf(stderr, "Ismeretlen hiba");
        return -2;
    }
    return 0;
}
