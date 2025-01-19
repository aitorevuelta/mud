#include <global.h>

#include <controls.h>
#include <settings_utils.h>

#include <gamecontext.h>


GAMECONTEXT* initializeGameContext() {
   GAMECONTEXT* ctx = (GAMECONTEXT*)malloc(sizeof(GAMECONTEXT));  // Asegúrate de asignar memoria correctamente

    if (ctx == NULL) {
        // Manejo de error si la memoria no se pudo asignar correctamente
        printf("Error al asignar memoria para GAMECONTEXT.\n");
        return NULL;
    }

    // Inicializar todos los miembros del GAMECONTEXT
    ctx->sdl.window = NULL;
    ctx->sdl.renderer = NULL;
    ctx->controls = (CONTROLS){0};  // Inicializar CONTROLS con valores por defecto
    ctx->config = readConfig();      // Inicializar CONFIG con valores por defecto
    ctx->gameState = LOADSCREEN;    // Estado inicial por defecto
    ctx->loadedAssets = (ASSETS){0}; // Inicializar assets como vacío
    ctx->buttons = NULL;

    return ctx;
}
