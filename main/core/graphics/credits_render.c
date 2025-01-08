#include <global.h>

#include <texturemanager.h>

#include <credits_render.h>

void renderCredits(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState) {
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);   
}