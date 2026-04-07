# embweek6 - PWM 제어 실습

중앙대학교 전자전기공학부 `임베디드 시스템 설계실습` 6주차용 예제/과제 레포입니다.

이번 주 실습은 지난주 WiringPi 기반 GPIO 기초 제어를 바탕으로, **PWM(Pulse Width Modulation)** 을 이용한 출력 제어를 다룹니다.

## 레포 구성

```text
embweek6/
├── softpwm_led.c
├── hardpwm_led.c
├── pwmservo.c
├── servo_gate_assignment/
│   ├── main.c
│   ├── gate.c
│   ├── gate.h
│   └── README.md
└── docs/
    └── week6_pwm_lab.md
```

## 실습 흐름

1. `softpwm_led.c`
   - software PWM으로 LED 밝기 조절
2. `hardpwm_led.c`
   - hardware PWM으로 LED duty 제어
3. `pwmservo.c`
   - hardware PWM으로 서보 모터 각도 제어
4. `servo_gate_assignment/`
   - 버튼 입력을 받아 LED 밝기 + 서보 모터를 함께 제어하는 통합 과제

## 컴파일 예시

### 1) software PWM LED
```bash
gcc -o softpwm_led softpwm_led.c -lwiringPi
./softpwm_led
```

### 2) hardware PWM LED
```bash
gcc -o hardpwm_led hardpwm_led.c -lwiringPi
./hardpwm_led
```

### 3) servo motor
```bash
gcc -o pwmservo pwmservo.c -lwiringPi
./pwmservo
```

### 4) 통합 과제
```bash
cd servo_gate_assignment
gcc -o servo_gate main.c gate.c -lwiringPi
./servo_gate
```

## 하드웨어 연결 요약

### Software PWM LED
- LED anode → 220Ω 저항 → physical pin 16 (BCM GPIO23, wiringPi 4)
- LED cathode → GND

### Hardware PWM LED / Servo
- physical pin 12 (BCM GPIO18, wiringPi 1)
- `hardpwm_led.c` 를 실행할 때는 LED 회로를,
- `pwmservo.c` / `servo_gate_assignment` 를 실행할 때는 서보 모터를 연결해서 사용

### Button (통합 과제)
- button input → physical pin 11 (BCM GPIO17, wiringPi 0)
- 나머지 한쪽은 GND
- 내부 pull-up 사용 기준으로 작성됨

## 참고
- 이번 주는 **Makefile 없이 gcc 명령어로 직접 컴파일**하는 흐름을 유지합니다.
- 핀 번호는 기본적으로 `wiringPiSetup()` 기준 **wiringPi 번호 체계**를 사용합니다.
