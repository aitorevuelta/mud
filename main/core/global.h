#ifndef GLOBAL_H

#define GLOBAL_H

#define MAX_STR 128

// Definiciones de acciones para los botones
#define ACTION_PLAY      1  // Iniciar juego
#define ACTION_HOWTOPLAY 2  // Mostrar instrucciones
#define ACTION_CREDITS   3  // Mostrar créditos
#define ACTION_SETTINGS  4  // Mostrar configuración
#define ACTION_EXIT      5  // Salir del juego



typedef enum {
    LOADSCREEN = 0,
    MAIN_MENU,
    LOBBY,
    GAME,
    SETTINGS,
    CREDITS,
} GAMESTATE;

typedef struct SDL_S
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font_small;
} SDL;

typedef struct CONFIG_S
{
    int window_width;
    int window_height; 
    bool fullscreen;
    int volume;
    int max_FPS;
} CONFIG;

typedef struct BUTTON_S{
    SDL_Rect rect;          // Rectángulo de la textura del botón
    SDL_Texture* texture;   // Textura del botón
    int action;             // Acción asociada al botón
    bool visible;           // Si el botón está visible
} BUTTON;


#endif