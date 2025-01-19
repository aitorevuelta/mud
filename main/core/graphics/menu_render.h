#ifndef MENU_RENDER_H
#define MENU_RENDER_H


int menu_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets);


void renderMenuBackground(SDL_Renderer *renderer, ASSETS *loadedAssets);

#endif 
