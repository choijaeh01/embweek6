#include <wiringPi.h>
#include <stdio.h>
#include "gate.h"

int main(void)
{
    int motion;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    if (pwmInit() == -1) {
        printf("pwmInit failed\n");
        return 1;
    }

    printf("PIR 센서를 감시합니다. 움직임이 감지되면 게이트 시퀀스를 실행합니다.\n");

    while (1) {
        motion = isMotionDetected();

        if (motion) {
            printf("움직임 감지 -> 게이트 시퀀스 실행\n");
            runGateSequence();
            delay(1000);
        } else {
            delay(100);
        }
    }

    return 0;
}
