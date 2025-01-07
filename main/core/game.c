#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <game.h>

// Función que inicializa el juego
int initGame(GAMEINFO *gameInfo) {
    // Inicializar el mapa
    gameInfo->mapInfo.mapName = "Mundo";  // Nombre del mapa
    gameInfo->mapInfo.numTerritories = 42;  // Número de territorios en el mapa
    gameInfo->mapInfo.territories = (TERRITORYINFO *)malloc(gameInfo->mapInfo.numTerritories * sizeof(TERRITORYINFO));

    // Inicializar territorios
    for (int i = 0; i < gameInfo->mapInfo.numTerritories; i++) {
        gameInfo->mapInfo.territories[i].name = "Territorio";  // Nombre por defecto
        gameInfo->mapInfo.territories[i].owner = -1;           // Sin dueño por defecto
        gameInfo->mapInfo.territories[i].troops = 0;            // Sin tropas por defecto
    }

    // Inicializar jugadores
    gameInfo->numPlayers = 4;  // Supongamos que siempre jugamos con 4 jugadores
    gameInfo->players = (PLAYER *)malloc(gameInfo->numPlayers * sizeof(PLAYER));

    for (int i = 0; i < gameInfo->numPlayers; i++) {
        char name[20];
        sprintf(name, "Jugador %d", i + 1);
        initPlayer(&gameInfo->players[i], i, name);  // Inicializar jugador con nombre por defecto
    }

    // Inicializar variables de juego
    gameInfo->currentPlayerIndex = 0;
    gameInfo->turn = 1;

    return 1;  // El juego se ha inicializado correctamente
}

// Función que inicia el juego
void startGame(GAMEINFO *gameInfo) {
    SDL_Event event;
    int gameOver = 0;

    while (!gameOver) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            gameOver = 1;
        }

        // Actualizar el estado del juego
        updateGame(gameInfo);

        // Aquí se podría dibujar el mapa y la interfaz con SDL
        // Por ahora, solo imprimimos información básica
        printf("Turno %d, Jugador actual: %s\n", gameInfo->turn, gameInfo->players[gameInfo->currentPlayerIndex].name);
        
        // Incrementar el turno
        gameInfo->turn++;

        // Cambiar al siguiente jugador
        gameInfo->currentPlayerIndex = (gameInfo->currentPlayerIndex + 1) % gameInfo->numPlayers;
    }

    printf("El juego ha terminado.\n");
}

// Función que actualiza el estado del juego (logística del turno)
void updateGame(GAMEINFO *gameInfo) {
    PLAYER *currentPlayer = &gameInfo->players[gameInfo->currentPlayerIndex];

    // Aquí podrías agregar la lógica para que el jugador realice su turno
    // Esto incluye mover tropas, atacar, asignar cartas, etc.

    // Ejemplo de un turno simple (sin mucha lógica de juego en este momento)
    printf("Jugador %s está en su turno.\n", currentPlayer->name);
}

// Función para finalizar el juego
void endGame(GAMEINFO *gameInfo) {
    // Aquí se podrían liberar recursos y anunciar al ganador
    printf("El juego ha terminado. ¡Felicidades al ganador!\n");

    // Liberar memoria de los jugadores y territorios
    for (int i = 0; i < gameInfo->numPlayers; i++) {
        free(gameInfo->players[i].territories);
        free(gameInfo->players[i].cards);
    }

    free(gameInfo->players);
    free(gameInfo->mapInfo.territories);
}

// Función para inicializar a un jugador
void initPlayer(PLAYER *player, int id, const char *name) {
    player->id = id;
    player->name = strdup(name);  // Asignar nombre al jugador
    player->numTerritories = 0;   // Inicialmente no controla ningún territorio
    player->territories = NULL;   // No tiene territorios asignados
    player->troops = 0;           // Inicialmente no tiene tropas
    player->numCards = 0;         // No tiene cartas
    player->cards = NULL;         // No tiene cartas
}

// Función para asignar un territorio a un jugador
void assignTerritory(PLAYER *player, int territoryIndex) {
    player->territories = realloc(player->territories, (player->numTerritories + 1) * sizeof(int));
    player->territories[player->numTerritories] = territoryIndex;
    player->numTerritories++;
}
