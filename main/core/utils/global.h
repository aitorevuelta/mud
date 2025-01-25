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
#define HOVER_SCALE 1.1f        // hover-a
#define ACTION_NONE -1
#define TERRITORY_COUNT 23
#define DEFAULT_TROOPS_COUNT 25
#define NUM_MAPS 3 // mapa kopurua
#define MAX_PLAYERS 4   // jokalari kopurua maximoa
#define MIN_PLAYERS 2   // jokalari kopurua minimoa

typedef struct SDL_S {
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL;      // sdl struct-a

typedef struct RESOLUTION_S {
    int width;
    int height; 
} RESOLUTION;   // erresoluzioaren struct-a

typedef struct CONFIG_S {
    RESOLUTION window_size;
    bool fullscreen;
    int volume;
    int selectedVolume;
    int max_FPS;
    int current_res;
    int total_res;
} CONFIG;       // konfigurazioaren struct-a

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
} GAMESTATE;        // jokoaren egoera

typedef struct IMAGES_S {
    SDL_Texture* texture;
} IMAGES;       // irudien struct-a

typedef struct SOUNDS_S {
    Mix_Music* sound;
}SOUNDS;    // soinuen struct-a

typedef struct FONTS_S {
    TTF_Font* font;
} FONTS;   // letren iturrien struct-a

typedef struct ASSETS_S {
    IMAGES *images;
    SOUNDS *sounds;
    FONTS *fonts;
}ASSETS;    // asset-en struct-a


typedef struct BUTTON_S {
    SDL_Rect rect;          
    SDL_Texture* texture;  
    int action;             
    bool visible;          
    float widthPercent;     
    float xPercent;        
    float yPercent;         
    bool hover;             
} BUTTON;       // botoien struct-a



typedef enum {
    SOLDIER,  
    HORSE,    
    CANNON,
} CARDS;    // kartak


typedef struct TERRITORYINFO_S {
    char name[MAX_STR];       
    int ownerID;        
    int troops;       
    int center[2];
     int radius;               
    bool isSelected;       
} TERRITORYINFO;        // territorioen struct-a


typedef struct MAPINFO_S {
    char mapName[MAX_STR];      // maparen izena
    TERRITORYINFO *territories;     // mapan dauden territorioen informazioa
    int numTerritories;     // territorio kopurua 
    int** adjMatrix;    // territorioen arteko konexioak
} MAPINFO;      // mapen struct-a


typedef struct PLAYER_S {
    int id;                 
    char name[MAX_STR];     
    int *territories;       
    int numTerritories;     
    int troops;             
    int numCards;           
    CARDS *cards;
    SDL_Color playerColor;        
} PLAYER;       // jokalarien struct-a 

typedef enum {
    DEPLOY, 
    ATTACK,
    REINFORCE,
} PHASE;        // faseak


typedef struct CAMERA_S {
    int pos[2]; // posizioa
    float zoom; // zoom-a
} CAMERA;       // kameraren struct-a


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
} GAMEINFO;     // jokoa informazioaren struct-a

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




#endif // GLOBAL_H