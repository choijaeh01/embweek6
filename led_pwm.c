#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int gpio_pin;

void cleanup(int sig)
{
    pwmWrite(gpio_pin, 0);
    pinMode(gpio_pin, INPUT);
    printf("\nPWM 종료 및 GPIO 정리\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s GPIO_NO(BCM)\n", argv[0]);
        printf("Example: %s 18\n", argv[0]);
        return 1;
    }

    gpio_pin = atoi(argv[1]);

    if (wiringPiSetupGpio() == -1) {
        printf("wiringPi 초기화 실패\n");
        return 1;
    }

    signal(SIGINT, cleanup);

    pinMode(gpio_pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(255);
    pwmSetClock(75);

    for (int i = 0; i < 10000; i++) {
        int duty = i % 256;
        pwmWrite(gpio_pin, duty);
        delay(5);
    }

    cleanup(0);
    return 0;
}
