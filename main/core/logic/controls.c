#include <global.h>

#include <controls.h>


KEYS get_key_code(SDL_Keycode key) {
    KEYS key_code;
    switch (key) {
        case SDLK_ESCAPE: key_code = ESC_KEY; break;
        case SDLK_F1: key_code = F1_KEY; break;
        case SDLK_F2: key_code = F2_KEY; break;
        case SDLK_F3: key_code = F3_KEY; break;
        case SDLK_F4: key_code = F4_KEY; break;
        case SDLK_F5: key_code = F5_KEY; break;
        case SDLK_F6: key_code = F6_KEY; break;
        case SDLK_F7: key_code = F7_KEY; break;
        case SDLK_F8: key_code = F8_KEY; break;
        case SDLK_F9: key_code = F9_KEY; break;
        case SDLK_F10: key_code = F10_KEY; break;
        case SDLK_F11: key_code = F11_KEY; break;
        case SDLK_F12: key_code = F12_KEY; break;
        case SDLK_1: key_code = NUM1_KEY; break;
        case SDLK_2: key_code = NUM2_KEY; break;
        case SDLK_3: key_code = NUM3_KEY; break;
        case SDLK_4: key_code = NUM4_KEY; break;
        case SDLK_5: key_code = NUM5_KEY; break;
        case SDLK_6: key_code = NUM6_KEY; break;
        case SDLK_7: key_code = NUM7_KEY; break;
        case SDLK_8: key_code = NUM8_KEY; break;
        case SDLK_9: key_code = NUM9_KEY; break;
        case SDLK_0: key_code = NUM0_KEY; break;
        case SDLK_MINUS: key_code = MINUS_KEY; break;
        case SDLK_EQUALS: key_code = EQUALS_KEY; break;
        case SDLK_BACKSPACE: key_code = BACKSPACE_KEY; break;
        case SDLK_TAB: key_code = TAB_KEY; break;
        case SDLK_q: key_code = Q_KEY; break;
        case SDLK_w: key_code = W_KEY; break;
        case SDLK_e: key_code = E_KEY; break;
        case SDLK_r: key_code = R_KEY; break;
        case SDLK_t: key_code = T_KEY; break;
        case SDLK_y: key_code = Y_KEY; break;
        case SDLK_u: key_code = U_KEY; break;
        case SDLK_i: key_code = I_KEY; break;
        case SDLK_o: key_code = O_KEY; break;
        case SDLK_p: key_code = P_KEY; break;
        case SDLK_LEFTBRACKET: key_code = LEFT_BRACKET_KEY; break;
        case SDLK_RIGHTBRACKET: key_code = RIGHT_BRACKET_KEY; break;
        case SDLK_BACKSLASH: key_code = BACKSLASH_KEY; break;
        case SDLK_a: key_code = A_KEY; break;
        case SDLK_s: key_code = S_KEY; break;
        case SDLK_d: key_code = D_KEY; break;
        case SDLK_f: key_code = F_KEY; break;
        case SDLK_g: key_code = G_KEY; break;
        case SDLK_h: key_code = H_KEY; break;
        case SDLK_j: key_code = J_KEY; break;
        case SDLK_k: key_code = K_KEY; break;
        case SDLK_l: key_code = L_KEY; break;
        case SDLK_SEMICOLON: key_code = SEMICOLON_KEY; break;
        case SDLK_QUOTE: key_code = QUOTE_KEY; break;
        case SDLK_RETURN: key_code = ENTER_KEY; break;
        case SDLK_LSHIFT: key_code = SHIFT_LEFT_KEY; break;
        case SDLK_z: key_code = Z_KEY; break;
        case SDLK_x: key_code = X_KEY; break;
        case SDLK_c: key_code = C_KEY; break;
        case SDLK_v: key_code = V_KEY; break;
        case SDLK_b: key_code = B_KEY; break;
        case SDLK_n: key_code = N_KEY; break;
        case SDLK_m: key_code = M_KEY; break;
        case SDLK_COMMA: key_code = COMMA_KEY; break;
        case SDLK_PERIOD: key_code = PERIOD_KEY; break;
        case SDLK_SLASH: key_code = SLASH_KEY; break;
        case SDLK_RSHIFT: key_code = SHIFT_RIGHT_KEY; break;
        case SDLK_LCTRL: key_code = CTRL_LEFT_KEY; break;
        case SDLK_LGUI: key_code = WIN_KEY; break;
        case SDLK_LALT: key_code = ALT_LEFT_KEY; break;
        case SDLK_SPACE: key_code = SPACE_KEY; break;
        case SDLK_RALT: key_code = ALT_RIGHT_KEY; break;
        case SDLK_RCTRL: key_code = CTRL_RIGHT_KEY; break;
        case SDLK_UP: key_code = UP_ARROW_KEY; break;
        case SDLK_DOWN: key_code = DOWN_ARROW_KEY; break;
        case SDLK_LEFT: key_code = LEFT_ARROW_KEY; break;
        case SDLK_RIGHT: key_code = RIGHT_ARROW_KEY; break;
        case SDLK_INSERT: key_code = INSERT_KEY; break;
        case SDLK_HOME: key_code = HOME_KEY; break;
        case SDLK_PAGEUP: key_code = PAGE_UP_KEY; break;
        case SDLK_PAGEDOWN: key_code = PAGE_DOWN_KEY; break;
        case SDLK_DELETE: key_code = DELETE_KEY; break;
        case SDLK_END: key_code = END_KEY; break;

        default:
            key_code = false;
            break;
    }

    return key_code;
}

bool process_events(GAMECONTEXT* gameContext) {
    SDL_Event event;
    bool run = true;

    // Reinicia valores de control que deben ser temporales
    gameContext->controls.scroll = 0;

    // Procesar todos los eventos en la cola
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                handle_keyboard_event(&event, &gameContext->controls);
                break;

            case SDL_MOUSEMOTION:
                handle_mouse_motion(event, &gameContext->controls);
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                handle_mouse_button_event(&event, &gameContext->controls);
                break;

            case SDL_MOUSEWHEEL:
                handle_mouse_wheel_event(&event, &gameContext->controls);
                break;

            case SDL_WINDOWEVENT:
                handle_window_event(event, gameContext);
                break;

            case SDL_QUIT:
                run = false;
                break;

            default:
                // Manejo de eventos adicionales (opcional)
                break;
        }
    }

    return run;
}


void handle_mouse_motion(SDL_Event event, CONTROLS *controls) {
    controls->coords[0] = event.motion.x;
    controls->coords[1] = event.motion.y;
}


void handle_window_event(SDL_Event event, SDL_Window *window, CONFIG *config) {
    int screenWidth, screenHeight;

    switch (event.window.event) {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
        case SDL_WINDOWEVENT_RESIZED:
        case SDL_WINDOWEVENT_MAXIMIZED:
            SDL_GetWindowSize(window, &screenWidth, &screenHeight);
            config->window_size.width = screenWidth;
            config->window_size.height = screenHeight;
            break;

        case SDL_WINDOWEVENT_MINIMIZED:
            break;

        case SDL_WINDOWEVENT_CLOSE:
            break;

        default:
            break;
    }
}
