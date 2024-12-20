#ifndef LOADSCREEN_H
#define LOADSCREEN_H

bool renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, CONFIG config);
void renderLoadBar(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, int windowWidth, int windowHeight, float percentage);
bool updateLoading(float *percentage);
#endif