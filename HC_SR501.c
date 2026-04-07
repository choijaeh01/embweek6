#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define LED_R 20    // BCM 20
#define LED_Y 21    // BCM 21
#define SENSOR 17   // BCM 17

void cleanup(int sig)
{
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_Y, LOW);
    pinMode(LED_R, INPUT);
    pinMode(LED_Y, INPUT);
    printf("\nStopped by User\n");
    exit(0);
}

int main(void)
{
    if (wiringPiSetupGpio() == -1) {
        printf("wiringPi 초기화 실패\n");
        return 1;
    }

    signal(SIGINT, cleanup);

    pinMode(LED_R, OUTPUT);
    pinMode(LED_Y, OUTPUT);
    pinMode(SENSOR, INPUT);

    printf("PIR Ready . . . . \n");
    delay(5000);

    while (1) {
        if (digitalRead(SENSOR) == HIGH) {
            digitalWrite(LED_Y, HIGH);
            digitalWrite(LED_R, LOW);
            printf("Motion Detected !\n");
            delay(200);
        } else {
            digitalWrite(LED_R, HIGH);
            digitalWrite(LED_Y, LOW);
            printf("NO Motion !\n");
            delay(200);
        }
    }

    return 0;
}
