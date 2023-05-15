#include <stdio.h>
#include "box.h"

void drawBox(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printText(int x, int y, const char* text) {
    printf("\033[%d;%dH%s", y, x, text);
}

void screen(int h, int w) {
    printf("\033[2J"); 
    drawBox(h, w);

    printText(w/2-5, h/2-3, "Game Title");
    printText(w/2-3, h/2-1, "1. Game Start");
    printText(w/2-3, h/2+1, "2. How to Play");
    printText(w/2-3, h/2+3, "3. Exit");
}

void htpscreen(int h, int w) {
    printf("\033[2J"); 
    drawBox(h, w);
    printText(w/2-6, h/2-3, "Game Description");
    printText(w/2-18, h/2-1, "This is a roguelike deck building game.");
    printText(w/2-9, h/2+1, "Enter the number of actions you want to use and you will perform them");

    printf("\nPress Enter to continue...");
    getchar();
}
