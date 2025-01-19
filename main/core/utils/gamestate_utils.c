#include <global.h>

#include <assets_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void checkGameStateChange(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE* gameState) {
    if (*gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, *gameState);
        lastGameState = *gameState;
    }
}

void loadGameStateVariables(GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case LOADSCREEN:
  
            break;
        case MAIN_MENU:
            break;
       case HOWTOPLAY:
            
            break;
       case SETTINGS:
            
            break;
        case CREDITS:
            
            break;
        case LOBBY:
            
            break;
        case GAME:
            initGameInfo(gameInfo, config);
            break;
    }
}