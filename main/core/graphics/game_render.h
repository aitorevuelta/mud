#ifndef GAME_RENDER_H
#define GAME_RENDER_H

int renderGame(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config, int rend_game);
void renderMap(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo);
void renderUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo);
void renderPlayerUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, PLAYER playerinfo);

#endif // GAME_RENDER_H