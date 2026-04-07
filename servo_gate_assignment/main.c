#include <wiringPi.h>
#include <stdio.h>
#include "gate.h"

int main(void)
{
    int prev_state = HIGH;
    int cur_state;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    if (pwmInit() == -1) {
        printf("pwmInit failed\n");
        return 1;
    }

    printf("버튼을 누르면 LED 밝기와 서보 모터를 이용한 게이트 시퀀스를 실행합니다.\n");

    while (1) {
        cur_state = isButtonPressed();

        if (prev_state == HIGH && cur_state == LOW) {
            printf("버튼 입력 감지 -> 게이트 시퀀스 실행\n");
            runGateSequence();
        }

        prev_state = cur_state;
        delay(50);
    }

    return 0;
}
