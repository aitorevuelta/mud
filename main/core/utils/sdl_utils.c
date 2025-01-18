#include <global.h>

#include <sdl_utils.h>

bool init_sdl(GAMECONTEXT *gameContext) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return false;
    }

    // Inicializar SDL_ttf
    if (TTF_Init() < 0) {
        fprintf(stderr, "Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return false;
    }

    // Inicializar SDL_net
    if (SDLNet_Init() < 0) {
        printf("Error inicializando SDL_net: %s\n", SDLNet_GetError());
        SDL_Quit();
        return false;
    }

    // Inicializar SDL_mixer
    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        printf("Error al inicializar SDL_mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return false;
    }

    // Configurar la salida de audio
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        printf("Error al abrir el audio: %s\n", Mix_GetError());
        cleanUp_sdl(gameContext->sdl);
        return false;
    }

    // Crear la ventana
    gameContext->sdl.window = SDL_CreateWindow(
        "MU Domination",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        gameContext->config.window_size.width,
        gameContext->config.window_size.height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (gameContext->sdl.window == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        cleanUp_sdl(gameContext->sdl);
        return false;
    }

    // Crear el renderer
    gameContext->sdl.renderer = SDL_CreateRenderer(
        gameContext->sdl.window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (gameContext->sdl.renderer == NULL) {
        printf("Error al crear el renderer: %s\n", SDL_GetError());
        cleanUp_sdl(gameContext->sdl);
        return false;
    }

    return true; // SDL y sus subsistemas fueron inicializados con éxito
}

void cleanUp_sdl(SDL* sdl)
{
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