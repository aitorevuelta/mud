#ifndef GAME_RENDER_H
#define GAME_RENDER_H

<<<<<<< HEAD
int renderGame(int rend_game, SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMEINFO* gameinfo, CONFIG config);
void renderMap(SDL_Renderer *renderer);
void renderUI(SDL_Renderer *renderer);
=======
void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config);
void renderMap(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo);
void renderUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo);
void renderPlayerUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, PLAYER playerinfo);
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a

#endif // GAME_RENDER_H