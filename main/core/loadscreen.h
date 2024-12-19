#ifndef LOADSCREEN_H
#define LOADSCREEN_H

void renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, CONFIG config);
void renderLoadBar(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, int windowWidth, int windowHeight, float percentage);

#endif