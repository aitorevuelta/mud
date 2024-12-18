#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#define MAX_TEXTURES 50
typedef struct LOADEDTEXTURES_S {
    SDL_Texture* texture;
} LOADEDTEXTURES;

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);

#endif