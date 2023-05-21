#ifndef SCREEN_H
#define SCREEN_H

void clearBuffer(char* screenBuf, int width, int height);
void drawBox(char* screenBuf, int width, int height);
void writeStringToBuffer(const char* string, int x, int y, char* screenBuf, int width);
void setTitleToScreenBuffer(const char* title, char* screenBuf, int width);
void setMenuOptionsToScreenBuffer(const char** options, int numOptions, int x, int y, char* screenBuf, int width);
void drawHowToPlayBox(int width, int height, char* screenBuf);
void drawMainMenu(int width, int height, char* screenBuf);

#endif
