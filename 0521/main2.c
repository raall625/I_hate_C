#include <stdio.h>
#include "screen.h"

int main(void) {
    int h = 20, w = 40;
    char screenBuf[(w + 1) * h];
    setTitleToScreenBuffer("Defected deck", screenBuf, w);

    int input = 0;

    while (input != 3) {
        drawMainMenu(w, h, screenBuf);
        scanf("%d", &input);

        if (input == 1) {
            printf("Game Start\n");
            // 게임 시작 로직
        } else if (input == 2) {
            drawHowToPlayBox(w, h, screenBuf);
            printf("Press any key to return to the main menu.\n");
            getchar();  // Enter 키 대기
            getchar();  // 임의의 키 입력 받기
        } else if (input != 3) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Game Exit\n");
    return 0;
}
