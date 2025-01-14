#ifndef GLOBAL_H

#define GLOBAL_H

#define MAX_STR 128

// LEER TEXTO

#define MAX_LINE_LENGTH 50

#define IMAGES_FILE "../data/images.txt"
#define FONTS_FILE "../data/fonts.txt"

// INCLUDES GENERALES

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_net.h>

// DEFINICIONES GLOBALES

typedef enum {
    LOADSCREEN = 0,
    MAIN_MENU,
    HOWTOPLAY,
    SETTINGS,
    CREDITS,
    LOBBY,
    GAME,
    EXIT,
    EXIT_TOTAL,
} GAMESTATE;

typedef struct SDL_S {
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL;

typedef struct CONFIG_S {
    int window_width;
    int window_height; 
    bool fullscreen;
    int volume;
    int max_FPS;
} CONFIG;

typedef struct BUTTON_S {
    SDL_Rect rect;          // Rectángulo calculado del botón
    SDL_Texture* texture;   // Textura del botón
    int action;             // Acción asociada al botón
    bool visible;           // Si el botón está visible
    float widthPercent;     // Ancho relativo del botón (y la imagen) en porcentaje
    float xPercent;         // Posición X relativa en porcentaje
    float yPercent;         // Posición Y relativa en porcentaje
} BUTTON;

#define HOVER_SCALE 1.1f // Escalado del botón al hacer hover (10% más grande)



#define HOVER_SCALE 1.1f // Escalado del botón al hacer hover (10% más grande)



typedef struct BUTTON_JUEGO_S{
    SDL_Rect rect;          // Rectángulo de la textura del botón
    SDL_Texture* texture;   // Textura del botón
    bool visible;           // Si el botón está visible
} BUTTON_JUEGO;


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
    int numMaps; 
    int totalMaps; 
} MAPINFO;

typedef struct CAMERA_S {
    int pos[1];
    float zoom;
} CAMERA;

// Estructura que representa la información general del juego
typedef struct GAMEINFO_S {
    MAPINFO mapInfo;          // Información sobre el mapa
    PLAYER *players;          // Jugadores en la partida
    CAMERA camera;   
    int numPlayers;           // Número total de jugadores
    int currentPlayerIndex;   // Índice del jugador actual
    int turn;   // Número de turno actual
} GAMEINFO;

typedef enum {
    ACTION_HOWTOPLAY=2,
    ACTION_SETTINGS,
    ACTION_CREDITS,
    ACTION_PLAY,
    ACTION_GAME,
    ACTION_EXIT,
    ACTION_ANADIR,
    ACTION_ELIMINAR,
}ACTION;


#endif