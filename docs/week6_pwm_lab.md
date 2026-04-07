# 6주차 실습 문제지
## 임베디드 시스템 설계실습 - WiringPi 기반 PWM 및 센서 실습

## 1. 실습 개요
본 실습의 목표는 라즈베리파이에서 WiringPi 라이브러리를 이용하여 **PWM(Pulse Width Modulation)** 출력을 제어하고,
PWM 이후 진도에 해당하는 **서보 모터, HC-SR04 초음파 센서, PIR 센서**를 활용한 간단한 임베디드 응용 프로그램을 작성하는 데 있다.

실습은 다음 순서로 진행한다.
1. software PWM LED 제어
2. hardware PWM LED 제어
3. hardware PWM 서보 모터 제어
4. HC-SR04 초음파 센서 거리 측정
5. PIR 센서 움직임 감지
6. PIR + PWM 기반 통합 과제 작성 및 실행

결과 보고서에는 회로 이미지, 작성한 코드, 컴파일 및 실행 명령, 실행 결과 이미지(또는 영상 캡처)를 포함한다.

---

## 2. 실습 환경 및 준비물
- Raspberry Pi 5
- 브레드보드
- LED 1개
- 220Ω 저항 1개
- 서보 모터 1개
- HC-SR04 초음파 센서 1개
- PIR 센서 1개
- 점퍼선
- WiringPi 설치 완료된 Raspberry Pi OS 환경

레포 다운로드:
```bash
git clone https://github.com/choijaeh01/embweek6.git
```

예상 디렉토리 구조:
```text
embweek6/
├── softpwm_led.c
├── hardpwm_led.c
├── pwmservo.c
├── wiringultra.c
├── wiringpir.c
├── pir_gate_assignment/
│   ├── main.c
│   ├── gate.c
│   ├── gate.h
│   └── README.md
└── docs/
    └── week6_pwm_lab.md
```

---

## 3. 핀 연결
### 3.1 software PWM LED
- LED cathode → GND
- LED anode → 220Ω 저항 → physical pin 16 (BCM GPIO23, wiringPi 4)

### 3.2 hardware PWM LED / servo motor
- signal → physical pin 12 (BCM GPIO18, wiringPi 1)
- LED 실습 시: LED anode → 저항 → physical pin 12
- 서보 실습 시: servo signal → physical pin 12

### 3.3 HC-SR04
- TRIG → physical pin 13 (BCM GPIO27, wiringPi 2)
- ECHO → physical pin 15 (BCM GPIO22, wiringPi 3)
- VCC → 5V
- GND → GND

### 3.4 PIR sensor
- PIR output → physical pin 18 (BCM GPIO24, wiringPi 5)
- VCC → 5V
- GND → GND

---

## 4. 실습 1 - software PWM LED 제어
### 4.1 목적
- software PWM의 기본 개념을 이해한다.
- duty cycle에 따라 LED 밝기가 변하는 것을 확인한다.

### 4.2 수행 내용
다음 조건을 만족하는 `softpwm_led.c`를 실행하시오.
- `softPwmCreate()` 사용
- duty를 0에서 100까지 증가시키고 다시 감소시킨다.
- LED 밝기가 서서히 변하도록 한다.

### 4.3 컴파일 및 실행 예시
```bash
gcc -o softpwm_led softpwm_led.c -lwiringPi
./softpwm_led
```

### 4.4 확인 사항
- LED 밝기가 점점 밝아졌다가 어두워지는가?
- `softPwmCreate()`와 `softPwmWrite()`의 역할을 설명할 수 있는가?

---

## 5. 실습 2 - hardware PWM LED 제어
### 5.1 목적
- hardware PWM의 사용 방법을 익힌다.
- `pwmSetMode()`, `pwmSetRange()`, `pwmSetClock()`의 역할을 이해한다.

### 5.2 수행 내용
다음 조건을 만족하는 `hardpwm_led.c`를 실행하시오.
- hardware PWM 핀(GPIO18)을 사용한다.
- duty를 변화시키며 LED 밝기를 제어한다.

### 5.3 컴파일 및 실행 예시
```bash
gcc -o hardpwm_led hardpwm_led.c -lwiringPi
./hardpwm_led
```

### 5.4 확인 사항
- software PWM과 hardware PWM의 차이를 설명할 수 있는가?
- duty cycle 변화에 따라 LED 밝기가 바뀌는가?

---

