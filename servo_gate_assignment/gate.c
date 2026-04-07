#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "gate.h"

/*
 * 과제 목표:
 * - LED 밝기가 서서히 증가하고,
 *   서보 모터가 0도 -> 90도 -> 0도로 움직이는 게이트 시퀀스를 구현한다.
 * - 이번 주는 버튼 입력 없이 PWM 출력 제어 자체에 집중한다.
 */

static void setLedBrightness(int percent)
{
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;
    softPwmWrite(LED, percent);
}

int pwmInit(void)
{
    /*
     * TODO 1.
     * 아래 초기화를 수행하시오.
     * 1) LED 핀에 softPwmCreate(LED, 0, 100) 적용
     * 2) SERVO 핀을 PWM_OUTPUT으로 설정
     * 3) pwmSetMode(PWM_MODE_MS), pwmSetRange(SERVO_RANGE), pwmSetClock(SERVO_CLOCK) 설정
     *
     * 힌트:
     * - LED 밝기는 0~100 범위로 제어
     * - 서보는 hardware PWM 사용
     */

    return 0;
}

void setServoAngle(int angle)
{
    /*
     * TODO 2.
     * 입력 각도(0~180도)를 PWM 값으로 변환해 서보 모터를 제어하시오.
     *
     * 힌트:
     * - pwmservo.c 참고
     * - 0.5ms ~ 2.5ms pulse를 50 ~ 250 count로 생각하면 된다.
     * - 범위를 벗어나는 값은 0~180으로 제한하라.
     */
}

void runGateSequence(void)
{
    int duty;
    int angle;

    /*
     * TODO 3.
     * 아래 순서대로 동작하는 게이트 시퀀스를 작성하시오.
     *
     * (1) LED 밝기를 0% -> 100%로 서서히 증가
     * (2) 서보 모터를 0도 -> 90도로 이동
     * (3) 1초 대기
     * (4) 서보 모터를 90도 -> 0도로 복귀
     * (5) LED 밝기를 100% -> 0%로 서서히 감소
     *
     * 구현 조건:
     * - LED는 softPwmWrite 사용
     * - 서보는 pwmWrite 사용
     * - setServoAngle()을 호출해서 구현해도 됨
     * - 서보 이동은 갑자기 점프하지 말고 작은 간격으로 움직일 것
     */
}
