#ifndef GAME_RENDER_H
#define GAME_RENDER_H

void game_render(SDL_Renderer *renderer, ASSETS loadedAssets, BUTTON *buttons, GAMEINFO gameInfo, RESOLUTION resolution);
void renderMap(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo, RESOLUTION resolution);
void renderUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo);
void renderSideUI(SDL_Renderer *renderer, ASSETS loadedAssets, int numPlayers, PLAYER players[], int turn);
void renderBottomUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo);
void renderTimeBar(SDL_Renderer *renderer, float elapsedTime, SDL_Color playerColor);
void renderRound(SDL_Renderer *renderer, ASSETS loadedAssets, int round);

#endif // GAME_RENDER_H