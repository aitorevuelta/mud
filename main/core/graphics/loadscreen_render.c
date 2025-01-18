#include <global.h>

#include <assets_utils.h>

#include <loadscreen_render.h>


void loadscreen_render(SDL_Renderer *renderer, ASSETS *loadedAssets) {
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

    SDL_SetTextureAlphaMod(loadedAssets->images[0].texture, alpha);  // Aplicar el alfa
    SDL_RenderCopy(renderer, loadedAssets->images[0].texture, NULL, NULL);  // Renderizar la textura
    SDL_RenderPresent(renderer);  // Presentar el renderizado

    if (elapsedTime >= totalDuration) {
        // Cambiar el estado del juego después de la duración total
        // Esto debería ser manejado en el bucle principal
    }
}