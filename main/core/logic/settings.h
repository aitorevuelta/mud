#ifndef SETTINGS_H
#define SETTINGS_H

typedef enum {
    LEFT_ARROW = 1,
    RIGHT_ARROW,
    APPLY,
    VOLUME_UP,
    VOLUME_DOWN,
} SETTINGS_BUTTONS;

void handleSettingsButtons(BUTTON buttons[], int buttonCount, CONTROLS controls, CONFIG* config, GAMESTATE* gameState);
bool isClickInsideButton(int coords[2], SDL_Rect rect);
void proccesButtonAction(int buttonIndex, CONFIG* config, GAMESTATE* gameState);
void applyResolution(int resolution);

#endif // SETTINGS_H