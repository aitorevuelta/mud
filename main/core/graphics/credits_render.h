#ifndef  CREDITS_RENDER_H
#define CREDITS_RENDER_H


int renderCredits(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_cred);
void initializeButtonsCredits(BUTTON *buttons, IMAGES *loadedImages);

#endif 