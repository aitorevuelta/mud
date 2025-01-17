#ifndef SETTINGS_H
#define SETTINGS_H



void handleResolutionButtons(SDL_Window *window, BUTTON *buttons, int buttonCount, CONTROLS *controls, GAMESTATE *gameState, CONFIG *config);
void changeResolution(int direction, CONFIG *config);
void applyResolution(SDL_Window *window, CONFIG *config);

#endif // SETTINGS_H