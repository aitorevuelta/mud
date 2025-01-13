#ifndef MENU_RENDER_H
#define MENU_RENDER_H


int renderMenu(int rend_menu,SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages);
void initializeButtons(BUTTON *buttons, IMAGES *loadedImages);
void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif 
