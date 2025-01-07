#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <utils.h>


// TEXTURAS

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



void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
