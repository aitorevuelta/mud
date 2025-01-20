#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = LOADSCREEN; 

void gameStateManager(SDL_Renderer* renderer, BUTTON buttons[], ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, gameState);
        loadGameStateVariables(renderer, buttons, *loadedAssets, gameState, gameInfo, config);
        lastGameState = gameState;
    }
}

void loadGameStateVariables(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case GAME:
            game_init(renderer, gameInfo);
            break;
    }
}