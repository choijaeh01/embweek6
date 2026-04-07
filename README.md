# 임베디드 시스템 설계실습 - PWM 및 센서 통합 실습

## 1. 실습 개요
본 실습은 제공된 PPT의 흐름을 기준으로, 라즈베리파이에서 WiringPi를 이용해 **PWM 출력**, **부저 제어**, **초음파 센서**, **PIR 센서**를 순서대로 확인한 뒤, 이를 통합한 하나의 응용 문제를 해결하는 것을 목표로 한다.

이번 실습은 다음 순서로 진행한다.
1. `led_pwm.c` - hardware PWM LED 제어
2. `music_pwm.c` - 피에조 부저 음 재생
3. `servo_pwm.c` - 서보 PWM 코드 확인 및 컴파일
4. `HC_SR04.c` - 초음파 센서 거리 측정
5. `HC_SR501.c` - PIR 센서 움직임 감지
6. `sensor_alarm_assignment/` - 최종 통합 과제

---

## 2. 실습 운영 원칙
- **푸쉬버튼은 사용하지 않는다.**
- **서보 모터는 이론 설명 및 코드 확인 중심**으로 다룬다.
- 라즈베리파이 5의 전원 안정성 문제 때문에, **서보 모터는 실제 연결을 가급적 피한다.**

---

## 3. 실습 환경 및 준비물
- Raspberry Pi 5
- 브레드보드
- LED
- 220Ω 저항
- 피에조 부저
- HC-SR04 초음파 센서
- HC-SR501 PIR 센서
- 점퍼선
- WiringPi 설치 완료된 Raspberry Pi OS 환경
- 서보 모터(선택 / 이론 설명용)

레포 다운로드:
```bash
git clone https://github.com/choijaeh01/embweek6.git
cd embweek6
```


파일 디렉토리 구조:
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
└── README.md
```
---

## 4. 핀 연결

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


---

## 5. 실습 1 - `led_pwm.c`
### 5.1 목표
- hardware PWM 출력을 이용해 LED 밝기를 제어한다.
- `pinMode(..., PWM_OUTPUT)`, `pwmSetMode()`, `pwmSetRange()`, `pwmSetClock()`의 역할을 이해한다.

### 5.2 실행
```bash
gcc -o led_pwm led_pwm.c -lwiringPi
./led_pwm 18
```

### 5.3 확인 사항
- LED 밝기가 점진적으로 바뀌는가?
- hardware PWM 가능한 핀(예: BCM 12, 13, 18, 19)을 설명할 수 있는가?

---

## 6. 실습 2 - `music_pwm.c`
### 6.1 목표
- 피에조 부저를 이용해 간단한 음을 출력한다.
- 주파수와 시간 제어를 통해 음을 만든다.

### 6.2 실행
```bash
gcc -o music_pwm music_pwm.c -lwiringPi
./music_pwm
```

### 6.3 확인 사항
- 부저에서 서로 다른 음이 재생되는가?
- 주파수와 음높이의 관계를 설명할 수 있는가?

---

## 7. 실습 3 - `servo_pwm.c`
### 7.1 목표
- 서보 모터 제어를 위한 PWM 설정값을 이해한다.
- 50Hz PWM, 듀티와 각도 매핑 개념을 이해한다.

### 7.2 실행
```bash
gcc -o servo_pwm servo_pwm.c -lwiringPi
./servo_pwm
```

### 7.3 운영 주의
- 이번 실습에서는 **코드 확인 및 컴파일 중심**으로 진행한다.
- **실제 서보 연결은 가급적 하지 않는다.**
- 라즈베리파이 5의 GPIO 5V 핀에서 서보를 직접 구동하면 전원 문제가 생길 수 있으므로 주의한다.

### 7.4 확인 사항
- 왜 서보는 일반 LED보다 더 주의해서 연결해야 하는가?
- `pwmWrite()` 값과 각도의 관계를 설명할 수 있는가?

---

## 8. 실습 4 - `HC_SR04.c`
### 8.1 목표
- 초음파 센서를 이용해 물체까지의 거리를 측정한다.
- Trigger/Echo 동작 원리를 이해한다.

### 8.2 실행
```bash
gcc -o HC_SR04 HC_SR04.c -lwiringPi
./HC_SR04
```

### 8.3 확인 사항
- 거리 변화에 따라 출력값이 달라지는가?
- 초음파 왕복 시간으로 거리를 계산하는 이유를 설명할 수 있는가?

---

## 9. 실습 5 - `HC_SR501.c`
### 9.1 목표
- PIR 센서의 디지털 출력 특성을 확인한다.
- 움직임 감지에 따라 LED 상태를 바꾼다.

### 9.2 실행
```bash
gcc -o HC_SR501 HC_SR501.c -lwiringPi
./HC_SR501
```

### 9.3 확인 사항
- 움직임 감지 시 출력이 바뀌는가?
- 감지 여부에 따라 서로 다른 LED 상태가 나타나는가?

---

## 10. 최종 과제 - `sensor_alarm_assignment`
### 10.1 목표
앞선 예제들을 바탕으로 다음 기능을 갖는 **통합 경고 시스템**을 작성한다.

### 10.2 문제
PIR 센서가 움직임을 감지하면 HC-SR04 초음파 센서로 거리를 측정하고, 일정 거리 이내의 대상이 감지되었을 때만 다음 동작을 수행하는 프로그램을 작성하시오.

- LED 밝기를 PWM으로 변화시킨다.
- 부저로 경고음을 출력한다.
- 거리 측정값과 감지 상태를 터미널에 출력한다.

### 10.3 과제 조건
- `wiringPiSetupGpio()` 기반으로 작성한다.
- 다음 예제의 아이디어를 통합한다.
  - `led_pwm.c`
  - `music_pwm.c`
  - `HC_SR04.c`
  - `HC_SR501.c`

### 10.4 작성할 핵심 함수
`sensor_alarm_assignment/alarm.c`에서 다음 함수들을 완성한다.
- `initSystem()`
- `isMotionDetected()`
- `measureDistanceCm()`
- `runAlertSequence()`

### 10.5 컴파일 및 실행
```bash
cd sensor_alarm_assignment
gcc -o sensor_alarm main.c alarm.c -lwiringPi
./sensor_alarm
```

### 10.6 확인 사항
- PIR이 움직임을 감지하는가?
- 초음파 센서가 거리를 정상 출력하는가?
- 가까운 물체일 때만 LED/부저 경고가 동작하는가?
- 여러 예제를 하나의 응용 프로그램으로 결합할 수 있는가?

---

## 11. 제출물
1. 회로 연결 사진
2. 작성한 코드 (`alarm.c` 중심)
3. 컴파일 및 실행 명령
4. 실행 결과 사진 또는 짧은 영상 캡처
5. 간단한 설명
   - hardware PWM의 의미
   - 부저 음 생성 방식
   - 초음파 거리 측정 원리
   - PIR 센서 감지 방식
   - 최종 과제 동작 흐름

