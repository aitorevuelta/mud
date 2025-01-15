#include <global.h>

#include <game.h>



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

void initializePlayer(PLAYER *player, int id) {
    player->id = id;  // ID único del jugador (por ejemplo, 1, 2, 3, ...)

    player->territories = NULL;  // Al inicio, no poseen territorios
    player->numTerritories = 0;  // Inicialmente no tienen territorios controlados

    player->troops = 0;  // Tropas iniciales

    player->numCards = 0;  // Inicialmente no poseen cartas
    player->cards = NULL;  // No poseen cartas al inicio
}

void initializePlayers(GAMEINFO *gameInfo) {
    int i = 0;

    if (!gameInfo->players) {
        fprintf(stderr, "Error al asignar memoria para los jugadores.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; gameInfo->numPlayers > i; i++) {
        initializePlayer(&gameInfo->players[i], i+1);
    }
}

void initializeTerritories(GAMEINFO *gameInfo) {
    char *territoryNames[TERRITORY_COUNT] = {"Territorio 1", "Territorio 2", "Territorio 3",
                                             "Territorio 4", "Territorio 5", "Territorio 6"};

    for (int i = 0; i < TERRITORY_COUNT; i++) {
        gameInfo->mapInfo.territories[i].name = (char *)territoryNames[i];  // Asignación directa desde el array predefinido
        gameInfo->mapInfo.territories[i].owner = i % MAX_PLAYERS;  // Asignación de dueño al territorio
        gameInfo->mapInfo.territories[i].troops = rand() % 10 + 1;  // Tropas aleatorias entre 1 y 10
    }
}


void initialize_game(GAMEINFO *gameInfo) {

    allocateTerritories(gameInfo);
    allocatePlayers(gameInfo);
    initializeTerritories(gameInfo);
    initializePlayers(gameInfo);
}


void handleTurn(GAMEINFO *gameInfo)
{
    
    // Logica para acciones en el turno

    //Cambio al siguiente jugador 
    gameInfo->currentPlayerID = (gameInfo->currentPlayerID + 1) % gameInfo->numPlayers;
    if (gameInfo->currentPlayerID == 0) {
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

static bool is_initialized = false;

void game(GAMEINFO *gameInfo) {

    if(!is_initialized) {
        initialize_game(gameInfo);
        is_initialized = true;
    }



    handleTurn(gameInfo);

    cleanup_game(gameInfo);
}

void updateGame(GAMEINFO *gameInfo) {

}