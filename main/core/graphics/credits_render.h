#ifndef  CREDITS_RENDER_H
#define CREDITS_RENDER_H


int renderCredits(int rend_cred,SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages);
void initializeButtons3(BUTTON *buttons, IMAGES *loadedImages);
void renderButtons3(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif 