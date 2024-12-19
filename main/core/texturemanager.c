#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <global.h>
#include <utils.h>
#include <texturemanager.h>

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filePath);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void LoadTextures(LOADEDTEXTURES** loadedTextures, GAMESTATE gameState, SDL_Renderer* renderer) {
    int numTextures = countPathsInState(gameState);
    int i;
    char filePath[MAX_STR];

    if (*loadedTextures != NULL) {
        free(*loadedTextures);
        *loadedTextures = NULL;
    }

    *loadedTextures = (LOADEDTEXTURES*)malloc(numTextures * sizeof(LOADEDTEXTURES));
    if (*loadedTextures == NULL) {
        fprintf(stderr, "Error al asignar memoria para loadedTextures\n");
        return;
    }

    for (i = 0; i < numTextures; i++) {
        char* path = getPathByIndex(gameState, i);
        if (path == NULL) {
            fprintf(stderr, "Error al obtener la ruta para el índice %d\n", i);
            continue;
        }

        snprintf(filePath, sizeof(filePath), "../src/img/%s", path);

        (*loadedTextures)[i].texture = CreateTexture(filePath, renderer);

        free(path);

        if ((*loadedTextures)[i].texture == NULL) {
            fprintf(stderr, "Error al cargar la textura para el archivo %s\n", filePath);
        }
    }
}

