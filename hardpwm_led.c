#include <wiringPi.h>
#include <stdio.h>

#define PWM_LED 1   // wiringPi pin 1 = BCM GPIO18 = physical pin 12

int main(void)
{
    int value;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    pinMode(PWM_LED, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(1024);
    pwmSetClock(32);    // about 586Hz

    while (1) {
        for (value = 0; value <= 1024; value += 64) {
            pwmWrite(PWM_LED, value);
            delay(120);
        }

        for (value = 1024; value >= 0; value -= 64) {
            pwmWrite(PWM_LED, value);
            delay(120);
        }
    }

    return 0;
}
