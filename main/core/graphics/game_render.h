#ifndef GAME_RENDER_H
#define GAME_RENDER_H

int renderGame(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo, CONFIG config, int rend_game);
void renderMap(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo);
void renderUI(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo);
void renderPlayerUI(SDL_Renderer *renderer, ASSETS *loadedAssets, int numPlayers, PLAYER *players);
void renderDeployUI(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo);
void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed);

#endif // GAME_RENDER_H