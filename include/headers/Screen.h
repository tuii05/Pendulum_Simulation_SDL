#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include "inga.h"

#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

class Screen{
private:
    int w, h;
    double dt;
public:
    Screen(int w, int h, double dt) {
        this->w=w; this->h=h; this->dt=dt;
    }
    void sdl_init(SDL_Window **pwindow, SDL_Renderer **prenderer);
    void abrazol(inga inga1, int R);
};

#endif // SCREEN_H_INCLUDED
