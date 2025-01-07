#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <loadscreen.h>


bool renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, CONFIG config) {
    // Variables para manejar el fade
    const int fadeDuration = 2000; // Duración del fade-in y fade-out en milisegundos
    const int totalDuration = 5000; // Duración total de la pantalla de carga (5 segundos)
    int elapsedTime = 0;
    Uint32 startTime = SDL_GetTicks(); // Tiempo inicial

    while (elapsedTime < totalDuration) {
        elapsedTime = SDL_GetTicks() - startTime;

        // Calcula el alfa según el tiempo transcurrido
        int alpha = 255;
        if (elapsedTime < fadeDuration) {
            // Fade-in
            alpha = (255 * elapsedTime) / fadeDuration;
        } else if (elapsedTime > totalDuration - fadeDuration) {
            // Fade-out
            int fadeOutStart = totalDuration - fadeDuration;
            alpha = (255 * (totalDuration - elapsedTime)) / fadeDuration;
        }

        // Asegúrate de que alpha esté entre 0 y 255
        alpha = alpha < 0 ? 0 : (alpha > 255 ? 255 : alpha);

        // Aplica el alpha a la textura
        SDL_SetTextureAlphaMod(loadedImages[0].texture, alpha);

        // Renderiza la textura
        SDL_RenderClear(renderer); // Limpia la pantalla
        SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);

        // Renderiza la barra de carga (si corresponde)
        float percentage = (float)elapsedTime / totalDuration;

        // Presenta la pantalla
        SDL_RenderPresent(renderer);

        // Pequeño retraso para evitar un bucle muy rápido
        SDL_Delay(16); // Aproximadamente 60 FPS
    }

    return true;
}
