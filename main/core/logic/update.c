#include <global.h>

#include <controls.h>
#include <menu.h>
#include <settings.h>
#include <loadscreen.h>

#include <update.h>



GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo, BUTTON *buttons, CONTROLS *controls) {

    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case LOADSCREEN:
            gameState = update_loadscreen();
            break;
        case MAIN_MENU:
            handleMenuEvents(buttons, 5, &gameState, controls);
            if(gameState==EXIT){
                gameState=EXIT_TOTAL;
            }
            break;
       case HOWTOPLAY:
            handleMenuEvents(buttons, 5, &gameState, controls);
            if(gameState==EXIT){
                  gameState=MAIN_MENU;
            }
            break;
       case SETTINGS:
            handleMenuEvents(buttons, 5, &gameState, controls);
            if  (gameState==EXIT) {
                  gameState=MAIN_MENU;
            }
            break;
        case CREDITS:
            handleMenuEvents(buttons, 5, &gameState, controls);
            if  (gameState==EXIT) {
                gameState=MAIN_MENU;
            }
            break;
        case LOBBY:
            break;
        case GAME:
            break;
    }

    //adjustFrameRate(frameStart, fps);
    return gameState;
}

void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
