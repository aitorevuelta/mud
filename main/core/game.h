#ifndef GAME_H
#define GAME_H

typedef enum CARDS {
    SOLDIER,
    HORSE,
    CANNON
};
typedef struct TERRITORYINFO_S {
    char name;         // Nombre del territorio
    int owner;             // ID del jugador que controla el territorio
    int troops;            // Número de tropas en el territorio
} TERRITORYINFO;

typedef struct PLAYER_S {
    int id;                // Identificador único del jugador
    char *name;         // Nombre del jugador
    int *territories;      // Lista de territorios controlados por el jugador
    int numTerritories;    // Número de territorios controlados
    int troops;            // Número total de tropas
    int numCards;
    CARDS *cards;
} PLAYER;

typedef struct MAPINFO_S {
    char *mapName;                 // Nombre del mapa actual (Ej. Mundo, Europa, etc.)
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
