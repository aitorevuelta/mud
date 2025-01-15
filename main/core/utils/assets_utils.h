#ifndef ASSETS_UTILS_H
#define ASSETS_UTILS_H

#define MAX_TEXTURES 50

int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

typedef struct IMAGES_S {
    SDL_Texture* texture;
} IMAGES;

typedef struct MUSIC_S {
    Mix_Music *music;
}MUSIC;
typedef struct FONTS_S {
    TTF_Font* font;
} FONTS;

typedef struct ASSETS_S {
    IMAGES *images;
    MUSIC *music;
    FONTS *fonts;
}ASSETS;


SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer);
void LoadImages(IMAGES** loadedImages, GAMESTATE gameState, SDL_Renderer* renderer);

TTF_Font* CreateFont(const char* filePath, int fontSize);
void LoadFonts(FONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer);

void LoadAssets(ASSETS *loadedAssets, GAMESTATE gameState, SDL_Renderer* renderer);

void renderText(SDL_Renderer *renderer, FONTS *loadedFonts, const char *text, SDL_Color color, int x, int y);

SDL_Color getPixelColor(SDL_Texture *texture, int x, int y);


#endif // ASSETS_UTILS_H