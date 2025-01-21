#ifndef SETTINGS_H
#define SETTINGS_H

typedef enum {
    LEFT_ARROW = 1,
    RIGHT_ARROW,
    APPLY,
    VOLUME_UP,
    VOLUME_DOWN,
    RESET,
} SETTINGS_BUTTONS;

void handleSettingsButtons(BUTTON buttons[], int buttonCount, CONTROLS controls, CONFIG* config, GAMESTATE* gameState);
void proccesButtonAction(int buttonIndex, CONFIG* config, GAMESTATE* gameState);
void applyResolution(int resolution);
void resetConfiguration(CONFIG* config);

#endif // SETTINGS_H