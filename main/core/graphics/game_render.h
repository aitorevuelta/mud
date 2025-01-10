#ifndef GAME_RENDER_H
#define GAME_RENDER_H

int renderGame(int rend_game, SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMEINFO* gameinfo, CONFIG config);
void renderMap(SDL_Renderer *renderer);
void renderUI(SDL_Renderer *renderer);

#endif // GAME_RENDER_H