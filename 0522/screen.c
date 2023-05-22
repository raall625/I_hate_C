#include <stdio.h>
#include "screen.h"
#include <stdlib.h>
#include <string.h>

Screen createScreen(int width, int height) {
    Screen screen;
    screen.width = width;
    screen.height = height;
    screen.buffer = (char*)malloc((width + 1) * height * sizeof(char));
    return screen;
}

void clearScreen(Screen* screen) {
    memset(screen->buffer, ' ', (screen->width + 1) * screen->height * sizeof(char));
}

void drawBox(Screen* screen) {
    int width = screen->width;
    int height = screen->height;
    char* buffer = screen->buffer;

    for (int i = 0; i < width; i++) {
        buffer[i] = '*';
        buffer[(height - 1) * (width + 1) + i] = '*';
    }
    buffer[width] = '\n';
    buffer[(height - 1) * (width + 1) + width] = '\n';

    for (int i = 1; i < height - 1; i++) {
        buffer[i * (width + 1)] = '*';
        buffer[i * (width + 1) + width - 1] = '*';
    }
}

void writeStringToBuffer(const char* string, int x, int y, Screen* screen) {
    int width = screen->width;
    char* buffer = screen->buffer;

    int index = y * (width + 1) + x;
    int i = 0;
    while (string[i] != '\0') {
        buffer[index++] = string[i++];
    }
}



void drawHowToPlayBox(Screen* screen) {
    clearScreen(screen);
    drawBox(screen);
    writeStringToBuffer("Game Description", 5, 2, screen);
    writeStringToBuffer("This is a Turn-based Game.", 2, 4, screen);
    writeStringToBuffer("Enter the number of actions you want to use", 1, 6, screen);
    writeStringToBuffer("and you will perform them.", 10, 7, screen);
}

void drawMainMenu(Screen* screen) {
    clearScreen(screen);
    drawBox(screen);

    const char* menuOptions[] = {
        "1. Game Start",
        "2. How to play",
        "3. Exit"
    };
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int x = (screen->width - 12) / 2;
    int y = screen->height / 2;
    for (int i = 0; i < numOptions; i++) {
        writeStringToBuffer(menuOptions[i], x, y + i, screen);
    }
}

void renderScreen(const Screen* screen) {
    printf("%s", screen->buffer);
}

void destroyScreen(Screen* screen) {
    free(screen->buffer);
}
