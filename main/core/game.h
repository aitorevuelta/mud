#ifndef GAME_H
#define GAME_H

// Definición de las cartas (un tipo de acción adicional en el juego)
typedef enum {
    SOLDIER,  // Soldado
    HORSE,    // Caballo
    CANNON    // Cañón
} CARDS;

// Estructura que representa la información de un territorio
typedef struct TERRITORYINFO_S {
    char *name;       // Nombre del territorio
    int owner;        // ID del jugador que controla el territorio
    int troops;       // Número de tropas en el territorio
} TERRITORYINFO;

// Estructura que representa a un jugador
typedef struct PLAYER_S {
    int id;                 // Identificador único del jugador
    char *name;             // Nombre del jugador
    int *territories;       // Lista de territorios controlados por el jugador
    int numTerritories;     // Número de territorios controlados
    int troops;             // Número total de tropas del jugador
    int numCards;           // Número de cartas que posee
    CARDS *cards;           // Lista de cartas que posee el jugador
} PLAYER;

// Estructura que representa la información del mapa
typedef struct MAPINFO_S {
    char *mapName;            // Nombre del mapa (Ej. Mundo, Europa, etc.)
    TERRITORYINFO *territories; // Lista de territorios del mapa
    int numTerritories;       // Número de territorios en el mapa
} MAPINFO;

// Estructura que representa la información general del juego
typedef struct GAMEINFO_S {
    MAPINFO mapInfo;          // Información sobre el mapa
    PLAYER *players;          // Jugadores en la partida
    int numPlayers;           // Número total de jugadores
    int currentPlayerIndex;   // Índice del jugador actual
    int turn;                 // Número de turno actual
} GAMEINFO;

// Funciones para el manejo del juego
int initGame(GAMEINFO *gameInfo);          // Inicializa el juego
void startGame(GAMEINFO *gameInfo);        // Inicia el juego
void updateGame(GAMEINFO *gameInfo);       // Actualiza el estado del juego
void endGame(GAMEINFO *gameInfo);          // Termina el juego (sin implementación en este ejemplo)

// Funciones para el manejo de jugadores
void initPlayer(PLAYER *player, int id, const char *name);  // Inicializa un jugador
void assignTerritory(PLAYER *player, int territoryIndex);   // Asigna un territorio a un jugador

#endif
