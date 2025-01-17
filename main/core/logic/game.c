#include <global.h>

#include <assets_utils.h>

#include <game.h>


void game_init(GAMEINFO *gameInfo) {
    allocatePlayers(gameInfo);
    initializePlayers(gameInfo);
}

void allocatePlayers(GAMEINFO *gameInfo) {
    size_t memorySize = sizeof(PLAYER) *gameInfo->numMaps;
    gameInfo->players = (PLAYER *) malloc(memorySize);

    if (!gameInfo->players) {
        fprintf(stderr, "Error al asignar memoria para %d jugadores.\n", gameInfo->numPlayers);
        exit(EXIT_FAILURE); // Terminar el programa si hay un error
    }
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

    for(i=0; gameInfo->numPlayers > i; i++) {
        gameInfo->players[i] = initializePlayer(i);
    }
}


void freePlayers(GAMEINFO *gameInfo) {
    if (gameInfo->players) {
    free(gameInfo->players);
    gameInfo->players = NULL; // Evitar punteros colgantes
    }
}