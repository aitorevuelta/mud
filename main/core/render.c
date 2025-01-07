#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <utils.h>

void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    
    switch(*gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages, gameState);
            break;
        case MAIN_MENU:
            renderMenu(renderer, loadedImages, gameState, config);
            break;
        case LOBBY:
            renderLobby(renderer, loadedImages, gameState, config);
            break;
        case GAME:
            renderGame(renderer, loadedImages, gameState, config);
            break;
        case SETTINGS:
            renderSettings(renderer, loadedImages, gameState, config);
            break;
        case CREDITS:
            renderCredits(renderer, loadedImages, gameState, config);
            break;
    }
    
    SDL_RenderPresent(renderer);
    adjustFrameRate(frameStart, config.max_FPS);
}

void renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gamestate) {
    static Uint32 startTime = 0;
    const Uint32 fadeInDuration = 2000;
    const Uint32 fadeOutDuration = 2000;
    const Uint32 totalDuration = 5000;

    if (startTime == 0) {
        startTime = SDL_GetTicks();
    }

    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    int alpha = 255;

    if (elapsedTime < fadeInDuration) {
        alpha = (255 * elapsedTime) / fadeInDuration;  // Fade-in
    } else if (elapsedTime > totalDuration - fadeOutDuration) {
        alpha = (255 * (totalDuration - elapsedTime)) / fadeOutDuration;  // Fade-out
    }

    if (elapsedTime >= totalDuration) {
        *gamestate = MAIN_MENU;  // Cambiar el estado después de la duración total
    } else {
        SDL_SetTextureAlphaMod(loadedImages[0].texture, alpha);  // Aplicar el alfa
        SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);  // Renderizar la textura
    }
}



void renderMenu(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {

}

void renderLobby(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {

}

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {

}

void renderSettings(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {

}

void renderCredits(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {

}
