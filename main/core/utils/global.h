#ifndef GLOBAL_H

#define GLOBAL_H


// Beharrezko include-ak

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_net.h>

// Define-ak

#define MAX_STR 128

#define MAX_LINE_LENGTH 50
#define IMAGES_FILE "../data/images.txt"
#define FONTS_FILE "../data/fonts.txt"

#define HOVER_SCALE 1.1f // Escalado del botón al hacer hover (10% más grande)

typedef struct SDL_S {
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL;

typedef struct RESOLUTION_S {
    int width;
    int height; 
} RESOLUTION;

typedef struct CONFIG_S {
    RESOLUTION window_size;
    bool fullscreen;
    int volume;
    int max_FPS;
    int current_res;
    int total_res;
    RESOLUTION *resolutions;
} CONFIG;

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

typedef struct IMAGES_S {
    SDL_Texture* texture;
} IMAGES;

typedef struct MUSIC_S {
    Mix_Music *music;
}MUSIC;
typedef struct FONTS_S {
    TTF_Font* font;
} FONTS;

typedef struct ASSETS_S {
    IMAGES *images;
    MUSIC *music;
    FONTS *fonts;
}ASSETS;


typedef struct BUTTON_S {
    SDL_Rect rect;          // Rectángulo calculado del botón
    SDL_Texture* texture;   // Textura del botón
    int action;             // Acción asociada al botón
    bool visible;           // Si el botón está visible
    float widthPercent;     // Ancho relativo del botón (y la imagen) en porcentaje
    float xPercent;         // Posición X relativa en porcentaje
    float yPercent;         // Posición Y relativa en porcentaje
} BUTTON;


typedef struct COLOUR_S {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} COLOUR;

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
    int id;                 // ID-a
    char name[MAX_STR];             // Nombre del jugador
    int *territories;       // Lista de territorios controlados por el jugador
    int numTerritories;     // Número de territorios controlados
    int troops;             // Número total de tropas del jugador
    int numCards;           // Número de cartas que posee
    CARDS *cards;
    COLOUR playerColor;        // Lista de cartas que posee el jugador
} PLAYER;

// Estructura que representa la información del mapa
typedef struct MAPINFO_S {
    char mapName[MAX_STR];            // Nombre del mapa (Ej. Mundo, Europa, etc.)
    TERRITORYINFO *territories; // Lista de territorios del mapa
    int numTerritories;       // Número de territorios en el mapa
    int numMaps; 
    int totalMaps; 
} MAPINFO;

typedef struct CAMERA_S {
    int pos[2];
    float zoom;
} CAMERA;

// Estructura que representa la información general del juego
typedef struct GAMEINFO_S {
    MAPINFO mapInfo;          // Información sobre el mapa
    PLAYER *players;          // Jugadores en la partida
    //CONFIG config;
    CAMERA camera;   
    int numPlayers;           // Número total de jugadores
    int currentPlayerID;   // Índice del jugador actual
    int turn;                 // Número de turno actual
    int currentMapIndex;      // Índice del mapa actual
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

#define ACTION_NONE -1


#endif