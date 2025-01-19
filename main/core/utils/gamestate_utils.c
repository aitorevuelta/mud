#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void gameStateManager(SDL_Renderer* renderer, BUTTON** buttons, ASSETS *loadedAssets, GAMESTATE* gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (*gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, *gameState);
        loadGameStateVariables(buttons, *gameState, gameInfo, config);
        lastGameState = *gameState;
    }
}

void loadGameStateVariables(BUTTON** buttons, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case MAIN_MENU:
            setupMenuButtons(buttons, gameInfo, config);
            break;
       case HOWTOPLAY:
            setupH2PButtons(buttons, gameInfo, config);
            break;
       case SETTINGS:
            setupSettingsButtons(buttons, gameInfo, config);
            break;
        case CREDITS:
            setupCreditsButtons(buttons, gameInfo, config);
            break;
        case LOBBY:
            setupLobbyButtons(buttons, gameInfo, config);
            break;
        case GAME:

            break;
    }
}