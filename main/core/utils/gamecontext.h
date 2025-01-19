#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <global.h>
#include <controls.h>

typedef struct GAMECONTEXT_S {
    SDL sdl;
    CONTROLS controls;
    CONFIG config;
    GAMESTATE gameState;
    GAMEINFO gameInfo;
    ASSETS loadedAssets;
    BUTTON* buttons;
}GAMECONTEXT;

GAMECONTEXT* initializeGameContext();


#endif // GAMECONTEXT_H