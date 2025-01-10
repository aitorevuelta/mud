#ifndef  HOWTOPLAY_RENDER_H
#define  HOWTOPLAY_RENDER_H


int renderHowtoplay(int rend_game, SDL_Renderer *renderer, BUTTON **buttons, LOADEDIMAGES *loadedImages);
void initializeButtons4(BUTTON *buttons, LOADEDIMAGES *loadedImages);
void renderButtons4(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);
#endif 