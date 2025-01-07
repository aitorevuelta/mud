#ifndef RENDER_H
#define RENDER_H


void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);
void renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gamestate);
void renderMenu(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);
void renderLobby(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);
void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);
void renderSettings(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);
void renderCredits(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);


#endif