#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


int renderSettings(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMEINFO *gameInfo, int rend_sett);
void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages);
void renderSelectedResolution(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedResolution);

#endif 