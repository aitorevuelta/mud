#include <global.h>
#include <string.h>
#include <assets_utils.h>
#include <game.h>
#include <player.h>

// Jokalariak gordetzeko memoria esleitzea
void allocatePlayers(GAMEINFO *gameInfo) {
    size_t memorySize = sizeof(PLAYER) * gameInfo->numPlayers;
    gameInfo->players = (PLAYER *) malloc(memorySize);
    if (!gameInfo->players) exit(1); // Memoria-errorea
}

// Jokalari bat hasieratzea
PLAYER initializePlayer(int id) {
    PLAYER player;
    player.id = id;
    player.numCards = 0;
    player.cards = NULL;
    player.numTerritories = 0;
    player.territories = NULL;
    player.playerColor = getRandomColour(); // Kolore aleatorio bat esleitu
    return player;
}

// Jokalari guztiak hasieratzea
void initializePlayers(GAMEINFO *gameInfo) {
    int i = 0;
    for (i = 0; gameInfo->numPlayers > i; i++) {
        gameInfo->players[i] = initializePlayer(i);
    }
}

// Jokalariak askatu eta memoria garbitzea
void freePlayers(GAMEINFO* gameInfo) {
    if (gameInfo->players) {
        free(gameInfo->players);
        gameInfo->players = NULL;
    }
}
