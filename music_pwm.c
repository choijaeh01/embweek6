#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define SPKR 12   // BCM 12

static int notes[] = {
    391, 391, 440, 440, 391, 391, 330, 330,
    391, 391, 330, 330, 294, 294, 294, 0,
    391, 391, 440, 440, 391, 391, 330, 330,
    391, 330, 294, 330, 262, 262, 262, 0
};

static int note_count = sizeof(notes) / sizeof(notes[0]);

void playTone(int pin, int freq, int duration_ms)
{
    if (freq == 0) {
        delay(duration_ms);
        return;
    }

    int period_us = 1000000 / freq;
    int half_period = period_us / 2;
    int cycles = (duration_ms * 1000) / period_us;

    for (int i = 0; i < cycles; i++) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(half_period);
        digitalWrite(pin, LOW);
        delayMicroseconds(half_period);
    }
}

int main(void)
{
    if (wiringPiSetupGpio() == -1) {
        printf("wiringPi 초기화 실패\n");
        return 1;
    }

    pinMode(SPKR, OUTPUT);

    for (int i = 0; i < note_count; i++) {
        playTone(SPKR, notes[i], 280);
    }

    digitalWrite(SPKR, LOW);
    return 0;
}
