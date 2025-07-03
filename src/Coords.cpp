#include "Coords.h"
#include <iostream>
#include <cstdio>

void Coords::clear() {
    data = NULL;
    elnum = 0;
}

//x, y, phi, phidot, t
void Coords::push_back(const xypt &val) {
    xypt *temp;
    temp = new xypt[elnum+1];
    for (int i = 0; i <= elnum; ++i) {
        if (i == elnum) {
            temp[i] = val;
        }
        else {
            temp[i] = data[i];
        }
    }
    delete[] data;
    data = new xypt[elnum+1];
    for (int i = 0; i < elnum+1; ++i) {
        data[i] = temp[i];
    }
   delete[] temp;
    elnum = elnum + 1;
}
