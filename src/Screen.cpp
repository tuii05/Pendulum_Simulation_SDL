#include "Screen.h"
#include "inga.h"
#include <iostream>
#include <cstdio>

void Screen::sdl_init(SDL_Window **pwindow, SDL_Renderer **prenderer) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Nem indithato az SDL: " << SDL_GetError();
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow("Inga szimulacio", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    if(window == NULL) {
        std::cout << "Nem hozhato letre az ablak: " << SDL_GetError();
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL) {
        std::cout << "Nem hozhato letre a megjelenito: " << SDL_GetError();
        exit(1);
    }
    SDL_RenderClear(renderer);
    *pwindow = window;
    *prenderer = renderer;
}

Uint32 idozit(Uint32 ms, void *param) {
    SDL_Event ev;
    ev.type  = SDL_USEREVENT;
    SDL_PushEvent(&ev);
    return ms;
}

void Screen::abrazol(inga inga1, int R) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init(&window, &renderer);
    SDL_TimerID id = SDL_AddTimer(20, idozit, NULL);
    xypt c0 = {inga1.getL()*sin(inga1.getPhi0()), inga1.getL()*cos(inga1.getPhi0()), inga1.getPhi0(), 0, 0};
    double eps = h/2+R, eps2 = R+h/2;
    bool isRunning = true;
    double x,y;
    filledCircleRGBA(renderer, w/2+(c0.x)*100, eps2+(c0.y)*100, R, 0x90, 0x90, 0xFF, 0xFF);
    thickLineRGBA(renderer, (w/2+(c0.x)*100), eps+(c0.y)*100, w/2, h/2, 1, 0x40, 0x40, 0xFF, 0xFF);
    while(isRunning) {
        SDL_Event ev;
        SDL_WaitEvent(&ev);
        switch(ev.type) {
            case SDL_USEREVENT:
                x = w/2+(c0.x)*100;
                y = (c0.y)*100;
                filledCircleRGBA(renderer, x, eps2+y, R, 0, 0, 0, 0xFF);
                thickLineRGBA(renderer, x, eps+y, w/2,  h/2, 1, 0, 0, 0, 0xFF);
                //lineRGBA(renderer, (w/2+(c0.x)*100)-(R+eps)*sin(c0.phi), (inga1.getL()*100+(c0.y)*100)-(R+eps)*cos(c0.phi), w/2,  0, 0, 0, 0, 0xFF);
                c0 = inga1.ujcoords(c0);
                x = w/2+(c0.x)*100;
                y = (c0.y)*100;
                filledCircleRGBA(renderer, x, eps2+y, R, 0x90, 0x90, 0xFF, 0xFF);
                thickLineRGBA(renderer, x, eps+y, w/2, h/2, 1, 0x40, 0x40, 0xFF, 0xFF);
                //lineRGBA(renderer, w/2, 0,(w/2+(c0.x)*100)-(R+eps)*sin(c0.phi), (inga1.getL()*100+(c0.y)*100)-(R+eps)*cos(c0.phi), 0x40, 0x40, 0xFF, 0xFF);
                SDL_RenderPresent(renderer);
                break;
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }
    SDL_RemoveTimer(id);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


