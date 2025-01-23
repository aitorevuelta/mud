#ifndef LOBBY_RENDER_H
#define LOBBY_RENDER_H

void lobby_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets, GAMEINFO gameInfo);
void renderLobbyPlayers(SDL_Renderer *renderer, ASSETS loadedAssets, int playerCount);
void renderLobbySelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap);
void getPlayerPosition(int index, int positions[][2], int maxPositions, int *x, int *y);

#endif  // RENDERLOBBY_H