#ifndef BUTTONS_UTILS_H
#define BUTTONS_UTILS_H


int allocateButtons(BUTTON **buttons, int buttonCount);

int setupMenuButtons(BUTTON **buttons, int buttonCount, ASSETS *loadedAssets);
void initializeButtonsMenu(BUTTON buttons[], IMAGES *loadedImages);

int setupLobbyButtons(BUTTON **buttons, int buttonCount, ASSETS *loadedAssets);
void initializeButtonsLobby(BUTTON buttons[], IMAGES *loadedImages);

int setupH2PButtons(BUTTON **buttons, int buttonCount, ASSETS *loadedAssets);
void initializeButtonsH2P(BUTTON buttons[], IMAGES *loadedImages);

int setupSettingsButtons(BUTTON **buttons,  int countButton, ASSETS *loadedAssets);
void initializeButtonsSettings(BUTTON buttons[], IMAGES *loadedImages);

int setupCreditsButtons(BUTTON **buttons, int buttonCount, ASSETS *loadedAssets);
void initializeButtonsCredits(BUTTON buttons[], IMAGES *loadedImages);

#endif 