#include <global.h>

#include <sdl_utils.h>
#include <controls.h>
#include <menu.h>
#include <settings.h>
#include <loadscreen.h>
#include <game.h>
#include <lobby.h>
#include <assets_utils.h>
#include <gamestate_utils.h>
#include <camera.h>

#include <update.h>


GAMESTATE update(GAMECONTEXT *gameContext) {
    Uint32 frameStart = SDL_GetTicks();

    // Determinar el estado actual del juego
    switch (gameContext->gameInfo.state) {
        case LOADSCREEN:
            gameContext->gameInfo.state = loadscreen();
            break;

        case MAIN_MENU:
        case HOWTOPLAY:
        case CREDITS:
            handleMenuEvents(gameContext->buttons, 
                             getButtonCountForState(gameContext->gameInfo.state), 
                             &gameContext->gameInfo.state, 
                             &gameContext->controls);
            break;

        case SETTINGS:
            handleResolutionButtons(gameContext->sdl.window, 
                                    gameContext->buttons, 
                                    5, 
                                    &gameContext->controls, 
                                    &gameContext->gameInfo.state, 
                                    &gameContext->config);
            break;

        case LOBBY:
            handleGameStateButtons(gameContext->buttons, 6, 
                                   &gameContext->gameInfo.state, 
                                   &gameContext->controls);
            handlePlayerButtons(gameContext->buttons, 4, 
                                &gameContext->gameInfo, 
                                &gameContext->controls);
            break;

        case GAME:
            // Inicializar el estado del juego si es necesario
            game_init(&gameContext->gameInfo);
            updateCamera(&gameContext->gameInfo.camera, 
                         &gameContext->controls, 
                         gameContext->config.window_size.width, 
                         gameContext->config.window_size.height);
            break;
    }

    // Verificar cambios en el estado del juego
    checkGameStateChange(gameContext->sdl.renderer, 
                         &gameContext->loadedAssets, 
                         &gameContext->gameInfo.state);

    // Ajustar la velocidad de fotogramas
    adjustFrameRate(frameStart, gameContext->config.max_FPS);

    return gameContext->gameInfo.state;
}


void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
