#include <global.h>

#include <string.h>

#include <assets_utils.h>

// Contar el número de líneas en un archivo
int countPathsInState(GAMESTATE gamestate, char* path) {
    FILE* file = fopen(path, "r");
    char line[MAX_LINE_LENGTH];
    int wordCount = 0, currentNumber = -1;
    bool readingPaths = false;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, "%d", &currentNumber) == 1) {
            if (currentNumber == gamestate) {
                readingPaths = true;
                continue;
            }
            if (readingPaths && currentNumber != gamestate) {
                break;
            }
        }

        if (readingPaths && !sscanf(line, "%d", &currentNumber)) {
            char* token = strtok(line, " ");
            while (token) {
                wordCount++;
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(file);
    return wordCount;
}

// Obtener la ruta de un archivo por índice
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex) {
    FILE* file = fopen(path, "r");

    char line[MAX_LINE_LENGTH];
    int currentNumber = -1;
    bool readingPaths = false;
    int currentPathIndex = 0;
    static char imagepath[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, "%d", &currentNumber) == 1) {
            if (currentNumber == gamestate) {
                readingPaths = true;
            }
            if (readingPaths && currentNumber != gamestate) {
                break;
            }
        }

        if (readingPaths && sscanf(line, "%d", &currentNumber) != 1) {
            if (currentPathIndex == pathIndex) {
                strncpy(imagepath, line, MAX_LINE_LENGTH);
                fclose(file);
                return imagepath;
            }
            currentPathIndex++;
        }
    }
    
    fclose(file);
    return NULL;
}

// Crear una textura a partir de un archivo
SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filePath);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Crear un sonido a partir de un archivo
Mix_Music* CreateSounds(const char* filePath) {
    Mix_Music* sound = Mix_LoadMUS(filePath);
    if (sound == NULL) {
        fprintf(stderr, "Error al cargar la música: %s\n", Mix_GetError());
        return NULL;  // Devuelve NULL si hubo un error en la carga
    }

    return sound;
}

// Crear una fuente a partir de un archivo
TTF_Font* CreateFont(const char* filePath) {
    TTF_Font* font = TTF_OpenFont(filePath, 50);
    if (!font) {
        fprintf(stderr, "Error al cargar la fuente: %s, %s\n", filePath, TTF_GetError());
        return NULL;
    }
    return font;
}

// Cargar las texturas de un estado
void LoadImages(SDL_Renderer* renderer, IMAGES** loadedImages, GAMESTATE gameState) {
    int numTextures = countPathsInState(gameState, IMAGES_FILE); // Obtener número de texturas para el estado actual
    int i;
    char filePath[MAX_STR];

    free(*loadedImages);

    *loadedImages = (IMAGES*)malloc(numTextures * sizeof(IMAGES));
    
    if (*loadedImages == NULL) {
        fprintf(stderr, "Error al asignar memoria para loadedImages\n");
        return;
    }

    for (i = 0; i < numTextures; i++) {
        (*loadedImages)[i].texture = NULL;
    }

    for (i = 0; i < numTextures; i++) {
        char* path = getPathByIndex(gameState, IMAGES_FILE, i);
        if (path == NULL) {
            fprintf(stderr, "Error al obtener la ruta para el índice %d\n", i);
            continue;
        }

        snprintf(filePath, sizeof(filePath), "../src/img/%s", path);

        (*loadedImages)[i].texture = CreateTexture(filePath, renderer);
        if ((*loadedImages)[i].texture == NULL) {
            fprintf(stderr, "Error al cargar la textura para el archivo %s\n", filePath);
        }
    }
}

