#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = LOADSCREEN; 

void gameStateManager(SDL_Renderer* renderer, BUTTON *buttons, ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, gameState);
        LoadButtonsByGameState(&buttons, gameState, loadedAssets->images);
        lastGameState = gameState;
    }
}
