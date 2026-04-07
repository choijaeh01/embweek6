#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define SERVO_PIN 18   // BCM 18 (PWM0)

void cleanup(int sig)
{
    pwmWrite(SERVO_PIN, 0);
    pinMode(SERVO_PIN, INPUT);
    printf("\n서보 종료 및 GPIO 정리\n");
    exit(0);
}

int main(void)
{
    if (wiringPiSetupGpio() == -1) {
        printf("wiringPi 초기화 실패\n");
        return 1;
    }

    signal(SIGINT, cleanup);

    pinMode(SERVO_PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(2000);
    pwmSetClock(192);

    while (1) {
        pwmWrite(SERVO_PIN, 150);   // 90도
        delay(1000);
        pwmWrite(SERVO_PIN, 250);   // 180도
        delay(1000);
        pwmWrite(SERVO_PIN, 50);    // 0도
        delay(1000);
    }

    return 0;
}
