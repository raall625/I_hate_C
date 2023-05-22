#ifndef SCREEN_H
#define SCREEN_H

typedef struct {
    int width;
    int height;
    char* buffer;
} Screen;

Screen createScreen(int width, int height);
void clearScreen(Screen* screen);
void drawBox(Screen* screen);
void writeStringToBuffer(const char* string, int x, int y, Screen* screen);
void drawHowToPlayBox(Screen* screen);
void drawMainMenu(Screen* screen);
void renderScreen(const Screen* screen);
void destroyScreen(Screen* screen);

#endif
