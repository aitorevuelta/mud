#ifndef GAME_RENDER_H
#define GAME_RENDER_H

void game_render(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo, CONFIG config);
void renderMap(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo);
void renderUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo);
void renderSideUI(SDL_Renderer *renderer, ASSETS loadedAssets, int numPlayers, PLAYER players[]);
void renderBottomUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo);
void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed);

#endif // GAME_RENDER_H