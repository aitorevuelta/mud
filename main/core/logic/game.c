#include <global.h>

#include <assets_utils.h>

#include <game.h>

static int init = 0;
void game_init(GAMEINFO *gameInfo) {
    if (gameInfo == NULL) {
        fprintf(stderr, "Información del juego no válida para la asignación de memoria.\n");
        exit(EXIT_FAILURE);
    }
    if (!init) {
        allocatePlayers(gameInfo);
        initializePlayers(gameInfo);
        init = true;
    }
}

void allocatePlayers(GAMEINFO *gameInfo) {
    size_t memorySize = sizeof(PLAYER) *gameInfo->numPlayers;
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

    if (gameInfo == NULL || gameInfo->players == NULL) {
    fprintf(stderr, "Información del juego o punteros no válidos.\n");
        return;
    }

    for(i = 0; gameInfo->numPlayers > i; i++) {
        gameInfo->players[i] = initializePlayer(i);
    }
}


void freePlayers(GAMEINFO *gameInfo) {
    if (gameInfo->players) {
    free(gameInfo->players);
    gameInfo->players = NULL; // Evitar punteros colgantes
    }
}
