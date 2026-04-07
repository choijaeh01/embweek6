#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>
#include "alarm.h"

static void writeLedDuty(int duty)
{
    if (duty < 0) duty = 0;
    if (duty > LED_PWM_RANGE) duty = LED_PWM_RANGE;
    pwmWrite(PWM_LED, duty);
}

static void playTone(int freq, int duration_ms)
{
    if (freq <= 0) {
        delay(duration_ms);
        return;
    }

    int period_us = 1000000 / freq;
    int half_period = period_us / 2;
    int cycles = (duration_ms * 1000) / period_us;

    for (int i = 0; i < cycles; i++) {
        digitalWrite(SPKR, HIGH);
        delayMicroseconds(half_period);
        digitalWrite(SPKR, LOW);
        delayMicroseconds(half_period);
    }
}

static double getTime(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int initSystem(void)
{
    /*
     * TODO 1.
     * 아래 초기화를 수행하시오.
     * 1) PWM_LED를 PWM_OUTPUT으로 설정
     * 2) pwmSetMode(PWM_MODE_MS), pwmSetRange(LED_PWM_RANGE), pwmSetClock(LED_PWM_CLOCK) 설정
     * 3) SPKR를 OUTPUT으로 설정
     * 4) TRIG를 OUTPUT, ECHO를 INPUT으로 설정
     * 5) SENSOR를 INPUT으로 설정
     * 6) TRIG를 LOW로 두고 센서 안정화 대기
     */

    return 0;
}

int isMotionDetected(void)
{
    /*
     * TODO 2.
     * PIR 센서 상태를 읽어 반환하시오.
     * - 감지되면 HIGH
     * - 아니면 LOW
     */

    return LOW;
}

double measureDistanceCm(void)
{
    /*
     * TODO 3.
     * HC-SR04를 이용해 거리를 cm 단위로 측정하시오.
     *
     * 힌트:
     * - TRIG에 10us 펄스 출력
     * - ECHO 상승 시각과 하강 시각 측정
     * - distance = (stop - start) * 34300 / 2
     * - 센서가 응답하지 않을 때를 대비해 timeout을 둬도 좋다
     */

    return -1.0;
}

void runAlertSequence(void)
{
    /*
     * TODO 4.
     * 가까운 물체가 감지되었을 때 다음 동작을 수행하시오.
     *
     * (1) LED 밝기를 점점 증가시킨다.
     * (2) 부저 경고음을 2~3회 출력한다.
     * (3) LED 밝기를 다시 감소시킨다.
     *
     * 구현 조건:
     * - LED는 pwmWrite 기반으로 제어한다.
     * - 부저는 playTone()을 사용해도 된다.
     * - 너무 길지 않게 1~2초 내외 경고 시퀀스로 구성한다.
     */
}
