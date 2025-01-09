#ifndef GAME_RENDER_H
#define GAME_RENDER_H

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO* gameInfo);
void renderMap(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages);
void renderUI(SDL_Renderer *renderer);

#endif // GAME_RENDER_H