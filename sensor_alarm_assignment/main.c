#include <wiringPi.h>
#include <stdio.h>
#include "alarm.h"

int main(void)
{
    double distance;

    if (wiringPiSetupGpio() == -1) {
        printf("wiringPiSetupGpio failed\n");
        return 1;
    }

    if (initSystem() == -1) {
        printf("initSystem failed\n");
        return 1;
    }

    printf("Sensor alarm system ready\n");
    printf("PIR motion -> ultrasonic distance -> LED + buzzer alert\n");

    while (1) {
        if (isMotionDetected()) {
            distance = measureDistanceCm();
            printf("Motion detected, distance = %.1f cm\n", distance);

            if (distance > 0 && distance <= DIST_THRESHOLD_CM) {
                printf("ALERT: close object detected\n");
                runAlertSequence();
            } else {
                printf("Motion detected but object is too far\n");
                delay(300);
            }
        } else {
            delay(100);
        }
    }

    return 0;
}
