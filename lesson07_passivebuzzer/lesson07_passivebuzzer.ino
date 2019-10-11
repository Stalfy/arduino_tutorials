#include "pitches.h"

#define OUTPUT_PIN 8
#define NOTES 8
#define NOTE_DURATION 500 // ms.

const int MELODY[] = {
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

void setup() {}

void loop() {
    for(int i = 0; i < NOTES; i++) {
       tone(OUTPUT_PIN, MELODY[i], NOTE_DURATION);
       delay(200);
    }

    delay(2000); 
}
