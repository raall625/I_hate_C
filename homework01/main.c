#include <stdio.h>
#include "box.h"

int main(void) {
    int h = 15, w = 30;

    screen(h, w);

    int input;
    scanf("%d", &input);

    while (1) {
        if (input == 1) {
            
            printf("게임 시작!\n");
            break;
        } else if (input == 2) {
            
            htpscreen(h, w);

            
            screen(h, w);
        } else if (input == 3) {
            
            break;
        } else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }

        scanf("%d", &input);
    }

    return 0;
}
