#ifndef MENU_RENDER_H
#define MENU_RENDER_H


int renderMenu(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_menu);
void initializeButtonsMenu(BUTTON *buttons, IMAGES *loadedImages);

#endif 