// Cargar los sonidos de un estado
void LoadSounds(SOUNDS** loadedSounds, GAMESTATE gameState) {
    int i = 0;
    int numSounds = countPathsInState(gameState, SOUNDS_FILE);
    char filePath[MAX_STR];

    free(*loadedSounds);

    *loadedSounds = (SOUNDS*)malloc(numSounds * sizeof(SOUNDS));

    if (*loadedSounds == NULL) return;

    for (i = 0; i < numSounds; i++) {
        char* path = getPathByIndex(gameState, SOUNDS_FILE, i);
        if (path == NULL) continue;

        char soundName[MAX_STR];

        sscanf(path, "%s", soundName);
        
        snprintf(filePath, sizeof(filePath), "../src/sound/%s", soundName);
        (*loadedSounds)[i].sound = CreateSounds(filePath);
    }
}

// Cargar las fuentes de un estado
void LoadFonts(SDL_Renderer* renderer, FONTS** loadedFonts, GAMESTATE gameState) {
    int numFonts = countPathsInState(gameState, FONTS_FILE);
    char filePath[MAX_STR];

    free(*loadedFonts);

    *loadedFonts = (FONTS*)malloc(numFonts * sizeof(FONTS));

    if (*loadedFonts == NULL) return;

    for (int i = 0; i < numFonts; i++) {
        char* path = getPathByIndex(gameState, FONTS_FILE, i);
        if (path == NULL) continue;

        char fontName[MAX_STR];

        sscanf(path, "%s", fontName);
        
        snprintf(filePath, sizeof(filePath), "../src/font/%s", fontName);
        (*loadedFonts)[i].font = CreateFont(filePath);
    }
}

// Cargar todos los recursos de un estado
void LoadAssets(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE gameState) {
    LoadImages( renderer, &(loadedAssets->images), gameState);
    LoadSounds(&(loadedAssets->sounds), gameState);
    LoadFonts(renderer, &(loadedAssets->fonts), gameState);
}

// Liberar los recursos cargados
void FreeAssets(ASSETS* loadedAssets) {
    if (loadedAssets != NULL) {
        if (loadedAssets->images != NULL) {
            free(loadedAssets->images);  // IMAGES
            loadedAssets->images = NULL;  // NULL
        }

        if (loadedAssets->sounds != NULL) {
            free(loadedAssets->sounds);  // SOUNDS
            loadedAssets->sounds = NULL;  // NULL
        }

        if (loadedAssets->fonts != NULL) {
            free(loadedAssets->fonts);   // FONTS
            loadedAssets->fonts = NULL;   // NULL
        }
    }
}


// Obtener el color de un píxel de una textura
SDL_Color getPixelColor(SDL_Texture *texture, int x, int y) {
    if (!texture) {
        fprintf(stderr, "Error: La textura proporcionada es NULL.\n");
        return (SDL_Color){0, 0, 0, 0}; 
    }

    SDL_Color color = {0, 0, 0, 0};
    void *pixels;
    int pitch;


    if (SDL_LockTexture(texture, NULL, &pixels, &pitch) != 0) {
        fprintf(stderr, "Error al bloquear la textura: %s\n", SDL_GetError());
        return color;
    }


    Uint32 format;
    SDL_QueryTexture(texture, &format, NULL, NULL, NULL);

    SDL_PixelFormat *mappingFormat = SDL_AllocFormat(format);
    if (!mappingFormat) {
        fprintf(stderr, "Error al asignar formato de píxeles: %s\n", SDL_GetError());
        SDL_UnlockTexture(texture);
        return color;
    }


    Uint8 *pixelData = (Uint8 *)pixels + y * pitch + x * (SDL_BYTESPERPIXEL(format));
    Uint32 pixelValue = 0;

    memcpy(&pixelValue, pixelData, SDL_BYTESPERPIXEL(format));

    SDL_GetRGBA(pixelValue, mappingFormat, &color.r, &color.g, &color.b, &color.a);


    SDL_FreeFormat(mappingFormat);
    SDL_UnlockTexture(texture);

    return color;
}

// Obtener un color aleatorio
SDL_Color getRandomColour() {
    SDL_Color randomColour;
    randomColour.r = rand() % 256;
    randomColour.g = rand() % 256;
    randomColour.b = rand() % 256;
    randomColour.a = 255;
    return randomColour;
}