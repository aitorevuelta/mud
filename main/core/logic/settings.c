#include <global.h>

#include <controls.h>
#include <assets_utils.h>
#include <settings_utils.h>
#include <render.h>
#include <menu.h>

#include <settings.h>


void handleSettingsButtons(BUTTON buttons[], int buttonCount, CONTROLS controls, CONFIG* config, GAMESTATE* gameState) {
    int i = 0;
    static Uint32 lastClickTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (controls.click == 1 && (currentTime - lastClickTime > 200)) { // 200 ms debounce time
        lastClickTime = currentTime;
        controls.click = 0;
        for (i = 0; buttonCount > i; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (isClickInsideButton(controls.coords, rect)) {
                    if (buttons[i].action == ACTION_NONE) {
                        proccesButtonAction(i, config, gameState);
                    }
                    if (gameState != NULL) {
                        GAMESTATE currentState = *gameState;
                        if (buttons[i].action != ACTION_NONE) { 
                            *gameState = buttons[i].action;
                        }
                        handleExitStates(currentState, gameState);
                    }
                    controls.click = 0;
                    return; 
                }
            }
        }
    }
}


void proccesButtonAction(int buttonIndex, CONFIG* config, GAMESTATE* gameState) {
    switch (buttonIndex) {
        case LEFT_ARROW:
            if (config->current_res > 1) {
                config->current_res--;
            } else config->current_res = 7; 
            break;
        case RIGHT_ARROW:
            if (config->current_res < 7) {
                config->current_res++;
            } else config->current_res = 1; 
            break;
        case APPLY:
            applyResolution(config->current_res);
            config->volume = config->selectedVolume * 20;
            Mix_VolumeMusic(config->volume);
            saveConfig(*config);
            break;
        case VOLUME_UP:
            if (config->selectedVolume < 5) {
                config->selectedVolume++;
            }
            break;
        case VOLUME_DOWN:
            if (config->selectedVolume > 0) {
                config->selectedVolume--;
            }
            break;
        case RESET:
            resetConfiguration(config);
        default:
            break;
    }
}

bool isClickInsideButton(int coords[2], SDL_Rect rect) {
    return coords[0] >= rect.x &&
           coords[0] <= rect.x + rect.w &&
           coords[1] >= rect.y &&
           coords[1] <= rect.y + rect.h;
}

void applyResolution(int resolution) {
    int width, height;
    switch (resolution) {
        case 1:
            width = 800;
            height = 600;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 2:
            width = 1024;
            height = 768;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 3:
            width = 1280;
            height = 720;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 4:
            width = 1366;
            height = 768;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 5:
            width = 1600;
            height = 900;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 6:
            width = 1920;
            height = 1080;
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), 0);
            break;
        case 7:
            SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), SDL_WINDOW_FULLSCREEN_DESKTOP);
            break;
        default:
            width = 800;
            height = 600;
            break;
    }

    SDL_SetWindowSize(SDL_GetWindowFromID(1), width, height);
    SDL_SetWindowPosition(SDL_GetWindowFromID(1), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void resetConfiguration(CONFIG* config) {

    if(config != NULL) free(config);
    
    config->window_size.width = 1280;
    config->window_size.height = 720;
    config->fullscreen = 0;
    config->selectedVolume = 3;
    config->current_res = 3;

    saveConfig(*config);
}