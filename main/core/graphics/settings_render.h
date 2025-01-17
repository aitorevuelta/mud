#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


int renderSettings(int rend_sett, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, GAMEINFO *gameInfo);
void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages);
void renderSelectedResolution(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedResolution);
void renderSelectedVolume(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedVolume);

#endif 