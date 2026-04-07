#ifndef GATE_H
#define GATE_H

#define SERVO 1        // wiringPi pin 1 = BCM GPIO18 = physical pin 12
#define LED 4          // wiringPi pin 4 = BCM GPIO23 = physical pin 16
#define PIR 5          // wiringPi pin 5 = BCM GPIO24 = physical pin 18

#define SERVO_RANGE 2000
#define SERVO_CLOCK 192

int pwmInit(void);
int isMotionDetected(void);
void setServoAngle(int angle);
void runGateSequence(void);

#endif
