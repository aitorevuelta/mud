#include <global.h>


#include <buttons_utils.h>

// MALLOC BUTTONS

int allocateButtons(BUTTON **buttons, int buttonCount) {
    if (buttonCount <= 0) {
        fprintf(stderr, "Error: El conteo de botones debe ser mayor que 0.\n");
        *buttons = NULL;
        return -1;
    }

    *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
    if (*buttons == NULL) {
        fprintf(stderr, "Error al asignar memoria para los botones\n");
        return -1;
    } else {
        printf("Memoria asignada correctamente para %d botones.\n", buttonCount);
        return 0;
    }
}

// MENU

int setupMenuButtons(BUTTON **buttons, ASSETS *loadedAssets) {
    const int buttonCount = 6;  // Number of buttons to initialize

    allocateButtons(buttons, buttonCount);  // Use the new function to allocate memory
    if (*buttons == NULL) {
        return -1;  // Indicate failure in initialization
    }

    initializeButtonsMenu(*buttons, loadedAssets->images);  // Specific lobby initialization
    return 1;  // Indicate that the initialization was successful
}

void initializeButtonsMenu(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ //BOTON JUGAR
        .texture = loadedImages[0].texture, 
        .action = ACTION_PLAY, 
        .visible = 1, 
        .widthPercent = 20.0, 
        .xPercent = 50.0, 
        .yPercent = 50.0 
    };
    buttons[1] = (BUTTON){ //BOTON HOW TO PLAY
        .texture = loadedImages[1].texture, 
        .action = ACTION_HOWTOPLAY, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 25.0, 
        .yPercent = 80.0 
    };
    buttons[2] = (BUTTON){ //BOTON CREDITOS
        .texture = loadedImages[2].texture, 
        .action = ACTION_CREDITS, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 50.0, 
        .yPercent = 80.0 
    };
    buttons[3] = (BUTTON){ //BOTON SETTINGS
        .texture = loadedImages[3].texture, 
        .action = ACTION_SETTINGS, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 75.0, 
        .yPercent = 80.0 
    };
    buttons[4] = (BUTTON){ //BOTON SALIR
        .texture = loadedImages[4].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}


// LOBBY

int setupLobbyButtons(BUTTON **buttons, ASSETS *loadedAssets) {
    const int buttonCount = 6;  // Number of buttons to initialize

    allocateButtons(buttons, buttonCount);  // Use the new function to allocate memory
    if (*buttons == NULL) {
        return -1;  // Indicate failure in initialization
    }

    initializeButtonsLobby(*buttons, loadedAssets->images);  // Specific lobby initialization
    return 1;  // Indicate that the initialization was successful
}

void initializeButtonsLobby(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ // BOTON AÑADIR
        .texture = loadedImages[4].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 15.0,
        .yPercent = 80.0
    };
    buttons[1] = (BUTTON){ // BOTON ELIMINAR
        .texture = loadedImages[5].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 20.0,
        .yPercent = 80.0
    };
    buttons[2] = (BUTTON){ // BOTON PASAR MAPA IZQUIERDA
        .texture = loadedImages[10].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 75.0,
        .yPercent = 90.0
    };
    buttons[3] = (BUTTON){ // BOTON PASAR MAPA DERECHA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 85.0,
        .yPercent = 90.0
    };
    buttons[4] = (BUTTON){ // BOTON JUGAR
        .texture = loadedImages[7].texture,
        .action = ACTION_GAME,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 50.0,
        .yPercent = 90.0
    };
    buttons[5] = (BUTTON){ // BOTON BACK
        .texture = loadedImages[6].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 3.7,
        .xPercent = 3.0,
        .yPercent = 6.0
    };
}

// HOWTOPLAY

int setupH2PButtons(BUTTON **buttons, ASSETS *loadedAssets) {
    const int buttonCount = 6;  // Number of buttons to initialize

    allocateButtons(buttons, buttonCount);  // Use the new function to allocate memory
    if (*buttons == NULL) {
        return -1;  // Indicate failure in initialization
    }

    initializeButtonsH2P(*buttons, loadedAssets->images);  // Specific lobby initialization
    return 1;  // Indicate that the initialization was successful
}

void initializeButtonsH2P(BUTTON *buttons, IMAGES *loadedImages) {
        buttons[0] = (BUTTON){ 
        .texture = loadedImages[1].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}


// SETTINGS

int setupSettingsButtons(BUTTON **buttons, ASSETS *loadedAssets) {
    const int buttonCount = 6;  // Number of buttons to initialize

    allocateButtons(buttons, buttonCount);  // Use the new function to allocate memory
    if (*buttons == NULL) {
        return -1;  // Indicate failure in initialization
    }

    initializeButtonsSettings(*buttons, loadedAssets->images);  // Specific lobby initialization
    return 1;  // Indicate that the initialization was successful
}

void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ // BOTON VOLVER
        .texture = loadedImages[10].texture, 
        .action = ACTION_EXIT,  // Acción para salir de la configuración
        .visible = 1,
        .widthPercent = 3.0,
        .xPercent = 6.0,
        .yPercent = 6.0
    };  
    buttons[1] = (BUTTON){ // BOTON PASAR RESOLUCION IZQUIERDA 
        .texture = loadedImages[8].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 25.0,
        .yPercent = 35.0
    };
    buttons[2] = (BUTTON){ // BOTON PASAR RESOLUCION DERECHA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 45.0,
        .yPercent = 35.0
    };
        buttons[3] = (BUTTON){ //BOTON APLICAR
        .texture = loadedImages[11].texture, 
        .action = ACTION_NONE, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 50.0, 
        .yPercent = 80.0 
    };
        buttons[4] = (BUTTON){  //BOTON SUBIR VOLUMEN
        .texture = loadedImages[12].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 15.7,
        .yPercent = 50.0
        };
        buttons[5] = (BUTTON){  //BOTON BAJAR VOLUMEN
        .texture = loadedImages[13].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 38.5,
        .yPercent = 50.0
        };

}


// CREDITS

int setupCreditsButtons(BUTTON **buttons, ASSETS *loadedAssets) {
    const int buttonCount = 1;  // Number of buttons to initialize

    allocateButtons(buttons, buttonCount);  // Use the new function to allocate memory
    if (*buttons == NULL) {
        return -1;  // Indicate failure in initialization
    }

    initializeButtonsCredits(*buttons, loadedAssets->images);  // Specific lobby initialization
    return 1;  // Indicate that the initialization was successful
}

void initializeButtonsCredits(BUTTON *buttons, IMAGES *loadedImages) {

    buttons[0] = (BUTTON){
        .texture = loadedImages[1].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}
