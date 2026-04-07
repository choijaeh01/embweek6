# sensor_alarm_assignment

## 과제 목표
앞서 실습한 예제들을 바탕으로,
- PIR 센서가 움직임을 감지하면
- 초음파 센서로 거리를 측정하고
- 가까운 거리일 때만 LED PWM 경고와 부저 경고음을 출력하는
통합 경고 시스템을 완성한다.

## 이번 과제의 특징
- **push button 사용 안 함**
- **servo motor 사용 안 함**
- `led_pwm.c`, `music_pwm.c`, `HC_SR04.c`, `HC_SR501.c`의 핵심 아이디어를 한 프로그램으로 통합

## 파일 설명
- `main.c`
  - 메인 루프와 전체 동작 흐름이 작성되어 있음
- `alarm.h`
  - 핀 번호, 상수, 함수 원형 선언
- `alarm.c`
  - 학생이 완성해야 할 핵심 함수들이 있음

## 작성할 함수
다음 함수들을 완성한다.
- `initSystem()`
- `isMotionDetected()`
- `measureDistanceCm()`
- `runAlertSequence()`

## 하드웨어 연결
### LED PWM
- LED anode → 220Ω 저항 → BCM 18 (physical pin 12)
- LED cathode → GND

### Piezo buzzer
- signal → BCM 12 (physical pin 32)
- GND → GND

### HC-SR04
- TRIG → BCM 23 (physical pin 16)
- ECHO → BCM 24 (physical pin 18)
- VCC → 5V
- GND → GND

### HC-SR501
- OUT → BCM 17 (physical pin 11)
- VCC → 5V
- GND → GND

## 기본 동작
1. PIR 센서가 움직임을 감지한다.
2. 초음파 센서로 거리를 잰다.
3. 일정 거리 이내라면
   - LED 밝기를 PWM으로 변화시키고
   - 부저 경고음을 출력한다.
4. 측정 거리와 상태를 터미널에 출력한다.

## 컴파일
```bash
gcc -o sensor_alarm main.c alarm.c -lwiringPi
```

## 실행
```bash
./sensor_alarm
```
