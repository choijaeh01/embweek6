#include <wiringPi.h>
#include <stdio.h>

#define TRIG 2   // wiringPi pin 2 = BCM GPIO27 = physical pin 13
#define ECHO 3   // wiringPi pin 3 = BCM GPIO22 = physical pin 15

int main(void)
{
    long start;
    long travel_time;
    double distance;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    digitalWrite(TRIG, LOW);
    delay(100);

    while (1) {
        digitalWrite(TRIG, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG, LOW);

        while (digitalRead(ECHO) == LOW)
            ;
        start = micros();

        while (digitalRead(ECHO) == HIGH)
            ;
        travel_time = micros() - start;

        distance = travel_time / 58.0;
        printf("distance = %.2f cm\n", distance);
        delay(500);
    }

    return 0;
}
