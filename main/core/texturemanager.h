#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#define MAX_TEXTURES 50
typedef struct LOADEDTEXTURES_S {
    SDL_Texture* texture;
} LOADEDTEXTURES;

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadTextures(LOADEDTEXTURES** loadedTextures, GAMESTATE gameState, SDL_Renderer* renderer);

#endif