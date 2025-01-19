#include <global.h>

#include <sdl_utils.h>

bool init_sdl(SDL *sdl, CONFIG* config) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return false;
    }

    if (TTF_Init() < 0) {
        fprintf(stderr, "Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        return false;
    }

    if (SDLNet_Init() < 0) {
        printf("Error inicializando SDL_net: %s\n", SDLNet_GetError());
        SDL_Quit(); 
        return false;
    }

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {  // Inicializa SDL_mixer con soporte para MP3 y OGG
        printf("Error al inicializar SDL_mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return false;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {  // Configura la salida de audio
        printf("Error al abrir el audio: %s\n", Mix_GetError());
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
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    sdl->renderer = SDL_CreateRenderer(
        sdl->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (sdl->renderer == NULL) {
        printf("Error al crear el renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(sdl->window);
        SDL_Quit();
        return false;
    }

    return true;
}

void cleanUp_sdl(SDL* sdl) {
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