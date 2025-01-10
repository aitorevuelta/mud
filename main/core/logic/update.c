#include <global.h>

#include <assets_utils.h>
#include <controls.h>
#include <menu.h>
#include <settings.h>

#include <loadscreen_render.h>

#include <update.h>


<<<<<<< HEAD
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo) {   
=======
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo) {

    static Uint32 startTime = 0;
    const Uint32 totalDuration = 5000;
    
    if (gameState == LOADSCREEN) {
        if (startTime == 0) {
            startTime = SDL_GetTicks();
        }

        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime > totalDuration) {
            gameState = GAME;
        }
    }
    
>>>>>>> 4821aaa96976c9a41525de1a057ea132bf42a193
    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case MAIN_MENU:
            MENU main_menu = create_main_menu(); 
            break;
        case LOBBY:
            break;
        case GAME:

            break;
        case SETTINGS:
            MENU settings_menu = create_settings_menu();
            break;
        case CREDITS:
            
            break;  
    }

    adjustFrameRate(frameStart, 144);

    return gameState;
}

void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
