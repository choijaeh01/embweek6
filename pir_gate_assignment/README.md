# pir_gate_assignment

## 과제 목표
PIR 센서가 움직임을 감지하면,
- LED 밝기가 점점 증가하고,
- 서보 모터가 게이트처럼 열렸다가,
- 다시 닫히는 프로그램을 완성한다.

이번 과제는 **PIR 입력 + PWM 출력**을 함께 사용하는 통합 실습이다.

## 파일 설명
- `main.c`
  - 메인 루프와 PIR 감지 흐름이 대부분 작성되어 있음
- `gate.h`
  - 핀 번호, 상수, 함수 원형 선언
- `gate.c`
  - 학생이 완성해야 할 핵심 함수들이 있음

## 작성할 함수
다음 **4개 항목**을 완성한다.
- `pwmInit()`
- `isMotionDetected()`
- `setServoAngle()`
- `runGateSequence()`

## 회로 연결
### PIR
- PIR output → physical pin 18 (BCM GPIO24, wiringPi 5)
- VCC → 5V
- GND → GND

### LED
- LED anode → 220Ω 저항 → physical pin 16 (BCM GPIO23, wiringPi 4)
- LED cathode → GND

### 서보 모터
- signal → physical pin 12 (BCM GPIO18, wiringPi 1)
- VCC → 5V
- GND → GND

## 참고 예제
- `../softpwm_led.c`
- `../pwmservo.c`
- `../wiringpir.c`

## 컴파일 방법
```bash
gcc -o pir_gate main.c gate.c -lwiringPi
```

## 실행 예시
```bash
./pir_gate
```
