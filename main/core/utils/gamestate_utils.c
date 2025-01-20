#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <game.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = LOADSCREEN; 

void gameStateManager(SDL_Renderer* renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO* gameInfo, CONFIG* config) {
    if (gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, gameState);
        LoadButtonsByGameState(buttons, gameState, loadedAssets->images);
        loadGameStateVariables(renderer, *loadedAssets, gameState, gameInfo, config);
        handleMusicChange(gameState, loadedAssets, config->selectedVolume * 20);
        lastGameState = gameState;
    }
}

void loadGameStateVariables(SDL_Renderer *renderer, ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config) {
    switch (gameState) {
        case MAIN_MENU:
            config->volume =  config->selectedVolume * 20;
            break;
        case SETTINGS:
            config->selectedVolume =  config->volume / 20;
            break;
        case GAME:
            game_init(renderer, gameInfo);
            break;
    }
}

static bool musicPlaying = false;

void handleMusicChange(GAMESTATE newState, ASSETS *loadedAssets, int volume) {
    if (newState == MAIN_MENU && !musicPlaying) {
        Mix_PlayMusic(loadedAssets->sounds[0].sound, -1);
        Mix_VolumeMusic(volume);
        musicPlaying = true;
    } else if (newState == GAME && musicPlaying) {
        Mix_HaltMusic();
        musicPlaying = false;
    }
}