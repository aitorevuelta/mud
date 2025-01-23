#ifndef ASSETS_UTILS_H
#define ASSETS_UTILS_H

#define MAX_TEXTURES 50

#define MAX_LINE_LENGTH 50
#define IMAGES_FILE "../data/images.txt"
#define SOUNDS_FILE "../data/sounds.txt"
#define FONTS_FILE "../data/fonts.txt"


int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadImages(SDL_Renderer* renderer, IMAGES** loadedImages, GAMESTATE gameState);

TTF_Font* CreateFont(const char* filePath);
void LoadFonts(SDL_Renderer* renderer, FONTS** loadedFonts, GAMESTATE gameState);

Mix_Music* CreateSounds(const char* filePath);
void LoadSounds(SOUNDS** loadedSounds, GAMESTATE gameState);


void LoadAssets(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE gameState);
void FreeAssets(ASSETS* loadedAssets);


SDL_Color getPixelColor(SDL_Texture *texture, int x, int y);
SDL_Color getRandomColour();


#endif // ASSETS_UTILS_H