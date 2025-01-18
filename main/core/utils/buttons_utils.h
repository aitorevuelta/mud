#ifndef BUTTONS_UTILS_H
#define BUTTONS_UTILS_H


int allocateButtons(BUTTON **buttons, int buttonCount);

int setupMenuButtons(BUTTON **buttons, ASSETS *loadedAssets);
void initializeButtonsMenu(BUTTON *buttons, IMAGES *loadedImages);

int setupLobbyButtons(BUTTON **buttons, ASSETS *loadedAssets);
void initializeButtonsLobby(BUTTON *buttons, IMAGES *loadedImages);

int setupH2PButtons(BUTTON **buttons, ASSETS *loadedAssets);
void initializeButtonsH2P(BUTTON *buttons, IMAGES *loadedImages);

int setupSettingsButtons(BUTTON **buttons, ASSETS *loadedAssets);
void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages);

int setupCreditsButtons(BUTTON **buttons, ASSETS *loadedAssets);
void initializeButtonsCredits(BUTTON *buttons, IMAGES *loadedImages);

#endif 