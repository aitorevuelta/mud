#include <global.h>

#include <string.h>

#include <assets_utils.h>

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


SDL_Texture* CreateTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filePath);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


TTF_Font* CreateFont(const char* filePath, int fontSize) {
    TTF_Font* font = TTF_OpenFont(filePath, fontSize);
    if (!font) {
        fprintf(stderr, "Error al cargar la fuente: %s, %s\n", filePath, TTF_GetError());
    }
    return font;
}


void LoadImages(IMAGES** loadedImages, GAMESTATE gameState, SDL_Renderer* renderer) {
    int numTextures = countPathsInState(gameState, IMAGES_FILE); // Obtener número de texturas para el estado actual
    int i;
    char filePath[MAX_STR];

    free(*loadedImages);

    *loadedImages = (IMAGES*)malloc(numTextures * sizeof(IMAGES));
    
    if (*loadedImages == NULL) {
        fprintf(stderr, "Error al asignar memoria para loadedImages\n");
        return;
    }

    // Inicializar todas las texturas a NULL
    for (i = 0; i < numTextures; i++) {
        (*loadedImages)[i].texture = NULL;
    }

    // Cargar cada textura
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


void LoadFonts(FONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer) {
    int numFonts = countPathsInState(gameState, FONTS_FILE);
    char filePath[MAX_STR];

    free(*loadedFonts);

    *loadedFonts = (FONTS*)malloc(numFonts * sizeof(FONTS));

    if (*loadedFonts == NULL) return;

    for (int i = 0; i < numFonts; i++) {
        char* path = getPathByIndex(gameState, FONTS_FILE, i);
        if (path == NULL) continue;

        char fontName[MAX_STR];
        int fontSize;

        if (sscanf(path, "%s %d", fontName, &fontSize) != 2) continue;

        snprintf(filePath, sizeof(filePath), "../src/fonts/%s", fontName);
        (*loadedFonts)[i].font = CreateFont(filePath, fontSize);

        if ((*loadedFonts)[i].font == NULL) {
            fprintf(stderr, "Error al cargar la fuente: %s con tamaño %d\n", fontName, fontSize);
        }
    }
}

void LoadAssets(ASSETS *loadedAssets, GAMESTATE gameState, SDL_Renderer* renderer) {
    LoadImages(&(loadedAssets->images), gameState, renderer);
    LoadFonts(&(loadedAssets->fonts), gameState, renderer);
}

void renderText(SDL_Renderer *renderer, FONTS *loadedFonts, const char *text, SDL_Color color, int x, int y){
    SDL_Surface *surface = TTF_RenderText_Solid(loadedFonts[0].font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    //SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

SDL_Color getPixelColor(SDL_Texture *texture, int x, int y) {
    if (!texture) {
        fprintf(stderr, "Error: La textura proporcionada es NULL.\n");
        return (SDL_Color){0, 0, 0, 0}; // Color negro como valor predeterminado
    }

    SDL_Color color = {0, 0, 0, 0};
    void *pixels;
    int pitch;

    // Bloquear la textura para acceder a los píxeles
    if (SDL_LockTexture(texture, NULL, &pixels, &pitch) != 0) {
        fprintf(stderr, "Error al bloquear la textura: %s\n", SDL_GetError());
        return color;
    }

    // Obtener el formato de píxeles de la textura
    Uint32 format;
    SDL_QueryTexture(texture, &format, NULL, NULL, NULL);

    // Crear un descriptor de formato
    SDL_PixelFormat *mappingFormat = SDL_AllocFormat(format);
    if (!mappingFormat) {
        fprintf(stderr, "Error al asignar formato de píxeles: %s\n", SDL_GetError());
        SDL_UnlockTexture(texture);
        return color;
    }

    // Calcular el píxel en las coordenadas x, y
    Uint8 *pixelData = (Uint8 *)pixels + y * pitch + x * (SDL_BYTESPERPIXEL(format));
    Uint32 pixelValue = 0;

    memcpy(&pixelValue, pixelData, SDL_BYTESPERPIXEL(format));

    // Convertir a componentes RGBA
    SDL_GetRGBA(pixelValue, mappingFormat, &color.r, &color.g, &color.b, &color.a);

    // Liberar los recursos
    SDL_FreeFormat(mappingFormat);
    SDL_UnlockTexture(texture);

    return color;
}

COLOUR getRandomColour() {
    COLOUR randomColour;
    randomColour.r = rand() % 256;
    randomColour.g = rand() % 256;
    randomColour.b = rand() % 256;
    randomColour.a = rand() % 256;
    return randomColour;
}