#include <global.h>

#include <game.h>

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 6

void allocateTerritories(GAMEINFO *gameInfo) {
    // Memoria alokatu territorioei
    gameInfo->mapInfo.territories = malloc(sizeof(TERRITORYINFO) * TERRITORY_COUNT);
    if (!gameInfo->mapInfo.territories) {
        fprintf(stderr, "Error al asignar memoria para territorios.\n");
        exit(EXIT_FAILURE);
    }
}

void allocatePlayers(GAMEINFO *gameInfo) {
    // Memoria alokatu jokalariei
    gameInfo->players = malloc(sizeof(PLAYER) * MAX_PLAYERS);
    if (!gameInfo->players) {
        fprintf(stderr, "Error al asignar memoria para jugadores.\n");
        free(gameInfo->mapInfo.territories);
        exit(EXIT_FAILURE);
    }
}

void initializeBasicData(GAMEINFO *gameInfo) {
    

}

void initializePlayer(GAMEINFO *gameInfo) {


}

void initializePlayers(GAMEINFO *gameInfo) {
    int i = 0;
    for(i = 0; gameInfo->numPlayers > i; i++) {
        initializePlayer(gameInfo);
    }
}

void initializeTerritories(GAMEINFO *gameInfo) {

}

void initialize_game(GAMEINFO *gameInfo) {

    allocateTerritories(gameInfo);
    allocatePlayers(gameInfo);
    initializeBasicData(gameInfo);
    initializeTerritories(gameInfo);
    
    // Nombres de los territorios
    char *territoryNames[TERRITORY_COUNT] = {"Territorio 1", "Territorio 2", "Territorio 3",
                                             "Territorio 4", "Territorio 5", "Territorio 6"};

    for (int i = 0; i < TERRITORY_COUNT; i++) {
        gameInfo->mapInfo.territories[i].name = territoryNames[i];
        gameInfo->mapInfo.territories[i].owner = i % MAX_PLAYERS;
        gameInfo->mapInfo.territories[i].troops = rand() % 10 + 1;
    }

    initializePlayers(gameInfo);

    // Inicialización de jugadores
    for (int i = 0; i < MAX_PLAYERS; i++) {
        gameInfo->players[i].id = i;

        // Asignar memoria para el nombre del jugador
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "Jugador %d", i + 1);
        gameInfo->players[i].name = malloc(strlen(buffer) + 1);
        if (!gameInfo->players[i].name) {
            fprintf(stderr, "Error al asignar memoria para el nombre del jugador.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(gameInfo->players[i].name, buffer);

        gameInfo->players[i].numTerritories = 0;
        gameInfo->players[i].troops = 30;
        gameInfo->players[i].numCards = 0;
        gameInfo->players[i].cards = NULL;

        // Contar territorios asignados a cada jugador
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

void cleanup_game(GAMEINFO *gameInfo) {
    freeTerritories(gameInfo);
    free(gameInfo->mapInfo.mapName);
}

void freeTerritories(GAMEINFO *gameInfo) {
    int i = 0;
    for (i = 0; i < gameInfo->mapInfo.numTerritories; i++) {
        free(gameInfo->mapInfo.territories[i].name);
    }
    free(gameInfo->mapInfo.territories);
}

void freePlayers(GAMEINFO *gameInfo) {
    int i = 0;
    for (i = 0; i < gameInfo->numPlayers; i++) {
        free(gameInfo->players[i].name);
        free(gameInfo->players[i].cards);
    }
    free(gameInfo->players);
}


void game(GAMEINFO *gameInfo) {
    
    initialize_game(gameInfo);

    handleTurn(gameInfo);

    cleanup_game(gameInfo);
}

void updateGame(GAMEINFO *gameInfo) {

}