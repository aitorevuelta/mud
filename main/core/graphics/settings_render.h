#ifndef SETTINGS_RENDER_H
#define SETTINGS_RENDER_H


void settings_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets, CONFIG config);

void renderSelectedResolution(SDL_Renderer *renderer, IMAGES loadedImages[], int selectedResolution);
void renderSelectedVolume(SDL_Renderer *renderer, IMAGES loadedImages[], int selectedVolume);

#endif 