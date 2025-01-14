#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


int renderSettings(int rend_sett, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages);
void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages);

#endif 