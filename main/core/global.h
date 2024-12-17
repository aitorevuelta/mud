#ifndef GLOBAL_H

#define GLOBAL_H

typedef struct SDL_S
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font* font_small;
} SDL;

typedef struct CONFIG_S
{
    int window_width;
    int window_height; 
    int volume;
    int max_FPS;
} CONFIG;

#endif