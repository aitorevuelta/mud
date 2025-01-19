#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void gameStateManager(SDL_Renderer* renderer, BUTTON buttons[], ASSETS *loadedAssets, GAMESTATE* gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (*gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, *gameState);
        loadGameStateVariables(buttons, loadedAssets, *gameState, gameInfo, config);
        lastGameState = *gameState;
    }
}

void loadGameStateVariables(BUTTON buttons[], ASSETS* loadedAssets, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case MAIN_MENU:
            setupMenuButtons(&buttons, 5, loadedAssets);
            break;
       case HOWTOPLAY:
            setupH2PButtons(&buttons, 1, loadedAssets);
            break;
       case SETTINGS:
            setupSettingsButtons(&buttons, 6, loadedAssets);
            break;
        case CREDITS:
            setupCreditsButtons(&buttons, 1, loadedAssets);
            break;
        case LOBBY:
            setupLobbyButtons(&buttons, 6, loadedAssets);
            break;
        case GAME:

            break;
    }
}