#ifndef LOBBY_RENDER_H´
#define LOBBY_RENDER_H


int renderLobby(int rend_lbby, SDL_Renderer *renderer, BUTTON **buttons,BUTTON_JUEGO **buttons_juego, IMAGES *loadedImages,GAMEINFO *gameInfo);
void initializeButtons5(BUTTON_JUEGO *buttons_juego,IMAGES *loadedImages);
void initializeButtons6(BUTTON *buttons,IMAGES *loadedImages);
void renderButtons5(SDL_Renderer *renderer, BUTTON *buttons,BUTTON_JUEGO *buttons_juego, int buttonCount);
void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages,int playerCount);      
void renderSelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap);
#endif  // RENDERLOBBY_H