#ifndef ALARM_H
#define ALARM_H

#define PWM_LED 18
#define SPKR 12
#define TRIG 23
#define ECHO 24
#define SENSOR 17

#define LED_PWM_RANGE 255
#define LED_PWM_CLOCK 75
#define DIST_THRESHOLD_CM 50.0

int initSystem(void);
int isMotionDetected(void);
double measureDistanceCm(void);
void runAlertSequence(void);

#endif
