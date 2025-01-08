#ifndef MENU_RENDER_H
#define MENU_RENDER_H


void renderMenu(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);

void initializeButtons(BUTTON *buttons, LOADEDIMAGES *loadedImages);
void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif  // MENU_RENDER_H

    