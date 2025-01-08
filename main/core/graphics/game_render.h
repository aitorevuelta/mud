#ifndef GAME_RENDER_H
#define GAME_RENDER_H

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, GAMEINFO* gameinfo, CONFIG config);
void renderMap(SDL_Renderer *renderer);
void renderUI(SDL_Renderer *renderer);

#endif // GAME_RENDER_H