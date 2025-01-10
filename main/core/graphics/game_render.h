#ifndef GAME_RENDER_H
#define GAME_RENDER_H

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config);
void renderMap(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo);
void renderUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo);
void renderPlayerUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, PLAYER playerinfo);

#endif // GAME_RENDER_H