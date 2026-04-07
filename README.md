# embweek6 - PWM · Sensor 실습 (PPT 기준)

중앙대학교 전자전기공학부 `임베디드 시스템 설계실습` 6주차용 예제/과제 레포입니다.

이번 실습은 **첨부 PPT의 흐름과 파일명**을 기준으로 진행합니다.
학생들은 아래 예제들을 **컴파일 및 실행**해 보고, 마지막에 이를 바탕으로 한 **통합 과제 1문제**를 해결합니다.

> 주의:
> - **푸쉬버튼은 사용하지 않습니다.**
> - **서보 모터는 이론 설명 및 코드 확인 중심**으로 다루며, 라즈베리파이 5 전원 안전 문제 때문에 **실제 연결은 가급적 하지 않는 방향**을 기본으로 합니다.

## 내일 실습에서 사용하는 핵심 파일

```text
embweek6/
├── led_pwm.c
├── music_pwm.c
├── servo_pwm.c
├── HC_SR04.c
├── HC_SR501.c
├── sensor_alarm_assignment/
│   ├── main.c
│   ├── alarm.c
│   ├── alarm.h
│   └── README.md
└── docs/
    └── week6_pwm_lab.md
```

## 실습 흐름

1. `led_pwm.c`
   - hardware PWM LED 제어
2. `music_pwm.c`
   - 피에조 부저로 간단한 음 재생
3. `servo_pwm.c`
   - 서보 PWM 코드 구조 확인 및 컴파일
   - 실제 배선/실행은 선택 또는 시연 대체
4. `HC_SR04.c`
   - 초음파 센서 거리 측정
5. `HC_SR501.c`
   - PIR 센서 움직임 감지
6. `sensor_alarm_assignment/`
   - PIR + 초음파 + LED PWM + 부저를 통합한 최종 과제

## 예제 컴파일 명령

### 1) LED PWM
```bash
gcc -o led_pwm led_pwm.c -lwiringPi
./led_pwm 18
```

### 2) Music PWM
```bash
gcc -o music_pwm music_pwm.c -lwiringPi
./music_pwm
```

### 3) Servo PWM
```bash
gcc -o servo_pwm servo_pwm.c -lwiringPi
./servo_pwm
```

### 4) HC-SR04
```bash
gcc -o HC_SR04 HC_SR04.c -lwiringPi
./HC_SR04
```

### 5) HC-SR501
```bash
gcc -o HC_SR501 HC_SR501.c -lwiringPi
./HC_SR501
```

### 6) 최종 과제
```bash
cd sensor_alarm_assignment
gcc -o sensor_alarm main.c alarm.c -lwiringPi
./sensor_alarm
```

## 핀 번호 기준
이번 레포의 PPT 기반 예제들은 **BCM 번호 기준**으로 작성되어 있으며,
`wiringPiSetupGpio()`를 사용합니다.

## 최종 과제 개요
최종 과제는 다음 동작을 구현합니다.

- PIR 센서가 움직임을 감지하면
- HC-SR04로 거리를 측정하고
- 가까운 거리에서만
  - LED 밝기를 변화시키고
  - 부저 경고음을 재생한다.


## 참고
- 자세한 문제 설명은 `docs/week6_pwm_lab.md`를 참고하세요.
