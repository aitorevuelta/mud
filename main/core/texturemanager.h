#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

typedef struct LOADEDTEXTURES_S {
    int id;
    SDL_Texture* texture;
} LOADEDTEXTURES;

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);

#endif