#ifndef MENU_RENDER_H
#define MENU_RENDER_H


int menu_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, int rend_menu);


void renderMenuBackground(SDL_Renderer *renderer, ASSETS *loadedAssets);
void renderMenuButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif 
