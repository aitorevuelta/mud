#ifndef UTILS_H
#define UTILS_H

#define IMAGES_FILE "../data/images.txt"
#define FONTS_FILE "../data/fonts.txt"
#define CONFIG_FILE "../data/config.txt"

#define MAX_LINE_LENGTH 50

// TEXTURAS

int countPathsInState(GAMESTATE gamestate, char* path);
char* getPathByIndex(GAMESTATE gamestate, char* path, int pathIndex);

// CONFIG

CONFIG readConfig();
void saveConfig(CONFIG config);

#endif