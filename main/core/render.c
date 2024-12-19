#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>

void render(SDL_Renderer *renderer, LOADEDTEXTURES *loadedTextures) {
    if (loadedTextures != NULL && loadedTextures[0].texture != NULL) {
        // Limpiar el renderer
        SDL_RenderClear(renderer);

        // Copiar la primera textura (o la textura que desees) al renderer
        SDL_RenderCopy(renderer, loadedTextures[0].texture, NULL, NULL);

        // Presentar el renderer (actualizar la pantalla)
        SDL_RenderPresent(renderer);
    } else {
        // En caso de que no haya texturas cargadas, podemos mostrar un mensaje de advertencia o hacer algo alternativo
        fprintf(stderr, "No hay texturas cargadas para renderizar.\n");
    }
}
