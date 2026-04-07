#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define LED 4   // wiringPi pin 4 = BCM GPIO23 = physical pin 16

int main(void)
{
    int duty;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    if (softPwmCreate(LED, 0, 100) == -1) {
        printf("softPwmCreate failed\n");
        return 1;
    }

    while (1) {
        for (duty = 0; duty <= 100; duty += 5) {
            softPwmWrite(LED, duty);
            delay(80);
        }

        for (duty = 100; duty >= 0; duty -= 5) {
            softPwmWrite(LED, duty);
            delay(80);
        }
    }

    return 0;
}