## 6. 실습 3 - 서보 모터 제어
### 6.1 목적
- PWM 신호 폭과 서보 모터 각도의 관계를 이해한다.
- 0도, 90도, 180도 제어를 구현한다.

### 6.2 수행 내용
다음 조건을 만족하는 `pwmservo.c`를 실행하시오.
- hardware PWM 핀(GPIO18)을 사용한다.
- 0도 → 90도 → 180도로 순차적으로 이동한다.

### 6.3 컴파일 및 실행 예시
```bash
gcc -o pwmservo pwmservo.c -lwiringPi
./pwmservo
```

### 6.4 확인 사항
- 서보가 각도에 맞게 움직이는가?
- `pwmWrite()` 값과 각도 매핑 관계를 설명할 수 있는가?

---

## 7. 실습 4 - 초음파 센서(HC-SR04)
### 7.1 목적
- 초음파 센서를 이용한 거리 측정 원리를 이해한다.
- `micros()`와 펄스 시간 측정 방식을 익힌다.

### 7.2 수행 내용
다음 조건을 만족하는 `wiringultra.c`를 실행하시오.
- TRIG 핀으로 짧은 펄스를 출력한다.
- ECHO 핀 HIGH 지속 시간을 측정한다.
- 거리를 cm 단위로 출력한다.

### 7.3 컴파일 및 실행 예시
```bash
gcc -o wiringultra wiringultra.c -lwiringPi
./wiringultra
```

### 7.4 확인 사항
- 손이나 물체의 거리 변화에 따라 출력이 달라지는가?
- 거리 계산식의 의미를 설명할 수 있는가?

---

## 8. 실습 5 - PIR 센서
### 8.1 목적
- PIR 센서의 디지털 출력 특성을 이해한다.
- 움직임 감지에 따라 LED를 제어한다.

### 8.2 수행 내용
다음 조건을 만족하는 `wiringpir.c`를 실행하시오.
- PIR 입력을 읽는다.
- 움직임 감지 시 LED를 켠다.
- 감지가 없으면 LED를 끈다.

### 8.3 컴파일 및 실행 예시
```bash
gcc -o wiringpir wiringpir.c -lwiringPi
./wiringpir
```

### 8.4 확인 사항
- 움직임 감지 시 출력이 HIGH로 바뀌는가?
- LED가 센서 상태에 따라 바뀌는가?

---

## 9. 실습 6 - 통합 과제: PIR Gate
### 9.1 목적
- PIR 입력과 PWM 출력을 결합한 간단한 임베디드 응용 프로그램을 작성한다.
- 함수 분리와 순차 제어 흐름을 연습한다.

### 9.2 요구사항
`pir_gate_assignment/gate.c`에서 다음 조건을 만족하도록 구현하시오.

1. `pwmInit()`
   - PIR 입력을 초기화한다.
   - LED soft PWM을 초기화한다.
   - 서보 PWM 출력을 초기화한다.

2. `isMotionDetected()`
   - PIR 현재 상태를 읽어 반환한다.

3. `setServoAngle()`
   - 입력 각도(0~180도)를 PWM 값으로 변환해 서보 모터를 제어한다.

4. `runGateSequence()`
   - PIR 감지 시 LED 밝기를 0%에서 100%로 증가시킨다.
   - 서보를 0도에서 90도로 이동시킨다.
   - 잠시 대기 후 다시 0도로 복귀시킨다.
   - LED 밝기를 다시 감소시킨다.

### 9.3 컴파일 및 실행 예시
```bash
cd pir_gate_assignment
gcc -o pir_gate main.c gate.c -lwiringPi
./pir_gate
```

### 9.4 확인 사항
- 움직임 감지 시 시퀀스가 실행되는가?
- LED 밝기 변화가 보이는가?
- 서보가 열림/닫힘 동작처럼 움직이는가?
- PIR 입력과 PWM 출력의 결합 구조를 설명할 수 있는가?

### 9.5 확장 미션 (선택)
- HC-SR04를 추가하여 **일정 거리 이내에서만** 게이트 시퀀스가 실행되도록 확장하시오.

---

## 10. 제출물
1. 회로 연결 사진
2. 작성한 코드 (`gate.c` 중심)
3. 컴파일 및 실행 명령
4. 실행 결과 사진 또는 짧은 영상 캡처
5. 간단한 설명
   - soft PWM과 hardware PWM 차이
   - 서보 각도 제어 원리
   - 초음파 거리 측정 원리
   - PIR 입력 처리 방식
