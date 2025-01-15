#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


int renderSettings(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_sett);
void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages);

#endif 