#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = LOADSCREEN; 
static bool musicPlaying = false;

void handleGameStateChange(GAMESTATE newState, ASSETS *loadedAssets) {
    if (newState == MAIN_MENU && !musicPlaying) {
        Mix_PlayMusic(loadedAssets->sounds[0].sound, -1);
        musicPlaying = true;
    }
}
void gameStateManager(SDL_Renderer* renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, gameState);
        LoadButtonsByGameState(buttons, gameState, loadedAssets->images);
        loadGameStateVariables(renderer, *loadedAssets, gameState, gameInfo, config);
        handleGameStateChange(gameState, loadedAssets);
        lastGameState = gameState;
    }
}

void loadGameStateVariables(SDL_Renderer *renderer, ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case GAME:
            game_init(renderer, gameInfo);
            break;
    }
}