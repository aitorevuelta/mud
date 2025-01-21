#include <global.h>

#include <assets_utils.h>


#include <map.h>
#include <player.h>

#include <game.h>




GAMEINFO loadGameInfo() {
    GAMEINFO info = {0};
    
    info.currentMapID = 1;
    info.numMaps = NUM_MAPS;
    info.numPlayers = 2;

    return info;
}


void update_game(GAMEINFO *gameInfo) {
    handleTurn(gameInfo);
}

static Uint32 lastUpdateTime = 0;

void handleTurn(GAMEINFO *gameInfo) {
    if (!gameInfo) return;
    
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0f;
    
    // Update elapsed time
    gameInfo->elapsedTime += deltaTime;
    
    // Reset timer and change turn at 60 seconds
    if (gameInfo->elapsedTime >= 60.0f) {
        gameInfo->elapsedTime = 0.0f;
        
        // Increment turn
        gameInfo->turn = (gameInfo->turn + 1) % gameInfo->numPlayers;
        
        // If we've completed a full round of players
        if (gameInfo->turn == 0) {
            gameInfo->round++;
        }
    }
    
    lastUpdateTime = currentTime;
}

void handlePhase() {
    
}


// Inicializar

void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo, RESOLUTION resolution) {
    SDL_GetRendererOutputSize(renderer, &resolution.width, &resolution.height);
    gameInfo->camera.pos[0] = resolution.width / 2;
    gameInfo->camera.pos[1] = resolution.height / 2;
    gameInfo->camera.zoom = 1.0f;


    allocatePlayers(gameInfo);
    initializePlayers(gameInfo);
}








bool checkGameOver(GAMEINFO* gameInfo) {
    int i = 0;
    for(i = 0; gameInfo->numPlayers > i; i++) {
    }
    return false;
}
