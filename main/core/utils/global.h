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

#include <time.h>

// Define-ak

#define MAX_STR 128


#define HOVER_SCALE 1.1f // Escalado del botón al hacer hover (10% más grande)

#define NUM_MAPS 3 // mapa kopurua

#define MAX_PLAYERS 4
#define MIN_PLAYERS 2

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
    int selectedVolume;
    int max_FPS;
    int current_res;
    int total_res;
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

typedef struct SOUNDS_S {
    Mix_Music* sound;
}SOUNDS;

typedef struct FONTS_S {
    TTF_Font* font;
} FONTS;

typedef struct ASSETS_S {
    IMAGES *images;
    SOUNDS *sounds;
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
    bool hover;             // Si el botón está siendo pulsado
} BUTTON;


// kartak
typedef enum {
    SOLDIER,  
    HORSE,    
    CANNON,
} CARDS;

// territorioen informazioa
typedef struct TERRITORYINFO_S {
    char name[MAX_STR];       // Nombre del territorio
    int ownerID;        // ID del jugador que controla el territorio
    int troops;       // Número de tropas en el territorio
    int center[2];
     int radius;               // Tamaño del territorio (radio)
    bool isSelected;       // Indicador si el territorio está seleccionado
} TERRITORYINFO;

// mapen informazioa
typedef struct MAPINFO_S {
    char mapName[MAX_STR];      // maparen izena
    TERRITORYINFO *territories;     // mapan dauden territorioen informazioa
    int numTerritories;     // territorio kopurua 
    int** adjMatrix;    // territorioen arteko konexioak
} MAPINFO;

// jokalarien informazioa
typedef struct PLAYER_S {
    int id;                 
    char name[MAX_STR];     
    int *territories;       
    int numTerritories;     
    int troops;             
    int numCards;           
    CARDS *cards;
    SDL_Color playerColor;        
} PLAYER;

typedef enum {
    DEPLOY, 
    ATTACK,
    REINFORCE,
} PHASE;

// kameraren informazioa
typedef struct CAMERA_S {
    int pos[2]; // posizioa
    float zoom; // zoom-a
} CAMERA;

// jokoa informazioa
typedef struct GAMEINFO_S {
    MAPINFO maps[NUM_MAPS]; // mapen arraya 
    int numMaps; // mapen kopurua
    int currentMapID;        
    PLAYER *players;            
    int numPlayers;           
    int currentPlayerID;    
    int turn;                   
    PHASE phase;           
    int round;
    float elapsedTime;
    CAMERA camera;              
    bool isGameOver;         
    int totalTerritories;
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