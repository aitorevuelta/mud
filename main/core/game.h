#ifndef GAME_H
#define GAME_H

typedef struct TERRITORYINFO_S {
    char name;         // Nombre del territorio
    int owner;             // ID del jugador que controla el territorio
    int troops;            // Número de tropas en el territorio
    int *neighbors;        // Lista de índices de los territorios adyacentes
    int numNeighbors;      // Número de vecinos (territorios adyacentes)
} TERRITORYINFO;

typedef struct PLAYER_S {
    int id;                // Identificador único del jugador
    char name[50];         // Nombre del jugador
    int *territories;      // Lista de territorios controlados por el jugador
    int numTerritories;    // Número de territorios controlados
    int troops;            // Número total de tropas
} PLAYER;

typedef struct MAPINFO_S {
    char mapName[50];                 // Nombre del mapa actual (Ej. Mundo, Europa, etc.)
    TERRITORYINFO *territories;       // Lista de territorios del mapa
    int numTerritories;               // Número de territorios
} MAPINFO;

typedef struct GAMEINFO_S {
    MAPINFO mapInfo;                  // Información sobre el mapa
    PLAYER *players;                  // Jugadores en la partida
    int numPlayers;                   // Número total de jugadores
    int currentPlayerIndex;           // Índice del jugador actual
    int turn;                          // Número de turno actual
} GAMEINFO;

#endif
