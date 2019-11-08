#include "Stepper.h"

#define BAUD_RATE 9600

#define ENCODER_POSITIONS 20
#define ENCODER_DEBOUNCE_DELAY 4
#define ENC_CLK_PIN 2
#define ENC_SW_PIN  3
#define ENC_DT_PIN  4

#define STEPS_PER_REVOLUTION 2040
#define RPM 17

#define STEPS_PER_POSITION STEPS_PER_REVOLUTION / ENCODER_POSITIONS

Stepper stepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11);

bool turnDetected;
bool turnDirection; // true = CCW, false = CW.
bool reset;

int encoderPos = 0;

void encoderRotationISR() {
    delay(ENCODER_DEBOUNCE_DELAY);
    
    turnDirection = digitalRead(ENC_DT_PIN);
    if(!digitalRead(ENC_CLK_PIN)) {
        turnDirection != turnDirection;
    }

    turnDetected = true;
}

void positionResetISR() {
    reset = true;
}

void setup() {
    pinMode(ENC_CLK_PIN, INPUT);
    pinMode(ENC_DT_PIN, INPUT);
    pinMode(ENC_SW_PIN, INPUT);

    digitalWrite(ENC_SW_PIN, HIGH);
    attachInterrupt(digitalPinToInterrupt(ENC_CLK_PIN), encoderRotationISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(ENC_SW_PIN), positionResetISR, FALLING);

    stepper.setSpeed(RPM);
}

void loop() {
    if(reset) {
        stepper.step(-1 * encoderPos * STEPS_PER_POSITION);
        encoderPos = 0;
        reset = false;
    }

    if(turnDetected) {
        if(turnDirection) {
            encoderPos++;
            stepper.step(STEPS_PER_POSITION);
        } else {
            encoderPos--;
            stepper.step(-1 * STEPS_PER_POSITION);
        }

        turnDetected = false;
    }
}
