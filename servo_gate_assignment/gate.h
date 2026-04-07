#ifndef GATE_H
#define GATE_H

#define BTN 0          // wiringPi pin 0 = BCM GPIO17 = physical pin 11
#define SERVO 1        // wiringPi pin 1 = BCM GPIO18 = physical pin 12
#define LED 4          // wiringPi pin 4 = BCM GPIO23 = physical pin 16

#define SERVO_RANGE 2000
#define SERVO_CLOCK 192

int pwmInit(void);
int isButtonPressed(void);
void runGateSequence(void);

#endif
