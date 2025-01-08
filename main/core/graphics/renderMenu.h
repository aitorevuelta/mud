#ifndef RENDERMENU_H
#define RENDERMENU_H

/*

*/
void renderMenu(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config);

void initializeButtons(BUTTON *buttons, LOADEDIMAGES *loadedImages);
void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif  // RENDERMENU_H

    