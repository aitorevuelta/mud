#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <menu_render.h>
#include <render.h>


int renderMenu(int rend_menu, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages) {
    // Variable estática para controlar la inicialización
    int buttonCount = 5;
    if(rend_menu==0){
    // Solo inicializa los botones una vez
    
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtonsMenu(*buttons, loadedImages);

       rend_menu = 1;
    }
    // Renderiza los botones
   renderTextureRelative(renderer, loadedImages[5].texture, 100, 50, 50);
   renderButtons(renderer, *buttons, buttonCount);

   return rend_menu;
}

void initializeButtonsMenu(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ //BOTON JUGAR
        .texture = loadedImages[0].texture, 
        .action = ACTION_PLAY, 
        .visible = 1, 
        .widthPercent = 25.0, 
        .xPercent = 30.0, 
        .yPercent = 25.0 
    };
    buttons[1] = (BUTTON){ //BOTON HOW TO PLAY
        .texture = loadedImages[1].texture, 
        .action = ACTION_HOWTOPLAY, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 30.0, 
        .yPercent = 50.0 
    };
    buttons[2] = (BUTTON){ //BOTON CREDITOS
        .texture = loadedImages[2].texture, 
        .action = ACTION_CREDITS, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 30.0, 
        .yPercent = 70.0 
    };
    buttons[3] = (BUTTON){ //BOTON SETTINGS
        .texture = loadedImages[3].texture, 
        .action = ACTION_SETTINGS, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 30.0, 
        .yPercent = 90.0 
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