#include <global.h>

#include <sdl_utils.h>

bool init_sdl(SDL *sdl, CONFIG config) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if (TTF_Init() < 0) {
        return false;
    }

    if (SDLNet_Init() < 0) {
        SDL_Quit(); 
        return false;
    }

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) { 
        SDL_Quit();
        return false;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) { 
        Mix_Quit();
        SDL_Quit();
        return false;
    }

    sdl->window = SDL_CreateWindow(
        "MU Domination",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config.window_size.width,
        config.window_size.height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE // | SDL_WINDOW_FULLSCREEN
    );

    if (sdl->window == NULL) {

        SDL_Quit();
        return false;
    }

    sdl->renderer = SDL_CreateRenderer(
        sdl->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    SDL_SetRenderDrawBlendMode(sdl->renderer, SDL_BLENDMODE_BLEND); //transparencias

    if (sdl->renderer == NULL) {
        SDL_DestroyWindow(sdl->window);
        SDL_Quit();
        return false;
    }

    return true;
}

void cleanUp_sdl(SDL *sdl) {
    if (sdl->renderer) {
        SDL_DestroyRenderer(sdl->renderer);
        sdl->renderer = NULL;
    }

    if (sdl->window) {
        SDL_DestroyWindow(sdl->window);
        sdl->window = NULL;
    }

    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}