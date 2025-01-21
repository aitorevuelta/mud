#ifndef BUTTONS_UTILS_H
#define BUTTONS_UTILS_H

bool isClickInsideButton(int coords[2], SDL_Rect rect);

int allocateButtons(BUTTON** buttons, int buttonCount);
void LoadButtonsByGameState(BUTTON** buttons, GAMESTATE gameState, IMAGES loadedImages[]);

void initializeButtonsMenu(BUTTON* buttons, IMAGES loadedImages[]);
void initializeButtonsLobby(BUTTON* buttons, IMAGES loadedImages[]);
void initializeButtonsGame(BUTTON* buttons, IMAGES loadedImages[]);
void initializeButtonsH2P(BUTTON* buttons, IMAGES loadedImages[]);
void initializeButtonsSettings(BUTTON* buttons, IMAGES loadedImages[]);
void initializeButtonsCredits(BUTTON *buttons, IMAGES loadedImages[]);
void initializeButtonsGame(BUTTON* buttons, IMAGES loadedImages[]);

#endif 