#ifndef UTILS_H
#define UTILS_H

#define PATHS_FILE "../data/paths.txt"
#define CONFIG_FILE "../data/config.txt"

#define MAX_LINE_LENGTH 50

int countPathsInState(GAMESTATE gamestate);

CONFIG readConfig();
void saveConfig(CONFIG config);

#endif