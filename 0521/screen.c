#include <stdio.h>
#include "screen.h"

void clearBuffer(char* screenBuf, int width, int height) {
    // Clear the screen buffer
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            screenBuf[i * (width + 1) + j] = ' ';
        }
        screenBuf[i * (width + 1) + width] = '\n';
    }
}

void drawBox(char* screenBuf, int width, int height) {
    // Draw the box outline
    for (int i = 0; i < width; i++) {
        screenBuf[i] = '-';
        screenBuf[(height - 1) * (width + 1) + i] = '-';
    }
    screenBuf[width] = '\n';
    screenBuf[(height - 1) * (width + 1) + width] = '\n';

    for (int i = 1; i < height - 1; i++) {
        screenBuf[i * (width + 1)] = '|';
        screenBuf[i * (width + 1) + width - 1] = '|';
    }
}

void writeStringToBuffer(const char* string, int x, int y, char* screenBuf, int width) {
    // Write the string to the screen buffer at the specified position
    int index = y * (width + 1) + x;
    int i = 0;
    while (string[i] != '\0') {
        screenBuf[index++] = string[i++];
    }
}

void setTitleToScreenBuffer(const char* title, char* screenBuf, int width) {
    // Write the title to the top of the screen buffer
    writeStringToBuffer(title, (width - strlen(title)) / 2, 0, screenBuf, width);
}

void setMenuOptionsToScreenBuffer(const char** options, int numOptions, int x, int y, char* screenBuf, int width) {
    // Write the menu options to the screen buffer
    for (int i = 0; i < numOptions; i++) {
        writeStringToBuffer(options[i], x, y + i, screenBuf, width);
    }
}

void drawHowToPlayBox(int width, int height, char* screenBuf) {
    clearBuffer(screenBuf, width, height);
    drawBox(screenBuf, width, height);
    writeStringToBuffer("Game Description", 5, 2, screenBuf, width);
    writeStringToBuffer("This is a roguelike deck building game.", 2, 4, screenBuf, width);
    writeStringToBuffer("Enter the number of actions you want to use", 1, 6, screenBuf, width);
    writeStringToBuffer("and you will perform them.", 10, 7, screenBuf, width);
}

void drawMainMenu(int width, int height, char* screenBuf) {
    clearBuffer(screenBuf, width, height);
    drawBox(screenBuf, width, height);

    const char* menuOptions[] = {
        "1. Game Start",
        "2. How to play",
        "3. Exit"
    };
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    setMenuOptionsToScreenBuffer(menuOptions, numOptions, (width - 12) / 2, height / 2, screenBuf, width);
}
