#include <global.h>

#include <sdl_utils.h>
#include <controls.h>
#include <render.h>
#include <menu.h>
#include <settings.h>
#include <loadscreen.h>
#include <game.h>
#include <lobby.h>
#include <assets_utils.h>
#include <gamestate_utils.h>
#include <buttons_utils.h>
#include <map.h>
#include <camera.h>

#include <update.h>

// Jokoa eguneratzen duen funtzio nagusia
void update(SDL_Renderer* renderer, GAMESTATE *gameState, ASSETS *loadedAssets, GAMEINFO *gameInfo, BUTTON **buttons, CONTROLS controls, CONFIG* config) {

    Uint32 frameStart = SDL_GetTicks();

    switch (*gameState) {
        case LOADSCREEN:
            *gameState = loadscreen();
            break;
        case MAIN_MENU:
            handleMenuEvents(*buttons, 5, gameState, controls);
            break;
       case HOWTOPLAY:
            handleMenuEvents(*buttons, 1, gameState, controls);
            break;
       case SETTINGS:
            handleSettingsButtons(*buttons, 6, controls, config, gameState);
            break;
        case CREDITS:
            handleMenuEvents(*buttons, 1, gameState, controls);
            break;
        case LOBBY:
            handleLobbyButtons(*buttons, 6, gameInfo, gameState, controls);
            break;
        case GAME:
            updateCamera(&gameInfo->camera, controls, config->window_size.width, config->window_size.height);
            loadMapMask(renderer, *loadedAssets, gameInfo->camera, gameInfo->currentMapID, config->window_size);
            SDL_Color color = getPixelColor(loadedAssets->images[1].texture, controls.coords[0], controls.coords[1]);
            update_game(gameInfo);
            break;
    }
    
    gameStateManager(renderer, buttons, loadedAssets, *gameState, gameInfo, config); // Gamestate-aren aldaketa kudeatu
    adjustFrameRate(frameStart, config->max_FPS); // Frame rate-a kudeatu
}

// Frame rate-a kudeatzeko funtzioa
void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
