#include <global.h>

#include <sdl_utils.h>
#include <controls.h>
#include <menu.h>
#include <settings.h>
#include <loadscreen.h>
#include <game.h>
#include <lobby.h>
#include <assets_utils.h>
#include <camera.h>

#include <update.h>


GAMESTATE update(SDL *sdl, GAMESTATE gameState, GAMEINFO *gameInfo, BUTTON *buttons, CONTROLS *controls, CONFIG* config) {

    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case LOADSCREEN:
            gameState = loadscreen();
            break;
        case MAIN_MENU:
            handleMenuEvents(buttons, 5, &gameState, controls);
            break;
       case HOWTOPLAY:
            handleMenuEvents(buttons, 1, &gameState, controls);
            break;
       case SETTINGS:
            handleResolutionButtons(sdl->window, buttons, 5, controls, &gameState, config);
            break;
        case CREDITS:
            handleMenuEvents(buttons, 1, &gameState, controls);
            break;
        case LOBBY:
            handleGameStateButtons(buttons,  6, &gameState, controls);
            handlePlayerButtons(buttons, 4, gameInfo, controls);
            break;
        case GAME:
            updateCamera(&gameInfo->camera, controls, config->window_size.width, config->window_size.height);
            break;
    }

    adjustFrameRate(frameStart, config->max_FPS);
    return gameState;
}

void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
