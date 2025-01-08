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


TTF_Font* CreateFont(const char* filePath, int fontSize) {
    TTF_Font* font = TTF_OpenFont(filePath, fontSize);
    if (!font) {
        fprintf(stderr, "Error al cargar la fuente: %s, %s\n", filePath, TTF_GetError());
    }
    return font;
}


void LoadImages(LOADEDIMAGES** loadedImages, GAMESTATE gameState, SDL_Renderer* renderer) {
    int numTextures = countPathsInState(gameState, IMAGES_FILE);
    int i;
    char filePath[MAX_STR];

    if (*loadedImages != NULL) {
        free(*loadedImages);
        *loadedImages = NULL;
    }

    *loadedImages = (LOADEDIMAGES*)malloc(numTextures * sizeof(LOADEDIMAGES));
    if (*loadedImages == NULL) {
        fprintf(stderr, "Error al asignar memoria para loadedImages\n");
        return;
    }

    for (i = 0; i < numTextures; i++) {
        char* path = getPathByIndex(gameState, IMAGES_FILE, i);
        if (path == NULL) {
            fprintf(stderr, "Error al obtener la ruta para el índice %d\n", i);
            continue;
        }

        snprintf(filePath, sizeof(filePath), "../src/img/%s", path);

        (*loadedImages)[i].texture = CreateTexture(filePath, renderer);

        if ((*loadedImages)[i].texture == NULL) {
            fprintf(stderr, "Error al cargar la textura para el archivo %s\n", filePath);
        }
    }
}


void LoadFonts(LOADEDFONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer) {
    int numFonts = countPathsInState(gameState, FONTS_FILE);
    char filePath[MAX_STR];

    if (*loadedFonts != NULL) {
        free(*loadedFonts);
        *loadedFonts = NULL;
    }

    *loadedFonts = (LOADEDFONTS*)malloc(numFonts * sizeof(LOADEDFONTS));

    if (*loadedFonts == NULL) return;

    for (int i = 0; i < numFonts; i++) {
        char* path = getPathByIndex(gameState, FONTS_FILE, i);
        if (path == NULL) continue;

        char fontName[MAX_STR];
        int fontSize;

        if (sscanf(path, "%s %d", fontName, &fontSize) != 2) continue;

        snprintf(filePath, sizeof(filePath), "../src/fonts/%s", fontName);
        (*loadedFonts)[i].font = CreateFont(filePath, fontSize);

        if ((*loadedFonts)[i].font == NULL) {
            fprintf(stderr, "Error al cargar la fuente: %s con tamaño %d\n", fontName, fontSize);
        }
    }
}


