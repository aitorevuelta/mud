#ifndef GLOBAL_H

#define GLOBAL_H

#define MAX_STR 128
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
} SDL;

typedef struct CONFIG_S
{
    int window_width;
    int window_height; 
    bool fullscreen;
    int volume;
    int max_FPS;
} CONFIG;

#endif