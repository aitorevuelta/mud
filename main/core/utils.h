#ifndef UTILS_H
#define UTILS_H

#define IMAGES_FILE "../data/images.txt"
#define FONTS_FILE "../data/fonts.txt"


#define MAX_LINE_LENGTH 50

void adjustFrameRate(Uint32 frameStart, int targetFPS);

// TEXTURAS

int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

//SDL
void cleanUp_sdl(SDL* sdl);

#endif