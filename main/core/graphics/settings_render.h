#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


int renderSettings(int rend_sett, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages);
void initializeButtons2(BUTTON *buttons, IMAGES *loadedImages);
void renderButtons2(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif 