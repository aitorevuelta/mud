#include <global.h>

#include <loadscreen.h>

GAMESTATE loadscreen() { // pantaila kargatzeko denbora kalkulatu
    static Uint32 startTime = 0;
    if (startTime == 0) {
        startTime = SDL_GetTicks();
    }

    Uint32 currentTime = SDL_GetTicks();
    GAMESTATE nextState = (currentTime - startTime >= 5000) ? MAIN_MENU : LOADSCREEN;
    return nextState;
}