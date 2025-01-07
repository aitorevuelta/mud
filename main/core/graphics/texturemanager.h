#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#define MAX_TEXTURES 50
typedef struct LOADEDIMAGES_S {
    SDL_Texture* texture;
} LOADEDIMAGES;

typedef struct LOADEDFONTS_S {
    TTF_Font* font;
} LOADEDFONTS;

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadImages(LOADEDIMAGES** loadedImages, GAMESTATE gameState, SDL_Renderer* renderer);

TTF_Font* CreateFont(const char* filePath, int fontSize);
void LoadFonts(LOADEDFONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer);

#endif