#ifndef  HOWTOPLAY_RENDER_H
#define  HOWTOPLAY_RENDER_H


int renderHowtoplay(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_h2p);
void initializeButtonsH2P(BUTTON *buttons, IMAGES *loadedImages);

#endif 