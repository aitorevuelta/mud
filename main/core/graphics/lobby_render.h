#ifndef LOBBY_RENDER_H´
#define LOBBY_RENDER_H


int renderLobby(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMEINFO *gameInfo, int rend_lbby);
void initializeButtonsLobby(BUTTON *buttons, IMAGES *loadedImages);
void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount);
void renderSelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap);

#endif  // RENDERLOBBY_H