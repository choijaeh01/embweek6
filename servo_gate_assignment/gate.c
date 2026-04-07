#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "gate.h"

/*
 * 과제 목표:
 * - 버튼을 누르면 LED 밝기가 서서히 증가하고,
 *   서보 모터가 0도 -> 90도 -> 0도로 움직이는 게이트 시퀀스를 구현한다.
 * - 지난주 GPIO 입력/출력과 이번 주 PWM 제어를 함께 연습한다.
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
     * 1) 버튼 핀을 INPUT으로 설정
     * 2) 버튼 핀에 pullUpDnControl(BTN, PUD_UP) 적용
     * 3) LED 핀에 softPwmCreate(LED, 0, 100) 적용
     * 4) SERVO 핀을 PWM_OUTPUT으로 설정
     * 5) pwmSetMode(PWM_MODE_MS), pwmSetRange(SERVO_RANGE), pwmSetClock(SERVO_CLOCK) 설정
     *
     * 힌트:
     * - 버튼은 '누르지 않으면 HIGH, 누르면 LOW'가 되도록 내부 pull-up 사용
     * - LED 밝기는 0~100 범위로 제어
     * - 서보는 hardware PWM 사용
     */

    return 0;
}

int isButtonPressed(void)
{
    /*
     * TODO 2.
     * 버튼 현재 상태를 읽어 반환하시오.
     *
     * 힌트:
     * - 내부 pull-up 회로 기준
     * - 누르지 않으면 HIGH, 누르면 LOW
     */

    return HIGH;
}

void runGateSequence(void)
{
    int duty;
    int angle;
    int pulse;

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
     * - 0도~180도 매핑식은 예제 pwmservo.c 참고
     * - 0도, 90도 정도만 사용해도 충분
     * - 서보 이동은 갑자기 점프하지 말고 작은 간격으로 움직일 것
     */
}
