#ifndef ASSETS_UTILS_H
#define ASSETS_UTILS_H

#define MAX_TEXTURES 50

int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

typedef struct IMAGES_S {
    SDL_Texture* texture;
} IMAGES;

typedef struct FONTS_S {
    TTF_Font* font;
} FONTS;

SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadImages(IMAGES** loadedImages, GAMESTATE gameState, SDL_Renderer* renderer);

TTF_Font* CreateFont(const char* filePath, int fontSize);
void LoadFonts(FONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer);

void LoadAssets(IMAGES** loadedImages, FONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer);

void renderText(SDL_Renderer *renderer, FONTS *loadedFonts, const char *text, SDL_Color color, int x, int y);

SDL_Color getPixelColor(SDL_Texture *texture, int x, int y);


#endif // ASSETS_UTILS_H