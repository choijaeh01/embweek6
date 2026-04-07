#include <wiringPi.h>
#include <stdio.h>
#include "gate.h"

int main(void)
{
    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    if (pwmInit() == -1) {
        printf("pwmInit failed\n");
        return 1;
    }

    printf("LED 밝기와 서보 모터를 이용한 게이트 시퀀스를 반복 실행합니다.\n");

    while (1) {
        runGateSequence();
        delay(2000);
    }

    return 0;
}
