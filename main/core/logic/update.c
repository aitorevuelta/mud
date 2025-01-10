#include <global.h>

<<<<<<< HEAD
#include <menu.h>

=======
#include <assets_utils.h>
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
#include <controls.h>
#include <menu.h>
#include <settings.h>
#include <loadscreen.h>

#include <update.h>


<<<<<<< HEAD

GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo,BUTTON *buttons,CONTROLS *controls) {

=======
GAMESTATE update(GAMESTATE gameState, GAMEINFO *gameInfo, int fps) {
    
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case LOADSCREEN:
            gameState = update_loadscreen();
            break;
        case MAIN_MENU:
<<<<<<< HEAD
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
        if(gameState==EXIT){
                  gameState=MAIN_MENU;
            }
            break;
        case CREDITS:
         handleMenuEvents(buttons, 5, &gameState, controls);
         if(gameState==EXIT){
                gameState=MAIN_MENU;
            }
=======
            //MENU main_menu = create_main_menu(); 
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
            break;
        case LOBBY:
            break;
        case GAME:
            break;
<<<<<<< HEAD
=======
        case SETTINGS:
            //MENU settings_menu = create_settings_menu();
            break;
        case CREDITS:
            break;  
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
    }

    adjustFrameRate(frameStart, fps);
    return gameState;
}

void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
