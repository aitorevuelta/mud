#include <global.h>

#include <assets_utils.h>

#include <game.h>

void update_game(GAMEINFO *gameInfo) {
    updateTime(gameInfo);
}

static Uint32 lastUpdateTime = 0;

void updateTime(GAMEINFO *gameInfo) {
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
// Inicializar

void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    gameInfo->camera.pos[0] = windowWidth / 2;
    gameInfo->camera.pos[1] = windowHeight / 2;
    gameInfo->camera.zoom = 1.0f;

    // Iniciar juego
    gameInfo->turn = 0;
    gameInfo->elapsedTime = 0;
    gameInfo->round = 1;
    allocatePlayers(gameInfo);
    initializePlayers(gameInfo);
}


void allocatePlayers(GAMEINFO *gameInfo) {
    size_t memorySize = sizeof(PLAYER) *gameInfo->numPlayers;
    gameInfo->players = (PLAYER *) malloc(memorySize);
}

PLAYER initializePlayer(int id) {
    PLAYER player;
    player.id = id;
    player.numCards = 0;
    player.cards = NULL;
    player.numTerritories = 0;
    player.territories = NULL;
    player.playerColor = getRandomColour();
    return player;
}

void initializePlayers(GAMEINFO *gameInfo) {
    int i = 0;

    for(i = 0; gameInfo->numPlayers > i; i++) {
        gameInfo->players[i] = initializePlayer(i);
    }
}

void freePlayers(GAMEINFO *gameInfo) {
    if (gameInfo->players) {
    free(gameInfo->players);
    gameInfo->players = NULL;
    }
}