#include <global.h>

#include <assets_utils.h>

#include <loadscreen_render.h>


void loadscreen_render(SDL_Renderer *renderer, ASSETS loadedAssets) {
    static Uint32 startTime = 0;
    const Uint32 fadeInDuration = 2000, fadeOutDuration = 2000, totalDuration = 5000;

    if (!startTime) startTime = SDL_GetTicks();

    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    int alpha = 255;

    if (elapsedTime < fadeInDuration) {
        alpha = (255 * elapsedTime) / fadeInDuration;
    } else if (elapsedTime > totalDuration - fadeOutDuration) {
        alpha = (255 * (totalDuration - elapsedTime)) / fadeOutDuration;
    }

    SDL_SetTextureAlphaMod(loadedAssets.images[0].texture, alpha);
    SDL_RenderCopy(renderer, loadedAssets.images[0].texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}