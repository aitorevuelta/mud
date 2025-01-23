#ifndef CONTROLS_H
#define CONTROLS_H

typedef enum {
    ESC_KEY = 1,         // Tecla Escape
    F1_KEY,              // Tecla F1
    F2_KEY,              // Tecla F2
    F3_KEY,              // Tecla F3
    F4_KEY,              // Tecla F4
    F5_KEY,              // Tecla F5
    F6_KEY,              // Tecla F6
    F7_KEY,              // Tecla F7
    F8_KEY,              // Tecla F8
    F9_KEY,              // Tecla F9
    F10_KEY,             // Tecla F10
    F11_KEY,             // Tecla F11
    F12_KEY,             // Tecla F12
    NUM1_KEY,            // Tecla 1
    NUM2_KEY,            // Tecla 2
    NUM3_KEY,            // Tecla 3
    NUM4_KEY,            // Tecla 4
    NUM5_KEY,            // Tecla 5
    NUM6_KEY,            // Tecla 6
    NUM7_KEY,            // Tecla 7
    NUM8_KEY,            // Tecla 8
    NUM9_KEY,            // Tecla 9
    NUM0_KEY,            // Tecla 0
    MINUS_KEY,           // Tecla -
    EQUALS_KEY,          // Tecla =
    BACKSPACE_KEY,       // Tecla de retroceso
    TAB_KEY,             // Tecla Tab
    Q_KEY,               // Tecla Q
    W_KEY,               // Tecla W
    E_KEY,               // Tecla E
    R_KEY,               // Tecla R
    T_KEY,               // Tecla T
    Y_KEY,               // Tecla Y
    U_KEY,               // Tecla U
    I_KEY,               // Tecla I
    O_KEY,               // Tecla O
    P_KEY,               // Tecla P
    LEFT_BRACKET_KEY,    // Tecla [
    RIGHT_BRACKET_KEY,   // Tecla ]
    BACKSLASH_KEY,       // Tecla / //
    A_KEY,               // Tecla A
    S_KEY,               // Tecla S
    D_KEY,               // Tecla D
    F_KEY,               // Tecla F
    G_KEY,               // Tecla G
    H_KEY,               // Tecla H
    J_KEY,               // Tecla J
    K_KEY,               // Tecla K
    L_KEY,               // Tecla L
    SEMICOLON_KEY,       // Tecla ;
    QUOTE_KEY,           // Tecla '
    ENTER_KEY,           // Tecla Enter
    SHIFT_LEFT_KEY,      // Tecla Shift izquierda
    Z_KEY,               // Tecla Z
    X_KEY,               // Tecla X
    C_KEY,               // Tecla C
    V_KEY,               // Tecla V
    B_KEY,               // Tecla B
    N_KEY,               // Tecla N
    M_KEY,               // Tecla M
    COMMA_KEY,           // Tecla ,
    PERIOD_KEY,          // Tecla .
    SLASH_KEY,           // Tecla /
    SHIFT_RIGHT_KEY,     // Tecla Shift derecha
    CTRL_LEFT_KEY,       // Tecla Ctrl izquierda
    WIN_KEY,             // Tecla de la Windows
    ALT_LEFT_KEY,        // Tecla Alt izquierda
    SPACE_KEY,           // Tecla Espacio
    ALT_RIGHT_KEY,       // Tecla Alt derecha
    CTRL_RIGHT_KEY,      // Tecla Ctrl derecha
    UP_ARROW_KEY,        // Tecla flecha arriba
    DOWN_ARROW_KEY,      // Tecla flecha abajo
    LEFT_ARROW_KEY,      // Tecla flecha izquierda
    RIGHT_ARROW_KEY,     // Tecla flecha derecha
    INSERT_KEY,          // Tecla Insertar
    HOME_KEY,            // Tecla Inicio
    PAGE_UP_KEY,         // Tecla AvPág
    PAGE_DOWN_KEY,       // Tecla RePág
    DELETE_KEY,          // Tecla Suprimir
    END_KEY              // Tecla Fin
} KEYS;

typedef struct CONTROLS_S {
    int key;
    int coords[2]; 
    bool click;
    int scroll;
} CONTROLS;

KEYS get_key_code(SDL_Keycode key);


bool process_events(SDL_Window *window, CONTROLS *controls, CONFIG *config); //

void handle_mouse_motion(SDL_Event event, CONTROLS *controls); //

void handle_window_event(SDL_Event event, SDL_Window *window, CONFIG *config); // 

bool isClickAllowed(Uint32* lastClickTime, Uint32 debounceTime); //




#endif