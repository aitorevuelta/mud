#include <global.h>

#include <assets_utils.h>

#include <game.h>

static bool is_initialized = false;

void game(GAMEINFO *gameInfo) {

    if(!is_initialized) {
        initialize_game(gameInfo);
        is_initialized = true;
    }


    handleTurn(gameInfo);

    cleanup_game(gameInfo);
}

void initialize_game(GAMEINFO *gameInfo) {
    allocateTerritories(gameInfo);
    allocatePlayers(gameInfo);
    initializeTerritories(gameInfo);
    initializePlayers(gameInfo);
}

void initializeCamera(CAMERA *camera) {
    camera->zoom = 1.0f;
    camera->pos[0] = 1000;
    camera->pos[1] = 500;
}

void cleanup_game(GAMEINFO *gameInfo) {
    freeTerritories(gameInfo);
    freePlayers(gameInfo);
}

void game_over(GAMEINFO *gameInfo){
    cleanup_game(gameInfo);
    is_initialized = false;
}


void allocateTerritories(GAMEINFO *gameInfo) {
    gameInfo->mapInfo.territories = malloc(sizeof(TERRITORYINFO) * TERRITORY_COUNT);
    if (!gameInfo->mapInfo.territories) {
        fprintf(stderr, "Error al asignar memoria para territorios.\n");
        exit(EXIT_FAILURE);
    }
}

void allocatePlayers(GAMEINFO *gameInfo) {
    gameInfo->players = malloc(sizeof(PLAYER) * MAX_PLAYERS);
    if (!gameInfo->players) {
        fprintf(stderr, "Error al asignar memoria para jugadores.\n");
        free(gameInfo->mapInfo.territories);
        exit(EXIT_FAILURE);
    }
}

void initializePlayer(PLAYER *player, int id) {
    player->id = id;
    player->territories = NULL;      
    player->numTerritories = 0;
    player->troops = 0;
    player->numCards = 0;
    player->cards = NULL;
    player->playerColor = getRandomColour();  
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

    for (int i = 0; TERRITORY_COUNT > i; i++) {
        gameInfo->mapInfo.territories[i].name = (char *)territoryNames[i];  // Asignación directa desde el array predefinido
        gameInfo->mapInfo.territories[i].owner = i % MAX_PLAYERS;  // Asignación de dueño al territorio
        gameInfo->mapInfo.territories[i].troops = rand() % 10 + 1;  // Tropas aleatorias entre 1 y 10
    }
}


void handleTurn(GAMEINFO *gameInfo)
{
    
    // Logica para acciones en el turno

    //Cambio al siguiente jugador 
    gameInfo->currentPlayerID = (gameInfo->currentPlayerID + 1) % gameInfo->numPlayers;
    if (gameInfo->currentPlayerID == 0) {
        gameInfo->turn++;
    }

    if (gameInfo->currentPlayerID == 0) {
        gameInfo->turn++;
        printf("Turno %d completo. Volviendo al primer jugador.\n", gameInfo->turn);
    }
}


void freeTerritories(GAMEINFO *gameInfo) {
    free(gameInfo->mapInfo.territories);
    gameInfo->mapInfo.territories = NULL;
}

void freePlayers(GAMEINFO *gameInfo) {
    free(gameInfo->players);
    gameInfo->players = NULL;
}