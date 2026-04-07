#include <wiringPi.h>
#include <stdio.h>

#define SERVO 1       // wiringPi pin 1 = BCM GPIO18 = physical pin 12
#define PWM_RANGE 2000
#define PWM_CLOCK 192 // 19.2MHz / 192 / 2000 = 50Hz

static void setServoAngle(int angle)
{
    int pulse;

    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    // 0.5ms ~ 2.5ms pulse -> 50 ~ 250 counts (10us per count)
    pulse = 50 + (angle * 200) / 180;
    pwmWrite(SERVO, pulse);
}

int main(void)
{
    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    pinMode(SERVO, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(PWM_RANGE);
    pwmSetClock(PWM_CLOCK);

    while (1) {
        setServoAngle(0);
        delay(1000);
        setServoAngle(90);
        delay(1000);
        setServoAngle(180);
        delay(1000);
    }

    return 0;
}
