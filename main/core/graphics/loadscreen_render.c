#include <global.h>

#include <assets_utils.h>

#include <loadscreen_render.h>

void renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages) {
    static Uint32 startTime = 0;
    const Uint32 fadeInDuration = 2000;
    const Uint32 fadeOutDuration = 2000;
    const Uint32 totalDuration = 5000;

    if (startTime == 0) {
        startTime = SDL_GetTicks();
    }

    Uint32 elapsedTime = 0;
    while (elapsedTime < totalDuration) {
        elapsedTime = SDL_GetTicks() - startTime;
        int alpha = 255;

<<<<<<< HEAD
        if (elapsedTime < fadeInDuration) {
            alpha = (255 * elapsedTime) / fadeInDuration;  // Fade-in
        } else if (elapsedTime > totalDuration - fadeOutDuration) {
            alpha = (255 * (totalDuration - elapsedTime)) / fadeOutDuration;  // Fade-out
        }

        SDL_SetTextureAlphaMod(loadedImages[0].texture, alpha);  // Aplicar el alfa
        SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);  // Renderizar la textura
        SDL_RenderPresent(renderer);  // Presentar el renderizado

        SDL_Delay(16);  // Añadir un pequeño retraso para limitar la velocidad del bucle (aproximadamente 60 FPS)
    }

    *gamestate = MAIN_MENU;  // Cambiar el estado después de la duración total
=======
    if (elapsedTime < fadeInDuration) {
        alpha = (255 * elapsedTime) / fadeInDuration;
    } else if (elapsedTime > totalDuration - fadeOutDuration) {
        alpha = (255 * (totalDuration - elapsedTime)) / fadeOutDuration;
    }

    SDL_SetTextureAlphaMod(loadedImages[0].texture, alpha);
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);

>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
}