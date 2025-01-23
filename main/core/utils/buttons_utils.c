#include <global.h>


#include <buttons_utils.h>


bool isClickInsideButton(int coords[2], SDL_Rect rect) {
    return coords[0] >= rect.x &&
           coords[0] <= rect.x + rect.w &&
           coords[1] >= rect.y &&
           coords[1] <= rect.y + rect.h;
}

int allocateButtons(BUTTON **buttons, int buttonCount) {
    if (!buttons || buttonCount <= 0) return -1;

    *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
    return (*buttons) ? 0 : -1;
}

void LoadButtonsByGameState(BUTTON** buttons, GAMESTATE gameState, IMAGES loadedImages[]) {
    int buttonCount = 0;

    if (!buttons) return;

    switch (gameState) {
        case MAIN_MENU:
            buttonCount = 5;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsMenu(*buttons, loadedImages);
            break;
        case LOBBY:
            buttonCount = 6;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsLobby(*buttons, loadedImages);
            break;
        case GAME:
            buttonCount = 3;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsGame(*buttons, loadedImages);
            break;
        case HOWTOPLAY:
            buttonCount = 1;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsH2P(*buttons, loadedImages);
            break;
        case SETTINGS:
            buttonCount = 6;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsSettings(*buttons, loadedImages);
            break;
        case CREDITS:
            buttonCount = 1;
            if (allocateButtons(buttons, buttonCount) != 0) return;
            initializeButtonsCredits(*buttons, loadedImages);
            break;
        default:
            return;
    }
}

// MENU

void initializeButtonsMenu(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){ // PLAY
        .texture = loadedImages[0].texture,
        .action = ACTION_PLAY,
        .visible = 1,
        .widthPercent = 20.0,
        .xPercent = 50.0,
        .yPercent = 80.0
    };
    buttons[1] = (BUTTON){ // HOW TO PLAY
        .texture = loadedImages[1].texture,
        .action = ACTION_HOWTOPLAY,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 25.0,
        .yPercent = 80.0
    };
    buttons[2] = (BUTTON){ // CREDITS
        .texture = loadedImages[2].texture,
        .action = ACTION_CREDITS,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 75.0,
        .yPercent = 80.0
    };
    buttons[3] = (BUTTON){ // SETTINGS
        .texture = loadedImages[3].texture,
        .action = ACTION_SETTINGS,
        .visible = 1,
        .widthPercent = 7.5,
        .xPercent = 95.0,
        .yPercent = 5.0
    };
    buttons[4] = (BUTTON){ // IRTEN
        .texture = loadedImages[4].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 3.0,
        .yPercent = 10.0
    };
}


// LOBBY

void initializeButtonsLobby(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){ // JOKALARIAK GEHITU
        .texture = loadedImages[4].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 15.0,
        .yPercent = 80.0
    };
    buttons[1] = (BUTTON){ // JOKALARIAK KENDU
        .texture = loadedImages[5].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 20.0,
        .yPercent = 80.0
    };
    buttons[2] = (BUTTON){ // MAPAK EZKERRETARA
        .texture = loadedImages[10].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 75.0,
        .yPercent = 90.0
    };
    buttons[3] = (BUTTON){ // MAPAK ESKUINETARA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 85.0,
        .yPercent = 90.0
    };
    buttons[4] = (BUTTON){ // JOLASTU
        .texture = loadedImages[7].texture,
        .action = ACTION_GAME,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 50.0,
        .yPercent = 90.0
    };
    buttons[5] = (BUTTON){ // ATZERA
        .texture = loadedImages[6].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 3.0,
        .yPercent = 4.0
    };
}


// GAME 

void initializeButtonsGame(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){ 
        .texture = loadedImages[8].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 7.0,
        .xPercent = 5.0,
        .yPercent = 89.0
    };
    buttons[1] = (BUTTON){ 
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 6.5,
        .xPercent = 50.0,
        .yPercent = 93.5
    };
    buttons[2] = (BUTTON){  // ITZULI
        .texture = loadedImages[10].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 95.5,
        .yPercent = 9.0
    };
 }




// HOWTOPLAY

void initializeButtonsH2P(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){ // ITZULI
        .texture = loadedImages[1].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 3.0,
        .yPercent = 4.0
    };
}

// SETTINGS

void initializeButtonsSettings(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){ // ITZULI
        .texture = loadedImages[10].texture,
        .action = ACTION_EXIT, 
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 3.0,
        .yPercent = 4.0
    };
    buttons[1] = (BUTTON){ // ERRESOLUZIOA EZKERRETARA
        .texture = loadedImages[8].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 25.0,
        .yPercent = 35.0
    };
    buttons[2] = (BUTTON){ // ERRESOLUZIOA ESKUINETARA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 45.0,
        .yPercent = 35.0
    };
    buttons[3] = (BUTTON){ // APPLY
        .texture = loadedImages[11].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 50.0,
        .yPercent = 80.0
    };
    buttons[4] = (BUTTON){  // BOLUMENA IGO
        .texture = loadedImages[12].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 17.0,
        .yPercent = 50.0
    };
    buttons[5] = (BUTTON){  // BOLUMENA BAJATU
        .texture = loadedImages[13].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 39.0,
        .yPercent = 50.0
    };
}

// CREDITS

void initializeButtonsCredits(BUTTON* buttons, IMAGES loadedImages[]) {
    buttons[0] = (BUTTON){  // ITZULI
        .texture = loadedImages[1].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 3.0,
        .yPercent = 4.0
    };
}
