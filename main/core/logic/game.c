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

    //cleanup_game(gameInfo);
}

void initialize_game(GAMEINFO *gameInfo) {
    allocatePlayers(gameInfo); // memoria asignatu
    initializePlayers(gameInfo); // jokalariak hasieratu
}

void cleanup_game(GAMEINFO *gameInfo) {
    freeTerritories(gameInfo);
    freePlayers(gameInfo);
}

void game_over(GAMEINFO *gameInfo){
    cleanup_game(gameInfo);
    is_initialized = false;
}


void allocatePlayers(GAMEINFO *gameInfo) {
    gameInfo->players = malloc(sizeof(PLAYER) * gameInfo->numPlayers);
    if (!gameInfo->players) {
        fprintf(stderr, "Error al asignar memoria para jugadores.\n");
        exit(EXIT_FAILURE);
    }
}

PLAYER initializePlayer() {
    PLAYER player = NULL;

    player.id = 1;
    player.name = "Player1";
    player.playerColor = getRandomColour();

    player.numTerritories = 0;
    player.troops = 0;
   
    return player;
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

}

void freePlayers(GAMEINFO *gameInfo) {

}

int getTerritoryOwner() {

}

bool isAdjacent(){
    
}

int calculateReinforcements() {

}

void placeReinforcements() {

}

bool canAttack() {

}

int rollDice() {

}

void resolveComabt() {

}

void conquerTerritory() {


}

bool canFortify() {

}

void moveTroops() {

}

bool checkVictoryCondition() {

}