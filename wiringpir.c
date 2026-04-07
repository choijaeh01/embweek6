#include <wiringPi.h>
#include <stdio.h>

#define PIR 5   // wiringPi pin 5 = BCM GPIO24 = physical pin 18
#define LED 4   // wiringPi pin 4 = BCM GPIO23 = physical pin 16

int main(void)
{
    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    pinMode(PIR, INPUT);
    pinMode(LED, OUTPUT);

    while (1) {
        if (digitalRead(PIR) == HIGH) {
            printf("Motion detected\n");
            digitalWrite(LED, HIGH);
            delay(500);
        } else {
            digitalWrite(LED, LOW);
            delay(100);
        }
    }

    return 0;
}
