#include <global.h>

#include <game.h>

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 6

void initialize_game(GAMEINFO *gameInfo)
{
    gameInfo->mapInfo.mapName = "MAPA";
    gameInfo->mapInfo.numTerritories = 6;

    gameInfo->numPlayers = 6;
    gameInfo->turn = 1;
    gameInfo->currentPlayerIndex = 0;

    char *territoryNames[TERRITORY_COUNT] = {"Territorio 1", "Territorio 2", "Territorio 3",
                                             "Territorio 4", "Territorio 5", "Territorio 6"};

    for (int i = 0; i < TERRITORY_COUNT; i++) {
        gameInfo->mapInfo.territories[i].name = territoryNames[i];
        gameInfo->mapInfo.territories[i].owner = i % MAX_PLAYERS;
        gameInfo->mapInfo.territories[i].troops = rand() % 10 + 1;
    }

    gameInfo->numPlayers = MAX_PLAYERS;
    gameInfo->turn = 1;
    gameInfo->currentPlayerIndex = 0;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        gameInfo->players[i].id = i;
        gameInfo->players[i].name = i == 0 ? "Jugador 1" : "Jugador 2";
        gameInfo->players[i].numTerritories = 0;
        gameInfo->players[i].troops = 30;
        gameInfo->players[i].numCards = 0;

        for (int j = 0; j < TERRITORY_COUNT; j++) {
            if (gameInfo->mapInfo.territories[j].owner == i) {
                gameInfo->players[i].numTerritories++;
            }
        }
    }
}


void handleTurn(GAMEINFO *gameInfo)
{
    
    // Logica para acciones en el turno

    //Cambio al siguiente jugador 
    gameInfo->currentPlayerIndex = (gameInfo->currentPlayerIndex + 1) % gameInfo->numPlayers;
    if (gameInfo->currentPlayerIndex == 0) {
        gameInfo->turn++;
    }
}

void cleanup_game()
{

}