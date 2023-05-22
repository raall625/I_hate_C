#include <stdio.h>
#include "screen.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
    int width = 40;
    int height = 20;
    Screen screen = createScreen(width, height);

    int input = 0;
    int showMainMenu = 1;

    while (input != 3) {
            drawMainMenu(&screen);
            renderScreen(&screen);

        scanf("%d", &input);

        if (input == 1) {
            printf("Game Start\n");

        } else if (input == 2) {
            clearScreen(&screen);
            drawHowToPlayBox(&screen);
            renderScreen(&screen);
            printf("press any key to return to menu.\n");
            getchar();
            input = 0;
        } else if (input != 3) {
            printf("Please try again.\n");
            showMainMenu = 1;
            input = 0;
        }
    }

    printf("Game Exit\n");
    destroyScreen(&screen);
    return 0;
}
