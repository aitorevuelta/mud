#ifndef LOBBY_RENDER_H´
#define LOBBY_RENDER_H


int renderLobby(int rend_lbby, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, GAMEINFO *gameInfo);
void initializeButtonsLobby(BUTTON *buttons, IMAGES *loadedImages);
void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount);
void renderSelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap);

#endif  // RENDERLOBBY_H