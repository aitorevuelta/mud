#ifndef MENU_RENDER_H
#define MENU_RENDER_H


int renderMenu(int rend_menu,SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages);
void initializeButtonsMenu(BUTTON *buttons, IMAGES *loadedImages);

#endif 
