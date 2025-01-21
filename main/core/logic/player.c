#include <global.h>

#include <game.h>

#include <player.h>



void allocatePlayers(GAMEINFO *gameInfo) {
    size_t memorySize = sizeof(PLAYER) *gameInfo->numPlayers;
    gameInfo->players = (PLAYER *) malloc(memorySize);
    if(!gameInfo->players) exit(1);
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

void freePlayers(GAMEINFO* gameInfo) {
    
}

