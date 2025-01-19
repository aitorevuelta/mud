#ifndef ASSETS_UTILS_H
#define ASSETS_UTILS_H

#define MAX_TEXTURES 50

int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadImages(SDL_Renderer* renderer, IMAGES** loadedImages, GAMESTATE gameState);

TTF_Font* CreateFont(const char* filePath, int fontSize);
void LoadFonts(SDL_Renderer* renderer, FONTS** loadedFonts, GAMESTATE gameState);

void LoadAssets(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE gameState);


SDL_Color getPixelColor(SDL_Texture *texture, int x, int y);
SDL_Color getRandomColour();


#endif // ASSETS_UTILS_H